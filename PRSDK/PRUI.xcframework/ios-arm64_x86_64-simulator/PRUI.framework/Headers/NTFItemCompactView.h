//
//  NTFItemCompactView.h
//  PRUI
//
//  Created by Vitalii Hudenko on 11.08.2021.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

@import PRAPI;

NS_ASSUME_NONNULL_BEGIN

@protocol NTFItemCompactView <NSObject>

@property (nullable, nonatomic, strong, readonly) NTFArticleCompactTextualView *textualView;
@property (nullable, nonatomic, strong, readonly) id<NTFItem> feedItem;
@property (nullable, nonatomic, strong, readonly) FeedItemAction *action;

@end

NS_ASSUME_NONNULL_END
