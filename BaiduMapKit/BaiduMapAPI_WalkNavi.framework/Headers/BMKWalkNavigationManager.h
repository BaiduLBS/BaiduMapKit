//
//  BMKWalkNaviHelper.h
//  WalkCycleComponent
//
//  Created by Xin,Qi on 24/01/2018.
//  Copyright © 2018 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "BMKWalkCycleNavigationDelegates.h"
#import "BMKWalkNaviLaunchParam.h"
#import "BMKWalkCycleNavigationDisplayOption.h"
#import "BMKWalkNavigationNPCOption.h"

#pragma mark - 步行导航控制器类
/**
 步行导航控制器类
 */
@interface BMKWalkNavigationManager : NSObject

/**
 算路代理回调
 */
@property (nonatomic, weak) id <BMKWalkCycleRoutePlanDelegate> routePlanDelegate;

/**
 导航状态信息回调
 */
@property (nonatomic, weak) id <BMKWalkCycleRouteGuidanceDelegate> routeGuidanceDelegate;

/**
 语音播报文本回调
 */
@property (nonatomic, weak) id <BMKWalkCycleTTSPlayerDelegate> ttsPlayerDelegate;

/**
 单例全局访问点
 
 @return BMKWalkNavigationManager单例对象。
 */
+ (instancetype)sharedManager;

/**
 销毁单例
 */
+ (void)destroy;

/**
 初始化引擎 方法一

 @param controller 导航页面，由开发者提供。
 @return 引擎初始化结果。
 */
- (BOOL)initNaviEngine:(UIViewController *)controller;

/**
 初始化引擎 方法二

 @param controller 导航页面，由开发者提供。
 @param displayOption 导航定制化展示相关参数。
 @param npcOption NPC（AR导航'3D'引导员）相关参数，如果不需要自定义AR3D引导员，可传nil,此参数设置为nil，将不显示打开导引员列表的按钮。
 @return 引擎初始化结果
 */
- (BOOL)initNaviEngine:(UIViewController *)controller
         displayOption:(BMKWalkCycleNavigationDisplayOption *)displayOption
             npcOption:(BMKWalkNavigationNPCOption *)npcOption;

/**
 发起算路
 
 @param parameter 步行导航起终点参数类。
 */
- (void)routePlanWithParams:(BMKWalkNaviLaunchParam *)parameter;

/**
 导航过程生命周期函数, 开始导航。
 选择模式的不同，加载导航页面不一样，分为普通步行和AR步行两种模式。
 @param navigationMode 步行导航模式。
 @return 开始导航结果
 */
- (BOOL)startWalkNavi:(BMKWalkNavigationMode)navigationMode;

/**
 导航过程生命周期函数，暂停导航。
 */
- (void)pause;

/**
 导航过程生命周期函数，恢复导航。
 */
- (void)resume;

/**
 导航过程生命周期函数，结束导航。
 */
- (void)stop;

#pragma mark - 步行AR导航3D模型显示相关接口

/**
 获取所有可用'3D'引导员资源，其中包括开发者您提供的自定义引导员以及由步骑行导航组件提供图图引导员和经典模式。
 可用于自定义引导员选择列表。
 
 @return 所有可用引导员。
 */
- (NSArray <BMKWalkNavigationNPCGuider *> *)fetchAllAvailableGuiders;

/**
 加载显示指定的引导员

 @param guider 指定引导员。
 @return 返回设置结果。
 */
- (BOOL)showGuider:(BMKWalkNavigationNPCGuider *)guider;

@end
