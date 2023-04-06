//
//  NTFBaseHomeFeedDataSource.h
//  PR-UI
//
//  Created by berec on 22/02/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "NTFFeedDataSource.h"

NS_ASSUME_NONNULL_BEGIN

@interface NTFBaseHomeFeedDataSource : NTFFeedDataSource

+ (instancetype)homeFeedDataSourceWithOptions:(NTFFeedDataSourceOption)parameters
                                      layoutType:(NTFLayoutType)layoutType
                                   layoutOptions:(NTFLayoutOption)layoutOptions;

@end

NS_ASSUME_NONNULL_END
