//
//  AdDataSource+Service.h
//  PRUI
//
//  Created by berec on 07/07/2021.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

@import PRAds;

NS_ASSUME_NONNULL_BEGIN

@interface AdDataSource (Service)

- (nullable id)initWithScreen:(AdBannerScreen)screen delegate:(id<AdDataSourceDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
