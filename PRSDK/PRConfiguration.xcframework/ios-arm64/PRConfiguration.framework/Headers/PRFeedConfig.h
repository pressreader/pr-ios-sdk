//
//  PRFeedConfig.h
//  PR-API
//
//  Created by berec on 12/03/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, PRFeedArticleAction) {
    PRFeedArticleActionNone = 0,
    PRFeedArticleActionPrint = 1 << 0,
    PRFeedArticleActionShare = 1 << 1,
    PRFeedArticleActionListen = 1 << 2,
    PRFeedArticleActionBookmark = 1 << 3,
    PRFeedArticleActionUnlock = 1 << 4,
    PRFeedArticleActionMulti = PRFeedArticleActionPrint | PRFeedArticleActionShare | PRFeedArticleActionListen
};

typedef NS_ENUM(uint8_t, PRFeedArticleAccessMode) {
    PRFeedArticleAccessModeNone = 0,
    PRFeedArticleAccessModeRequireSignIn,
    PRFeedArticleAccessModeRequireSubscription
};

typedef NS_ENUM(uint8_t, NTFLayoutType) {
    NTFLayoutTypeAutomatic = 0,
    NTFLayoutTypeFlow,
    NTFLayoutTypeCompact,
    NTFLayoutTypeDuple,
    NTFLayoutTypeTriple,
    NTFLayoutTypeComplex,
};

@interface PRFeedConfig : NSObject
@property (nonatomic, readonly) BOOL authorizationRequiredToRead;
@property (nonatomic, readonly) BOOL multipleBookmarksEnabled;

@property (nonatomic, readonly) PRFeedArticleAction articleActions;
@property (nonatomic, readonly) PRFeedArticleAction issueArticleActions;

@property (nonatomic, readonly) PRFeedArticleAccessMode feedArticleAccessMode;
@property (nonatomic, readonly) BOOL enableFeedAccessForActiveTrial;

@property (nonatomic, readonly) NSString *defaultFeedLanguage;

@property (nonatomic, readonly) BOOL ignoreRadioRestrictions;

@property (nonatomic, readonly) NSUInteger articlesCoupleLookupStep;

@property (nonatomic, readonly) NTFLayoutType preferredRegularLayoutType;
@property (nonatomic, readonly) NTFLayoutType preferredCompactLayoutType;

@end

NS_ASSUME_NONNULL_END
