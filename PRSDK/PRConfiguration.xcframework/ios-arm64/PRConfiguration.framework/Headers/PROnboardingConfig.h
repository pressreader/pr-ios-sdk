//
//  PROnboardingConfig.h
//  PR-API
//
//  Created by berec on 11/07/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, PROnboardingStep) {
    PROnboardingStepUndefined = 0,
    PROnboardingStepGetStarted,
    PROnboardingStepIntro,
    PROnboardingStepInterests,
    PROnboardingStepPublications
};

typedef NS_ENUM(uint8_t, PROnboardingType) {
    PROnboardingTypePersonalization = 0,
    PROnboardingTypePublications
};

@interface PROnboardingConfig : NSObject
@property (nonatomic) BOOL onboardingCompleted;
@property (nonatomic) BOOL shouldAskForNotifications;
@property (nonatomic) PROnboardingStep lastStep;
@property (nonatomic, readonly) BOOL isSupported;
@property (nonatomic, readonly) BOOL isEnabled;
@property (nonatomic, readonly) BOOL isDeferred;
@property (nonatomic, readonly) BOOL interestsEnabled;
@property (nonatomic, readonly) PROnboardingType onboardingType;

@property (nonatomic, readonly) NSUInteger skipButtonColor;
@property (nonatomic, readonly) BOOL needAdditionalOverlayToBackgroundGradient;

@property (nonatomic, readonly) BOOL publicationsSuggestionsAllowed;

@property (nonatomic, readonly) BOOL showGetStartedIntro;
@property (nonatomic, readonly) BOOL showRegistrationIntro;

// A/B Testing
@property (nonatomic, readonly) NSString *signInDescripitonKey;
@property (nonatomic, readonly) NSString *bannerTitleKey;
@property (nonatomic, readonly) NSString *bannerDescriptionKey;

- (void)resetShouldAskForNotifications;

@end

NS_ASSUME_NONNULL_END
