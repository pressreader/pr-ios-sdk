//
//  PRSmartLink.h
//  PRiphone
//
//  Created by Jackie Cane on 26/08/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import "PRSmartRegion.h"

NS_ASSUME_NONNULL_BEGIN

extern PRSmartObjectAttribute const PRSmartObjectAttributeHyperlinkType;
extern PRSmartObjectAttribute const PRSmartObjectAttributeHyperlinkTarget;

extern PRSmartRegionType const PRSmartRegionTypeLink;

@interface PRSmartHyperLink : PRSmartRegion
@property (nullable, nonatomic, readonly) NSString *linkType;
@property (nonatomic, readonly) NSString *target;
@end

@interface PRSmartPageLink : PRSmartRegion
- (NSUInteger) toPageNo;
@end

@interface PRSmartArticleLink : PRSmartRegion
- (NSString*) artID;
- (BOOL) isForwardLink; //YES-forward link, NO-back link
@end

NS_ASSUME_NONNULL_END
