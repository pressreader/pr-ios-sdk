//
//  PRCommandOpenHomeFeed.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 8/18/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "PROnlineCommand.h"

NS_ASSUME_NONNULL_BEGIN

@class PRVerticalFeedVC;

@interface PRCommandOpenHomeFeed : PROnlineCommand

- (__kindof PRVerticalFeedVC *)homeFeedVC;

@end

NS_ASSUME_NONNULL_END
