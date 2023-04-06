//
//  PRService_Constants.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 7/24/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#ifndef PRService_Constants_h
#define PRService_Constants_h

@import Foundation;

#pragma mark - request DeliveryQueue and and OnlineService request keys in option dictionary

typedef NSString *PRServiceRequestOption NS_TYPED_ENUM;

/// BOOL
extern PRServiceRequestOption const PRServiceRequestOptionDontLogErrorsKey;
/// BOOL
extern PRServiceRequestOption const PRServiceRequestOptionDQSimpleResponseKey;
/// BOOL
extern PRServiceRequestOption const PRServiceRequestOptionDebugLogQueryKey;
/// BOOL
extern PRServiceRequestOption const PRServiceRequestOptionAccountRequiredKey;
/// BOOL
extern PRServiceRequestOption const PRServiceRequestOptionShowWaitingAlertViewKey;
/// NSString, default "PR.iPad.Loading"
extern PRServiceRequestOption const PRServiceRequestOptionWatingAlertTextKey;
/// BOOL
extern PRServiceRequestOption const PRServiceRequestOptionShowAlertIfErrorKey;
/// BOOL
extern PRServiceRequestOption const PRServiceRequestOptionRepeatOnTimeoutKey;
/// NSInteger number of repeats (0 - no repeating)
extern PRServiceRequestOption const PRServiceRequestOptionRepeatOnErrorKey;
/// double in secs
extern PRServiceRequestOption const PRServiceRequestOptionRepeatOnErrorDelayKey;
/// BOOL
extern PRServiceRequestOption const PRServiceRequestOptionNoClientInfoKey;
/// BOOL
extern PRServiceRequestOption const PRDeliverQueueOptionReturnNSXMLParserKey;
/// BOOL
extern PRServiceRequestOption const PRServiceRequestOptionUseContentProxyKey;
/// BOOL
extern PRServiceRequestOption const PRServiceRequestOptionDontRemoveNullsFromJSONKey;
/// NSString
extern PRServiceRequestOption const PRServiceRequestOptionBaseURLKey;
/// NSTimeInterval - default 20 sec after completion
extern PRServiceRequestOption const PRServiceRequestOptionExpirationInterval;
/// NSTimeInterval - default 0 after completion
extern PRServiceRequestOption const PRServiceRequestOptionFailureExpirationInterval;
/// BOOL - default NO ( use prev. request cache if available)
extern PRServiceRequestOption const PRServiceRequestOptionResetRequestCache;
/// BOOL - YES means that we should use `error-message` as a localized description for the error instead of localized string
extern PRServiceRequestOption const PRServiceRequestOptionUseServerError;
/// BOOL - default NO ( ignore external command to load catalog, used when requested from get-hotspot-status )
extern PRServiceRequestOption const PRServiceRequestOptionIgnoreCommandReloadCatalog;
/// BOOL - default NO : don't register promise object allowing several identical request at the same time
extern PRServiceRequestOption const PRServiceRequestOptionNoCoalescing;

#pragma mark - Parameters Keys

typedef NSString *PRServiceRequestParameter NS_TYPED_ENUM;

/// NSArray
extern PRServiceRequestParameter const PRServiceRequestParameterMultipartDataPartsKey;
/// NSDictionary
extern PRServiceRequestParameter const PRServiceRequestParameterCustomHeadersKey;
/// NSString
extern PRServiceRequestParameter const PRServiceRequestParameterCustomBodyKey;
/// NSString
extern PRServiceRequestParameter const PRServiceRequestParameterCustomContentTypeKey;
/// NSString, overrides access online token to use
extern PRServiceRequestParameter const PRServiceRequestParameterOnlineToken;


typedef NSString *PRServiceResponseField NS_TYPED_EXTENSIBLE_ENUM;
/// NSDictionary with PRServiceResponseCommandKey
extern PRServiceResponseField const PRServiceResponseFieldCommandKey;

typedef NSString *PRServiceResponseCommandKey NS_TYPED_ENUM;
/// PRServiceRresponseCommandName
extern PRServiceResponseCommandKey const PRServiceResponseCommandKeyName;
/// NSString
extern PRServiceResponseCommandKey const PRServiceResponseCommandKeyData;

typedef NSString *PRServiceResponseCommandName NS_TYPED_ENUM;
extern NSString *const PRServiceResponseCommandNameReloadCatalog;
extern NSString *const PRServiceResponseCommandNameReloadCatalogLegacy;
extern NSString *const PRServiceResponseCommandNameReloadAction;
extern NSString *const PRServiceResponseCommandNameReloadAlert;

extern const NSTimeInterval kPRServiceResponseTimeout;

#endif /* PRService_Constants_h */
