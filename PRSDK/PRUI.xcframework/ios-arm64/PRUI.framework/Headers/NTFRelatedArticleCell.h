//
//  NTFRelatedArticleCell.h
//  PRUI
//
//  Created by berec on 11/10/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@class NTFArticleItem, FeedItemAction;

NS_ASSUME_NONNULL_BEGIN

/// Abstract class
@interface NTFRelatedArticleCell : UICollectionViewCell

@property (class, nonatomic, readonly) CGFloat anchorHeight;

@property (nonatomic, strong, readonly) UIStackView *placeholder;

@end

@interface NTFRelatedArticleCell (/*Protected*/)
- (void)setupSubviews;
@end

NS_ASSUME_NONNULL_END
