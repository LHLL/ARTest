//
//  LocationMath.h
//  PromotionAR
//
//  Created by Xu, Jay on 10/10/16.
//  Copyright © 2016 Yijie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>
#import <CoreLocation/CoreLocation.h>

#import "ARObject.h"


@interface LocationMath : NSObject <CLLocationManagerDelegate>
{
    // Major variables
    float currentHeading;
    float currentInclination;
    
    CLLocationCoordinate2D location;
    
    // Others
    float rollingZ;
    float rollingX;
    
    float rollingZ2;
    float rollingX2;
    
    float deviceViewHeight;
}
- (id)init;

- (void)startTrackingWithLocation:(CLLocationCoordinate2D)location andSize:(CGSize)deviceScreenSize;
- (void)stopTracking;

- (CGRect)getCurrentFramePosition;
- (int)getCurrentHeading;
- (int)getARObjectXPosition:(ARObject*)arObject;

@end
