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
    
    private class Sections {
        var service: Int?
        var fullUI: Int?
        var auth: Int?
        var log: Int?
        var dismiss: Int?
        var catalog: Int?
        var downloaded: Int?
        var articles: Int?
    }

    // MARK: - Private Properties

    private lazy var model = {
        RootModel(delegate: self)
    }()
    
    private var isReloadingDisabled = false
    private var sections = Sections()

    private var authoriseCellTitle: String {
        guard let account = self.model.account else {
            return ""
        }
        
        switch account.state {
        case .authorising:
            return "Authorising..."
        case .notReachable:
            return "Service is unavailable"
        default:
            return "Authorize"
        }
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

    private func updateTokenCell(_ cell: TextFieldCell) {
        let textField = cell.textField
        textField.placeholder = "Enter token and tap Authorize"
        textField.clearButtonMode = .whileEditing
        textField.text = self.model.authToken
        
        let isEnabled = self.model.canAuthorise
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
    
    // MARK: - Reloadable

    func reloadData() {
        guard !self.isReloadingDisabled else { return }
        
        self.tableView.reloadData()
    }

    // MARK: - UITableViewDataSource
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        let sections = Sections()
        var section = -1
        
        let increment = { () -> Int in
            section += 1; return section
        }
        
        let model = self.model

        if !model.isDismissed {
            sections.service = increment()
            if model.canPresentFullUI {
                sections.fullUI = increment()
            }
        }
        
        if !model.isFullUIOnly {
            sections.dismiss = increment()
            
            if model.isAuthEnabled {
                sections.auth = increment()
            }
            
            if model.isLoggingEnabled {
                sections.log = increment()
            }
            
            if self.model.isCatalogEnabled {
                sections.catalog = increment()
                sections.downloaded = increment()
            }
            
            if self.model.isArticleSetEnabled {
                sections.articles = increment()
            }
        }
        
        self.sections = sections
        
        return increment()
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        let sections = self.sections
        let model = self.model
        switch section {
        case sections.auth:
            return 2
        case sections.catalog:
            return model.catalogItemsCount
        case sections.downloaded:
            return model.downloadedItemsCount
        case sections.articles:
            return model.articles.count
        default:
            return 1
        }
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        var cell: UITableViewCell
        
        let sections = self.sections
        let model = self.model
        
        switch indexPath.section {
        case sections.auth:
            if indexPath.row == 0 {
                let _cell = self.textFieldCell(tableView, indexPath: indexPath)
                self.updateTokenCell(_cell)
                cell = _cell
            }
            else {
                cell = self.actionCell(tableView,
                                       indexPath: indexPath,
                                       title: self.authoriseCellTitle,
                                       enabled: model.canAuthorise)
            }
            
        case sections.service:
            cell = self.selectorCell(tableView,
                                     indexPath: indexPath,
                                     title: "Service",
                                     details: model.currentService.rawValue)

        case sections.fullUI:
            cell = self.actionCell(tableView,
                                   indexPath: indexPath,
                                   title: "Full UI",
                                   accessibilityId: .sdkTest.cells.fullUI)

        case sections.log:
            cell = self.actionCell(tableView,
                                   indexPath: indexPath,
                                   title: "Upload Logs and Get the link")

        case sections.dismiss:
            cell = self.actionCell(
                tableView,
                indexPath: indexPath,
                title: model.isDismissed ? "Restore" : "Dismiss",
                accessibilityId: .sdkTest.cells.dismiss
            )

        case sections.catalog:
            let _cell = self.issueCell(tableView, indexPath: indexPath)
            _cell.issue = model.catalogItem(at: indexPath.row)
            _cell.delegate = self

            cell = _cell

        case sections.downloaded:
            let _cell = self.issueCell(tableView, indexPath: indexPath)
            _cell.issue = model.downloadedItem(at: indexPath.row)

            cell = _cell

        case sections.articles:
            cell = tableView.dequeueReusableCell(
                withIdentifier: .sdkTest.cells.article,
                for: indexPath
            )
            
            var content = cell.defaultContentConfiguration()
            content.text = "id: \(model.articles[indexPath.row])"
            cell.contentConfiguration = content

        default:
            cell = self.actionCell(tableView, indexPath: indexPath)
        }
        
        return cell
    }
    
    // MARK: - UITableViewDelegate

    override func tableView(_ tableView: UITableView, shouldHighlightRowAt indexPath: IndexPath) -> Bool {
        let sections = self.sections
        switch indexPath.section {
        case sections.auth:
            return indexPath.row > 0 && self.model.canAuthorise
        case sections.log, sections.dismiss, sections.service, sections.fullUI, sections.articles:
            return true
        default:
            return false
        }
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let model = self.model
        let sections = self.sections

        switch indexPath.section {
        case sections.auth:
            guard let cell = tableView.cellForRow(at: IndexPath(row: indexPath.row - 1, section: indexPath.section)) as? TextFieldCell
            else {
                return
            }
            
            let textField = cell.textField
            let token = textField.text
            model.authToken = token
            
            if token?.count ?? 0 > 0 {
                textField.isEnabled = false
                
                model.authorisePressreader()
            }
            
        case sections.log:
            model.getLogs()
            
        case sections.articles:
            Task { await self.openArticle(at: indexPath) }
            
        case sections.dismiss:
            model.isDismissed.toggle()
            
        case sections.service:
            self.selectService()
        
        case sections.fullUI:
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
        let sections = self.sections

        switch section {
        case sections.auth:
            return "Authorization"
        case sections.log:
            return "Logs"
        case sections.catalog:
            return "Catalog"
        case sections.downloaded:
            return "Downloaded"
        case sections.articles:
            return "Articles"
        default:
            return nil
        }
    }
    
    override func tableView(
        _ tableView: UITableView,
        titleForFooterInSection section: Int
    ) -> String? {
        let sections = self.sections
        let model = self.model

        switch section {
        case sections.auth:
            return model.account.flatMap {
                $0.state == .authorized
                ? "Authorised till \(DateFormatter.localizedString(from: $0.expirationDate ?? .distantFuture, dateStyle: .short, timeStyle: .short))"
                : nil
            }
        case sections.catalog:
            return model.catalogItemsCount > 0 ? nil : "Loading..."

        case sections.downloaded:
            return "Downloaded (ordered) items will appear here"

        default:
            return nil
        }
    }
    
    override func tableView(
        _ tableView: UITableView,
        editingStyleForRowAt indexPath: IndexPath
    ) -> UITableViewCell.EditingStyle {
        let sections = self.sections
        
        switch indexPath.section {
        case sections.downloaded:
            return .delete
        case sections.catalog:
            return self.model.catalogItem(at: indexPath.row)?.download?.state ==  .ready
                ? .delete
                : .none
        default:
            return .none
        }
    }
    
    override func tableView(_ tableView: UITableView,
                            commit editingStyle: UITableViewCell.EditingStyle,
                            forRowAt indexPath: IndexPath)
    {
        let sections = self.sections
        if indexPath.section == sections.downloaded {
            self.isReloadingDisabled = true

            self.model.deleteDownloadedItem(at: indexPath.row)
            tableView.deleteRows(at: [indexPath], with: .automatic)
            
            self.isReloadingDisabled = false
        }
        else if indexPath.section == sections.catalog {
            self.model.catalogItem(at: indexPath.row).map {
                self.model.delete($0)
                (self.tableView.cellForRow(at: indexPath) as? IssueCell).map {
                    $0.update()
                }
            }
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
