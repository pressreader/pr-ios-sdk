//
//  PRSmartComplexRegion.h
//  PRiphone
//
//  Created by Jackie Cane on 26/08/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import "PRSmartRegion.h"

@interface PRSmartComplexRegion	: PRSmartRegion {
    NSMutableArray<PRSmartRegion *>* regions;
    NSMutableDictionary<NSString *, PRSmartRegion *>* textRegions;
}

- (NSDictionary<NSString *, PRSmartRegion *>*)textRegions;
- (NSArray<PRSmartRegion *>*)regions;
- (PRSmartRegion *)textRegionByType:(NSString *)type;
- (NSString *)textOfRegionByType:(NSString *)type hyphenated:(BOOL)hyphenated;
- (NSString *)textOfRegionByType:(NSString *)type hyphenated:(BOOL)hyphenated isoLanguage:(NSString *)isoLanguage;
- (void)addSmartRegion:(PRSmartRegion *)region;
- (CGRect)shallowUnionRect;

@end
