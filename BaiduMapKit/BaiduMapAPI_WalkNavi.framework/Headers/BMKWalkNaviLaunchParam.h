//
//  BMKWalkNaviLaunchParam.h
//  WalkCycleComponent
//
//  Created by Xin,Qi on 24/01/2018.
//  Copyright © 2018 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
 算路起始点设置类
 */
@interface BMKWalkNaviLaunchParam : NSObject

/**
 算路起点
 */
@property (nonatomic, assign) CLLocationCoordinate2D startPoint;

/**
 算路终点
 */
@property (nonatomic, assign) CLLocationCoordinate2D endPoint;

@end
