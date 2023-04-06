//
//  MKMapView+ZoomLevel.h
//  PRiphone
//
//  Created by Jackie Cane on 13/10/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

@interface MKMapView (ZoomLevel)

@property (assign, nonatomic, readonly) NSUInteger minZoomLevel;
@property (assign, nonatomic) NSUInteger zoomLevel;

- (NSUInteger)zoomLevelForRegion:(MKCoordinateRegion)region;
- (void)setCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate
                  zoomLevel:(NSUInteger)zoomLevel
                   animated:(BOOL)animated;

@end
