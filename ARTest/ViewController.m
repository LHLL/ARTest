//
//  ViewController.m
//  ARTest
//
//  Created by Xu, Jay on 10/10/16.
//  Copyright © 2016 Yijie. All rights reserved.
//

#import "ViewController.h"
#import <PromotionAR/PromotionManager.h>
#import <PromotionAR/ARRadar.h>
#include <stdlib.h>

#define NUMBER_OF_POINTS    20

@interface ViewController ()<ManagerDelegate>
@property (nonatomic, strong) PromotionManager *manager;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.manager = [[PromotionManager alloc]initWithSize:self.view.frame.size delegate:self showRadar:YES];
}

- (void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:YES];
    CLLocationCoordinate2D locationCoordinates = CLLocationCoordinate2DMake(0, 0);
    
    [self.manager startARWithData:[self fuckingStupidFakeCounterfeitData] forLocation:locationCoordinates];

}

#pragma mark Fucking Stupid Fake Data
- (NSArray *)fuckingStupidFakeCounterfeitData {
    NSMutableArray *points = [NSMutableArray arrayWithCapacity:NUMBER_OF_POINTS];
    
    srand48(time(0));
    for (int i=0; i<NUMBER_OF_POINTS; i++)
    {
        CLLocationCoordinate2D pointCoordinates = [self getRandomLocation];
        NSDictionary *point = [self createPointWithId:i at:pointCoordinates];
        [points addObject:point];
    }
    
    return [NSArray arrayWithArray:points];
}

-(CLLocationCoordinate2D)getRandomLocation {
    double latRand = drand48() * 90.0;
    double lonRand = drand48() * 180.0;
    double latSign = drand48();
    double lonSign = drand48();
    
    CLLocationCoordinate2D locCoordinates = CLLocationCoordinate2DMake(latSign > 0.5 ? latRand : -latRand,
                                                                       lonSign > 0.5 ? lonRand*2 : -lonRand*2);
    return locCoordinates;
}

// Creates the Data for an AR Object at a given location
-(NSDictionary*)createPointWithId:(int)the_id at:(CLLocationCoordinate2D)locCoordinates {
    NSDictionary *point = @{
                            @"id" : @(the_id),
                            @"title" : [NSString stringWithFormat:@"Place Num %d", the_id],
                            @"lon" : @(locCoordinates.longitude),
                            @"lat" : @(locCoordinates.latitude)
                            };
    return point;
}

#pragma mark PromotionManager
- (void)didSetupAR:(UIView *)arView withCameraLayer:(AVCaptureVideoPreviewLayer *)cameraLayer andRadarView:(UIView *)radar {
    [self.view.layer addSublayer:cameraLayer];
    [self.view addSubview:arView];
    
    [self.view bringSubviewToFront:[self.view viewWithTag:AR_VIEW_TAG]];
    
    [self.view addSubview:radar];
}

- (void)shouldUpdateFrame:(CGRect)arViewFrame {
    [[self.view viewWithTag:AR_VIEW_TAG] setFrame:arViewFrame];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
