//
//  PRCoreUtil.h
//  PRiphone
//
//  Created by Dmitry Melnik on 02/09/08.
//  Copyright 2008 NewspaperDirect. All rights reserved.
//

@import UIKit;
@import PRUtils.PRReachability;

@class PROptions;
@class CCCryptorAES256;

NS_ASSUME_NONNULL_BEGIN

typedef void(^CompletionHandlerBlockType)(NSString *_Nullable cwlFilePath, NSString *_Nullable description, NSError *_Nullable error);

typedef NS_ENUM(NSUInteger, PRAlertControllerPresentationContext) {
    PRAlertControllerPresentationContextNone,
    PRAlertControllerPresentationContextAPICommand,
};

@class MBProgressHUD;
@class PRReachability;

@interface PRCoreUtil : NSObject

//memory usage
+ (void)logMemUsage; //print log message if memory difference more then 100Kb
+ (void)logMemUsage:(BOOL)forced;

- (instancetype)initWithOptions:(PROptions *)options;
- (instancetype)init NS_UNAVAILABLE;

- (nullable NSString*)saveCrashReport;
- (void)zipLogsWithCompletionHandler:(CompletionHandlerBlockType)handler;
- (void)zipAndUploadLogsWithCompletionHandler:(CompletionHandlerBlockType)handler;

- (void)alertSimpleAction:(nullable NSString*)title message:(nullable NSString*)message presentationContext:(PRAlertControllerPresentationContext)presentationContext;
- (void)alertSimpleAction:(nullable NSString*)title message:(nullable NSString*)message controller:(nullable UIViewController *)controller handler:(void (^_Nullable)(BOOL okPressed))handler;
- (void)alertSimpleActionYesNo:(nullable NSString*)title message:(nullable NSString*)message controller:(nullable UIViewController *)controller handler:(void (^_Nullable)(BOOL yesPressed))handler;
- (void)resetCookies;
- (void)setupCookiePolicy:(NSHTTPCookieAcceptPolicy)policy;

- (nullable NSString*)xmlAttrib:(id)node attrName:(NSString*)attrName defValue:(nullable NSString*)defValue;

- (nullable NSDate*) GetFileModificationDate:(NSString*)fileName GMT:(BOOL)GMT;
- (BOOL) IsFileDestinationOlderOrDoesNotExist:(NSString*)srcPath dstPath:(NSString*)dstPath;
- (BOOL) ReplaceFileIfOlderOrDoesNotExist:(NSString*)src dst:(NSString*)dst;

- (nullable UIColor*)colorFromNSString:(NSString *)string;

- (void)restartNetworkNotifiers;
- (void)stopNetworkNotifiers;
- (void)addNetworkObserver:(id)observer selector:(SEL)selector;
- (void)removeNetworkObserver:(id)observer;
- (PRNetworkStatus)networkStatus;

- (nullable id) unsupportedJSONClass:(id)unsupported;

- (void) setDebugLevel:(NSInteger) debugLevel;
- (void) setDebugId:(NSInteger) debugId;

#pragma mark global utils

- (void) SwapObjects:(NSObject *_Nonnull *_Nonnull)o1 o2:(NSObject *_Nonnull *_Nonnull)o2;
- (nullable NSString*)DateStringFromIssueId:(NSString*)issueId format:(NSString*)format;
- (nullable NSString*)IsoDateStringFromIssueId:(NSString*)issueId;
- (nullable NSDate*)NSDateFromIssueId:(NSString*)issueId;
- (NSString*)GetJSONSystemParameters;
- (NSString*)GetURLSystemParameters;

#pragma mark - localized Language And Country Names
- (nullable NSString *)localizedCountryNameForISOCode:(NSString *)countryISOCode;
- (nullable NSString *)localizedLanguageNameForISOCode:(NSString *)languageISOCode;

@property (nonatomic, readonly) BOOL isNetworkReachable;

@end


NSInteger numericSort(id string1, id string2, void *reverse);


@interface NSFileManager (PRUtil)
- (void)asyncAppendItemAtURL:(NSURL *)fromLocation toURL:(NSURL *)toLocation completed:(void(^_Nullable)(NSError *_Nullable error))completionBlock;
- (BOOL)appendItemAtURL:(NSURL *)fromLocation toURL:(NSURL *)toLocation error:(NSError *_Nullable *)error;
@end

NS_ASSUME_NONNULL_END
