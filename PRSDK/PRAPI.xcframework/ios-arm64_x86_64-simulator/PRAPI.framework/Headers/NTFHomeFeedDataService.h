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

@interface NTFHomeFeedDataService : NTFDataService
+ (PRPromise *)submitToken:(NSString *)token;
+ (PRPromise *)requestLastToken;

@end

NS_ASSUME_NONNULL_END
