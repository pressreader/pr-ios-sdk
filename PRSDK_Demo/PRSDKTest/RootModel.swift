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
    
    enum Service: RawRepresentable, Equatable {
        case `default`
        case multiTitlesNoFeed
        case kioscoPerfilBeta
        case beSingleTitle
        case singleTitleAndFeedBE
        case singleTitleAndSupAndFeed
        case custom(name: RawValue)
        
        static var defaultServices = [Service.default,
                                      .multiTitlesNoFeed,
                                      .kioscoPerfilBeta,
                                      .beSingleTitle,
                                      .singleTitleAndFeedBE,
                                      .singleTitleAndSupAndFeed]

        var rawValue: String {
            switch self {
            case .default: PRConfig.defaultServiceName
            case .multiTitlesNoFeed: "Multi titles + no Feed "
            case .kioscoPerfilBeta: "Kiosco Perfil Beta "
            case .beSingleTitle: " BE SingleTitle "
            case .singleTitleAndFeedBE: "Single title and Feed BE"
            case .singleTitleAndSupAndFeed: "Single title  and sup and feed"
            case .custom(let name): name
            }
        }
        
        init(rawValue: RawValue) {
            switch rawValue {
            case PRConfig.defaultServiceName:
                self = .default
            case Service.multiTitlesNoFeed.rawValue:
                self = .multiTitlesNoFeed
            case Service.kioscoPerfilBeta.rawValue:
                self = .kioscoPerfilBeta
            case Service.beSingleTitle.rawValue:
                self = .beSingleTitle
            case Service.singleTitleAndFeedBE.rawValue:
                self = .singleTitleAndFeedBE
            case Service.singleTitleAndSupAndFeed.rawValue:
                self = .singleTitleAndSupAndFeed
            default:
                self = .custom(name: rawValue)
            }
        }
    }
    
    enum AuthData: RawRepresentable {
        case token(String)
        case externalAuthToken(token: String, provider: String)
                
        var rawValue: [String: String] {
            switch self {
            case .token(let token):
                ["type": "token",
                 "token": token]
            case .externalAuthToken(let token, let provider):
                ["type": "externalToken",
                 "token": token,
                 "provider": provider]
            }
        }
        
        init?(rawValue: [String : String]) {
            guard let type = rawValue["type"] else {
                return nil
            }
            
            switch type {
            case "token":
                guard let auth = rawValue["token"]
                    .map({ AuthData.token($0) })
                else {
                    return nil
                }
                
                self = auth
                
            case "externalToken":
                guard let auth = lift(rawValue["token"], rawValue["provider"])
                    .map({ AuthData.externalAuthToken(token: $0, provider: $1) })
                else {
                    return nil
                }
                
                self = auth
                
            default:
                return nil
            }
        }
    }
    
    // MARK: - Public Properties

    var services: [Service] {
        var services = Service.defaultServices
        let currentService = self.currentService
        if !services.contains(currentService) {
            services.append(currentService)
        }
            
        return services
    }
    
    var currentService: Service {
        get {
            Service(rawValue: PressReader.serviceName)
        }
        set {
            PressReader.serviceName = newValue.rawValue
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

    var isAuthEnabled: Bool {
        !self.isDismissed && !self.isLocalService
    }
    
    var isReady: Bool {
        switch self.account?.state {
        case .idle, .authorized: return true
        default: return false
        }
    }

    var canAuthorise: Bool {
        self.isReady
    }
    
    var account: Account? {
        self.pressreader?.account
    }

    var authData: AuthData {
        get {
            if let rawData = UserDefaults.standard
                .dictionary(forKey: "PRSDKTestAuthData") as? [String: String],
                let authData = AuthData(rawValue: rawData)
            {
                return authData
            }
            
            if let token = UserDefaults.standard.string(forKey: "PRAuthToken") {
                UserDefaults.standard.setValue(nil, forKey: "PRAuthToken")
                let auth = AuthData.token(token)
                self.authData = auth
                
                return auth
            }
            
            return .token("")
        }
        set {
            UserDefaults.standard.set(newValue.rawValue, forKey: "PRSDKTestAuthData")
        }
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

    // MARK: - Private Properties

    private let delegate: Reloadable

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
    
    func authorisePressreader() {
        let complete = { (success: Bool, error: Error?) in
            print("Auth result: \(success), \(String(describing: error))")
            
            if !success {
                UIAlertController
                    .presentDismissableAlert(withTitle: "Auth Error",
                                             message: error?.localizedDescription)
            }
        }
        
        switch self.authData {
        case .token(let token):
            guard !token.isEmpty else { return }
            
            self.account?.authorize(token: token, completion: complete)
        case .externalAuthToken(let token, let provider):
            guard !token.isEmpty, !provider.isEmpty else { return }
            
            self.account?.authorize(externalToken: token,
                                    provider: provider,
                                    completion: complete)
        }
    }
    
    func deauthorizeAccount() async throws {
        try await self.account?.signOut()
    }
    
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
    
    func generateExternalAuthTokenMock() async throws -> AuthData {
        guard self.currentService == .singleTitleAndFeedBE else {
            throw ServiceError.unknown
        }
        
        guard let mockURL = URL(string: "https://services.pressreader.com/test/pr-mock-auth-server/token?sub=00u-\(Int.random(in: 1...Int.max))&aud=test-aud&minutes=36000")
        else {
            throw ServiceError.noServiceUrlProvided
        }
        
        let (data, _) = try await URLSession.shared.data(from: mockURL)
        let json = try JSONSerialization.jsonObject(with: data) as? [String: String]
        guard let token = json?["token"] else {
            throw ServiceError.unexpectedResponse
        }
        
        return .externalAuthToken(token: token, provider: "pressreaderJwt")
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
