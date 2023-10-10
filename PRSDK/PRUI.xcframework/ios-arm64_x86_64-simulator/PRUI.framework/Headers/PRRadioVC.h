//
//  PRRadioCtrl.h
//  PRiphone
//
//  Created by Vitali Bounine on 5/2/11.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <PRUI/ReadingMapFrame.h>
#import <PRUI/NTFDataSource.h>

NS_ASSUME_NONNULL_BEGIN

@class PRMyLibraryItem;
@class PRRadioManager;
@protocol PRRadioDataSource;

@interface PRRadioVC : UIViewController <ReadingMapOperations>

+ (void)startWithLibraryItem:(PRMyLibraryItem *)mli
                presentingVC:(UIViewController *)presentingVC
                        page:(NSUInteger)initPage
                  articleUid:(nullable NSString *)initArticle;

+ (void)startWithDataSource:(id<PRRadioDataSource>)dataSource
                    article:(nullable id<NTFArticle>)article
               presentingVC:(UIViewController *)presentingVC;

+ (void)startForTitleItem:(PRTitleItem *)titleItem
             presentingVC:(UIViewController *)presentingVC;

+ (void)startForTitleItem:(PRTitleItem *)titleItem
             subscription:(PRSubscription *)subscription
                issueDate:(NSDate *)date
             presentingVC:(UIViewController *)presentingVC;

- (nullable instancetype)initWithLibraryItem:(PRMyLibraryItem *)libraryItem;
- (nullable instancetype)initWithTitleItem:(PRTitleItem *)titleItem
                              subscription:(PRSubscription *)subscription
                                 issueDate:(NSDate *)date;

@property (nonatomic, readonly) NSUInteger currentPageNumber;
@property (nonatomic, strong, readonly) PRRadioManager *radioManager;
@property (nonatomic, strong, readonly) UIView *bottomBar;

@end

NS_ASSUME_NONNULL_END
