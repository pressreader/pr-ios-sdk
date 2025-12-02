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


protocol Reloadable {
    func reloadData()
}

final class RootModel {
    
    // MARK: - Nested Types
    
    struct Service {
        static let `default` = PRConfig.defaultServiceName
        static let multiTitlesNoFeed = "Multi titles + no Feed "
        static let kioscoPerfilBeta = "Kiosco Perfil Beta "
        static let beSingleTitle = " BE SingleTitle "
        static let singleTitleAndFeedBE = "Single title and Feed BE"
        static let singleTitleAndSupAndFeed = "Single title  and sup and feed"
    }
        
    // MARK: - Public Properties

    var services: [String] {
        var services = [
            Service.default,
            Service.multiTitlesNoFeed,
            Service.kioscoPerfilBeta,
            Service.beSingleTitle,
            Service.singleTitleAndFeedBE,
            Service.singleTitleAndSupAndFeed
        ]
        let currentService = self.currentService
        if !services.contains(currentService) {
            services.append(currentService)
        }
            
        return services
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

    private var cids: [String] {
        // Never rely on `catalog.sources` property in your implementation.
        // It's used only for demonstration and a subject to change.
        // Instead obtain `cids` using provided PressReader Public API.
        self.catalog?.loadedPublications()?.prefix(20).map { $0.cid } ?? []
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
        self.catalog?.item(cid: self.cids[index], date: nil)
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
        let hud = MBProgressHUD.showWindowHUD(withTitle: "Uploading...", message: nil, animated: true)
        self.pressreader?
            .getLogs { (result: Result<(linkToUploadedLogs: URL,
                                        additionalInfo: String), Error>) in
                hud.hide(animated: false)

                switch result {
                case .success (let (link, extraInfo)):
                    UIAlertController.presentDismissableAlert(withTitle: "Logs uploaded", message: "\(link.absoluteString)\n\n\(extraInfo)")
                case .failure(let error):
                    UIAlertController.presentDismissableAlert(withTitle: "Error", message: error.localizedDescription)
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

extension RootModel: ReadingViewAnalyticsTracker {
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

extension RootModel: AnalyticsTracker {
    func track(_ name: PRAnalyticsTrackName,
               parameters: AnalyticsParameters?)
    {
        print("pr-analytics: \(name.rawValue)")
    }
}
