//
//  BMKWalkCycleNavigationDisplayOption.h
//  BaiduMapAPI_WalkNavi
//
//  Created by Xin,Qi on 2018/7/28.
//  Copyright © 2018 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "BMKWalkCycleDefine.h"
#import "BMKWalkNavigationNPCGuider.h"

/**
 步骑行导航定制化设置类。
 此类提供对步骑行导航页面元素和导航行为进行个性化定制的能力。
 */
@interface BMKWalkCycleNavigationDisplayOption : NSObject

/**
 导航页面右下角进入AR导航模式图标
 */
@property (nonatomic, strong) UIImage *walkARModeIcon;

/**
 导航页面右下角进入普通导航模式图标
 */
@property (nonatomic, strong) UIImage *walkNormalModeIcon;

/**
 是否支持结束导航自动弹窗提示，默认值为YES。
 */
@property (nonatomic, assign) BOOL supportEndPopup;

@end
