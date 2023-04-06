//
//  PRArticleContainerVC.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 10/5/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@import PRAPI.NTFArticle;
#import "PRFlowArticle.h"

#import "PRArticleContainer.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, PRArticleContainerOption) {
    PRArticleContainerOptionDisableDataSourceNavigation = 1 << 0
};

@interface PRArticleContainerVC : UIPageViewController <PRArticleContainer>

- (instancetype)initWithArticle:(id<PRFlowArticle>)article
                         parent:(NTFArticleItem *_Nullable)parent;

- (instancetype)initWithArticle:(id<PRFlowArticle>)article
                         parent:(NTFArticleItem *_Nullable)parent
                        options:(PRArticleContainerOption)options NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) id<PRFlowArticle> article;
@property (nullable, nonatomic, strong) NSArray<NSString *> *textToHighlight;
@property (nonatomic, readonly) PRArticleContainerOption options;

@end


@interface PRArticleContainerVC (/*Restrictions*/)

- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil
                         bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

- (instancetype)initWithTransitionStyle:(UIPageViewControllerTransitionStyle)style
                  navigationOrientation:(UIPageViewControllerNavigationOrientation)navigationOrientation
                                options:(nullable NSDictionary<UIPageViewControllerOptionsKey, id> *)options NS_UNAVAILABLE;
@end


@class VerticalTextFlowArticleDetailsVC;

@interface PRArticleContainerVC (/*Protected*/)

- (void)updateEmbeddedAdsInController:(VerticalTextFlowArticleDetailsVC *)vc;

@property (nonatomic, readonly) BOOL isRightToLeft;
@property (nullable, nonatomic, readonly) VerticalTextFlowArticleDetailsVC *visibleVC;

@end

NS_ASSUME_NONNULL_END
