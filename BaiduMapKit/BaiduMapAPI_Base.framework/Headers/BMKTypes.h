//
//  BMKType.h
//  MapPlatform
//
//  Created by BaiduMapAPI on 13-3-26.
//  Copyright (c) 2013年 baidu. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

#ifndef BMKType_h
#define BMKType_h
//地图模块枚举
typedef enum {
    BMKMapModuleTile = 0,   //瓦片图模块
} BMKMapModule;


/**
 坐标类型

 - BMK_COORDTYPE_GPS: GPS设备采集的原始GPS坐标（WGS-84）
 - BMK_COORDTYPE_COMMON: GCJ坐标，google地图、soso地图、aliyun地图、mapabc地图和amap地图所用坐标
 - BMK_COORDTYPE_BD09LL: 百度经纬度坐标
 */
typedef NS_ENUM(NSUInteger, BMK_COORD_TYPE) {
    BMK_COORDTYPE_GPS = 0,
    BMK_COORDTYPE_COMMON,
    BMK_COORDTYPE_BD09LL,
};

/**
 底图展示的地图类型

 - BMKMapTypeNone: 空白地图
 - BMKMapTypeStandard: 标准地图
 - BMKMapTypeSatellite: 卫星地图
 */
typedef NS_ENUM(NSUInteger, BMKMapType) {
    BMKMapTypeNone = 0,
    BMKMapTypeStandard = 1,
    BMKMapTypeSatellite = 2,
};


typedef enum {
	BMKErrorOk = 0,	///< 正确，无错误
    BMKErrorConnect = 2,	///< 网络连接错误
	BMKErrorData = 3,	///< 数据错误
	BMKErrorRouteAddr = 4, ///<起点或终点选择(有歧义)
	BMKErrorResultNotFound = 100,	///< 搜索结果未找到
	BMKErrorLocationFailed = 200,	///< 定位失败
	BMKErrorPermissionCheckFailure = 300,	///< 百度地图API授权Key验证失败
	BMKErrorParse = 310		///< 数据解析失败
}BMKErrorCode;
//鉴权结果状态码
typedef enum {
    E_PERMISSIONCHECK_CONNECT_ERROR = -300,//链接服务器错误
    E_PERMISSIONCHECK_DATA_ERROR = -200,//服务返回数据异常
    E_PERMISSIONCHECK_OK = 0,	// 授权验证通过
	E_PERMISSIONCHECK_KEY_ERROR = 101,	//ak不存在
	E_PERMISSIONCHECK_MCODE_ERROR = 102,	//mcode签名值不正确
	E_PERMISSIONCHECK_UID_KEY_ERROR = 200,	// APP不存在，AK有误请检查再重试
	E_PERMISSIONCHECK_KEY_FORBIDEN = 201,	// APP被用户自己禁用，请在控制台解禁
    E_PERMISSIONCHECK_KEY_DENY_BY_SERVER = 202, // APP被服务端管理员删除
    E_PERMISSIONCHECK_USER_DENY_BY_SERVER = 252, // 用户被服务端管理员删除
    /*
     *更多鉴权状态码请参考：
     *http://lbsyun.baidu.com/index.php?title=webapi/appendix
     */
}BMKPermissionCheckResultCode;

//检索结果状态码
typedef enum{
    BMK_SEARCH_NO_ERROR = 0,///<检索结果正常返回
    BMK_SEARCH_AMBIGUOUS_KEYWORD,///<检索词有岐义
    BMK_SEARCH_AMBIGUOUS_ROURE_ADDR,///<检索地址有岐义
    BMK_SEARCH_NOT_SUPPORT_BUS,///<该城市不支持公交搜索
    BMK_SEARCH_NOT_SUPPORT_BUS_2CITY,///<不支持跨城市公交
    BMK_SEARCH_RESULT_NOT_FOUND,///<没有找到检索结果
    BMK_SEARCH_ST_EN_TOO_NEAR,///<起终点太近
    BMK_SEARCH_KEY_ERROR,///<key错误
    BMK_SEARCH_NETWOKR_ERROR,///网络连接错误
    BMK_SEARCH_NETWOKR_TIMEOUT,///网络连接超时
    BMK_SEARCH_PERMISSION_UNFINISHED,///还未完成鉴权，请在鉴权通过后重试
    BMK_SEARCH_INDOOR_ID_ERROR,///室内图ID错误
    BMK_SEARCH_FLOOR_ERROR,///室内图检索楼层错误
    BMK_SEARCH_INDOOR_ROUTE_NO_IN_BUILDING,///起终点不在支持室内路线的室内图内
    BMK_SEARCH_INDOOR_ROUTE_NO_IN_SAME_BUILDING,///起终点不在同一个室内
    BMK_SEARCH_PARAMETER_ERROR,///参数错误
    BMK_SEARCH_SERVER_ERROR,//服务器错误
}BMKSearchErrorCode;

//调起百度地图结果状态码
typedef enum{
    BMK_OPEN_NO_ERROR = 0,///<正常
    BMK_OPEN_WEB_MAP,///打开的是web地图
    BMK_OPEN_OPTION_NULL,///<传入的参数为空
    BMK_OPEN_NOT_SUPPORT,///<没有安装百度地图，或者版本太低
    BMK_OPEN_POI_DETAIL_UID_NULL,///<poi详情 poiUid为空
    BMK_OPEN_POI_NEARBY_KEYWORD_NULL,///<poi周边 keyWord为空
    BMK_OPEN_ROUTE_START_ERROR,///<路线起点有误
    BMK_OPEN_ROUTE_END_ERROR,///<路线终点有误
    BMK_OPEN_PANORAMA_UID_ERROR,///<调起全景 poiUid不正确
    BMK_OPEN_PANORAMA_ABSENT,///<调起全景 此处不支持全景
    BMK_OPEN_PERMISSION_UNFINISHED,///还未完成鉴权，请在鉴权通过后重试
    BMK_OPEN_KEY_ERROR,///<app key错误
    BMK_OPEN_NETWOKR_ERROR,///网络连接错误
}BMKOpenErrorCode;

/// 表示一个经纬度范围
typedef struct {
    CLLocationDegrees latitudeDelta; /// 纬度范围
    CLLocationDegrees longitudeDelta; /// 经度范围
} BMKCoordinateSpan;

/**
 构造BMKCoordinateSpan对象

 @param latitudeDelta 纬度范围
 @param longitudeDelta 经度范围
 @return 根据指定参数生成的BMKCoordinateSpan对象
 */
UIKIT_STATIC_INLINE BMKCoordinateSpan BMKCoordinateSpanMake(CLLocationDegrees latitudeDelta, CLLocationDegrees longitudeDelta) {
    BMKCoordinateSpan span;
    span.latitudeDelta = latitudeDelta;
    span.longitudeDelta = longitudeDelta;
    return span;
}

///表示一个经纬度区域
typedef struct {
    CLLocationCoordinate2D northEast; /// 东北角点经纬度坐标
    CLLocationCoordinate2D southWest; /// 西南角点经纬度坐标
} BMKCoordinateBounds;


///表示一个经纬度区域
typedef struct {
	CLLocationCoordinate2D center; /// 中心点经纬度坐标
	BMKCoordinateSpan span; /// 经纬度范围
} BMKCoordinateRegion;

/**
 *构造BMKCoordinateRegion对象
 *@param centerCoordinate 中心点经纬度坐标
 *@param span 经纬度的范围
 *@return 根据指定参数生成的BMKCoordinateRegion对象
 */
UIKIT_STATIC_INLINE BMKCoordinateRegion BMKCoordinateRegionMake(CLLocationCoordinate2D centerCoordinate, BMKCoordinateSpan span) {
    BMKCoordinateRegion region;
    region.center = centerCoordinate;
    region.span = span;
    return region;
}

///表示一个经纬度坐标点
typedef struct {
	int latitudeE6;		///< 纬度，乘以1e6之后的值
	int longitudeE6;	///< 经度，乘以1e6之后的值
} BMKGeoPoint;

/// 地理坐标点，用直角地理坐标表示
typedef struct {
    double x; /// 横坐标
    double y; /// 纵坐标
} BMKMapPoint;

/**
 构造BMKMapPoint对象

 @param x 水平方向坐标值
 @param y 垂直方向坐标值
 @return 根据指定参数生成的BMKMapPoint对象
 */
UIKIT_STATIC_INLINE BMKMapPoint BMKMapPointMake(double x, double y) {
    return (BMKMapPoint){x, y};
}

/// 矩形大小，用直角地理坐标表示
typedef struct {
    double width; /// 宽度
    double height; /// 高度
} BMKMapSize;

/**
 构造BMKMapSize对象

 @param width 宽度
 @param height 高度
 @return 根据指定参数生成的BMKMapSize对象
 */
UIKIT_STATIC_INLINE BMKMapSize BMKMapSizeMake(double width, double height) {
    return (BMKMapSize){width, height};
}

/// 矩形，用直角地理坐标表示
typedef struct {
    BMKMapPoint origin; /// 屏幕左上点对应的直角地理坐标
    BMKMapSize size; /// 坐标范围
} BMKMapRect;

/**
 构造BMKMapRect对象

 @param x 矩形左上顶点的x坐标值
 @param y 矩形左上顶点的y坐标值
 @param width 矩形宽度
 @param height 矩形高度
 @return 根据指定参数生成的BMKMapRect对象
 */
UIKIT_STATIC_INLINE BMKMapRect BMKMapRectMake(double x, double y, double width, double height) {
    return (BMKMapRect){ BMKMapPointMake(x, y), BMKMapSizeMake(width, height)};
}

/**
 判断指定矩形是否为NULL

 @param rect BMKMapRect矩形对象
 @return 如果矩形为NULL，返回YES，否则返回NO
 */
UIKIT_STATIC_INLINE BOOL BMKMapRectIsNull(BMKMapRect rect) {
    return isinf(rect.origin.x) || isinf(rect.origin.y);
}


/**
 获取指定矩形的x轴坐标最小值
 @param rect 指定的矩形
 @return x轴坐标最小值
 */
UIKIT_STATIC_INLINE double BMKMapRectGetMinX(BMKMapRect rect) {
    return rect.origin.x;
}

/**
 获取指定矩形的y轴坐标最小值
 @param rect 指定的矩形
 @return y轴坐标最小值
 */
UIKIT_STATIC_INLINE double BMKMapRectGetMinY(BMKMapRect rect) {
    return rect.origin.y;
}

/**
 获取指定矩形在x轴中点的坐标值
 @param rect 指定的矩形
 @return x轴中点的坐标值
 */
UIKIT_STATIC_INLINE double BMKMapRectGetMidX(BMKMapRect rect) {
    return rect.origin.x + rect.size.width / 2.0;
}

/**
 获取指定矩形在y轴中点的坐标值
 @param rect 指定的矩形
 @return y轴中点的坐标值
 */
UIKIT_STATIC_INLINE double BMKMapRectGetMidY(BMKMapRect rect) {
    return rect.origin.y + rect.size.height / 2.0;
}

/**
 获取指定矩形的x轴坐标最大值
 @param rect 指定的矩形
 @return x轴坐标最大值
 */
UIKIT_STATIC_INLINE double BMKMapRectGetMaxX(BMKMapRect rect) {
    return rect.origin.x + rect.size.width;
}

/**
 获取指定矩形的y轴坐标最大值
 @param rect 指定的矩形
 @return y轴坐标最大值
 */
UIKIT_STATIC_INLINE double BMKMapRectGetMaxY(BMKMapRect rect) {
    return rect.origin.y + rect.size.height;
}

///地图缩放比例
typedef CGFloat BMKZoomScale;

/// 经过投影后的世界范围大小，与经纬度（-85，180）投影后的坐标值对应
UIKIT_EXTERN const BMKMapSize BMKMapSizeWorld;
/// 经过投影后的世界矩形范围
UIKIT_EXTERN const BMKMapRect BMKMapRectWorld;
/// 空的直角坐标矩形
UIKIT_EXTERN const BMKMapRect BMKMapRectNull;

/// 线路检索节点信息,一个路线检索节点可以通过经纬度坐标或城市名加地名确定
@interface BMKPlanNode : NSObject
/// 节点所在城市
@property (nonatomic, copy) NSString *cityName;
/// 节点所在城市ID
@property (nonatomic, assign) NSInteger cityID;
/// 节点名称
@property (nonatomic, copy) NSString *name;
/// 节点坐标
@property (nonatomic, assign) CLLocationCoordinate2D pt;
@end

/// 室内路线检索节点信息
@interface BMKIndoorPlanNode : NSObject
/// 节点所在楼层
@property (nonatomic, copy) NSString *floor;
/// 节点坐标
@property (nonatomic, assign) CLLocationCoordinate2D pt;
@end


///此类表示地址结果的层次化信息
@interface BMKAddressComponent : NSObject
// 国家
@property (nonatomic, copy) NSString *country;
// 省份名称
@property (nonatomic, copy) NSString *province;
// 城市名称
@property (nonatomic, copy) NSString *city;
// 区县名称
@property (nonatomic, copy) NSString *district;
// 乡镇
@property (nonatomic, copy) NSString *town;
// 街道名称
@property (nonatomic, copy) NSString *streetName;
// 街道号码
@property (nonatomic, copy) NSString *streetNumber;
/// 行政区域编码
@property (nonatomic, copy) NSString *adCode;
/// 国家代码
@property (nonatomic, copy) NSString *countryCode;
// 相对当前坐标点的方向，当有门牌号的时候返回数据
@property (nonatomic, copy) NSString *direction;
// 相对当前坐标点的距离，当有门牌号的时候返回数据
@property (nonatomic, copy) NSString *distance;
@end

#endif
