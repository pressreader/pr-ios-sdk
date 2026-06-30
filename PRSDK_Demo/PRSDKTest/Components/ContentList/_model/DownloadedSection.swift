//
//  DownloadedSection.swift
//  PRSDKTest
//
//  Created by Ivan Berezin on 24/06/2026.
//  Copyright © 2026 PressReader. All rights reserved.
//

import UIKit
import PRUI

final class DownloadedSection: PublicationSection {

    override var title: String { "Downloaded" }

    override var itemsCount: Int {
        self.model.downloadedItemsCount
    }

    override var isLoadable: Bool {
        false
    }
    
    override func item(at index: Int) -> TitleItem? {
        self.model.downloadedItem(at: index)
    }
}
