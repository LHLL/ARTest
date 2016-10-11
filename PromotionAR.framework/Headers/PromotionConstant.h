//
//  PromotionConstant.h
//  PromotionAR
//
//  Created by Xu, Jay on 10/10/16.
//  Copyright © 2016 Yijie. All rights reserved.
//

#ifndef PromotionConstant_h
#define PromotionConstant_h


#endif /* PromotionConstant_h */
#define RADAR_ON                YES

/**
 * MAX_NUMBER_OF_TRIES
 *
 * The number of times the system will try to do an asynchronous action before it gives up.
 *
 * This is especially relevant in the ARController, whenever the system tries to get
 * network or location updates.
 */
#define MAX_NUMBER_OF_TRIES     5


// -- Accelerometer -- //

#define kFilteringFactor        0.05    // Filtering of noise for the accelerometer


// -- Overlays & Container View -- //

#define AR_VIEW_TAG             042313  // Random number to tag the view that contains the overlays with

/**
 * VERTICAL_SENS
 * The vertical sensitivity of the overlays --> How fast they move up & down with the accelerometer data
 */
#define VERTICAL_SENS           960

/**
 * HORIZ_SENS
 * Counterpart of the VERTICAL_SENS --> How fast they move left & right with the accelerometer data
 */
#define HORIZ_SENS              14

/**
 * OVERLAY_VIEW_WIDTH
 * The size of the view that contains the ar overlays, to simulate 360 view
 */
#define OVERLAY_VIEW_WIDTH      350*HORIZ_SENS

#define X_CENTER                160     // Vertical center value to use to position the overlays
#define Y_CENTER                170     // Horizontal center value to use to position the overlays

#define DEF_SCREEN_WIDTH        320.0
#define DEF_SCREEN_HEIGHT       460.0


// -- MATH -- //
// Some of the values below may seem redundant but they do in fact remove overhead floating-point calculations

/**
 * inc_avg
 * Average of the new inclination with the previous --> Rudimentary padding mechanism
 */
#define inc_avg(x)              (x+currentInclination)/2

#define max(x,y)                (x > y ? x : y)
#define min(x,y)                (x < y ? x : y)

#define METERS_TO_MILES         0.00062
#define POINT_ONE_MILE_METERS   161
#define METERS_TO_FEET          3.28084
#define lat_over_lon            1.33975031663

#define DEGREES( radians )      ((radians)*180/M_PI)
