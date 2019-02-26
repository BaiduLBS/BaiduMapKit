//
//  BMKBusLineSearchResult.h
//  BaiduMapAPI_Search
//
//  Created by DanielBey on 2019/1/23.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BMKRouteSearchType.h"

/// 公共交通路线查询结果类
@interface BMKBusLineResult : NSObject
/// 公交公司名称
@property (nonatomic, copy) NSString *busCompany;
/// 公交线路名称
@property (nonatomic, copy) NSString *busLineName;
/// 公交线路方向
@property (nonatomic, copy) NSString *busLineDirection;
/// 公交线路uid
@property (nonatomic, copy) NSString *uid;
/// 公交路线首班车时间
@property (nonatomic, copy) NSString *startTime;
/// 公交路线末班车时间
@property (nonatomic, copy) NSString *endTime;
/// 公交路线是否有月票
@property (nonatomic, assign) int isMonTicket;
/// 起步票价
@property (nonatomic, assign) CGFloat basicPrice;
/// 全程票价
@property (nonatomic, assign) CGFloat totalPrice;
/// 所有公交站点信息,成员类型为BMKBusStation
@property (nonatomic, copy) NSArray <BMKBusStation *> *busStations;
/// 公交路线分段信息，成员类型为BMKBusStep
@property (nonatomic, copy) NSArray <BMKBusStep *> *busSteps;
@end

