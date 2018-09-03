//
//  BMKWalkNavigationNPCGuider.h
//  BaiduMapAPI_WalkNavi
//
//  Created by Xin,Qi on 2018/7/31.
//  Copyright © 2018 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "BMKWalkCycleDefine.h"

/**
 步行AR导航3D模型引导员类，
 开发者自定义引导员时使用。
 */
@interface BMKWalkNavigationNPCGuider : NSObject

/**
 引导员名称
 */
@property (nonatomic, copy) NSString *name;

/**
 引导员占位图标，显示资源列表用
 */
@property (nonatomic, strong) UIImage *icon;

/**
 开发者提供的资源存放的路径
 */
@property (nonatomic, copy) NSString *guiderPath;

/**
 开发者提供的资源下载秘钥
 */
@property (nonatomic, copy) NSString *downloadKey;

/**
 '3D'引导员资源类型
 */
@property (nonatomic, assign) BMKWalkARGuiderResourceType resourceType;
/**
 生成3D引导员

 @param name 3D引导员的名字，不为nil。
 @param icon 3D引导员的图标。
 @param guiderPath 引导员资源所在本地地址。
 @return 引导员模型
 */
- (instancetype)initGuiderWithName:(NSString *)name itemIcon:(UIImage *)icon guiderPath:(NSString *)guiderPath;

/**
 生成3D引导员

 @param name 3D引导员的名字，不为nil。
 @param icon 3D引导员的图标。
 @param downloadKey 下载秘钥，由开发者上传3D模型到AR平台，并有AR平台下发下载秘钥。
 @return 引导员模型
 */
- (instancetype)initGuiderWithName:(NSString *)name itemIcon:(UIImage *)icon downloadKey:(NSString *)downloadKey;
    
@end

