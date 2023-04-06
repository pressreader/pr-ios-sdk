//
//  NTFAbstractArticle.h
//  PR-API
//
//  Created by berec on 24/08/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol NTFArticle;
@class PRTitleItem;
@class PRTitleItemExemplar;
@class PRAccountItem;
@class PRSmartVideoPreviewRegion;

@interface NTFAbstractArticle : NSObject

- (instancetype)initWithArticle:(id<NTFArticle>)article;

@property (nonatomic, unsafe_unretained) id<NTFArticle> article;

@property (nullable, nonatomic, readonly) PRAccountItem *preferredAccount;

@property (nullable, nonatomic, readonly) PRTitleItem *titleItem;
@property (nullable, nonatomic, readonly) PRTitleItemExemplar *issue;
@property (nonatomic, readonly) BOOL hasBookmarks;
@property (nonatomic, readonly) BOOL rightToLeft;
@property (nonatomic, readonly) NSInteger pageIndex;
@property (nonatomic, readonly) BOOL isVotable;
@property (nonatomic, readonly) BOOL isTranslated;
@property (nullable, nonatomic, readonly) NSString *shortContent;
@property (nonatomic) BOOL ignoreAutoTranslation;
@property (nonatomic) NSTimeInterval listenDuration;

- (void)updateShortContentWithData:(nullable NSDictionary *)data language:(nullable NSString *)language NS_SWIFT_NAME(updateShortContent(data:language:));
- (void)resetToOriginalLanguage;

@end

NS_ASSUME_NONNULL_END

#import "NTFAbstractArticle+Images.h"
