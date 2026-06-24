//
//  PublicationSection.swift
//  PRSDKTest
//
//  Created by Ivan Berezin on 24/06/2026.
//  Copyright © 2026 PressReader. All rights reserved.
//

import UIKit
import PRUI

class PublicationSection: ContentSection {

    // MARK: - Private Properties

    let model: RootModel

    // MARK: - Init

    init(model: RootModel) {
        self.model = model
    }

    // MARK: - Public Methods

    func deleteItem(at index: Int) {
        self.item(at: index).map {
            self.model.delete($0)
        }
    }

    func item(at index: Int) -> TitleItem? {
        self.model.catalogItem(at: index)
    }

    func discloseItem(_ item: PRCatalogItem, sender: Any) async throws {
        guard let presenter = (sender as? UIViewController) ?? UIApplication.shared.rootVC,
              let reader = ReadingVC(item)
        else {
            throw ServiceError.unavailable
        }
        
        presenter.present(reader, animated: true, completion: nil)
    }

    // MARK: - ContentSection

    var title: String { "Publications" }

    var itemsCount: Int {
        self.model.catalogItemsCount
    }

    var isLoadable: Bool { true }

    func title(for indexPath: IndexPath) -> String { "" }

    func contentController() -> UIViewController {
        IssueListVC(section: self)
    }

    func discloseItem(at index: Int, sender: Any) async throws {
        guard let item = self.item(at: index) else {
            throw ServiceError.unavailable
        }
        
        try await self.discloseItem(item, sender: sender)
    }
}
