//
//  IssueListVC.swift
//  PRSDKTest
//
//  Created by Ivan Berezin on 23/06/2026.
//  Copyright © 2026 PressReader. All rights reserved.
//

import UIKit
import PRUI

final class IssueListVC: ContentListVC, IssueHandler {

    // MARK: - Private Properties

    private let section: PublicationSection

    // MARK: - Init

    init(section: PublicationSection) {
        self.section = section
        
        super.init(section: section)
    }

    // MARK: - Protected Methods

    override func registerCells() {
        self.tableView.register(IssueCell.self, forCellReuseIdentifier: .sdkTest.cells.issue)
    }

    // MARK: - UITableViewDataSource
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(
            withIdentifier: .sdkTest.cells.issue, for: indexPath
        ) as! IssueCell
        
        cell.delegate = self
        let item = self.section.item(at: indexPath.row)
        cell.issue = item
        
        return cell
    }
    
    // MARK: - UITableViewDelegate

    override func tableView(
        _ tableView: UITableView,
        editingStyleForRowAt indexPath: IndexPath
    ) -> UITableViewCell.EditingStyle {
        self.section.item(at: indexPath.row)?.download?.state == .ready
        ? .delete
        : .none
    }

    override func tableView(_ tableView: UITableView,
                            commit editingStyle: UITableViewCell.EditingStyle,
                            forRowAt indexPath: IndexPath)
    {
        guard editingStyle == .delete else { return }

        let section = self.section
        let itemsCount = section.itemsCount
        
        section.deleteItem(at: indexPath.row)
        
        if itemsCount > section.itemsCount {
            tableView.deleteRows(at: [indexPath], with: .automatic)
        }
        else {
            (tableView.cellForRow(at: indexPath) as? IssueCell)?.update()
        }
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
    }
    
    // MARK: - IssueHandler

    func openIssue(_ issue: PRCatalogItem) {
        Task {
            do {
                try await self.section.discloseItem(issue, sender: self)
            }
            catch {
                UIAlertController.showErrorAlert(message: error.localizedDescription)
            }
        }
    }
}
