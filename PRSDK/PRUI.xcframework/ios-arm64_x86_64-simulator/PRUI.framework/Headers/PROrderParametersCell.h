//
//  PROrderParametersCell.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 3/18/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

@import PRUIKit.PRRoundedTableViewCell;

NS_ASSUME_NONNULL_BEGIN

@interface PROrderParametersCell : PRRoundedTableViewCell
@property (nonatomic) CGFloat lineViewPadding;
@property (nonatomic) BOOL topLineViewHidden;
@property (nonatomic) BOOL bottomLineViewHidden;

@end

NS_ASSUME_NONNULL_END
