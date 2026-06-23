//
//  RootModel.swift
//  PRSDKTest
//
//  Created by berec on 03/12/2020.
//  Copyright © 2020 PressReader. All rights reserved.
//

import Foundation
import PRUI
import PRAlertKit
import MBProgressHUD
import PRUtils

@MainActor
protocol Reloadable {
    func reloadData()
}

@MainActor
final class RootModel {
    
    // MARK: - Nested Types
    
    struct Service {
        static let `default` = PRConfig.defaultServiceName
        static let multiTitles = "Multi titles + no Feed "
        static let kioscoPerfil = "Kiosco Perfil Beta "
        static let singleTitle = " BE SingleTitle "
        static let singleTitleAndFeed = "Single title and Feed BE"
        static let singleTitleAndSupplementsAndFeed = "Single title  and sup and feed"
    }
        
    // MARK: - Public Properties

    var services: [String] {
        var services = [
            Service.default,
            Service.multiTitles,
            Service.kioscoPerfil,
            Service.singleTitle,
            Service.singleTitleAndFeed,
            Service.singleTitleAndSupplementsAndFeed
        ]
        let currentService = self.currentService
        if !services.contains(currentService) {
            services.append(currentService)
        }
            
        return services
    }
    
    var isServiceSelectionEnabled: Bool {
        PRConfig.configDefaults?.string("SERVICE_NAME") == nil
        && !PressReader.isLocalService
    }
    
    var currentService: String {
        get {
            PressReader.serviceName
        }
        set {
            PressReader.serviceName = newValue
        }
    }

    var isEdition: Bool {
        PressReader.isEdition
    }
    
    var isLocalService: Bool {
        PressReader.isLocalService
    }
    
    var canPresentFullUI: Bool {
        Bundle.main.infoDictionary?["PRFullUIEnabled"] as? Bool == true
        || self.isEdition
        || self.isLocalServiceActive
    }

    var isFullUIOnly: Bool {
        Bundle.main.infoDictionary?["PRFullUIOnly"] as? Bool == true
    }

    var isLocalServiceActive: Bool {
        self.account?.state == .localService
    }
    
    var isReady: Bool {
        switch self.account?.state {
        case .idle, .authorized: return true
        default: return false
        }
    }
    
    var account: Account? {
        self.pressreader?.account
    }
    
    var isCatalogEnabled: Bool {
        !self.isDismissed && !self.cids.isEmpty && !self.isLocalService
    }
    
    var booksEnabled: Bool {
        true
    }

    var gamesEnabled: Bool {
        true
    }

    var isLoggingEnabled: Bool {
        !self.isDismissed
    }

    var isArticleSetEnabled: Bool {
        !self.isDismissed && !self.articles.isEmpty && !self.isLocalService && !self.isEdition
    }

    var catalogItemsCount: Int {
        self.canShowCatalog ? self.cids.count : 0
    }

    var downloadedItemsCount: Int {
        self.downloaded?.items.count ?? 0
    }
    
    var books: [[String: Sendable]] {
        [
            ["id": "196778"],
            ["id": "211279"],
            ["id": "394959"],
            ["id": "216086"],
            ["id": "271073"],
            ["id": "196556"]
        ]
    }
    
    var games: [[String: Sendable]] {
        [
            ["id": 44667,
             "titleId": 40001,
             "displayName": "Codeword",
             "issueDate": "2026-06-16",
             "slug": "0071b441059049689269f8653e3b1f0a"],
            ["id": 44528,
             "titleId": 40012,
             "displayName": "Concise Crossword",
             "issueDate": "2026-06-16",
             "slug": "30f64dcc5fe8482eb5fd2d639f57a2f7"],
            ["id": 44529,
             "titleId": 40003,
             "displayName": "Cryptic Crossword",
             "issueDate": "2026-06-16",
             "slug": "233901f620cf40dfb7d2c42618c6ecea"],
            ["id": 44531,
             "titleId": 40013,
             "displayName": "Make Tracks",
             "issueDate": "2026-06-16",
             "slug": "2836b531c44b4172b6d26d4d2d95a607"],
            ["id": 44536,
             "titleId": 40011,
             "displayName": "Noughts and Crosses",
             "issueDate": "2026-06-16",
             "slug": "76491f640cb841f19711bb3838df48a6"]
        ]
    }
    
    var articles: [String] {
        self.isReady
        ? ["281651080992599",
           "281505052102991",
           "281852944455775",
           "281736980338521"]
        : []
    }

    let delegate: Reloadable

    // MARK: - Private Properties

    private var pressreader: PressReader? {
        guard !self.isDismissed else {
            return nil
        }

        if !PressReader.hasInstance() {
            Task { @MainActor in
                self.registerObservers()
            }

            PressReader.launchOptions = [.prAnalyticsTrackers: [self]]
        }

        return PressReader.instance()
    }

    private var catalog: PRCatalog? {
        self.pressreader?.catalog
    }

    private var downloaded: Downloaded? {
        self.catalog?.downloaded
    }

    private var cids: [(cid: String, date: Date?)] {
        // Don't rely on `catalog.loadedPublications` in your implementation.
        // It's used only for demonstration and a subject to change.
        // Instead obtain `cids` using provided PressReader Public API.
        self.catalog?.loadedPublications()?.prefix(20).map { ($0.cid, nil) } ?? []
        
        /*let formatter = PRDateFormatter.canonicalDateFormatter
        return [
            ("2962", formatter.date(from: "20260309")),
            ("2923", formatter.date(from: "20260305"))
        ]*/
    }
    
    private var canShowCatalog = false {
        didSet {
            guard self.canShowCatalog != oldValue else { return }
            
            self.delegate.reloadData()
        }
    }
    
    private var downloadedObserver: Downloaded.Observer?
    
    var isDismissed = false {
        didSet {
            if self.isDismissed {
                self.unregisterObservers()
                PressReader.dismiss()
            }

            self.delegate.reloadData()
        }
    }

    // MARK: - Init

    init(delegate: Reloadable) {
        self.delegate = delegate
    }
    
    // MARK: - Public Methods
        
    func catalogItem(at index: Int) -> TitleItem? {
        self.cids.safeObject(at: index).flatMap {
            self.catalog?.item(cid: $0.cid, date: $0.date)
        }
    }

    func downloadedItem(at index: Int) -> TitleItem? {
        self.catalog?.downloaded.items[index]
    }
    
    func deleteDownloadedItem(at index: Int) {
        self.downloadedItem(at: index).map {
            self.delete($0)
        }
    }

    func delete(_ item: TitleItem) {
        self.downloaded?.delete(item)
    }

    func getLogs() {
        guard let pressreader else { return }
        
        let hud = MBProgressHUD.showWindowHUD(withTitle: "Uploading...", message: nil, animated: true)
        
        Task {
            @MainActor
            func presentResults(title: String, message: String) {
                hud.hide(animated: false)
                UIAlertController.presentDismissableAlert(
                    withTitle: title,
                    message: message
                )
            }
            
            do {
                let logInfo = try await pressreader.getLogs()
                presentResults(
                    title: "Logs uploaded",
                    message: "\(logInfo.linkToUploadedLogs.absoluteString)\n\n\(logInfo.additionalInfo)"
                )
            }
            catch {
                presentResults(
                    title: "Error",
                    message: error.localizedDescription
                )
            }
        }
    }
        
    // MARK: - Notifications
    
    private func registerObservers() {
        let nCentre = NotificationCenter.default
        
        nCentre.addObserver(self,
                            selector: #selector(pressreaderStateHandler),
                            name: .PressReaderStateDidChange,
                            object: self.pressreader)
        
        nCentre.addObserver(self,
                            selector: #selector(authStateHandler),
                            name: .PRAuthStateDidChange,
                            object: self.account)
        
        self.downloadedObserver = self.downloaded?.observe { [weak self] in
            self?.delegate.reloadData()
        }
    }
    
    private func unregisterObservers() {
        NotificationCenter.default.removeObserver(self)
        self.downloadedObserver = nil
    }

    @objc
    private func pressreaderStateHandler(note: NSNotification) {
        let state = self.pressreader?.state ?? []
        print("PR state: \(state.rawValue)")
        
        if let error = note.userInfo?["error"] as? Error {
            print("PR error: \(error.localizedDescription)")
            
            return
        }
        
        if state.contains(.catalogLoaded) {
            self.canShowCatalog = true
        }
    }
    
    @objc
    private func authStateHandler(note: NSNotification) {
        guard let account else { return }
        
        print("PR account state: \(account.state)")
        
        self.delegate.reloadData()
    }
}

extension RootModel: @MainActor ReadingViewAnalyticsTracker {
    func trackOpenIssueForReading(issue: TrackingIssue) {
        print("opening \(issue.sourceType.rawValue) \(issue.title),\(issue.date ?? Date()) for reading")
    }
    func trackIssuePage(issue: TrackingIssue, pageNumber: Int) {
        print("switching to page \(pageNumber) in \(issue.sourceType.rawValue) \(issue.title),\(issue.date ?? Date())")
    }

    func trackArticleView(issue: TrackingIssue, article: TrackingArticle) {
        print("open article(\(article.id)) '\(article.headline)' from \(issue)")
    }
}

extension RootModel: @MainActor AnalyticsTracker {
    func track(_ name: PRAnalyticsTrackName,
               parameters: AnalyticsParameters?)
    {
        print("pr-analytics: \(name.rawValue)")
    }
}
