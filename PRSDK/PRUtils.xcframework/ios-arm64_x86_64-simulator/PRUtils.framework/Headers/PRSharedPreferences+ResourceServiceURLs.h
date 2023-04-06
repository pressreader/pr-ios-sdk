//
//  PRSharedPreferences+ResourceServiceURLs.h
//  PRSharedData
//
//  Created by berec on 07/12/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "PRSharedPreferences.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRSharedPreferences (ResourceServiceURLs)

- (NSArray<NSString *> *)thumbnailURLsForService:(NSString *)serviceName;
- (void)setThumbnailURLs:(NSArray<NSString *> *)urls forService:(NSString *)serviceName;
- (NSString *)randomThumbnailURLForService:(NSString *)serviceName;

- (NSArray<NSString *> *)mediaURLsForService:(NSString *)serviceName;
- (void)setMediaURLs:(NSArray<NSString *> *)urls forService:(NSString *)serviceName;

- (NSArray<NSString *> *)imageURLsForService:(NSString *)serviceName;
- (void)setImageURLs:(NSArray<NSString *> *)urls forService:(NSString *)serviceName;

@end

NS_ASSUME_NONNULL_END
