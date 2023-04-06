//
//  PRCommentPostView.h
//  PR-UI
//
//  Created by berec on 03/11/2017.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PRAccountItem;

@protocol PRCommentPostViewDelegate <NSObject>
- (void)presentCommentPostVC;
@end

NS_ASSUME_NONNULL_BEGIN

@interface PRCommentPostView : UIView
- (instancetype)initWithAccount:(PRAccountItem *)account delegate:(id<PRCommentPostViewDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END

