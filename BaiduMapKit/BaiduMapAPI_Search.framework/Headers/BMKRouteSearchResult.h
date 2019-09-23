//
//  BMKRouteSearchResult.h
//  BaiduMapAPI_Search
//
//  Created by DanielBey on 2019/1/23.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BMKRouteSearchType.h"

/// 步行路线规划结果类
@interface BMKWalkingRouteResult : NSObject
/// 该路线打车信息
@property (nonatomic, strong) BMKTaxiInfo *taxiInfo __deprecated_msg("预留字段，现为空");
/// 返回起点或终点的地址信息结果
@property (nonatomic, strong) BMKSuggestAddrInfo *suggestAddrResult;
/// 步行结果,现在只返回一条。成员类型为BMKWalkingRouteLine
@property (nonatomic, copy) NSArray <BMKWalkingRouteLine *> *routes;
@end


/// 驾车路线规划结果类
@interface BMKDrivingRouteResult : NSObject
/// 该路线打车信息
@property (nonatomic, strong) BMKTaxiInfo *taxiInfo __deprecated_msg("预留字段，现为空");
/// 返回起点或终点的地址信息结果
@property (nonatomic, strong) BMKSuggestAddrInfo *suggestAddrResult;
/// 驾车结果,支持多路线。成员类型为BMKDrivingRouteLine
@property (nonatomic, copy) NSArray <BMKDrivingRouteLine *> *routes;
@end

/// 公交路线规划结果类
@interface BMKTransitRouteResult : NSObject
/// 该路线打车信息
@property (nonatomic, strong) BMKTaxiInfo *taxiInfo;
/// 返回起点或终点的地址信息结果
@property (nonatomic, strong) BMKSuggestAddrInfo *suggestAddrResult;
/// 方案数组,成员类型为BMKTransitRouteLine
@property (nonatomic, copy) NSArray <BMKTransitRouteLine *> *routes;
@end


/// 跨城路线规划结果类
@interface BMKMassTransitRouteResult : NSObject
/// 返回起点或终点的地址信息结果
@property (nonatomic, strong) BMKSuggestAddrInfo *suggestAddrResult;
/// 方案数组,成员类型为BMKMassTransitRouteLine
@property (nonatomic, copy) NSArray <BMKMassTransitRouteLine *> *routes;
/// 总方案数
@property (nonatomic, assign) NSInteger totalRoutes;
/// 该路线打车信息(只有起终点是大陆地区且是同城的请求时才返回此字段, 否则此字段为nil)
@property (nonatomic, strong) BMKTaxiInfo *taxiInfo;
@end


/// 骑行路线规划结果类
@interface BMKRidingRouteResult : NSObject
/// 返回起点或终点的地址信息结果
@property (nonatomic, strong) BMKSuggestAddrInfo *suggestAddrResult;
/// 骑行路线结果,成员类型为BMKRidingRouteLine
@property (nonatomic, copy) NSArray <BMKRidingRouteLine *> *routes;
@end


/// 室内路线规划结果类
@interface BMKIndoorRouteResult : NSObject
/// 方案数组,成员类型为BMKIndoorRouteLine
@property (nonatomic, copy) NSArray <BMKIndoorRouteLine *> *routes;
@end
