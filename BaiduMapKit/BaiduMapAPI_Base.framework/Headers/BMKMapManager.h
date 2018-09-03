//
//  BMKMapManager.h
//  BaiduMapAPI_Base
//
//  Created by Daniel Bey on 2018年07月05日.
//  Copyright © 2018 Baidu. All rights reserved.
//

#import "BMKGeneralDelegate.h"
#import <UIKit/UIKit.h>
#import "BMKTypes.h"

///主引擎类
@interface BMKMapManager : NSObject

/**
 全局设置地图SDK与开发者交互时的坐标类型。不调用此方法时，
 
 设置此坐标类型意味着2个方面的约定：
 1. 地图SDK认为开发者传入的所有坐标均为此类型；
 2. 所有地图SDK返回给开发者的坐标均为此类型；

 地图SDK默认使用BD09LL（BMK_COORDTYPE_BD09LL）坐标。
 如需使用GCJ02坐标，传入参数值为BMK_COORDTYPE_COMMON即可。
 本方法不支持传入WGS84（BMK_COORDTYPE_GPS）坐标。
 
 @param coorType 地图SDK全局使用的坐标类型
 @return 设置成功返回YES，设置失败返回False
 */
+ (BOOL)setCoordinateTypeUsedInBaiduMapSDK:(BMK_COORD_TYPE)coorType;


/**
 获取地图SDK与开发者交互时使用的全局坐标类型

 @return 坐标类型
 */
+ (BMK_COORD_TYPE)getCoordinateTypeUsedInBaiduMapSDK;


/**
 打开某模块的日志，默认不打印日志
 debug时，建议打开，有利于调试程序；release时建议关闭
 @param enable 是否开启日志打印
 @param mapModule 开启哪个模块的日志
 */
+ (void)logEnable:(BOOL)enable module:(BMKMapModule)mapModule;


/**
 启动引擎，主要是进行鉴权并初始化引擎。鉴权结果通过BMKGeneralDelegate中的方法回调给开发者

 @param key AK
 @param delegate 回调对象
 @return 参数错误或引擎内部异常则返回NO；鉴权请求发送成功则返回YES
 */
- (BOOL)start:(NSString *)key generalDelegate:(id <BMKGeneralDelegate>)delegate;


/**
 获取所有在线服务消耗的发送流量，单位：字节

 @return 发送流量
 */
- (NSUInteger)getTotalSendFlaxLength;


/**
 获取所有在线服务消耗的接收流量，单位：字节

 @return 接收流量
 */
- (NSUInteger)getTotalRecvFlaxLength;

/**
 停止引擎
*/
- (BOOL)stop;

@end
