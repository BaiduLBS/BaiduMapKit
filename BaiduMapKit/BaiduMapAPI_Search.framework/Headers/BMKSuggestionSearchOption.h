/*
 *  BMKSuggestionSearchOption.h
 *  BMapKit
 *
 *  Copyright 2014 Baidu Inc. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/// sug检索信息类
@interface BMKSuggestionSearchOption : NSObject

/// 搜索关键字，必选
@property (nonatomic, copy) NSString *keyword;
/// 城市名，参数也可以传入citycode，必选
@property (nonatomic, copy) NSString *cityname;
/// 指定位置，可选，注：会影响关键字不在设置城市范围内时的检索结果，故不建议使用。
@property (nonatomic, assign) CLLocationCoordinate2D location;
/// 是否只返回指定城市检索结果（默认：NO）（提示：海外区域暂不支持设置cityLimit）
@property (nonatomic, assign) BOOL cityLimit;

@end


