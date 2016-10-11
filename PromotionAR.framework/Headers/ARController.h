//
//  ARController.h
//  PromotionAR
//
//  Created by Xu, Jay on 10/10/16.
//  Copyright © 2016 Yijie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class LocationMath;

@interface ARController : NSObject
{
    NSMutableDictionary *geoobjectOverlays;
    NSMutableDictionary *geoobjectPositions;
    NSMutableDictionary *geoobjectVerts;
}

@property (nonatomic, strong) LocationMath *locationMath;

-(NSDictionary*)buildAROverlaysForData:(NSArray*)arData andLocation:(CLLocationCoordinate2D)newLocation;
-(NSArray*)createRadarSpots;

@end
