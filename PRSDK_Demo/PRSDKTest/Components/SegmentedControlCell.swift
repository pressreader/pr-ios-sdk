//
//  SegmentedControlCell.swift
//  PRSDKTest
//
//  Created by Vitalii Hudenko on 17.11.2025.
//  Copyright © 2025 NewspaperDirect. All rights reserved.
//

import UIKit
import PRUIKit

public final class SegmentedControlCell: UITableViewCell {
    
    // MARK: - Public Properties
    
    public var selectedItemIndex: Int {
        get {
            self.segmentControl.selectedSegmentIndex
        }
        set {
            self.segmentControl.selectedSegmentIndex = newValue
        }
    }
    
    public var items: [UIAction] = [] {
        didSet {
            let control = self.segmentControl
            control.removeAllSegments()
            self.items.enumerated().forEach {
                control.insertSegment(action: $0.element, at: $0.offset, animated: false)
            }
        }
    }
    
    // MARK: - Private Properties
    
    private let segmentControl = UISegmentedControl()
    
    // MARK: - Init
    
    public override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
        
        self.segmentControl.include(into: self.contentView,
                                    insets: UIEdgeInsets(top: 8, left: 20, bottom: 8, right: 20))
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
