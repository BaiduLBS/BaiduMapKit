//
//  BMKCycleNaviLaunchParam.h
//  WalkCycleComponent
//
//  Created by Xin,Qi on 24/01/2018.
//  Copyright © 2018 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "BMKWalkCycleDefine.h"
/**
 算路起始点设置类
 */
@interface BMKCycleNaviLaunchParam : NSObject

/**
 算路起点
 */
@property (nonatomic, assign) CLLocationCoordinate2D startPoint;

/**
 算路终点
 */
@property (nonatomic, assign) CLLocationCoordinate2D endPoint;

/**
 骑行类型，分别为普通骑行，电动车骑行
 */
@property (nonatomic, assign) BMKWalkCycleNavigationType naviType;

@end
