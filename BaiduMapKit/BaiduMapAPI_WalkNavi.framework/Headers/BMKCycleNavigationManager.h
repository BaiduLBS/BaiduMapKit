//
//  BMKCycleNaviHelper.h
//  CycleComponent
//
//  Created by Xin,Qi on 24/01/2018.
//  Copyright © 2018 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "BMKWalkCycleNavigationDelegates.h"

#import "BMKWalkCycleDefine.h"
#import "BMKCycleNaviLaunchParam.h"
#import "BMKWalkCycleNavigationDisplayOption.h"

#pragma mark - 骑行导航控制器类
/**
 骑行导航控制器类
 */
@interface BMKCycleNavigationManager : NSObject

/**
 算路代理回调
 */
@property (nonatomic, weak) id <BMKWalkCycleRoutePlanDelegate> routePlanDelegate;

/**
 导航状态信息回调
 */
@property (nonatomic, weak) id <BMKWalkCycleRouteGuidanceDelegate> routeGuidanceDelegate;

/**
 语言播报文本回调
 */
@property (nonatomic, weak) id <BMKWalkCycleTTSPlayerDelegate> ttsPlayerDelegate;

/**
 单例全局访问点
 
 @return BMKCycleNavigationManager单例对象
 */
+ (instancetype)sharedManager;

/**
 销毁单例
 */
+ (void)destroy;

/**
 初始化引擎

 @param controller 目的导航控制器
 @param option 设置导航定制化参数。
 @return 引擎初始化结果
 */
- (BOOL)initNaviEngine:(UIViewController *)controller option:(BMKWalkCycleNavigationDisplayOption *)option;

/**
 发起算路
 
 @param parameter 骑行导航起终点参数类
 */
- (void)routePlanWithParams:(BMKCycleNaviLaunchParam *)parameter;

/**
 导航过程生命周期函数, 开始导航

 @return 开始导航结果
 */
- (BOOL)startCycleNavi;

/**
 导航过程生命周期函数, 暂停导航
 */
- (void)pause;

/**
 导航过程生命周期函数, 恢复导航
 */
- (void)resume;

/**
 导航过程生命周期函数, 结束导航
 */
- (void)stop;

@end
