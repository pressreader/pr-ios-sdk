//
//  PRMapAnnotation.h
//  PRiphone
//
//  Created by Jackie Cane on 20/02/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>


@interface PRMapAnnotation : NSObject<MKAnnotation>

- (instancetype)initWithLocationInfo:(NSDictionary *)locationInfo;

@property (nonatomic, strong) NSDictionary *locationInfo;
@property (nonatomic, readonly) CLLocationDegrees latitude;
@property (nonatomic, readonly) CLLocationDegrees longitude;
@property (nonatomic, readonly) CLLocationCoordinate2D locationCoordinate;

@end
