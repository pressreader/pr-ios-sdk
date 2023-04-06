//
//  PRConfig+KYM.h
//  PRSharedData
//
//  Created by Viacheslav Soroka on 11/17/20.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <PRConfiguration/PRConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRConfig (KYM)
@property (class, nonatomic, readonly) BOOL isKYMEdition;
@property (class, nonatomic, readonly) BOOL useNightEdition;
@property (class, nonatomic, readonly) BOOL includeAdditionalParamsOnWebLink;
@property (class, nonatomic, readonly) BOOL useMultiplePresentationStyleSafariVC;
@property (class, nonatomic, readonly) BOOL publicationDetailsShowRibbon;
@property (class, nonatomic, readonly) BOOL publicationDetailCalendarScrollToIssue;
@property (class, nonatomic, readonly) BOOL enableOpenInSafariOption;
@property (class, nonatomic, readonly) BOOL clientInfoUseShortSystemPlatform;
@property (class, nonatomic, readonly) BOOL orderDeliveryHideOrderText;
@property (class, nonatomic, readonly) BOOL printingUseShortFooterFormat;
@property (class, nonatomic, readonly) BOOL showParentTitleWithRegionalEditions;

@end

NS_ASSUME_NONNULL_END
