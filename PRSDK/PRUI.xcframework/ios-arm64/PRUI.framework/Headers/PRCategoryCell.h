//
//  PRCategoryCell.h
//  PRUI
//
//  Created by Viacheslav Soroka on 2/22/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PRCountableDictionary;

NS_ASSUME_NONNULL_BEGIN

@interface PRCategoryCell : UICollectionViewCell
@property (nullable, nonatomic, strong) PRCountableDictionary *category;

@end

NS_ASSUME_NONNULL_END
