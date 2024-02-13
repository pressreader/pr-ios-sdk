//
//  PRConfig+Analytics.h
//  PR-API
//
//  Created by KeithC on 2019-08-23.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <PRConfiguration/PRConfig.h>

NS_ASSUME_NONNULL_BEGIN

#define enable_analytics                 _PRCONFIG_BOOL_(@"enable_analytics", YES)
#define google_analytics_account         _PRCONFIG_STRING_(@"google_analitics_account", @"")
#define ENABLE_AD_MOB                    _PRCONFIG_BOOL_(@"ENABLE_AD_MOB", NO)
#define APP_ITUNES_ID                    _PRCONFIG_STRING_(@"APP_ITUNES_ID", nil)
#define OJD_TRACKER_ENABLED              _PRCONFIG_BOOL_(@"OJD_TRACKER_ENABLED", NO)

#define GOOGLE_ANALYTICS_TRACKING_EVENTS_DISABLED _PRCONFIG_BOOL_(@"GOOGLE_ANALYTICS_TRACKING_EVENTS_DISABLED", NO)
#define GOOGLE_ANALYTICS_SAMPLE_RATE    _PRCONFIG_INT_(@"GOOGLE_ANALYTICS_SAMPLE_RATE", 0)

#define GA_REPORT_ADDITIONAL_TEXT_VIEW_INFO    _PRCONFIG_BOOL_(@"GA_REPORT_ADDITIONAL_TEXT_VIEW_INFO", PRConfig.isBrandEdition)
#define GA_REPORT_ADDITIONAL_PAGE_VIEW_INFO    _PRCONFIG_BOOL_(@"GA_REPORT_ADDITIONAL_PAGE_VIEW_INFO", PRConfig.isBrandEdition)
#define GA_REPORT_FEED_ARTICLE_TEXT_VIEW     _PRCONFIG_BOOL_(@"GA_REPORT_FEED_ARTICLE_TEXT_VIEW", PRConfig.isBrandEdition)
#define GA_REPORT_READING_EVENT_ALONGSIDE_SCREENVIEW     _PRCONFIG_BOOL_(@"GA_REPORT_READING_EVENT_ALONGSIDE_SCREENVIEW", PRConfig.isBrandEdition)
#define GA_OLD_REPLICA_PAGE_VIEW_REPORT_BEHAVIOUR       _PRCONFIG_BOOL_(@"GA_OLD_REPLICA_PAGE_VIEW_REPORT_BEHAVIOUR", PRConfig.isBrandEdition)

#define FACEBOOK_AD_COLLECTION_ENABLED _PRCONFIG_BOOL_(@"FACEBOOK_AD_COLLECTION_ENABLED", YES)

@interface PRConfig (Analytics)

@property (class, nonatomic, readonly) BOOL isAnalyticsEnabled;
@property (class, nonatomic, readonly) BOOL useAnalyticRemoteConfig;

@end

@interface PRConfig (Braze)
@property (class, nullable, nonatomic, readonly) NSString *brazeApiKey;
@property (class, nonatomic, readonly) NSString *brazeApiEndPoint;

@end

@interface PRConfig (Facebook)
@property (class,nonatomic, readonly) BOOL isFacebookAdCollectionEnabled;
@end


NS_ASSUME_NONNULL_END
