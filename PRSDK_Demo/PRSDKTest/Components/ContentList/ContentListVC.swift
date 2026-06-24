//
//  ContentListVC.swift
//  PRSDKTest
//
//  Created by Ivan Berezin on 23/06/2026.
//  Copyright © 2026 PressReader. All rights reserved.
//

import UIKit
import PRUI

class ContentListVC: UITableViewController {

    // MARK: - Private Properties

    private let section: any ContentSection

    // MARK: - Init

    init(section: any ContentSection) {
        self.section = section
        super.init(style: .grouped)
    }

    @available(*, unavailable)
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    // MARK: - Life Cycle

    override func viewDidLoad() {
        super.viewDidLoad()

        self.title = self.section.title
        self.registerCells()
    }
    
    // MARK: - Protected Methods
    
    func registerCells() {
        self.tableView.register(UITableViewCell.self, forCellReuseIdentifier: .sdkTest.cells.issue)
    }
    
    // MARK: - UITableViewDataSource

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        self.section.itemsCount
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: .sdkTest.cells.issue, for: indexPath)

        var content = cell.defaultContentConfiguration()
        content.text = self.section.title(for: indexPath)
        cell.contentConfiguration = content

        return cell
    }

    // MARK: - UITableViewDelegate

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        
        Task {
            let activityIndicator = UIActivityIndicatorView(style: .medium)
            activityIndicator.startAnimating()
            tableView.cellForRow(at: indexPath)?.accessoryView = activityIndicator

            defer {
                activityIndicator.stopAnimating()
            }

            do {
                try await self.section.discloseItem(at: indexPath.row, sender: self)
            }
            catch {
                UIAlertController.showErrorAlert(message: error.localizedDescription)
            }
        }
    }
}
