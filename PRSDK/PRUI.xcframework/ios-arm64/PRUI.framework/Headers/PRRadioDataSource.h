//
//  PRRadioDataSource.h
//  PRUI
//
//  Created by Ivan Berezin on 16/11/2022.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

#ifndef PRRadioDataSource_h
#define PRRadioDataSource_h

@import Foundation;
#import "NTFFeedDataSource.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PRRadioDataSource <NSObject>

- (nullable id<NTFArticle>)articleForIndex:(NSInteger)index;
- (NSInteger)indexForArticle:(id<NTFArticle>)item;

- (nullable id<NTFArticle>)getCurrentArticleWithLoadingHandler:(void(^_Nullable)(id<NTFArticle>))completion;
- (void)getCurrentArticleWithCompletion:(void(^_Nullable)(id<NTFArticle> _Nullable))completion;
- (nullable id<NTFArticle>)articleWithId:(NSString *)itemId;

- (void)loadMoreToTheEnd:(void(^_Nullable)(void))completionBlock;
- (void)loadMoreAtTheBeginning:(void(^_Nullable)(void))completionBlock;

@property (nullable, nonatomic) id<NTFArticle> currentArticle;
@property (nonatomic, readonly) BOOL hasMoreItemsAtTheBeginning;
@property (nonatomic, readonly) BOOL hasMoreItemsAtTheEnd;
@property (nonatomic, readonly) BOOL isReady;
@property (nonatomic, readonly) NSInteger itemsCount;
@property (nonatomic, readonly) NTFDataState dataState;

@end

NS_ASSUME_NONNULL_END

#endif /* PRRadioDataSource_h */
