//
//  PRAccountItem.h
//  PRiphone
//
//  Created by Jackie Cane on 4/12/11.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

@import UIKit;
@import PRUtils.PRNotification;

#import <PRAPI/PRAccountItemNestedTypes.h>

@class SPNode;
@class PRSubscription;
@class PRAccountManager;
@class PRAccountCardInfo;
@class PRLinkedService;
@class SKProduct;
@class PRPromise;

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const PRAccountItemPriorityChangedNotification;

extern NSNotificationName const PRHotSpotStatusFailedNotification;

typedef NS_ENUM(NSInteger, PRAccountItemPriority){
    PRAccountItemPriorityDefault = 0,
    PRAccountItemPriorityLow = -1,
    PRAccountItemPriorityHigh = 1
};

typedef NS_ENUM(NSInteger, PRAccountItemStatus){
    PRAccountItemStatusReady = 0, // account is ready for use, but may be not reachable (see reachable property for details)
    PRAccountItemStatusDeauthorizing,
    PRAccountItemStatusInvalid
};

typedef NS_ENUM(NSInteger, PRAccountItemReachabilityStatus){
    PRAccountItemReachabilityStatusNotDefined = 0,
    PRAccountItemReachabilityStatusReachable,
    PRAccountItemReachabilityStatusNotReachable
};

typedef NS_ENUM(int, PRAccountPrintOptions) {
    PRAccountPrintOptionsNo = 1,
    PRAccountPrintOptionsPage,
    PRAccountPrintOptionsIssue,
    PRAccountPrintOptionsAuto,
    PRAccountPrintOptionsCorporate
};

typedef NS_ENUM(NSUInteger, PRSubscriptionStatus) {
    PRSubscriptionStatusUndefined = -1,
    PRSubscriptionStatusActive = 1,
    PRSubscriptionStatusSuspended,
    PRSubscriptionStatusCancelled,
    PRSubscriptionStatusPaymentDeclined,
    PRSubscriptionStatusFinished
};

@class PRUserBundle;

@interface PRAccountItem: PRNotification {
    PRAccountItemPriority _priority;
	NSString *url;
	NSString *baseUrl;
	NSString *userName;
	NSString *activationNumber;
	NSString *clientName;
	int profileStatus;
    PRAccountPrintOptions printOptions;
	NSString *_authTicket;
    NSDate *_catalogUpdateDate;
    NSString *_catalogLanguage;
@public
    BOOL justRegistered;
}

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *displayServiceName;
@property (nullable, nonatomic, copy) NSString *friendlyUserName;
@property (nonatomic, readonly) NSString* url;
@property (nonatomic, readonly) NSString* baseUrl;
@property (nonatomic, readonly) NSString* onlineUrl;
@property (nonatomic, readonly) NSString* clientName;
@property (nonatomic, readonly) NSString *profileName;
@property (nullable, nonatomic, strong) NSDictionary<NSString *, id> *accStatus;
@property (nonatomic, assign) int profileStatus;
@property (nonatomic, assign) PRAccountPrintOptions printOptions;
@property (nullable, nonatomic, readonly) NSString *premiumProductId;
@property (nullable, nonatomic, strong) SKProduct *premiumProduct;
@property (nonatomic, assign) BOOL premiumProductInfoUpdated;
@property (nonatomic) BOOL eligibilityForPremiumTrialNotAvailable;
@property (nonatomic) BOOL eligibilityForPremiumTrialUpdated;
@property (nonatomic, readonly, getter=isPremiumProductWithTrial) BOOL premiumProductWithTrial;
@property (nonatomic, readonly) NSInteger accountNumber;
@property (null_resettable, nonatomic, strong) PRPromise *authTicketRequest;
@property (nonatomic, readonly) BOOL hasAuthTicket;
@property (nullable, nonatomic, strong) NSDate * ticketExpirationDate;
@property (nullable, nonatomic, strong) NSDate *requestingNewMessagesDate;
@property (nonatomic, strong) PRSubscription *subscription;
@property (nonatomic, readonly) NSString *host;
@property (nonatomic, readonly) BOOL isLocalServiceAccount;
@property (nonatomic, readonly) BOOL isReachableLocalServiceAccount;
@property (nonatomic, readonly) BOOL isCatalogAccount;
@property (nonatomic, readonly) BOOL isSubscriptionForBundle;
@property (nonatomic, copy) NSString* userName;
@property (nullable, nonatomic, readonly) NSString* logonName;
@property (nullable, nonatomic, readonly) NSString* nickname;
@property (nullable, nonatomic, readonly) NSString* email;
@property (nullable, nonatomic, readonly) NSDate* lastPasswordChangeDate;
@property (nullable, nonatomic, readonly) NSString *internalRefNumber;
@property (nullable, nonatomic, readonly) NSString *firstAndLastName;
@property (nullable, nonatomic, readonly) NSString* firstName;
@property (nullable, nonatomic, readonly) NSString* lastName;
@property (nonatomic, readonly) NSString* displayName;
@property (nonatomic, readonly) NSString* publicEmail;
@property (nonatomic, readonly) BOOL enablePromotional;
@property (nonatomic, readonly) BOOL enableNewsDigest;
@property (nonatomic, strong) NSString* profilePhotoURL;
@property (nullable, nonatomic, readonly) NSString *userRegisteredCountry;
@property (nullable, nonatomic, readonly) NSString *currentCountry;
@property (nonatomic, copy) NSString* activationNumber;
@property (nullable, nonatomic, strong) NSArray<PRUserBundle *> *userBundles;
@property (nonatomic, readonly) NSString *behaviourProfileId;
@property (nonatomic) BOOL askProfileInfo;
@property (nonatomic) BOOL downloadCompletedNotConfirmed;
@property (nonatomic) BOOL downloadCompletedRequesting;
@property (nonatomic) NSUInteger downloadCounter;
@property (nonatomic) NSTimeInterval repeatIntervalOnAccountStatusError;
@property (nonatomic) PRAccountItemPriority priority;
@property (nonatomic, strong) NSDate *catalogUpdateDate;
@property (nullable, nonatomic, strong) NSDate *customCatalogUpdateDate;
@property (nonatomic, copy) NSString *catalogLanguage;
@property (nonatomic, readonly) PRAccountManager *accountManager;
@property (nullable, nonatomic, strong) UIImage *profilePhotoIcon;

// This flag guarantees that account is reachable. It becomes true when get-account-status
// response is received, and sets by setAccStatus: method.
@property (nonatomic, readonly, getter = isReachable) BOOL reachable;
@property (nonatomic, strong) NSDate *reachabilitySuccessCheckDate;
@property (nonatomic) PRAccountItemReachabilityStatus reachabilityStatus;

@property (nullable, nonatomic, strong) NSError *networkError;
@property (nonatomic, getter = isActive) BOOL active;
@property (nonatomic) PRAccountItemStatus status;
@property (nonatomic) BOOL isJustCreated;
@property (nonatomic) BOOL isJustSignedUpWithEmail;

// SUBSCRIPTION STATUS PROPERTIES
@property (nonatomic, readonly) BOOL isTrialSubscription;
@property (nonatomic, readonly) BOOL isFreeSubscription;
@property (nonatomic, readonly) BOOL isPayAsYoGoSubscripiton;
@property (nullable, nonatomic, readonly) NSString *subscriptionId;
@property (nullable, nonatomic, readonly) NSString *subscriptionPlan;
@property (nullable, nonatomic, readonly) NSString *subscriptionType;
@property (nonatomic, readonly) NSDate*	expirationDate;
@property (nonatomic, readonly) NSDate* startDate;
@property (nonatomic, readonly) PRSubscriptionStatus subscriptionStatus;

// CARD INFO PROPERTIES
@property (nonatomic, strong) PRAccountCardInfo *cardInfo;
@property (nonatomic, readonly) BOOL shouldReloadCardInfo;
@property (nonatomic, readonly) BOOL accountContainsValidCard;

// HOTZONE STATUS PROPERTIES
@property (nonatomic, readonly) BOOL hotzoneEnabled;
@property (nonatomic, readonly) BOOL canHotzoneBeUsed;
@property (nullable, nonatomic, readonly) NSString *hotzoneId;
@property (nullable, nonatomic, readonly) NSString *hotzoneIndustry;
@property (nullable, nonatomic, readonly) NSString *hotzoneName;
@property (nonatomic, readonly) NSInteger sponsorshipStatus;
@property (nullable, nonatomic, readonly) NSString * sponsorshipMessage;
@property (nonatomic, readonly) NSInteger sponsorshipCredits;
@property (nullable, nonatomic, readonly) NSDate * sponsorshipRadiantAccessExpiration;
@property (nonatomic, readonly) BOOL isSponsorshipExpired;
@property (nonatomic, readonly) BOOL notificationEnabled;
- (BOOL) needShowHotzoneWelcomeMessage;
- (void) updateHotzoneWelcomeMessageInfo;
// true if device uses sponsorship netpoint
@property (nonatomic, readonly) BOOL inSponsorshipArea;
// true if user wants to use hotzone's benefits when he is in sponsorship area,
// configured in account settings view

// LINKED SERVICES
@property (nonatomic, strong) NSArray<PRLinkedService *> *linkedServices;

@property (nonatomic, assign) PROnboardingStatus onboardingStatus;
@property (nonatomic, readonly) BOOL onboardingCompleted;
@property (class, nonatomic, readonly) BOOL isRegistrationEnabled;
@property (nonatomic, readonly) BOOL isUnregistered;
/// Account is registered or doesn't require registration.
@property (nonatomic, readonly) BOOL isSufficient;
@property (nonatomic, readonly) BOOL isUnlimited;

- (BOOL)isBrandRegisteredAccount;
- (BOOL)isPressDisplayAccount;
- (BOOL)isDefaultServiceAccount;
- (BOOL)isDefaultAccount;
- (BOOL)isDefaultOnlineAccount;
- (BOOL)isEligibleIPhoneAccount;
- (BOOL)isEligibleAccount;
- (BOOL)hasSubscription;
- (BOOL)subscriptionNotValid;
- (BOOL)subscriptionNotValidOrExceeded;
- (BOOL)isUnlimitedSubscription;
@property (nonatomic, readonly) BOOL isPremiumTrial;
@property (nonatomic, readonly) BOOL isBalanceInIssues;

- (BOOL)isPremiumSubscriptionEligible;
- (BOOL)expirationDateHidden;
- (void)setProfileProperties:(nullable NSDictionary *)properties;
- (void)setValue:(id)value forAccStatusKey:(NSString *)key;

- (nullable UIImage *)getProfilePhotoIcon:(void(^)(UIImage *icon))completionBlock;
- (BOOL)setUnlimitedSubscription:(BOOL)isUnlimited withPremiumTrial:(BOOL)isPremiumTrial;
- (void)getProfileName:(void(^_Nullable)(NSString *))completion;

- (void)repair;
- (void)resetCaches;

@end

NS_ASSUME_NONNULL_END

#import "PRAccountItem+Image.h"
#import "PRAccountItem+Notifications.h"
