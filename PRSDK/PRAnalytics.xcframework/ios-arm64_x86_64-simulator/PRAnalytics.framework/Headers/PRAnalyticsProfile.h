//
//  PRAnalyticsProfile.h
//  PR-API
//
//  Created by Vitali Bounine on 2018-02-21.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PRAnalyticsProfileType){
    PRAnalyticsProfileTypeGA = 1,
    PRAnalyticsProfileTypeOJD
};

typedef NSString * const PRAnalyticsProfileEventName NS_STRING_ENUM;
FOUNDATION_EXPORT PRAnalyticsProfileEventName PRAnalyticsProfileEventNamePagePreview;
FOUNDATION_EXPORT PRAnalyticsProfileEventName PRAnalyticsProfileEventNameArticlePreview;
FOUNDATION_EXPORT PRAnalyticsProfileEventName PRAnalyticsProfileEventNameArticleDetailed;
FOUNDATION_EXPORT PRAnalyticsProfileEventName PRAnalyticsProfileEventNameIssueDownload;
FOUNDATION_EXPORT PRAnalyticsProfileEventName PRAnalyticsProfileEventNameIssueOpen;

// can be used either as either PRAnalyticsProfileEventNamePagePreview
// or PRAnalyticsProfileEvent.pageviewPreview
FOUNDATION_EXPORT const struct PRAnalyticsProfileEvent {
    __unsafe_unretained PRAnalyticsProfileEventName pageviewPreview;
    __unsafe_unretained PRAnalyticsProfileEventName articlePreview;
    __unsafe_unretained PRAnalyticsProfileEventName articleDetailed;
    __unsafe_unretained PRAnalyticsProfileEventName issueDownload;
    __unsafe_unretained PRAnalyticsProfileEventName issueOpen;
} PRAnalyticsProfileEvent;

typedef NSString * const PRAnalyticsPatternPlaceholder NS_STRING_ENUM;
FOUNDATION_EXPORT PRAnalyticsPatternPlaceholder PRAnalyticsPatternPlaceholderCID;
FOUNDATION_EXPORT PRAnalyticsPatternPlaceholder PRAnalyticsPatternPlaceholderDate;
FOUNDATION_EXPORT PRAnalyticsPatternPlaceholder PRAnalyticsPatternPlaceholderPage;
FOUNDATION_EXPORT PRAnalyticsPatternPlaceholder PRAnalyticsPatternPlaceholderArticleId;
FOUNDATION_EXPORT PRAnalyticsPatternPlaceholder PRAnalyticsPatternPlaceholderTrackerId;

// can be used either as either PRAnalyticsPatternPlaceholderCID
// or PRAnalyticsPatternPathPlaceholder.cid
FOUNDATION_EXPORT const struct PRAnalyticsPatternPathPlaceholder {
    __unsafe_unretained PRAnalyticsPatternPlaceholder cid;
    __unsafe_unretained PRAnalyticsPatternPlaceholder date;
    __unsafe_unretained PRAnalyticsPatternPlaceholder page;
    __unsafe_unretained PRAnalyticsPatternPlaceholder articleId;
    __unsafe_unretained PRAnalyticsPatternPlaceholder trackerId;
} PRAnalyticsPatternPathPlaceholder;

@interface PRAnalyticsProfileBase : NSObject

@property (nonatomic, readonly) NSString * profileId;
@property (nonatomic, readonly) NSInteger version;
@property (nonatomic, readonly) PRAnalyticsProfileType type;
@property (nonatomic, readonly) NSString * trackerId;
@property (nonatomic, readonly) NSDictionary<NSString *, id> *json;

- (instancetype) initWithJSON:(NSDictionary<NSString *, id> *)jsonDict;

@end

@interface PRAnalyticsProfileBase (Serialization)

- (instancetype) initWithData:(NSData *)data;
- (NSData *)serialize;

@end

@interface PRAnalyticsProfile : PRAnalyticsProfileBase

@property (nonatomic, readonly, strong) NSDictionary<PRAnalyticsProfileEventName, NSString *> *eventConfig;

- (nullable NSString *)patternForEvent:(PRAnalyticsProfileEventName)event;
- (nullable NSString *)resolvedPathForEvent:(PRAnalyticsProfileEventName)event substitute:(NSDictionary<NSString *, id> *)params;

@end

NS_ASSUME_NONNULL_END
