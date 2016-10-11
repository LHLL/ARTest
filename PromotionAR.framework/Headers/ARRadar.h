//
//  ARRadar.h
//  PromotionAR
//
//  Created by Xu, Jay on 10/10/16.
//  Copyright © 2016 Yijie. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ARRadar : UIView
{
    UIImageView *radarMV;
    UIImageView *radarBars;
    NSMutableDictionary *theSpots;
}

- (id)initWithFrame:(CGRect)frame withSpots:(NSArray*)spots;

- (void)moveDots:(int)angle;

@end
