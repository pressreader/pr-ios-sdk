//
//  ArticlesSection.swift
//  PRSDKTest
//
//  Created by Ivan Berezin on 24/06/2026.
//  Copyright © 2026 PressReader. All rights reserved.
//

import UIKit
import PRUI

final class ArticlesSection: ContentSection {

    // MARK: - Private Properties

    private let model: RootModel

    // MARK: - Init

    init(model: RootModel) {
        self.model = model
    }
    
    // MARK: - Private Methods
    
    private func item(at index: Int) -> String {
        self.model.articles[index]
    }

    // MARK: - ContentSection

    var title: String { "Articles" }

    var itemsCount: Int {
        self.model.articles.count
    }

    func title(for indexPath: IndexPath) -> String {
        "id: \(self.item(at: indexPath.row))"
    }
    
    func discloseItem(at index: Int, sender: Any) async throws {
        guard await PressReader.instance().openArticle(id: self.item(at: index)) != nil else {
            throw ServiceError.unavailable
        }
    }
}
