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
                        page:(NSInteger)initPage
                  articleUid:(nullable NSString *)initArticle;

+ (void)startWithDataSource:(id<PRRadioDataSource>)dataSource
                    article:(nullable id<NTFArticle>)article
               presentingVC:(UIViewController *)presentingVC;

+ (void)startWithItem:(PRTitleItemExemplar *)item
         presentingVC:(UIViewController *)presentingVC;

+ (void)startWithItem:(PRTitleItemExemplar *)item
         subscription:(PRSubscription *)subscription
         presentingVC:(UIViewController *)presentingVC;

- (nullable instancetype)initWithLibraryItem:(PRMyLibraryItem *)libraryItem;
- (nullable instancetype)initWithItem:(PRTitleItemExemplar *)item
                         subscription:(PRSubscription *)subscription;

@property (nonatomic, readonly) NSUInteger currentPageNumber;
@property (nonatomic, strong, readonly) PRRadioManager *radioManager;
@property (nonatomic, strong, readonly) UIView *bottomBar;
@property (nonatomic, strong, readonly) UILabel *issueLabel;
@property (nonatomic, strong, readonly) UILabel *sectionLabel;
@property (nullable, nonatomic, strong, readonly) NSString *issueDate;
@property (nullable, nonatomic, strong, readonly) PRMyLibraryItem *libraryItem;
@property (nullable, nonatomic, strong, readonly) UIView *defaultTextTitleView;

@end

NS_ASSUME_NONNULL_END
