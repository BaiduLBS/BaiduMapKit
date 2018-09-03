//
//  BMKWalkCycleVersion.h
//  WalkCycleComponent
//
//  Created by Xin,Qi on 2018/6/11.
//  Copyright © 2018 Baidu. All rights reserved.
//

#ifndef BMKWalkCycleVersion_h
#define BMKWalkCycleVersion_h

#import <UIKit/UIKit.h>

/**
 *重要：
 *其他组件的版本和WalkCycle组件的版本必须一致，否则不能正常使用
 */

/**
 *获取当前地图API WalkCycle组件 的版本号
 *return  返回当前API WalkCycle组件 的版本号
 */
UIKIT_EXTERN NSString* BMKGetMapApiWalkCycleComponentVersion();

/**
 *检查WalkCycle组件的版本号是否和base组件的版本号一致
 *return    版本号一致返回YES
 */
UIKIT_EXTERN BOOL BMKCheckWalkCycleComponentIsLegal();

#endif /* BMKWalkCycleVersion_h */
