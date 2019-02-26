/*
 *  BMKBusLineSearchOption.h
 *  BMapKit
 *
 *  Copyright 2014 Baidu Inc. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
/// 公交线路检索信息类
@interface BMKBusLineSearchOption : NSObject
/// 城市名
@property (nonatomic, copy) NSString *city;
/// 公交线路的uid
@property (nonatomic, copy) NSString *busLineUid;

@end

