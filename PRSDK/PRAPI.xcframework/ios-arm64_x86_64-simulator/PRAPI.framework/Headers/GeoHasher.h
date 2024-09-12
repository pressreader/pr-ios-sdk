//
//  GeoHasher.h
//  PRAPI
//
//  Created by Vitalii Hudenko on 09.05.2024.
//  Copyright © 2024 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class LocationRect;

NS_ASSUME_NONNULL_BEGIN

@interface GeoHasher : NSObject
- (NSString *)calculateGeoHash:(CLCircularRegion *)region;
- (NSString *)calculateGeoHash:(CLCircularRegion *)region size:(NSUInteger)hashSize;
- (nullable LocationRect *)decodeGeoHash:(NSString *)geoHash;
- (CLCircularRegion *)decodeGeoHashAsRegion:(NSString *)geoHash;
@end

NS_ASSUME_NONNULL_END
