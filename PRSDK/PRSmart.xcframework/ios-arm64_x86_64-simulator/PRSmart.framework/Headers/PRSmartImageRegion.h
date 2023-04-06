//
//  PRSmartImageRegion.h
//  PRiphone
//
//  Created by Jackie Cane on 26/08/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import "PRSmartComplexRegion.h"

@class PRImageValidationCriteria;

@interface PRSmartImageRegion : PRSmartComplexRegion

- (CGRect) unionRect;
- (NSString*) captionWithHyphens:(BOOL)hyphenated;
- (NSString*) bylineWithHyphens:(BOOL)hyphenated;
- (NSString*) titleWithHyphens:(BOOL)hyphenated;
- (NSString*) subtitleWithHyphens:(BOOL)hyphenated;
- (PRSmartRegion *) captionRegion;
- (PRSmartRegion *) bylineRegion;
- (PRSmartRegion *) titleRegion;
- (PRSmartRegion *) subtitleRegion;
- (NSURL *) url;

- (BOOL)isValidForSize:(CGSize)size criteria:(PRImageValidationCriteria *)criteria reason:(NSString * __autoreleasing *)info;
- (BOOL)isValidForSize:(CGSize)size criteria:(PRImageValidationCriteria *)criteria;

- (CGSize)outputSizeForMinSize:(CGSize)size;
- (long)scaleForMinSize:(CGSize)size outputSize:(CGSize *)outputSize info:(NSString **)info;
- (long)scaleForMaxSize:(CGSize)size outputSize:(CGSize *)outputSize;

@property (nonatomic, readonly) NSString *imageRegionKey;
@property (nonatomic, readonly) BOOL isOnline;

@end
