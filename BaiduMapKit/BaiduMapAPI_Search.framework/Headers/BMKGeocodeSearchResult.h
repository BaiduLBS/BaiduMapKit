//
//  BMKGeocodeSearchResult.h
//  SearchComponent
//
//  Created by Baidu on 2018年05月24日.
//  Copyright © 2018年 Baidu. All rights reserved.
//

#import <BaiduMapAPI_Base/BMKTypes.h>
#import "BMKPoiSearchType.h"

#pragma mark - RC检索结果类
/// 地址编码结果类
@interface BMKGeoCodeSearchResult : NSObject
/// 地址对应的经纬度坐标
@property (nonatomic, assign) CLLocationCoordinate2D location;
/// 是否是精准查找，1为精确查找，即准确打点，0为不精确，即模糊打点
@property (nonatomic, assign) NSInteger precise;
/**
 可信度，值范围0-100，数值越大，可信度越高，误差范围越小
 大于80误差小于100m，该字段仅作参考，返回结果准确度主要参考precise参数
 */
@property (nonatomic, assign) NSInteger confidence;
/// 地址类型，包含：UNKNOWN、国家、省、商圈、生活服务等等
@property (nonatomic, copy) NSString *level;

@end

#pragma mark - RGC检索结果归属区域面信息类
@interface BMKSearchRGCRegionInfo : NSObject
/// 请求坐标与所归属区域面的相对位置关系
@property (nonatomic, copy) NSString *regionDescription;
/// 归属区域面名称
@property (nonatomic, copy) NSString *regionName;
/// 归属区域面类型
@property (nonatomic, copy) NSString *regionTag;
/// 归属区域面唯一标识
@property (nonatomic, copy) NSString *regionUID;

@end

#pragma mark - RGC检索结果类
/// 反地理编码结果类
@interface BMKReverseGeoCodeSearchResult : NSObject
/// 地址坐标
@property (nonatomic, assign) CLLocationCoordinate2D location;
/// 地址名称
@property (nonatomic, copy) NSString *address;
/// 商圈名称
@property (nonatomic, copy) NSString *businessCircle;
/// 层次化地址信息
@property (nonatomic, strong) BMKAddressComponent *addressDetail;
/**
 可信度，值范围0-100，数值越大，可信度越高，误差范围越小
 大于80误差小于100m，该字段仅作参考，返回结果准确度主要参考precise参数
 */
@property (nonatomic, assign) NSInteger confidence;
/// 地址周边POI信息，成员类型为BMKPoiInfo
@property (nonatomic, copy) NSArray <BMKPoiInfo *> *poiList;
/// 地址所属区域面信息
@property (nonatomic, copy) NSArray <BMKSearchRGCRegionInfo *> *poiRegions;
/// 结合当前位置POI的语义化结果描述
@property (nonatomic, copy) NSString *sematicDescription;
/// 城市编码（此字段不再更新，建议使用addressDetail中的adCode）
@property (nonatomic, copy) NSString *cityCode __deprecated_msg("自4.1.0不再更新");

@end

