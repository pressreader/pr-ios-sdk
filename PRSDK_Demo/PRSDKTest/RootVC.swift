//
//  RootVC.swift
//  PRSDKTest
//
//  Created by berec on 21/01/2020.
//  Copyright © 2020 PressReader. All rights reserved.
//

import UIKit
import PRUI

final class RootVC: UITableViewController, Reloadable {
    
    // MARK: - Private Properties

    private lazy var model = {
        RootModel(delegate: self)
    }()
    
    private var isReloadingDisabled = false
    
    private var serviceSection: Int?
    private var authSection: Int?
    private var logSection: Int?
    private var catalogSection: Int?
    private var downloadedSection: Int?

    private var authoriseCellTitle: String {
        let account = self.model.account
        switch account.state {
        case .sponsorship:
            return "Authorised till \(DateFormatter.localizedString(from: account.sponsorshipExpiration ?? .distantFuture, dateStyle: .short, timeStyle: .short))"
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
    }
    
    // MARK: - Private Methods
    
    private func actionCell(_ tableView: UITableView,
                            indexPath: IndexPath,
                            title: String? = nil,
                            enabled: Bool = true) -> UITableViewCell
    {
        let cell = tableView.dequeueReusableCell(withIdentifier: "actionCell", for: indexPath)
        cell.textLabel.map {
            $0.isEnabled = enabled
            $0.textColor = .label
            $0.text = title
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
        var section = 0
        self.serviceSection = section; section += 1
        
        if self.model.isAuthEnabled {
            self.authSection = section; section += 1
        }

        self.logSection = section; section += 1

        if self.model.isCatalogEnabled {
            self.catalogSection = section; section += 1
            self.downloadedSection = section; section += 1
        }

        return section
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        switch section {
        case self.authSection:
            return 2
        case self.catalogSection:
            return self.model.catalogItemsCount
        case self.downloadedSection:
            return self.model.downloadedItemsCount
        default:
            return 1
        }
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        var cell: UITableViewCell
        
        let model = self.model
        
        switch indexPath.section {
        case self.authSection:
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
            
        case self.serviceSection:
            cell = self.actionCell(tableView,
                                   indexPath: indexPath,
                                   title: model.serviceName,
                                   enabled: model.canPresentFullUI)

        case self.logSection:
            cell = self.actionCell(tableView,
                                   indexPath: indexPath,
                                   title: "Upload Logs and Get the link")

        case self.catalogSection:
            let _cell = self.issueCell(tableView, indexPath: indexPath)
            _cell.issue = model.catalogItem(at: indexPath.row)

            cell = _cell

        case self.downloadedSection:
            let _cell = self.issueCell(tableView, indexPath: indexPath)
            _cell.issue = model.downloadedItem(at: indexPath.row)

            cell = _cell

        default:
            cell = self.actionCell(tableView, indexPath: indexPath)
        }
        
        return cell
    }
    
    // MARK: - UITableViewDelegate

    override func tableView(_ tableView: UITableView, shouldHighlightRowAt indexPath: IndexPath) -> Bool {
        switch indexPath.section {
        case self.authSection:
            return indexPath.row > 0 && self.model.canAuthorise
        case self.logSection:
            return true
        case self.serviceSection:
            return self.model.canPresentFullUI
        default:
            return false
        }
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        switch indexPath.section {
        case self.authSection:
            guard let cell = tableView.cellForRow(at: IndexPath(row: indexPath.row - 1, section: indexPath.section)) as? TextFieldCell
            else {
                return
            }
            
            let textField = cell.textField
            let token = textField.text
            self.model.authToken = token

            if token?.count ?? 0 > 0 {
                textField.isEnabled = false

                self.model.authorisePressreader()
            }

        case self.logSection:
            self.model.getLogs()
            
        case self.serviceSection:
            self.present(PressReader.instance().rootViewController, animated: true, completion: nil)

        default:
            break
        }
        
        tableView.deselectRow(at: indexPath, animated: true)
    }
    
    override func tableView(_ tableView: UITableView,
                            titleForHeaderInSection section: Int) -> String?
    {
        switch section {
        case self.authSection:
            return "Authorisation"
        case self.serviceSection:
            return "Service"
        case self.logSection:
            return "Logs"
        case self.catalogSection:
            return "Catalog"
        case self.downloadedSection:
            return "Downloaded"
        default:
            return nil
        }
    }
    
    override func tableView(_ tableView: UITableView,
                            titleForFooterInSection section: Int) -> String?
    {
        switch section {
        case self.catalogSection:
            return self.model.catalogItemsCount > 0 ? nil : "Loading..."
        case self.downloadedSection:
            return "Downloaded (ordered) items will appear here"
        default:
            return nil
        }
    }
    
    override func tableView(_ tableView: UITableView,
                            editingStyleForRowAt indexPath: IndexPath) -> UITableViewCell.EditingStyle
    {
        switch indexPath.section {
        case self.downloadedSection:
            return .delete
        case self.catalogSection:
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
        if indexPath.section == self.downloadedSection {
            self.isReloadingDisabled = true

            self.model.deleteDownloadedItem(at: indexPath.row)
            tableView.deleteRows(at: [indexPath], with: .automatic)
            
            self.isReloadingDisabled = false
        }
        else if indexPath.section == self.catalogSection {
            self.model.catalogItem(at: indexPath.row).map {
                self.model.delete($0)
                (self.tableView.cellForRow(at: indexPath) as? IssueCell).map {
                    $0.update()
                }
            }
        }
    }
}
