//
//  BMKWalkNavigationNPCOption.h
//  BaiduMapAPI_WalkNavi
//
//  Created by Xin,Qi on 2018/7/31.
//  Copyright © 2018 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BMKWalkNavigationNPCGuider.h"

typedef void(^BMKWalkOpenGuidersListCallback)(NSArray <BMKWalkNavigationNPCGuider *> *guiders);

@interface BMKWalkNavigationNPCOption : NSObject

/**
 自定义的'3D'引导员资源
 */
@property (nonatomic, strong) NSArray <BMKWalkNavigationNPCGuider *> * customGuiders;

/**
 当点击导航页面引导员图标时，会触发本回调，
 本回调可用于点击引导员按钮展示引导员列表。
 */
@property (nonatomic, copy) BMKWalkOpenGuidersListCallback openGuidersCallback;

/**
 是否采用默认展示3D模型资源，默认值为YES
 如果设置为NO，有开发者自行展示相关视图。
 */
//@property (nonatomic, assign) BOOL supportListView;

@end
