//
//  GamesSection.swift
//  PRSDKTest
//
//  Created by Ivan Berezin on 24/06/2026.
//  Copyright © 2026 PressReader. All rights reserved.
//

import UIKit
import PRUI

final class GamesSection: ContentSection {

    // MARK: - Private Properties

    private let model: RootModel

    // MARK: - Init

    init(model: RootModel) {
        self.model = model
    }

    // MARK: - Private Methods

    private func item(at index: Int) -> [String: Sendable] {
        self.model.games[index]
    }

    // MARK: - ContentSection

    var title: String { "Games" }

    var itemsCount: Int {
        self.model.games.count
    }

    func title(for indexPath: IndexPath) -> String {
        "issue id: \(self.item(at: indexPath.row).string("id")!)"
    }

    func discloseItem(at index: Int, sender: Any) async throws {
        let issue = self.item(at: index)
        
        let vc = try await PressReader.instance().gamePlay(
            issueId: issue.string("id")!,
            title: issue.string("displayName"),
            date: issue.string("issueDate")?.serverDate
        )
        
        (sender as? UIViewController)?.navigationController?.pushViewController(vc, animated: true)
    }
}
