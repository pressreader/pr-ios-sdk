//
//  ContentSection.swift
//  PRSDKTest
//
//  Created by Ivan Berezin on 23/06/2026.
//  Copyright © 2026 PressReader. All rights reserved.
//

import UIKit

@MainActor
protocol ContentSection {
    var title: String { get }
    var isLoadable: Bool { get }
    var itemsCount: Int { get }

    func title(for indexPath: IndexPath) -> String
    func contentController()  -> UIViewController
    func discloseItem(at index: Int, sender: Any) async throws
}

extension ContentSection {
    var isLoadable: Bool { false }
    
    func contentController() -> UIViewController {
        ContentListVC(section: self)
    }
}
