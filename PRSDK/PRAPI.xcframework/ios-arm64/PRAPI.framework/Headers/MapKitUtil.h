//
//  MKUtils.h
//  PRiphone
//
//  Created by Jackie Cane on 24/06/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

typedef struct {
    double NELat;
    double NELng;
    double SWLat;
    double SWLng;
} PRCoordinateRegion;

NS_INLINE MKCoordinateRegion MKMakeCoordinateRegionFromPRCoordinateRegion(PRCoordinateRegion region)
{
    CLLocationDegrees regionLatExpansion = 0.0;
    CLLocationDegrees regionLngExpansion = 0.0;
    
    // expand given location region to pose border points in visible area
    regionLatExpansion = (region.NELat - region.SWLat) * 0.04;
    regionLngExpansion = (region.NELng - region.SWLng) * 0.04;
    
    region.NELat += regionLatExpansion;
    region.NELng += regionLngExpansion;
    region.SWLat -= regionLatExpansion;
    region.SWLng -= regionLngExpansion;
    
    CLLocationCoordinate2D centerCoordinate = CLLocationCoordinate2DMake(region.SWLat + (region.NELat - region.SWLat) / 2.f, region.SWLng + (region.NELng - region.SWLng) / 2.f);
    
    CLLocationDegrees latitudeDelta = region.NELat - region.SWLat;
    CLLocationDegrees longitudeDelta = region.NELng - region.SWLng;
    CLLocationDegrees maxLatDelta = 180.0;
    CLLocationDegrees maxLngDelta = 360.0;
    if (latitudeDelta > maxLatDelta) {
        latitudeDelta = maxLatDelta;
    }
    if (longitudeDelta > maxLngDelta) {
        longitudeDelta = maxLngDelta;
    }
    MKCoordinateSpan span = MKCoordinateSpanMake(latitudeDelta, longitudeDelta);
    
    return MKCoordinateRegionMake(centerCoordinate, span);
}

NS_INLINE MKCoordinateRegion MKCoordinateRegionZero()
{
    return MKCoordinateRegionMake(CLLocationCoordinate2DMake(0, 0), MKCoordinateSpanMake(0, 0));
}

/// Region is considered as Zero in case of any of its span deltas is equal to 0
NS_INLINE BOOL MKCoordinateRegionIsZero(MKCoordinateRegion region)
{
    return region.span.latitudeDelta == 0.0 || region.span.longitudeDelta == 0.0;
}

NS_INLINE BOOL MKCoordinateRegionEqualToRegion(MKCoordinateRegion region1, MKCoordinateRegion region2)
{
    return region1.center.latitude == region2.center.latitude &&
    region1.center.longitude == region2.center.longitude &&
    region1.span.latitudeDelta == region2.span.latitudeDelta &&
    region1.span.longitudeDelta == region2.span.longitudeDelta;
}


@interface MapKitUtil : NSObject

@end
