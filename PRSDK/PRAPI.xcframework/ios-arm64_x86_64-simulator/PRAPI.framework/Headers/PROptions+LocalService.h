//
//  PROptions+LocalService.h
//  PRAPI
//
//  Created by Ivan Berezin on 02/05/2025.
//  Copyright © 2025 NewspaperDirect. All rights reserved.
//

#import <PRAPI/PROptions.h>

NS_ASSUME_NONNULL_BEGIN

@interface PROptions (LocalService)

- (void)disableLocalService;
- (void)enableLocalServiceModeWithServiceName:(NSString *)serviceName;

@property (nullable, nonatomic) NSString *localServiceName;
@property (nullable, nonatomic) NSString *localServiceURL;

@end

NS_ASSUME_NONNULL_END
