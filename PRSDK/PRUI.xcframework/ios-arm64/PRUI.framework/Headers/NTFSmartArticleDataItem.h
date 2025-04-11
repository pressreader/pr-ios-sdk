//
//  NTFSmartArticleDataItem.h
//  PR-API
//
//  Created by berec on 30/05/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

@import PRAPI;

@class NTFMyLibraryItemDataSource;

NS_ASSUME_NONNULL_BEGIN

@interface NTFSmartArticleDataItem : NTFSmartDataItem <NTFArticle>

- (instancetype)initWithSmartArticle:(PRSmartArticle *)article
                         isoLanguage:(NSString *)language
                          issueTitle:(NSString *)issueTitle
                           issueDate:(NSString *)issueDate
                                 mli:(PRMyLibraryItem *)mli NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithType:(NTFDataItemType)type NS_UNAVAILABLE;

@property (nonatomic, strong) PRSmartArticle *smartArticle;
@property (nonatomic, unsafe_unretained, readonly) PRMyLibraryItem *mli;
@property (nullable, nonatomic, strong) NSArray<PRSmartImageRegion *> *imageRegions;
@property (nullable, nonatomic, readonly) NSString *issueId;
@property (nullable, nonatomic, readonly) NSString *byline;
@property (nullable, nonatomic, readonly) NSString *subtitle;
@property (nullable, nonatomic, readonly) NSString *annotation;

@property (nullable, nonatomic, readonly) NSString *bylineForDisplay;
@property (nullable, nonatomic, readonly) NSString *bylineForDisplayWithLineBreak;

/// DEPRECATED (in new code rely on item's interface)
@property (nullable, nonatomic, readonly) NTFMyLibraryItemDataSource *dataSource;

@property (nonatomic) NTFArticleItemPresentationType presentationType;

@end

NS_ASSUME_NONNULL_END
