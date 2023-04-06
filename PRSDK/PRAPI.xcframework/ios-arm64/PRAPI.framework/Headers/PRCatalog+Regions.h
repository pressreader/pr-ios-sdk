//
//  PRCatalog+Regions.h
//  PRiphone
//
//  Created by Jackie Cane on 10/04/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import "PRCatalog.h"

@interface PRCatalog (Regions)

- (NSDictionary *)regionByName:(NSString *)regionName;

/**
 Returns top level region that corresponds to region with given name.
 @param regionName Name of searching region
 @param ceilingRegion Parameter to limit degree of generalization. To get the toppest level region set nil.
 */
- (NSDictionary *)topRegionForRegionWithName:(NSString *)regionName ceilingRegion:(NSDictionary *)ceilingRegion;
- (BOOL)region:(NSDictionary *)region complyWithFilterRegion:(NSDictionary *)filterRegion;

@end
