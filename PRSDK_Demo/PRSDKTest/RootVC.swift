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

final class RootVC: UITableViewController, Reloadable, IssueHandler {

    // MARK: - Nested Types
    
    private class Sections {
        var service: Int?
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
            return "Authorise"
        }
    }
    
    // MARK: - Life Cycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.title = self.model.serviceName
        
        let table: UITableView = self.tableView
        table.register(UITableViewCell.self, forCellReuseIdentifier: "actionCell")
        table.register(TextFieldCell.self, forCellReuseIdentifier: "textFieldCell")
        table.register(IssueCell.self, forCellReuseIdentifier: "issueCell")
        table.register(UITableViewCell.self, forCellReuseIdentifier: .sdkTest.cells.article)
    }
    
    // MARK: - Private Methods
    
    private func actionCell(
        _ tableView: UITableView,
        indexPath: IndexPath,
        title: String? = nil,
        enabled: Bool = true,
        accessibilityId: String? = nil
    ) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "actionCell", for: indexPath)
        cell.textLabel.map {
            $0.isEnabled = enabled
            $0.textColor = .label
            $0.text = title
        }

        accessibilityId.map {
            cell.accessibilityIdentifier = $0
        }

        return cell
    }

    private func textFieldCell(_ tableView: UITableView, indexPath: IndexPath) -> TextFieldCell {
        tableView.dequeueReusableCell(withIdentifier: "textFieldCell", for: indexPath) as! TextFieldCell
    }

    private func issueCell(_ tableView: UITableView, indexPath: IndexPath) -> IssueCell {
        tableView.dequeueReusableCell(withIdentifier: "issueCell", for: indexPath) as! IssueCell
    }

    private func updateTokenCell(_ cell: TextFieldCell) {
        let textField = cell.textField
        textField.placeholder = "Enter token and tap Authorise"
        textField.clearButtonMode = .whileEditing
        textField.text = self.model.authToken
        
        let isEnabled = self.model.canAuthorise
        textField.isEnabled = isEnabled
        textField.textColor = isEnabled ? .label : .secondaryLabel
    }
    
    // MARK: - Reloadable

    func reloadData() {
        guard !self.isReloadingDisabled else { return }
        
        self.tableView.reloadData()
    }

    // MARK: - UITableViewDataSource
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        let sections = Sections()
        var section = 0
        
        let model = self.model

        if !model.isDismissed {
            sections.service = section; section += 1
        }

        sections.dismiss = section; section += 1

        if model.isAuthEnabled {
            sections.auth = section; section += 1
        }

        if model.isLoggingEnabled {
            sections.log = section; section += 1
        }

        if self.model.isCatalogEnabled {
            sections.catalog = section; section += 1
            sections.downloaded = section; section += 1
        }
        
        if self.model.isArticleSetEnabled {
            sections.articles = section; section += 1
        }

        self.sections = sections
        
        return section
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
            cell = self.actionCell(tableView,
                                   indexPath: indexPath,
                                   title: model.serviceName,
                                   enabled: model.canPresentFullUI)

        case sections.log:
            cell = self.actionCell(tableView,
                                   indexPath: indexPath,
                                   title: "Upload Logs and Get the link")

        case sections.dismiss:
            cell = self.actionCell(
                tableView,
                indexPath: indexPath,
                title: model.isDismissed ? "Restore" : "Dismiss",
                accessibilityId: "dismiss"
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
            cell.accessibilityIdentifier = cell.reuseIdentifier

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
        case sections.log, sections.dismiss:
            return true
        case sections.service:
            return self.model.canPresentFullUI
        case sections.articles:
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
            Task { @MainActor in
                let activityIndicator = UIActivityIndicatorView(style: .medium)
                activityIndicator.startAnimating()

                let cell = tableView.cellForRow(at: indexPath)!
                cell.accessoryView = activityIndicator

                await PressReader.instance().openArticle(
                    id: model.articles[indexPath.row]
                )
                
                activityIndicator.stopAnimating()
            }
            
        case sections.dismiss:
            model.isDismissed.toggle()

        case sections.service:
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
            return "Authorisation"
        case sections.service:
            return "Service"
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
                $0.state == .sponsorship
                ? "Authorised till \(DateFormatter.localizedString(from: $0.sponsorshipExpiration ?? .distantFuture, dateStyle: .short, timeStyle: .short))"
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
