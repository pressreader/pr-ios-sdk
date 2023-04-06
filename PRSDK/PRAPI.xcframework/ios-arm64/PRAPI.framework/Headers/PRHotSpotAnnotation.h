//
//  PRHotSpotLocationInfo.h
//  PRiphone
//
//  Created by Jackie Cane on 10/10/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PRMapAnnotation.h"
#import "PRHotSpotManager.h"

// dictionary's keys
extern NSString *const kHSId;
extern NSString *const kHSTitle;
extern NSString *const kHSAddress;
extern NSString *const kHSPhone;
extern NSString *const kHSUrl;
extern NSString *const kHSDescription;
extern NSString *const kHSEnable;
extern NSString *const kHSRestricted;
extern NSString *const kHSDistance;
extern NSString *const kHSLat;
extern NSString *const kHSLng;
extern NSString *const kHSLocationsTotal;
extern NSString *const kLocationsRegionNELat;
extern NSString *const kLocationsRegionNELng;
extern NSString *const kLocationsRegionSWLat;
extern NSString *const kLocationsRegionSWLng;

/* Example of dictionary:
 {
 "LocationInfo": {
     "Id": "10464_1",
     "Title": "Estonian Academy of Security Sciences",
     "Address": "Tallinn, 01, Estonia",
     "Phone": null,
     "Url": null,
     "Description": null,
     "Enable": true,
     "Restricted": false,
     "Distance": 6934.0,
     "Lat": 59.4339,
     "Lng": 24.7281
 },
 "MoreLocations": [{
     "Id": "11817_1",
     "Title": "Hotel - Hotel Palace Tallinn",
     "Address": "Tallinn, 01, Estonia",
     "Phone": null,
     "Url": null,
     "Description": null,
     "Enable": true,
     "Distance": 6934.0,
     "Lat": 59.4339,
     "Lng": 24.7281
 }],
 "LocationsTotal": 2,
 "NELat": 59.4339,
 "NELng": 24.7281,
 "SWLat": 59.4339,
 "SWLng": 24.7281
 }
 */

@interface PRHotSpotAnnotation : PRMapAnnotation

+ (MKCoordinateRegion)coordinateRegionFromHotspotLocationInfo:(NSDictionary *)hotspotLocationInfo;

@property (nonatomic, readonly) NSString *hotSpotId;
@property (nonatomic, readonly) BOOL enabled;
@property (nonatomic, readonly) BOOL restricted;
@property (nonatomic, readonly) PRHotSpotStatus status;
@property (nonatomic, strong, readonly) UIImage *icon;
@property (nonatomic, readonly) UIImage *pinIcon;
@property (nonatomic, readonly) NSUInteger distance;
@property (nonatomic, readonly) NSString *address;
@property (nonatomic, readonly) NSString *phone;
@property (nonatomic, readonly) NSString *url;
@property (nonatomic, readonly) NSString *details;
@property (nonatomic, readonly) NSUInteger locationsTotal;
@property (nonatomic, readonly) MKCoordinateRegion locationsRegion;

@end

@interface PRHotSpotAnnotation (/*UI*/)
@property (nonatomic, assign) BOOL showDetails;
@end
