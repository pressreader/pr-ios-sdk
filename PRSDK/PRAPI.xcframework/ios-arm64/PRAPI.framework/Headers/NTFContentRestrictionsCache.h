//
//  NTFContentRestrictionsCache.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 5/29/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NTFContentRestrictions;

@interface NTFContentRestrictionsCache : NSObject

+ (instancetype)sharedCache;

- (NTFContentRestrictions *)contentRestrictionsForIssueId:(NSString *)issueId;
- (void)addContentRestrictions:(NTFContentRestrictions *)restrictions forIssueId:(NSString *)issueId;

@end
