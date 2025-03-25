//
//  PRAccountManager.h
//  PRiphone
//
//  Created by Dmitry Melnik on 29/08/08.
//  Copyright 2008 NewspaperDirect. All rights reserved.
//

@import PRUtils.PRNotification;
#import <PRAPI/PRAccountItem.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, PRAccountDeauthorizationOption) {
    PRAccountDeauthorizationOptionAuthorizeIfNeeded = 1 << 0,
    PRAccountDeauthorizationOptionDeleteAccount = 1 << 1,
    PRAccountDeauthorizationOptionRequestless = 1 << 2
};

@class PRSignInOption;
@class PRPromise;

@interface PRAccountManager : PRNotification

+ (NSError *)noDefaultAccountError;

- (void)saveAccounts;

- (NSUInteger)accountIdxByName:(NSString*)accountName;
- (void)addAccount:(PRAccountItem *)account;
- (void)rearrangeAccountsOrderToMakeDefaultAccountFirst;

- (void)removeAllAccounts;
- (void)removeAccount:(PRAccountItem *)accountItem;

- (void)authorize;
- (void)authorizeWithCompletion:(void(^ _Nullable)(BOOL success, NSError * _Nullable error))completion;
- (BOOL)registerDeviceWithCompletion:(void(^ _Nullable)(BOOL success, NSError * _Nullable error))completion;
- (BOOL)registerDevice:(NSString *)serviceName;
- (BOOL)registerDevice:(NSString *)serviceName completion:(void(^ _Nullable)(BOOL success, NSError *error))completion;

- (void)AuthorizeUser:(NSString*)usr pwd:(NSString*)pwd devName:(nullable NSString*)devName serviceName:(NSString*)serviceName;
- (void)authorizeUserWithSocialID:(NSString *)socialID;
- (void)authorizeUserWithSocialID:(NSString *)socialID
                        signature:(nullable NSString *)signature
                            stamp:(nullable NSString *)stamp
                       socialData:(nullable NSString *)socialData
                       completion:(void(^_Nullable)(BOOL success, NSError * _Nullable error))completion;

- (void)deauthorize:(PRAccountItem *)accountItem;
- (void)deleteAccount:(PRAccountItem *)accountItem;
- (void)deauthorize:(PRAccountItem *)accountItem
            options:(PRAccountDeauthorizationOption)options
         completion:(void(^ _Nullable)(BOOL success, NSError * _Nullable error))completion;

- (void)signUpUser:(NSString *)usr pwd:(NSString *)pwd firstName:(NSString *)firstName lastName:(NSString *)lastName completionBlock:(void (^)(BOOL success, NSError *error))completionBlock;

- (void)pingAllAccounts;
- (void)updateSubscriptionStatusOfAllReachableAccounts;
- (void)updateSubscriptionStatusOfCatalogAccounts;
- (void)updateSubscriptionStatusOfDefaultAccount;
- (void)updateProfileOfAllReachableAccounts;

- (BOOL)isAnyOnlineAccountReachable;
- (BOOL)isAnyAccountReachable;

- (PRAccountItem*) AccountByName:(NSString*)accountName;
- (PRAccountItem*) AccountByIdx:(NSUInteger)idx;
- (PRAccountItem*) GetFirstAvailableAccount;

- (BOOL) isAuthorizationRequired;
- (BOOL) isUserAuthorizationRequired;
- (BOOL) isDeviceRegistered;

- (PRPromise *)onboardingStateUpdated;

@property (nonatomic, readonly) NSString *defaultServiceName;

@property (nullable, nonatomic, readonly) PRAccountItem *defaultServiceAccount;
@property (nullable, nonatomic, readonly) PRAccountItem *defaultServiceDefaultAccount;
@property (nullable, nonatomic, readonly) PRAccountItem *registeredDefaultServiceAccount;
@property (nullable, nonatomic, readonly) PRAccountItem *firstRegisteredNondefaultServiceAccount;
@property (nullable, nonatomic, readonly) PRAccountItem *defaultAccount;
@property (nullable, nonatomic, readonly) PRAccountItem *localServiceAccount;
@property (nonatomic, readonly) BOOL isLocalServiceOn;

@property (nonatomic, readonly) NSArray<PRAccountItem *> *allAccounts;
@property (nonatomic, readonly) NSArray<PRAccountItem *> *enabledAccounts;
@property (nonatomic, readonly) NSArray<PRAccountItem *> *accountsForCatalog;
@property (nonatomic, readonly) NSArray<PRAccountItem *> *reachableAccounts;
@property (nonatomic, readonly) NSArray<PRAccountItem *> *onlineAccounts;
@property (nonatomic, readonly) NSArray<PRAccountItem *> *linkedOnlineAccounts;
@property (nonatomic, readonly) NSArray<PRAccountItem *> *activeOfflineAccounts;

@property (nonatomic, readonly) BOOL isAuthorizationRequired;
@property (nonatomic) BOOL accountStatusesUpdated;

@property (nullable, nonatomic, strong) NSArray<PRSignInOption *> *signInOptions;
@property (nullable, nonatomic, readonly) NSArray<PRSignInOption *> *signInOptionsSortedByPriority;
@property (nullable, nonatomic, strong) NSArray<PRSignInOption *> *allSignInOptions;
@property (nullable, nonatomic, strong) NSArray<PRSignInOption *> *allManagedSignInOptions;
@property (nullable, nonatomic, strong) NSArray<PRSignInOption *> *managedSignInOptions;
@property (nonatomic, strong) NSString *externalSignInTemplateId;
@property (nonatomic) BOOL emailSignInSupported;

@end


@interface PRAccountManager (/*Protected*/)
/// to avoid sending multiple register requests
@property (nonatomic, strong) NSMutableDictionary *processingRegisterRequests;
@property (nonatomic, strong) NSArray *socialAuthNetworks;

@end

NS_ASSUME_NONNULL_END

#import "PRAccountManager+Store.h"
