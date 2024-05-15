//
//  TextFieldCell.swift
//  PRSDKTest
//
//  Created by berec on 12/11/2020.
//  Copyright © 2020 PressReader. All rights reserved.
//

import UIKit

final class TextFieldCell: UITableViewCell {

    let textField = UITextField()
    
    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
        
        let insets = UIEdgeInsets(top: 0, left: 20, bottom: 0, right: 20)
        self.textField.include(into: self.contentView, insets: insets)
        self.textField.heightAnchor.activeConstraint(greaterThanOrEqualToConstant: 44)
    }
    
    @available(*, unavailable)
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
