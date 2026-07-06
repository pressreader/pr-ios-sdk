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

final class RootVC: UITableViewController, Reloadable {
    
    // MARK: - Nested Types
    
    private enum Section: Int {
        case service
        case fullUI
        case auth
        case log
        case dismiss
        case catalog
    }
    
    // MARK: - Private Properties
    
    private lazy var model = {
        RootModel(delegate: self)
    }()
    
    private var sections = [Section]()
    private var catalogSections = [any ContentSection]()

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

    private func configureAuthTextField(cell: TextFieldCell,
                                        text: String?,
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
        model.authorizationData = .externalAuthToken(
            token: token,
            provider: provider,
            userId: self.authTextField(at: 2)?.text?.nonEmpty
        )
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
            }
        }
        
        self.sections = sections
    }
    
    private func updateCatalogSections() {
        let model = self.model
        var sections = [any ContentSection]()
        
        if model.publicationsEnabled {
            sections.append(PublicationSection(model: model))
            sections.append(DownloadedSection(model: model))
        }

        if model.articlesEnabled {
            sections.append(ArticlesSection(model: model))
        }

        if model.booksEnabled {
            sections.append(BooksSection(model: model))
        }

        if model.gamesEnabled {
            sections.append(GamesSection(model: model))
        }

        self.catalogSections = sections
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
            case .externalAuthToken(let token, _, _):
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
            case .externalAuthToken(_, let provider, _):
                let cell = self.textFieldCell(tableView, indexPath: indexPath)
                self.configureAuthTextField(cell: cell,
                                            text: provider,
                                            placeholder: "Provider",
                                            isEnabled: model.canAuthorize)
                
                return cell
            }
        case 2 where model.isTokenGenerationAvailable:
            let cell = self.textFieldCell(tableView, indexPath: indexPath)
            var userId: String?
            if case .externalAuthToken(_, _, let id) = authData {
                userId = id
            }
            
            self.configureAuthTextField(cell: cell,
                                        text: userId,
                                        placeholder: "User Id",
                                        isEnabled: model.canAuthorize)
            return cell
        case 3 where model.isTokenGenerationAvailable && model.account?.state != .authorized:
            return self.actionCell(tableView,
                                   indexPath: indexPath,
                                   title: "Generate external token and provider",
                                   enabled: model.canAuthorize)
        case 2, 3, 4:
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
        
        return switch sections[section] {
        case .auth:
            switch model.authorizationData {
            case .giftToken:
                2
            case .externalAuthToken:
                model.isTokenGenerationAvailable
                ? model.account?.state == .authorized ? 4 : 5
                : 3
            }
            
        case .catalog: {
            self.updateCatalogSections()
            
            return self.catalogSections.count
        }()
            
        default:
            1
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
            let contentSection = self.catalogSections[indexPath.row]
            let itemsCount = contentSection.itemsCount
            
            let details = itemsCount > 0
            ? "\(itemsCount)"
            : contentSection.isLoadable ? "Loading..." : "0"
            
            cell = self.selectorCell(
                tableView,
                indexPath: indexPath,
                title: contentSection.title,
                details: details,
                accessibilityId: contentSection.acessibilityId
            )
        }

        return cell
    }
    
    // MARK: - UITableViewDelegate

    override func tableView(_ tableView: UITableView, shouldHighlightRowAt indexPath: IndexPath) -> Bool {
        switch self.sections[indexPath.section] {
        case .auth:
            self.model.canAuthorize
            && !(tableView.cellForRow(at: indexPath) is TextFieldCell)
        case .log, .dismiss, .fullUI, .catalog:
            true
        case .service:
            self.model.isServiceSelectionEnabled
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
                        try await model.generateExternalAuthTokenMock(
                            userId: self.authTextField(at: 2)?.text
                        )
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

        case .catalog:
            let listVC = self.catalogSections[indexPath.row].contentController()
            self.navigationController?.pushViewController(listVC, animated: true)

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
        }
        
        tableView.deselectRow(at: indexPath, animated: true)
    }
    
    override func tableView(
        _ tableView: UITableView,
        titleForHeaderInSection section: Int
    ) -> String? {
        switch self.sections[section] {
        case .auth: "Authorization"
        case .log: "Logs"
        case .catalog: "Catalog"
        default: nil
        }
    }

    override func tableView(
        _ tableView: UITableView,
        titleForFooterInSection section: Int
    ) -> String? {
        switch self.sections[section] {
        case .auth:
            return self.authorizationFooterText
        default:
            return nil
        }
    }
}
