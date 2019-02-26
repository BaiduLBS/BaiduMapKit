//
//  BMKDistrictSearchResult.h
//  BaiduMapAPI_Search
//
//  Created by DanielBey on 2019/1/23.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/// 行政区域检索结果
@interface BMKDistrictResult : NSObject
/// 行政区域编码
@property (nonatomic, assign) NSInteger code;
/// 行政区域名称
@property (nonatomic, copy) NSString *name;
/// 行政区域中心点
@property (nonatomic, assign) CLLocationCoordinate2D center;
/// 行政区边界直角地理坐标点数据(NSString数组，字符串数据格式为: @"x,y;x,y")
@property (nonatomic, copy) NSArray<NSString *> *paths;
@end
