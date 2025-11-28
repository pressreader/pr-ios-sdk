//
//  RootVC.swift
//  PRSDKTest
//
//  Created by berec on 21/01/2020.
//  Copyright © 2020 PressReader. All rights reserved.
//

import UIKit
import PRUI
import PRUIKit
import SwiftUI

final class RootVC: UITableViewController, Reloadable, IssueHandler {
    
    // MARK: - Nested Types
    
    private enum Section {
        case service, fullUI, auth(RootModel.AuthData), log, dismiss, catalog, downloaded, articles
    }
        
    // MARK: - Private Properties
    
    private lazy var model = {
        RootModel(delegate: self)
    }()
    
    private var isReloadingDisabled = false
    private var sections = [Section]()
        
    // MARK: - Life Cycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.title = "PRSDK Demo"
        
        let table: UITableView = self.tableView
        table.register(UITableViewCell.self, forCellReuseIdentifier: "actionCell")
        table.register(TextFieldCell.self, forCellReuseIdentifier: "textFieldCell")
        table.register(IssueCell.self, forCellReuseIdentifier: .sdkTest.cells.issue)
        table.register(UITableViewCell.self, forCellReuseIdentifier: .sdkTest.cells.article)
    }
    
    // MARK: - Private Methods
    
    private func selectorCell(
        _ tableView: UITableView,
        indexPath: IndexPath,
        title: String,
        details: String,
        accessibilityId: AccessibilityId? = nil
    ) -> UITableViewCell {
        let cellId = "selectorCell"
        let cell = tableView.dequeueReusableCell(withIdentifier: cellId)
        ?? UITableViewCell(style: .value1, reuseIdentifier: cellId )
        
        cell.accessoryType = .disclosureIndicator
        
        cell.textLabel.map {
            $0.textColor = .label
            $0.text = title
        }
        
        cell.detailTextLabel.map {
            $0.text = details
        }
        
        accessibilityId.map {
            cell.accessibilityId = $0
        }
        
        return cell
    }

    private func actionCell(
        _ tableView: UITableView,
        indexPath: IndexPath,
        title: String? = nil,
        enabled: Bool = true,
        accessibilityId: AccessibilityId? = nil
    ) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "actionCell", for: indexPath)
        cell.textLabel.map {
            $0.isEnabled = enabled
            $0.textColor = .label
            $0.text = title
        }

        cell.accessibilityId = accessibilityId

        return cell
    }

    private func textFieldCell(_ tableView: UITableView, indexPath: IndexPath) -> TextFieldCell {
        tableView.dequeueReusableCell(withIdentifier: "textFieldCell", for: indexPath) as! TextFieldCell
    }

    private func issueCell(_ tableView: UITableView, indexPath: IndexPath) -> IssueCell {
        
        tableView.dequeueReusableCell(withIdentifier: .sdkTest.cells.issue, for: indexPath) as! IssueCell
    }
        
    private func updateTokenCell(_ cell: TextFieldCell, authData: RootModel.AuthData) {
        if case .giftToken(let token) = authData {
            self.configureAuthTextField(cell: cell,
                                        text: token,
                                        placeholder: "Token",
                                        isEnabled: self.model.canAuthorize(authData: authData))
        }
        else if case .externalAuthToken(let token, _) = authData {
            self.configureAuthTextField(cell: cell,
                                        text: token,
                                        placeholder: "External Token",
                                        isEnabled: false)
        }
    }
    
    private func updateProviderCell(_ cell: TextFieldCell, authData: RootModel.AuthData) {
        var  text = ""
        if case .externalAuthToken(_, let provider) = authData {
            text = provider
        }

        self.configureAuthTextField(cell: cell,
                                    text: text,
                                    placeholder: "Provider",
                                    isEnabled: false)
    }
    
    private func configureAuthTextField(cell: TextFieldCell,
                                        text: String,
                                        placeholder: String,
                                        isEnabled: Bool)
    {
        let textField = cell.textField
        textField.placeholder = placeholder
        textField.clearButtonMode = .whileEditing
        textField.text = text
        textField.isEnabled = isEnabled
        textField.textColor = isEnabled ? .label : .secondaryLabel
    }
    
    private func selectService() {
        let serviceSelector = SelectionView(
            options: self.model.services.map ({ $0.rawValue }),
            selectedOption: self.model.currentService.rawValue
        ) { [weak self] in
            guard let self else { return }
            
            self.model.currentService = .init(rawValue: $0)
            self.navigationController?.popViewController(animated: true)
        }
        
        let hosting = UIHostingController(rootView: serviceSelector)
        hosting.title = "Services"
        
        self.navigationController?.pushViewController(hosting, animated: true)
    }
    
    @MainActor
    private func openArticle(at indexPath: IndexPath) async {
        let activityIndicator = UIActivityIndicatorView(style: .medium)
        activityIndicator.startAnimating()
        
        let cell = tableView.cellForRow(at: indexPath)!
        cell.accessoryView = activityIndicator
        
        await PressReader.instance().openArticle(
            id: model.articles[indexPath.row]
        )
        
        activityIndicator.stopAnimating()
    }
    
    private func authWithToken() {
        let section = self.sections.firstIndex(where: {
            if case .auth(.giftToken) = $0 {
                return true
            }
            
            return false
        })
        guard let section,
              let cell = self.tableView.cellForRow(at: IndexPath(row: 0, section: section)) as? TextFieldCell
        else {
            return
        }
        
        let textField = cell.textField
        let token = textField.text ?? ""
        
        Task {
            do {
                try await self.model.authorize(giftToken: token)
            }
            catch {
                self.presentAuthError(error: error)
            }
        }
    }
    
    private func toggleExternalAuth() {
        Task {
            do {
                let model = self.model
                if model.account?.state == .authorized {
                    try await model.deauthorize()
                }
                else {
                    try await model.authorizeWithExternalToken()
                }
            }
            catch {
                self.presentAuthError(error: error)
            }
        }
    }
    
    @MainActor
    private func presentAuthError(error: Error) {
        UIAlertController.presentDismissableAlert(withTitle: "Auth Error",
                                                  message: error.localizedDescription)
    }
    
    private func updateSections() {
        let model = self.model
        var sections = [Section]()
        
        if !model.isDismissed {
            sections.append(.service)
            if model.canPresentFullUI {
                sections.append(.fullUI)
            }
        }
        
        if !model.isFullUIOnly {
            sections.append(.dismiss)
            
            model.availableAuthOptions.forEach {
                sections.append(.auth($0))
            }
                        
            if model.isLoggingEnabled {
                sections.append(.log)
            }
            
            if model.isCatalogEnabled {
                sections.append(.catalog)
                sections.append(.downloaded)
            }
            
            if model.isArticleSetEnabled {
                sections .append(.articles)
            }
        }
        
        self.sections = sections
    }
    
    private func authoriseCellTitle(authData: RootModel.AuthData) -> String {
        guard let account = self.model.account else {
            return ""
        }
        
        let state = account.state
        switch state {
        case .authorising:
            return "Authorising..."
        case .notReachable:
            return "Service is unavailable"
        case .localService:
            return "Not available for local service"
        default:
            switch authData {
            case .giftToken:
                return "Authorize with Gift token"
            case .externalAuthToken:
                return state == .authorized
                && self.model.authorizationData?.id == RootModel.AuthData
                    .externalAuthToken(token: "", provider: "").id
                ? "Deuthorize account"
                : "Generate token and authorize"
            }
        }
    }
    
    private func authorizationFooterText(authData: RootModel.AuthData) -> String {
        let text = switch authData{
        case .giftToken:
            "Authorizes the account by requesting gifted access using the provided token."
        case .externalAuthToken:
            "Authorizes the user with an external authentication token from a third-party provider.\nToken and provider are generated automatically."
        }
        
        let expiration = self.model.account.flatMap {
            $0.state == .authorized
            ? "Authorized till \(DateFormatter.localizedString(from: $0.expirationDate ?? .distantFuture, dateStyle: .short, timeStyle: .short))"
            : nil
        }
        
        return [expiration, text]
            .compactMap { $0 }
            .joined(separator: "\n")
    }
    
    // MARK: - Reloadable

    func reloadData() {
        guard !self.isReloadingDisabled else { return }
        
        self.tableView.reloadData()
    }

    // MARK: - UITableViewDataSource
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        self.updateSections()
        
        return self.sections.count
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        let sections = self.sections
        let model = self.model
        switch sections[section] {
        case .auth(let authData):
            return switch authData {
                case .giftToken(_): 2
                case .externalAuthToken(_, _): 3
            }
        case .catalog:
            return model.catalogItemsCount
        case .downloaded:
            return model.downloadedItemsCount
        case .articles:
            return model.articles.count
        default:
            return 1
        }
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        var cell: UITableViewCell
        
        let sections = self.sections
        let model = self.model
        
        switch sections[indexPath.section] {
        case .auth(let authData):
            switch indexPath.row {
            case 0:
                let _cell = self.textFieldCell(tableView, indexPath: indexPath)
                self.updateTokenCell(_cell, authData: authData)
                cell = _cell

            case 1:
                switch authData {
                case .giftToken(_):
                    cell = self.actionCell(tableView,
                                           indexPath: indexPath,
                                           title: self.authoriseCellTitle(authData: authData),
                                           enabled: model.canAuthorize(authData: authData))
                case .externalAuthToken(_, _):
                    let _cell = self.textFieldCell(tableView, indexPath: indexPath)
                    self.updateProviderCell(_cell, authData: authData)
                    cell = _cell
                }
            case 2:
                cell = self.actionCell(tableView,
                                       indexPath: indexPath,
                                       title: self.authoriseCellTitle(authData: authData),
                                       enabled: model.canAuthorize(authData: authData))
            
            default:
                cell = UITableViewCell()
            }
            
        case .service:
            cell = self.selectorCell(tableView,
                                     indexPath: indexPath,
                                     title: "Service",
                                     details: model.currentService.rawValue)

        case .fullUI:
            cell = self.actionCell(tableView,
                                   indexPath: indexPath,
                                   title: "Full UI",
                                   accessibilityId: .sdkTest.cells.fullUI)

        case .log:
            cell = self.actionCell(tableView,
                                   indexPath: indexPath,
                                   title: "Upload Logs and Get the link")

        case .dismiss:
            cell = self.actionCell(
                tableView,
                indexPath: indexPath,
                title: model.isDismissed ? "Restore" : "Dismiss",
                accessibilityId: .sdkTest.cells.dismiss
            )

        case .catalog:
            let _cell = self.issueCell(tableView, indexPath: indexPath)
            _cell.issue = model.catalogItem(at: indexPath.row)
            _cell.delegate = self

            cell = _cell

        case .downloaded:
            let _cell = self.issueCell(tableView, indexPath: indexPath)
            _cell.issue = model.downloadedItem(at: indexPath.row)

            cell = _cell

        case .articles:
            cell = tableView.dequeueReusableCell(
                withIdentifier: .sdkTest.cells.article,
                for: indexPath
            )
            
            var content = cell.defaultContentConfiguration()
            content.text = "id: \(model.articles[indexPath.row])"
            cell.contentConfiguration = content
        }
        
        return cell
    }
    
    // MARK: - UITableViewDelegate

    override func tableView(_ tableView: UITableView, shouldHighlightRowAt indexPath: IndexPath) -> Bool {
        switch self.sections[indexPath.section] {
        case .auth(let authData):
            return indexPath.row == self.tableView(tableView,
                                                   numberOfRowsInSection: indexPath.section) - 1
            && self.model.canAuthorize(authData: authData)
        case .log, .dismiss, .service, .fullUI, .articles:
            return true
        default:
            return false
        }
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let model = self.model
        switch self.sections[indexPath.section] {
        case .auth(let authData):
            switch authData {
            case .giftToken(_):
                self.authWithToken()
            case .externalAuthToken(_, _):
                self.toggleExternalAuth()
            }

        case .log:
            model.getLogs()
            
        case .articles:
            Task { await self.openArticle(at: indexPath) }
            
        case .dismiss:
            model.isDismissed.toggle()
            
        case .service:
            self.selectService()
        
        case .fullUI:
            self.present(
                PressReader.instance().rootViewController,
                animated: true,
                completion: nil
            )

        default:
            break
        }
        
        tableView.deselectRow(at: indexPath, animated: true)
    }
    
    override func tableView(_ tableView: UITableView,
                            titleForHeaderInSection section: Int) -> String?
    {
        switch self.sections[section] {
        case .auth: "Authorization"
        case .log: "Logs"
        case .catalog: "Catalog"
        case .downloaded: "Downloaded"
        case .articles: "Articles"
        default: nil
        }
    }
    
    override func tableView(
        _ tableView: UITableView,
        titleForFooterInSection section: Int
    ) -> String? {
        let model = self.model

        switch self.sections[section] {
        case .auth(let authData):
            return self.authorizationFooterText(authData: authData)
        case .catalog:
            return model.catalogItemsCount > 0 ? nil : "Loading..."

        case .downloaded:
            return "Downloaded (ordered) items will appear here"

        default:
            return nil
        }
    }
    
    override func tableView(
        _ tableView: UITableView,
        editingStyleForRowAt indexPath: IndexPath
    ) -> UITableViewCell.EditingStyle {
        switch self.sections[indexPath.section] {
        case .downloaded: .delete
        case .catalog:
            self.model.catalogItem(at: indexPath.row)?.download?.state ==  .ready
            ? .delete
            : .none
        default: .none
        }
    }
    
    override func tableView(_ tableView: UITableView,
                            commit editingStyle: UITableViewCell.EditingStyle,
                            forRowAt indexPath: IndexPath)
    {
        switch self.sections[indexPath.section] {
        case .downloaded:
            self.isReloadingDisabled = true
            
            self.model.deleteDownloadedItem(at: indexPath.row)
            tableView.deleteRows(at: [indexPath], with: .automatic)
            
            self.isReloadingDisabled = false
        case .catalog:
            self.model.catalogItem(at: indexPath.row).map {
                self.model.delete($0)
                (self.tableView.cellForRow(at: indexPath) as? IssueCell).map {
                    $0.update()
                }
            }
        default: break
        }
    }
    
    // MARK: - IssueHandler
    
    func openIssue(_ issue: PRCatalogItem) {
        guard let rootVC = UIApplication.shared.rootVC,
              let reader = ReadingVC(issue)
        else { return }
        
        rootVC.present(reader, animated: true, completion: nil)
    }
}
