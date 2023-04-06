//
//  PRProductCell.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 6/14/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@class PRProduct;

@protocol PRProductHolder <NSObject>
@property (nullable, nonatomic, strong) NSArray<PRProduct *> *products;

@end

@interface PRProductCell : UITableViewCell <PRProductHolder>
@property (nonatomic, strong) NSArray<PRProduct *> *products;

@end

NS_ASSUME_NONNULL_END
