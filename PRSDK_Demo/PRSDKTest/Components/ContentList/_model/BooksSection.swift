//
//  BooksSection.swift
//  PRSDKTest
//
//  Created by Ivan Berezin on 24/06/2026.
//  Copyright © 2026 PressReader. All rights reserved.
//

import UIKit
import PRUI

final class BooksSection: ContentSection {

    // MARK: - Private Properties

    private let model: RootModel

    // MARK: - Init

    init(model: RootModel) {
        self.model = model
    }
    
    // MARK: - Private Methods
    
    private func item(at index: Int) -> String {
        self.model.books[index].string("id")!
    }

    // MARK: - ContentSection

    var title: String { "Books" }

    var itemsCount: Int {
        self.model.books.count
    }

    func title(for indexPath: IndexPath) -> String {
        "book id: \(self.item(at: indexPath.row))"
    }

    func discloseItem(at index: Int, sender: Any) async throws {
        let vc = try await PressReader.instance().bookReader(bookId: self.item(at: index))
        (sender as? UIViewController)?.navigationController?.pushViewController(vc, animated: true)
    }
}
