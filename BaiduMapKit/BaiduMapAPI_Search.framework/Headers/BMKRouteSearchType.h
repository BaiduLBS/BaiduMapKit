/*
 *  BMKRouteSearchType.h
 *	BMapKit
 *
 *  Copyright 2011 Baidu Inc. All rights reserved.
 *
 */

#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>
#import "BMKPoiSearchType.h"
#import <BaiduMapAPI_Base/BMKTypes.h>

///路段类型枚举
typedef enum {
    BMK_BUSLINE                 = 0,///公交
	BMK_SUBWAY                  = 1,///地铁
 	BMK_WAKLING                 = 2,///步行
} BMKTransitStepType;


///交通方式枚举
typedef enum {
    BMK_TRANSIT_SUBWAY        = 0,///地铁
    BMK_TRANSIT_TRAIN         = 1,///火车
    BMK_TRANSIT_PLANE         = 2,///飞机
    BMK_TRANSIT_BUSLINE       = 3,///公交
    BMK_TRANSIT_DRIVING       = 4,///驾车
    BMK_TRANSIT_WAKLING       = 5,///步行
    BMK_TRANSIT_COACH         = 6,///大巴
} BMKMassTransitType;


///室内路线结点类型
typedef enum {
    BMK_INDOOR_STEP_NODE_TYPE_ELEVATOR        = 1,///直梯
    BMK_INDOOR_STEP_NODE_TYPE_ESCALATOR       = 2,///扶梯
    BMK_INDOOR_STEP_NODE_TYPE_STAIR           = 3,///楼梯
    BMK_INDOOR_STEP_NODE_TYPE_SECURITY_CHECK  = 4,///安检
} BMKIndoorStepNodeType;


typedef enum {
	BMK_TRANSIT_TIME_FIRST = 3,		//较快捷(公交)
	BMK_TRANSIT_TRANSFER_FIRST = 4,	//少换乘(公交)
	BMK_TRANSIT_WALK_FIRST = 5,		//少步行(公交)
	BMK_TRANSIT_NO_SUBWAY = 6,		//不坐地铁
} BMKTransitPolicy;


/// 公共交通：市内公交换乘策略
typedef enum {
    BMK_MASS_TRANSIT_INCITY_RECOMMEND         = 0,//推荐
    BMK_MASS_TRANSIT_INCITY_TRANSFER_FIRST    = 1,//少换乘
    BMK_MASS_TRANSIT_INCITY_WALK_FIRST        = 2,//少步行
    BMK_MASS_TRANSIT_INCITY_NO_SUBWAY         = 3,//不坐地铁
    BMK_MASS_TRANSIT_INCITY_TIME_FIRST        = 4,//较快捷
    BMK_MASS_TRANSIT_INCITY_SUBWAY_FIRST      = 5,//地铁优先
} BMKMassTransitIncityPolicy;


/// 公共交通：跨城公交换乘策略
typedef enum {
    BMK_MASS_TRANSIT_INTERCITY_TIME_FIRST    = 0,//较快捷
    BMK_MASS_TRANSIT_INTERCITY_START_EARLY   = 1,//出发早
    BMK_MASS_TRANSIT_INTERCITY_PRICE_FIRST   = 2,//价格低
} BMKMassTransitIntercityPolicy;


/// 公共交通：跨城交通方式策略
typedef enum {
    BMK_MASS_TRANSIT_INTERCITY_TRANS_TRAIN_FIRST    = 0,//火车优先
    BMK_MASS_TRANSIT_INTERCITY_TRANS_PLANE_FIRST    = 1,//飞机优先
    BMK_MASS_TRANSIT_INTERCITY_TRANS_BUS_FIRST      = 2,//大巴优先
} BMKMassTransitIntercityTransPolicy;


typedef enum {
    BMK_DRIVING_BLK_FIRST = -1, //躲避拥堵(自驾)
	BMK_DRIVING_TIME_FIRST = 0,	//最短时间(自驾)
	BMK_DRIVING_DIS_FIRST = 1,	//最短路程(自驾)
	BMK_DRIVING_FEE_FIRST,		//少走高速(自驾)
} BMKDrivingPolicy;



typedef enum {
    BMK_DRIVING_REQUEST_TRAFFICE_TYPE_NONE = 0,                 //不带路况
    BMK_DRIVING_REQUEST_TRAFFICE_TYPE_PATH_AND_TRAFFICE = 1,    //道路和路况
}BMKDrivingRequestTrafficType;


///打车信息类
@interface BMKTaxiInfo : NSObject
///路线打车描述信息
@property (nonatomic, copy) NSString *desc;
///总路程，单位： 米
@property (nonatomic, assign) int distance;
///总耗时，单位： 秒
@property (nonatomic, assign) int duration;
///每千米单价(白天)，单位 元
@property (nonatomic, assign) CGFloat perKMPrice;
///起步价(白天)，单位 元
@property (nonatomic, assign) CGFloat startPrice;
///总价(预估) , 单位： 元
@property (nonatomic, assign) int totalPrice;
@end


/// 路线换乘方案里的交通工具信息类
@interface BMKVehicleInfo : NSObject
/// 该交通路线的标识
@property (nonatomic, copy) NSString *uid;
/// 该交通路线的名称
@property (nonatomic, copy) NSString *title;
/// 该交通路线的所乘站数
@property (nonatomic, assign) int passStationNum;
/// 该交通路线的全程价格
@property (nonatomic, assign) int totalPrice;
/// 该交通路线的所乘区间的区间价格
@property (nonatomic, assign) int zonePrice;
@end


/// 此类代表一个时间段，每个属性都是一个时间段。
@interface BMKTime : NSObject
/// 时间段，单位（天）
@property (nonatomic, assign) int dates;
/// 时间段，单位（小时）
@property (nonatomic, assign) int hours;
/// 时间段，单位（分）
@property (nonatomic, assign) int minutes;
/// 时间段，单位（秒）
@property (nonatomic, assign) int seconds;
@end


/// 此类表示路线中的一节点，节点包括：路线起终点，公交站点等
@interface BMKRouteNode : NSObject
/// 该节点uid
@property (nonatomic, copy) NSString *uid;
/// 该节点的名称
@property (nonatomic, copy) NSString *title;
/// 该节点的坐标
@property (nonatomic, assign) CLLocationCoordinate2D location;
@end


/// 此类表示公交站点信息
@interface BMKBusStation : BMKRouteNode
@end


/// 此类表示路线中的一个路段（基类）
@interface BMKRouteStep : NSObject
/// 路段长度 单位： 米
@property (nonatomic, assign) int distance;
/// 路段耗时 单位： 秒
@property (nonatomic, assign) int duration;
/// 路段所经过的地理坐标集合
@property (nonatomic) BMKMapPoint *points;
/// 路段所经过的地理坐标集合内点的个数
@property (nonatomic, assign) int pointsCount;
@end


///此类表示公交线路中的一个路段
@interface BMKBusStep : BMKRouteStep
@end


/// 此类表示公交换乘路线中的一个路段
@interface BMKTransitStep : BMKRouteStep
/// 路段入口信息
@property (nonatomic, strong) BMKRouteNode *entrace;
/// 路段出口信息
@property (nonatomic, strong) BMKRouteNode *exit;
/// 路段换乘说明
@property (nonatomic, copy) NSString *instruction;
/// 路段类型
@property (nonatomic, assign) BMKTransitStepType stepType;
/// 当路段为公交路段或地铁路段时，可以获取交通工具信息
@property (nonatomic, strong) BMKVehicleInfo *vehicleInfo;
@end


/// 公共交通方案里的交通工具信息基类类
@interface BMKBaseVehicleInfo : NSObject
/// 该交通路线的名称
@property (nonatomic, copy) NSString *name;
/// 出发站
@property (nonatomic, copy) NSString *departureStation;
/// 到达站
@property (nonatomic, copy) NSString *arriveStation;
/// 出发时间(BMKBusVehicleInfo时departureTime为空)
@property (nonatomic, copy) NSString *departureTime;
/// 到达时间(BMKBusVehicleInfo时arriveTime为空)
@property (nonatomic, copy) NSString *arriveTime;
@end


/// 公共交通方案里的交通工具信息类- 公交车、地铁
@interface BMKBusVehicleInfo : BMKBaseVehicleInfo
/// 该交通路线的所乘站数
@property (nonatomic, assign) NSInteger passStationNum;
/// 始发车发车时间
@property (nonatomic, copy) NSString *firstTime;
/// 末班车发车时间
@property (nonatomic, copy) NSString *lastTime;
@end


/// 公共交通方案里的交通工具信息类 - 飞机
@interface BMKPlaneVehicleInfo : BMKBaseVehicleInfo
/// 价格（单位：元）
@property (nonatomic, assign) CGFloat price;
/// 折扣
@property (nonatomic, assign) CGFloat discount;
/// 航空公司
@property (nonatomic, copy) NSString *airlines;
/// 订票网址
@property (nonatomic, copy) NSString *bookingUrl;
@end


/// 公共交通方案里的交通工具信息类 - 火车
@interface BMKTrainVehicleInfo : BMKBaseVehicleInfo
/// 价格（单位：元）
@property (nonatomic, assign) CGFloat price;
/// 订票电话
@property (nonatomic, copy) NSString *booking;
@end

/// 公共交通方案里的交通工具信息类 - 大巴
@interface BMKCoachVehicleInfo : BMKBaseVehicleInfo
/// 价格（单位：元）
@property (nonatomic, assign) CGFloat price;
/// 订票网址
@property (nonatomic, copy) NSString *bookingUrl;
/// 合作方名称
@property (nonatomic, copy) NSString *providerName;
/// 合作方官网
@property (nonatomic, copy) NSString *providerUrl;
@end



@class BMKMassTransitSubStep;


/// 此类表示公共交通路线中的路段
@interface BMKMassTransitStep : NSObject
/// steps中是方案还是子路段，YES:steps是BMKMassTransitStep的子路段（A到B需要经过多个steps）;NO:steps是多个方案（A到B有多个方案选择）
@property (nonatomic, assign) BOOL isSubStep;
/// 本BMKMassTransitStep中的有几个方案或几个子路段，成员类型为BMKMassTransitSubStep
@property (nonatomic, copy) NSArray <BMKMassTransitSubStep *> *steps;
@end


/// 此类表示公共交通路线中的一个路段
@interface BMKMassTransitSubStep : BMKRouteStep
/// 路段入口经纬度
@property (nonatomic, assign) CLLocationCoordinate2D entraceCoor;
/// 路段出口经纬度
@property (nonatomic, assign) CLLocationCoordinate2D exitCoor;
/// 路段说明
@property (nonatomic, copy) NSString *instructions;
/// 路段类型
@property (nonatomic, assign) BMKMassTransitType stepType;
/// 该路段交通工具信息（当stepType为公交地铁时，BMKBusVehicleInfo对象；stepType为大巴时，BMKCoachVehicleInfo对象；stepType为飞机时，BMKPlaneVehicleInfo对象；stepType为火车时，BMKTrainVehicleInfo对象；其它为nil）
@property (nonatomic, strong) BMKBaseVehicleInfo *vehicleInfo;
@end


/// 此类表示驾车路线中的一个路段
@interface BMKDrivingStep : BMKRouteStep
/// 该路段起点方向值
@property (nonatomic, assign) int direction;
/// 路段入口信息
@property (nonatomic, strong) BMKRouteNode *entrace;
/// 路段入口的指示信息
@property (nonatomic, copy) NSString *entraceInstruction;
/// 路段出口信息
@property (nonatomic, strong) BMKRouteNode *exit;
/// 路段出口指示信息
@property (nonatomic, copy) NSString *exitInstruction;
/// 路段总体指示信息
@property (nonatomic, copy) NSString *instruction;
/// 路段需要转弯数
@property (nonatomic, assign) int numTurns;
/// 路段是否有路况信息
@property (nonatomic, assign) BOOL hasTrafficsInfo;
/// 路段的路况信息，成员为NSNumber。0：无数据；1：畅通；2：缓慢；3：拥堵
@property (nonatomic, copy) NSArray <NSNumber *> *traffics;
@end


///室内路线结点
@interface BMKIndoorStepNode : NSObject
/// 坐标
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;
/// 类型
@property (nonatomic, assign) BMKIndoorStepNodeType type;
/// 描述
@property (nonatomic, copy) NSString *desc;
@end


/// 此类表示室内路线的一个路段
@interface BMKIndoorRouteStep : BMKRouteStep
/// 入口信息
@property (nonatomic, strong) BMKRouteNode *entrace;
/// 出口信息
@property (nonatomic, strong) BMKRouteNode *exit;
/// 路段指示信息
@property (nonatomic, copy) NSString *instructions;
/// 建筑物id
@property (nonatomic, copy) NSString *buildingid;
/// 室内楼层id
@property (nonatomic, copy) NSString *floorid;
/// 结点数组，成员类型为：BMKIndoorStepNode
@property (nonatomic, copy) NSArray <BMKIndoorStepNode *> *indoorStepNodes;
@end


/// 此类表示步行路线中的一个路段
@interface BMKWalkingStep : BMKRouteStep
/// 该路段起点方向值
@property (nonatomic, assign) int direction;
/// 路段入口信息
@property (nonatomic, strong) BMKRouteNode *entrace;
/// 获取该路段入口指示信息
@property (nonatomic, copy) NSString *entraceInstruction;
/// 路段出口信息
@property (nonatomic, strong) BMKRouteNode *exit;
/// 获取该路段出口指示信息
@property (nonatomic, copy) NSString *exitInstruction;
/// 获取该路段指示信息
@property (nonatomic, copy) NSString *instruction;
@end


/// 此类表示骑行路线中的一个路段
@interface BMKRidingStep : BMKRouteStep
/// 该路段起点方向值
@property (nonatomic, assign) NSInteger direction;
/// 路段入口信息
@property (nonatomic, strong) BMKRouteNode *entrace;
/// 获取该路段入口指示信息
@property (nonatomic, copy) NSString *entraceInstruction;
/// 路段出口信息
@property (nonatomic, strong) BMKRouteNode *exit;
/// 获取该路段出口指示信息
@property (nonatomic, copy) NSString *exitInstruction;
/// 获取该路段指示信息
@property (nonatomic, copy) NSString *instruction;
@end


/// 此类表示路线数据结构的基类,表示一条路线，路线可能包括：路线规划中的换乘/驾车/步行路线
/// 此类为路线数据结构的基类，一般关注其子类对象即可，无需直接生成该类对象
@interface BMKRouteLine : NSObject
/// 路线长度 单位： 米
@property (nonatomic, assign) int distance;
/// 路线耗时 单位： 秒
@property (nonatomic, strong) BMKTime *duration;
/// 路线起点信息
@property (nonatomic, strong) BMKRouteNode *starting;
/// 路线终点信息
@property (nonatomic, strong) BMKRouteNode *terminal;
/// 路线名称(预留字段，现为空)
@property (nonatomic, copy) NSString *title;
/// 路线中的所有路段，成员类型为BMKWalkingStep，BMKDrivingStep，BMKTransitStep，BMKRidingStep，BMKIndoorRouteStep，BMKMassTransitStep
@property (nonatomic, copy) NSArray *steps;
@end


///此类表示一个换乘路线，换乘路线将根据既定策略调配多种交通工具
@interface BMKTransitRouteLine : BMKRouteLine
@end


/// 此类表示一条公共交通路线
@interface BMKMassTransitRouteLine : BMKRouteLine
/// 路线花费
@property (nonatomic, assign) CGFloat price;
@end


/// 此类表示一个室内路线
@interface BMKIndoorRouteLine : BMKRouteLine
@end


/// 此类表示一条驾车路线
@interface BMKDrivingRouteLine : BMKRouteLine
/// 该路线所在区域是否含有交通流量信息，从2.7.0开始，废弃
@property (nonatomic, assign) BOOL isSupportTraffic;
/// 路线途经点列表，成员类型为BMKPlanNode
@property (nonatomic, copy) NSArray <BMKPlanNode *> *wayPoints;
/// 路线红绿灯个数
@property (nonatomic, assign) NSInteger lightNum;
/// 路线拥堵米数，发起请求时需设置参数 drivingRequestTrafficType = BMK_DRIVING_REQUEST_TRAFFICE_TYPE_PATH_AND_TRAFFICE 才有值
@property (nonatomic, assign) NSInteger congestionMetres;
/// 路线预估打车费(元)，负数表示无打车费信息
@property (nonatomic, assign) NSInteger taxiFares;
@end

/// 此类表示一条步行路线
@interface BMKWalkingRouteLine : BMKRouteLine
@end

/// 此类表示一条骑行路线
@interface BMKRidingRouteLine : BMKRouteLine
@end

/// 路线搜索地址结果类.当输入的起点或终点有多个地点选择时，或者选定的城市没有此地点，但其它城市有(驾乘或步行)，返回该类的实例
@class BMKCityListInfo;
@interface BMKSuggestAddrInfo : NSObject
/// 起点POI列表，成员类型为BMKPoiInfo
@property (nonatomic, copy) NSArray <BMKPoiInfo *> *startPoiList;
/// 起点城市列表，成员类型为BMKCityListInfo,如果输入的地点在本城市没有而在其它城市有，则返回其它城市的信息
@property (nonatomic, copy) NSArray <BMKCityListInfo *> *startCityList;
/// 终点POI列表，成员类型为BMKPoiInfo
@property (nonatomic, copy) NSArray <BMKPoiInfo *> *endPoiList;
/// 终点城市列表，成员类型为BMKCityListInfo,如果输入的地点在本城市没有而在其它城市有，则返回其它城市的信息
@property (nonatomic, copy) NSArray <BMKCityListInfo *> *endCityList;
/// 途经点POI列表，成员类型为NSArray<BMKPoiInfo*>
@property (nonatomic, copy) NSArray <NSArray<BMKPoiInfo *> *> *wayPointPoiList;
/// 途经点城市列表，成员类型为NSArray<BMKCityListInfo*>,如果输入的地点在本城市没有而在其它城市有，则返回其它城市的信息
@property (nonatomic, copy) NSArray <NSArray<BMKCityListInfo *> *> *wayPointCityList;
@end

#pragma mark - 城市列表信息类
/// 城市列表信息类
@interface BMKCityListInfo : NSObject
/// 城市名称
@property (nonatomic, copy) NSString *city;
/// 该城市所含搜索结果数目
@property (nonatomic, assign) NSInteger num;

@end
