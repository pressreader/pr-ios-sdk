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
    
    // MARK: - Public Properties

    var serviceName: String {
        PressReader.serviceName
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
    
    var isLocalServiceActive: Bool {
        self.pressreader.account.state == .localService
    }

    var isAuthEnabled: Bool {
        !self.isLocalService
    }
    
    var canAuthorise: Bool {
        self.pressreader.account.state == .idle
    }
    
    var account: Account {
        self.pressreader.account
    }

    var authToken: String? {
        get {
            UserDefaults.standard.string(forKey: "PRAuthToken")
        }
        set {
            UserDefaults.standard.setValue(newValue, forKey: "PRAuthToken")
        }
    }
    
    var isCatalogEnabled: Bool {
        !self.cids.isEmpty && !self.isLocalService
    }
        
    var catalogItemsCount: Int {
        self.canShowCatalog ? self.cids.count : 0
    }

    var downloadedItemsCount: Int {
        self.downloaded.items.count
    }

    // MARK: - Private Properties

    private let delegate: Reloadable

    private var pressreader: PressReader {
        if !PressReader.hasInstance() {
            PressReader.launchOptions = [.prAnalyticsTrackers: [self]]
        }

        return PressReader.instance()
    }

    private var catalog: PRCatalog {
        self.pressreader.catalog
    }

    private var downloaded: Downloaded {
        self.catalog.downloaded
    }

    private var cids: [String] {
        // Never rely on `catalog.sources` property in your implementation.
        // It's used only for demonstration and a subject to change.
        // Instead obtain `cids` using provided PressReader Public API.
        self.catalog.sources?.prefix(20).map { $0.cid } ?? []
    }
    
    private var canShowCatalog = false {
        didSet {
            guard self.canShowCatalog != oldValue else { return }
            
            self.delegate.reloadData()
        }
    }
    
    private lazy var downloadedObserver: Downloaded.Observer = {
        self.downloaded.observe { [weak self] in
            self?.delegate.reloadData()
        }
    }()
    
    // MARK: - Init

    init(delegate: Reloadable) {
        self.delegate = delegate
        self.registerObservers()
    }
    
    // MARK: - Public Methods
    
    func authorisePressreader() {
        guard let token = self.authToken, token.count > 0 else {
            return
        }

        self.pressreader.account.authorize(token: token) { (success, error) in
            print("Auth result: \(success), \(String(describing: error))")
            
            if !success {
                UIAlertController
                    .presentDismissableAlert(withTitle: "Auth Error",
                                             message: error?.localizedDescription)
            }
        }
    }
    
    func catalogItem(at index: Int) -> PRCatalogItem? {
        self.catalog.item(cid: self.cids[index], date: nil)
    }

    func downloadedItem(at index: Int) -> PRCatalogItem {
        self.catalog.downloaded.items[index]
    }
    
    func deleteDownloadedItem(at index: Int) {
        self.delete(self.downloadedItem(at: index))
    }

    func delete(_ item: PRCatalogItem) {
        self.downloaded.delete(item)
    }

    func getLogs() {
        let hud = MBProgressHUD.showWindowHUD(withTitle: "Uploading...", message: nil, animated: true)
        self.pressreader
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
                            object: self.pressreader.account)
        
        _ = self.downloadedObserver
    }

    @objc
    private func pressreaderStateHandler(note: NSNotification) {
        let state = self.pressreader.state
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
        print("PR account state: \(self.pressreader.account.state)")
        
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
//    func trackIssueTextFlow(issue: TrackingIssue) {}
    func trackArticleView(issue: TrackingIssue, article: TrackingArticle) {
        print("open article(\(article.id)) '\(article.headline)' from \(issue)")
    }
//    func trackListenView(issue: TrackingIssue) {}
//    func trackTranlated(article: TrackingArticle, languageFrom: String, laguageTo: String) {}
//    func trackPrintedPages(issue: TrackingIssue, isFullPage: Bool, pageNumbers: [Int]) {}
//    func trackPrintedArticle(issue: TrackingIssue, article: TrackingArticle, inReplicaPresentation: Bool) {}
}
