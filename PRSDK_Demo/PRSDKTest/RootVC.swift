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
    
    private enum Section: Int {
        case service, fullUI, auth, log, dismiss, catalog, downloaded, articles
    }
        
    // MARK: - Private Properties
    
    private lazy var model = {
        RootModel(delegate: self)
    }()
    
    private var isReloadingDisabled = false
    private var sections = [Section]()
    
    private var authorizeCellTitle: String {
        let model = self.model
        guard let account = model.account else {
            return ""
        }
        
        let state = account.state
        switch state {
        case .authorising:
            return "Authorizing..."
        case .notReachable:
            return "Service is unavailable"
        case .localService:
            return "Not available for local service"
        default:
            switch model.authorizationData {
            case .externalAuthToken where state == .authorized:
                return "Deauthorize"
            default:
                return "Authorize"
            }
        }
    }
    
    private var authorizationFooterText: String {
        let authorizationData = self.model.authorizationData
        let text = switch authorizationData {
        case .giftToken:
            "Authorizes the account by requesting gifted access using the provided token."
        case .externalAuthToken:
            "Authorizes the user with an external authentication token from a third-party provider."
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
        selectionEnabled: Bool = true,
        accessibilityId: AccessibilityId? = nil
    ) -> UITableViewCell {
        let cellId = "selectorCell"
        let cell = tableView.dequeueReusableCell(withIdentifier: cellId)
        ?? UITableViewCell(style: .value1, reuseIdentifier: cellId )
        
        cell.accessoryType = selectionEnabled ? .disclosureIndicator : .none
        
        cell.textLabel.map {
            $0.textColor = .label
            $0.text = title
        }
        
        cell.detailTextLabel?.text = details
        cell.accessibilityId = accessibilityId
        
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
        let model = self.model
        let serviceSelector = SelectionView(
            options: model.services,
            selectedOption: model.currentService
        ) { [weak self] in
            guard let self else { return }
            
            self.model.currentService = $0
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
    
    @MainActor
    private func authTextField(at row: Int) -> UITextField? {
        guard let section = self.sections.firstIndex(of: .auth),
              let cell = self.tableView.cellForRow(
                at: IndexPath(row: row, section: section)
              ) as? TextFieldCell
        else {
            return nil
        }
        
        return cell.textField
    }
    
    private func authWithToken() async throws {
        guard let token = self.authTextField(at: 0)?.text else {
            return
        }
        
        let model = self.model
        model.authorizationData = .giftToken(token)
        try await model.authorize()
    }
    
    private func authWithExternalToken() async throws{
        guard let token = self.authTextField(at: 0)?.text,
              let provider = self.authTextField(at: 1)?.text
        else {
            return
        }
        
        let model = self.model
        model.authorizationData = .externalAuthToken(token: token, provider: provider)
        try await model.authorize()
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
            
            if model.isAuthorizationEnabled {
                sections.append(.auth)
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
    
    private func authCell(tableView: UITableView, indexPath: IndexPath) -> UITableViewCell {
        let model = self.model
        let authData = model.authorizationData
        
        switch indexPath.row {
        case 0:
            let cell = self.textFieldCell(tableView, indexPath: indexPath)
            let data = switch authData {
            case .giftToken(let token):
                (token, "Token")
            case .externalAuthToken(let token, _):
                (token, "External Token")
            }
            
            self.configureAuthTextField(cell: cell,
                                        text: data.0,
                                        placeholder: data.1,
                                        isEnabled: model.canAuthorize)
            
            return cell
            
        case 1:
            switch authData {
            case .giftToken:
                return self.actionCell(tableView,
                                       indexPath: indexPath,
                                       title: self.authorizeCellTitle,
                                       enabled: model.canAuthorize)
            case .externalAuthToken(_, let provider):
                let cell = self.textFieldCell(tableView, indexPath: indexPath)
                self.configureAuthTextField(cell: cell,
                                            text: provider,
                                            placeholder: "Provider",
                                            isEnabled: model.canAuthorize)
                
                return cell
            }
        case 2 where model.isTokenGenerationAvailable:
            return self.actionCell(tableView,
                                   indexPath: indexPath,
                                   title: "Generate external token and provider",
                                   enabled: model.canAuthorize)
        case 2, 3:
            return self.actionCell(tableView,
                                   indexPath: indexPath,
                                   title: self.authorizeCellTitle,
                                   enabled: model.canAuthorize)
        default:
            return UITableViewCell()
        }
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
        case .auth:
            return switch model.authorizationData {
                case .giftToken: 2
            case .externalAuthToken: model.isTokenGenerationAvailable ? 4 : 3
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
        case .auth:
            cell = self.authCell(tableView: tableView, indexPath: indexPath)
        case .service:
            cell = self.selectorCell(tableView,
                                     indexPath: indexPath,
                                     title: "Service",
                                     details: model.currentService,
                                     selectionEnabled: model.isServiceSelectionEnabled)

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
        case .auth:
            self.model.canAuthorize
            && !(tableView.cellForRow(at: indexPath) is TextFieldCell)
        case .log, .dismiss, .fullUI, .articles:
            true
        case .service:
            self.model.isServiceSelectionEnabled
        default:
            false
        }
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let model = self.model
        switch self.sections[indexPath.section] {
        case .auth:
            Task { @MainActor in
                do {
                    switch model.authorizationData {
                    case .giftToken:
                        try await self.authWithToken()
                    case .externalAuthToken where indexPath.row == tableView
                            .numberOfRows(inSection: indexPath.section) - 1:
                        if model.account?.state == .authorized {
                            try await model.deauthorize()
                        }
                        else {
                            try await self.authWithExternalToken()
                        }
                    case .externalAuthToken:
                        try await model.generateExternalAuthTokenMock()
                        self.reloadData()
                    }
                }
                catch {
                    UIAlertController.presentDismissableAlert(withTitle: "Auth Error",
                                                              message: error.localizedDescription)
                }
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
        case .auth:
            return self.authorizationFooterText
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
