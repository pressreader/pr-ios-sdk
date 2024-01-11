//
//  PROptions+URLs.h
//  PRAPI
//
//  Created by berec on 30/01/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PROptions.h"

NS_ASSUME_NONNULL_BEGIN

@interface PROptions (URLs)

- (NSArray<NSString *> *)urlsForBaseService:(NSString *)serviceName;

@property (nonatomic, readonly) NSString *onlineUrl;
@property (nonatomic, readonly) NSString *onlineHostUrl;
@property (nonatomic, readonly) NSString *registerUrl;
@property (nonatomic, readonly) NSString *instructionsUrl;
@property (nonatomic, readonly) NSString *onlineServiceUrl;
@property (nonatomic, readonly) NSString *publicationCatalogServiceURL;
@property (nullable, nonatomic, readonly) NSString *bookServiceURL;
@property (nullable, nonatomic, readonly) NSString *bookCatalogServiceURL;
@property (nullable, nonatomic, readonly) NSString *bookReadingCollectorServiceUrl;
@property (nullable, nonatomic, readonly) NSString *bookAccessServiceURL;
@property (nullable, nonatomic, readonly) NSString *bookUserServiceURL;
@property (nullable, nonatomic, readonly) NSURL *defaultServiceUrl;

@end

NS_ASSUME_NONNULL_END
