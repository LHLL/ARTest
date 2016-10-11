//
//  PromotionManager.h
//  PromotionAR
//
//  Created by Xu, Jay on 10/10/16.
//  Copyright © 2016 Yijie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

#import "ARRadar.h"
#import "ARController.h"
#import "PromotionConstant.h"

@class PromotionManager;

@protocol ManagerDelegate

@optional

- (void)shouldUpdateFrame:(CGRect)arViewFrame;
- (void)didSetupAR:(UIView *)arView withCameraLayer:(AVCaptureVideoPreviewLayer *)cameraLayer;
- (void)didSetupAR:(UIView *)arView withCameraLayer:(AVCaptureVideoPreviewLayer *)cameraLayer andRadarView:(UIView *)radar;
- (void)shouldThrowError:(NSString *)errorTitle withErrorMessage:(NSString *)message;

@end

@interface PromotionManager : NSObject
{
    AVCaptureSession *cameraSession;
    AVCaptureVideoPreviewLayer *cameraLayer;
    
    ARRadar *radar;
    BOOL radarOption;
    
    CGSize frameSize;
    UIView *arOverlaysContainerView;
    CADisplayLink *refreshTimer;
}

@property (nonatomic, strong) ARController *arController;
@property (weak, nonatomic) id <ManagerDelegate> delegate;

- (id)initWithSize:(CGSize)size delegate:(id)delegate showRadar:(BOOL)showRadar;

- (void)startARWithData:(NSArray*)arData forLocation:(CLLocationCoordinate2D)location;
- (void)stopAR;

@end
