//
//  PRCommentTableVC.h
//  PRiphone
//
//  Created by Keith Choi on 2016-11-08.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

@import PRAPI.NTFArticle;
@protocol FlowArticle;
@class PRMenuItem;

NS_ASSUME_NONNULL_BEGIN

@interface PRCommentTableVC : UITableViewController

+ (void)presentForArticle:(id<FlowArticle>)article
                presenter:(UIViewController *)presenter
                   sender:(id)sender;

+ (void)presentForArticle:(id<FlowArticle>)article
           menuController:(id)menuVC
                 menuItem:(PRMenuItem *)menuItem
                presenter:(nullable UIViewController *)presenter
                   sender:(id)sender;

- (instancetype)initWithArticle:(id<FlowArticle>)article;

- (void)refreshComments:(NSNotification *)notifInfo;
- (void)resizePopover;

@property (nonatomic, strong) PRSmartCommentPost *commentPostForFocus;

@property (nonatomic, readonly) id<FlowArticle> articleItem;

@end

NS_ASSUME_NONNULL_END
