//
//  PRSponsorshipManagerService.h
//  PRAPI
//
//  Created by Ivan Berezin on 26/03/2024.
//  Copyright © 2024 NewspaperDirect. All rights reserved.
//

#import <PRAPI/PRSubscriptionService.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRSponsorshipManagerService : PRSubscriptionService

- (void)optoutHotzone:(BOOL)optout
              success:(void(^ _Nullable)(void))success
              failure:(PRSimpleResult)failure;

- (void)getHotZoneLocationsWithZoomLevel:(long)zoomLevel
                            northEastLat:(double)northEastLat
                            northEastLng:(double)northEestLng
                            southWestLat:(double)southWestLat
                            southWestLng:(double)southWestLng
                              currentLat:(double)myLat
                              currentLng:(double)myLng
                                 pattern:(NSString *)pattern
                                 success:(void(^ _Nullable)(NSArray * _Nullable hotSpots))success
                                 failure:(PRSimpleResult)failure;

- (void)getGeoFencingHotZoneLocationsAtNorthEastLat:(double)northEastLat
                                       northEastLng:(double)northEestLng
                                       southWestLat:(double)southWestLat
                                       southWestLng:(double)southWestLng
                                            success:(void (^ _Nullable)(NSArray * _Nullable hotSpots))success
                                            failure:(PRSimpleResult)failure;

- (void)searchForHotZoneLocations:(NSString *)searchString
                            count:(NSUInteger)count
                       completion:(void(^ _Nullable)(NSArray * _Nullable hotSpots,
                                                     NSError * _Nullable error))completion;

- (void)getRegionOfHotZonesWithPattern:(NSString *)searchString
                            currentLat:(double)myLat
                            currentLng:(double)myLng
                      currentZoomLevel:(int)myZoomLevel
                               success:(void (^ _Nullable)(NSDictionary *regionOfHotZones))success
                               failure:(PRSimpleResult)failure;

@end

NS_ASSUME_NONNULL_END
