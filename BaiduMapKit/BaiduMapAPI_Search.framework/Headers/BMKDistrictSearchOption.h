//
//  BMKDistrictSearchOption.h
//  BaiduMapAPI_Search
//
//  Created by DanielBey on 2019/1/23.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 行政区域检索信息
@interface BMKDistrictSearchOption : NSObject
/// 城市名字（必须）
@property (nonatomic, copy) NSString *city;
/// 区县名字（可选）
@property (nonatomic, copy) NSString *district;
@end
