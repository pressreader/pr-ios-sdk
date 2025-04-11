//
//  PRCommentComposeVC.h
//  PRiphone
//
//  Created by Keith Choi on 2016-11-17.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

@import PRAPI.NTFArticle;

NS_ASSUME_NONNULL_BEGIN

@class PRSmartArtifact;

@interface PRCommentComposeVC : UIViewController

- (instancetype)initWithArticle:(id<NTFArticle>)article;
- (instancetype)initWithArticle:(id<NTFArticle>)article param:(nullable NSDictionary *)param;

@property (nonatomic, readonly) PRSmartCommentPost *post;
@property (nonatomic, readonly) NSAttributedString *commentText;
@property (nonatomic, readonly) NSInteger commentIndex;
@property (nonatomic, readonly) NSInteger parentPostId;

@end

NS_ASSUME_NONNULL_END
