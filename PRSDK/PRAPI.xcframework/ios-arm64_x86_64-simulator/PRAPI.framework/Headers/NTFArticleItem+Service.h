//
//  NTFArticleItem+Service.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 5/24/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "NTFArticleItem.h"

@class PRPromise;
@class NTFFeed;

NS_ASSUME_NONNULL_BEGIN

@interface NTFArticleItem (Service)

+ (PRPromise *)getContentRestrictionsForIssueId:(NSString *)issueId;

+ (PRPromise *)requestArticlesJSON:(NSString *)articles
                          viewType:(NSString *)viewType
                        parameters:(NSDictionary *)parameters;

- (PRPromise *)getContentRestrictions;
- (void)loadFullContent:(void(^)(BOOL success, NSError *_Nullable error))completion;
    
@end

NS_ASSUME_NONNULL_END
