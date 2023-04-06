//
//  PRSmartArticle+Bookmarks.h
//  PR-API
//
//  Created by Viacheslav Soroka on 4/4/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <PRSmart/PRSmart.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRSmartArticle (Bookmarks)

- (void)changeBookmarkedStatusAfterDelay:(NSTimeInterval)delay
                              completion:(void(^_Nullable)(NSError *_Nullable error))completion;
- (void)changeBookmarkedStatus;

@end

NS_ASSUME_NONNULL_END
