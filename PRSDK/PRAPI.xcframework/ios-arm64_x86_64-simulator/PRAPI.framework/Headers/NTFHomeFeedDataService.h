//
//  NTFHomeFeedDataService.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 8/18/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "NTFDataService.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString * const kPRHomeFeedBaseURL;
extern NSString * const kPRDefaultToken;

@class NewsFeedConfig;

@interface NTFHomeFeedDataService : NTFDataService
+ (PRPromise *)submitToken:(NSString *)token;
+ (PRPromise *)requestLastToken;

@property (nonatomic, readonly) NewsFeedConfig *newsFeedConfig;

@end

NS_ASSUME_NONNULL_END
