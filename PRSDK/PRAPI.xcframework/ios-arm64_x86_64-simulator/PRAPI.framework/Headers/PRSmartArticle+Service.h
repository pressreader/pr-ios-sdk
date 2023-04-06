//
//  PRSmartArticle+Service.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 5/24/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <PRSmart/PRSmart.h>

@class PRSubscription;

NS_ASSUME_NONNULL_BEGIN

typedef void(^CollectionsResponse)(NSUInteger userCollectionsCount,
                                   NSUInteger sharingCollectionsCount,
                                   NSArray<NSString *> *_Nullable collectionIds,
                                   NSError *_Nullable error);

@interface PRSmartArticle (Services)

- (void)updateCurrentVote:(NSInteger)value subscription:(PRSubscription *)subscription;

- (void)sendVote:(NSInteger)vote
withSubscription:(PRSubscription *)subscription
      completion:(void(^ _Nullable)(NSError *error))completionBlock;

- (void)requestVoteWithSubscription:(PRSubscription *)subscription
                         completion:(void(^)(NSError *error))completionBlock;

- (void)updateDataWithLanguage:(nullable NSString *)language
                  subscription:(PRSubscription *)subscription
                     completed:(void(^)(BOOL updated, NSError *error))completionBlock;

- (void)requestCollectionsForSubscription:(PRSubscription *)subscription
                               completion:(CollectionsResponse)completionBlock;

@end

NS_ASSUME_NONNULL_END
