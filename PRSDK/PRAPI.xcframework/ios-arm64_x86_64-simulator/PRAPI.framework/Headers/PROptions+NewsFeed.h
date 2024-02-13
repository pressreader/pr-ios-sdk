//
//  PROptions+NewsFeed.h
//  PRAPI
//
//  Created by berec on 06/02/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PROptions.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, PRNewsFeedAPI) {
    PRNewsFeedAPINone = 0,
    // Type reserved for PressReader service.
    PRNewsFeedAPIHomeFeed,
    // Aggregate feed based on the followed by user issues.
    PRNewsFeedAPIPublicationsRSSFeed,
    // Feed of the specific channel.
    // HOME_FEED_CHANNEL parameter must be set.
    PRNewsFeedAPIChannel,
    // Feed of the specific bookmark collection.
    // Both HOME_FEED_CHANNEL and HOME_FEED_COLLECTION must be set.
    PRNewsFeedAPIBookmarks,
    PRNewsFeedAPIMin = PRNewsFeedAPINone,
    PRNewsFeedAPIMax = PRNewsFeedAPIBookmarks
};

@interface PROptions (NewsFeed)
@property (nullable, nonatomic, readonly) NSString *newsFeedChannel;
@property (nonatomic, readonly) NSString *newsFeedChannelSecret;
@property (nullable, nonatomic, readonly) NSString *newsFeedCollection;
@property (nonatomic, readonly) PRNewsFeedAPI newsFeedServiceAPI;
@property (nonatomic, readonly) NSString *newsFeedViewType;

@property (nonatomic, readonly) BOOL isSingleChannelApp;

@end

NS_ASSUME_NONNULL_END
