//
//  ARObject.h
//  PromotionAR
//
//  Created by Xu, Jay on 10/10/16.
//  Copyright © 2016 Yijie. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

#import "PromotionConstant.h"

@protocol TouchDelegate

@optional

- (void)didTouchTheIcon;

@end

@interface ARObject : UIViewController<TouchDelegate>
{
    
    // ARObject main components
    NSString *arTitle;
    
    int arId;
    double lat;
    double lon;
    NSNumber *distance;
    
    // Overlay View Objects
    IBOutlet UILabel *titleL;
    IBOutlet UILabel *distanceL;
    IBOutlet UIImageView *backgroundImageView;
    IBOutlet UIImageView *foregroundImageView;
    
}

@property (nonatomic, strong) NSString *arTitle;
@property (nonatomic, strong) NSNumber *distance;
@property (nonatomic, weak) id<TouchDelegate> delegate;

- (id)initWithId:(int)newId
           title:(NSString*)newTitle
        delegate:(id)delegate
     coordinates:(CLLocationCoordinate2D)newCoordinates
andCurrentLocation:(CLLocationCoordinate2D)currLoc;

- (NSDictionary*)getARObjectData;

@end
