//
//  PRSourceItemCellList.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 1/19/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "PRSourceItemCell.h"

@interface PRSourceItemCellList : PRSourceItemCell
@property (nonatomic, strong) IBOutlet UILabel *additionalInfoLabel;
@property (nonatomic, strong) IBOutlet UIView *separatorLine;
@property (strong, nonatomic) IBOutlet NSLayoutConstraint *separatorLineHeightConstraint;
@end
