/*  BMKGeometry.h
 *  BMapKit
 *
 *  Copyright 2011 Baidu Inc. All rights reserved.
 *
 */

#import <BaiduMapAPI_Base/BMKTypes.h>
#import <UIKit/UIKit.h>

/**
 *根据中心点和距离生成BMKCoordinateRegion
 *@param centerCoordinate 中心点坐标
 *@param latitudinalMeters 纬度方向的距离范围，单位：米
 *@param longitudinalMeters 经度方向的距离范围，单位：米
 *@return 根据中心点和距离生成BMKCoordinateRegion
 */
UIKIT_EXTERN BMKCoordinateRegion BMKCoordinateRegionMakeWithDistance(CLLocationCoordinate2D centerCoordinate, CLLocationDistance latitudinalMeters, CLLocationDistance longitudinalMeters);

/**
 *将经纬度坐标转换为投影后的直角地理坐标
 *@param coordinate 待转换的经纬度坐标
 *@return 转换后的直角地理坐标
 */
UIKIT_EXTERN BMKMapPoint BMKMapPointForCoordinate(CLLocationCoordinate2D coordinate);

/**
 *将投影后的直角地理坐标转换为经纬度坐标
 *@param mapPoint 投影后的直角地理坐标
 *@return 转换后的经纬度坐标
 */
UIKIT_EXTERN CLLocationCoordinate2D BMKCoordinateForMapPoint(BMKMapPoint mapPoint);

/**
 *计算在指定纬度下一个BMKMapPoint单位对应的米数
 *@param latitude 指定的纬度
 *@return 在指定纬度下一个BMKMapPoint单位对应的米数
 */
UIKIT_EXTERN CLLocationDistance BMKMetersPerMapPointAtLatitude(CLLocationDegrees latitude);

/**
 *计算在指定纬度下一米对应的MKMapPoint的单位数
 *@param latitude 指定的纬度
 *@return 在指定纬度下一米对应的MKMapPoint的单位数
 */
UIKIT_EXTERN double BMKMapPointsPerMeterAtLatitude(CLLocationDegrees latitude);

/**
 *计算指定两点之间的距离
 *@param a 第一个坐标点
 *@param b 第二个坐标点
 *@return 两点之间的距离，单位：米
 */
UIKIT_EXTERN CLLocationDistance BMKMetersBetweenMapPoints(BMKMapPoint a, BMKMapPoint b);

/**
 *获取指定矩形的宽度
 *@param rect 指定的矩形
 *@return 指定矩形的宽度
 */
UIKIT_STATIC_INLINE double BMKMapRectGetWidth(BMKMapRect rect) {
    return rect.size.width;
}

/**
 *获取指定矩形的高度
 *@param rect 指定的矩形
 *@return 指定矩形的高度
 */
UIKIT_STATIC_INLINE double BMKMapRectGetHeight(BMKMapRect rect) {
    return rect.size.height;
}

/**
 *判断两个点是否相等
 *@param point1 第一个点
 *@param point2 第二个点
 *@return 如果两点相等，返回YES，否则返回NO
 */
UIKIT_STATIC_INLINE BOOL BMKMapPointEqualToPoint(BMKMapPoint point1, BMKMapPoint point2) {
    return point1.x == point2.x && point1.y == point2.y;
}

/**
 *判断两个矩形范围是否相等
 *@param size1 范围1
 *@param size2 范围2
 *@return 如果相等，返回YES，否则返回NO
 */
UIKIT_STATIC_INLINE BOOL BMKMapSizeEqualToSize(BMKMapSize size1, BMKMapSize size2) {
    return size1.width == size2.width && size1.height == size2.height;
}

/**
 *判断两个矩形是否相等
 *@param rect1 矩形1
 *@param rect2 矩形2
 *@return 如果相等，返回YES，否则返回NO
 */
UIKIT_STATIC_INLINE BOOL BMKMapRectEqualToRect(BMKMapRect rect1, BMKMapRect rect2) {
    return 
    BMKMapPointEqualToPoint(rect1.origin, rect2.origin) &&
    BMKMapSizeEqualToSize(rect1.size, rect2.size);
}

/**
 *判断一个矩形是否为空矩形
 *@param rect 指定矩形
 *@return 如果矩形为空矩形，返回YES，否则返回NO
 */
UIKIT_STATIC_INLINE BOOL BMKMapRectIsEmpty(BMKMapRect rect) {
    return BMKMapRectIsNull(rect) || (rect.size.width == 0.0 && rect.size.height == 0.0);
}

/**
 *将BMKMapPoint格式化为字符串
 *@param point 指定的标点
 *@return 返回转换后的字符串
 */
UIKIT_STATIC_INLINE NSString *BMKStringFromMapPoint(BMKMapPoint point) {
    return [NSString stringWithFormat:@"{%.1f, %.1f}", point.x, point.y];
}

/**
 *将BMKMapSize格式化为字符串
 *@param size 指定的size
 *@return 返回转换后的字符串
 */
UIKIT_STATIC_INLINE NSString *BMKStringFromMapSize(BMKMapSize size) {
    return [NSString stringWithFormat:@"{%.1f, %.1f}", size.width, size.height];
}

/**
 *将BMKMapRect格式化为字符串
 *@param rect 指定的rect
 *@return 返回转换后的字符串
 */
UIKIT_STATIC_INLINE NSString *BMKStringFromMapRect(BMKMapRect rect) {
    return [NSString stringWithFormat:@"{%@, %@}", BMKStringFromMapPoint(rect.origin), BMKStringFromMapSize(rect.size)];
}

/**
 *计算两个矩形的并集
 *@param rect1 矩形1
 *@param rect2 矩形2
 *@return 两个矩形的并集
 */
UIKIT_EXTERN BMKMapRect BMKMapRectUnion(BMKMapRect rect1, BMKMapRect rect2);

/**
 *计算两个矩形的交集
 *@param rect1 矩形1
 *@param rect2 矩形2
 *@return 两个矩形的交集
 */
UIKIT_EXTERN BMKMapRect BMKMapRectIntersection(BMKMapRect rect1, BMKMapRect rect2);

/**
 *将矩形向内缩小dx，dy大小
 *@param rect 指定的矩形
 *@param dx x轴的变化量
 *@param dy y轴的变化量
 *@return 调整后的矩形
 */
UIKIT_EXTERN BMKMapRect BMKMapRectInset(BMKMapRect rect, double dx, double dy);

/**
 *将矩形原点偏移指定大小
 *@param rect 指定的矩形
 *@param dx x轴的偏移量
 *@param dy y轴的偏移量
 *@return 调整后的矩形
 */
UIKIT_EXTERN BMKMapRect BMKMapRectOffset(BMKMapRect rect, double dx, double dy);

/**
 *矩形分割，将一个矩形分割为两个矩形
 *@param rect 待分割的矩形
 *@param slice 指针，用来保存分割后被移除的矩形
 *@param remainder 指针，用来保存分割后剩下的矩形
 *@param amount 指定分割的大小，如果设置为负数，则将自动调整为0
 *@param edge 用来指定要从那条边开始分割
 */
UIKIT_EXTERN void BMKMapRectDivide(BMKMapRect rect, BMKMapRect *slice, BMKMapRect *remainder, double amount, CGRectEdge edge);

/**
 *判断指定点是否在某矩形内
 *@param rect 指定的矩形
 *@param point 指定的点
 *@return 如果包含，返回YES，否则，返回NO
 */
UIKIT_EXTERN BOOL BMKMapRectContainsPoint(BMKMapRect rect, BMKMapPoint point);

/**
 *判断矩形rect1是否包含矩形rect2
 *@param rect1 矩形1
 *@param rect2 矩形2
 *@return 如果包含，返回YES，否则，返回NO
 */
UIKIT_EXTERN BOOL BMKMapRectContainsRect(BMKMapRect rect1, BMKMapRect rect2);

/**
 *判断两矩形是否相交
 *@param rect1 矩形1
 *@param rect2 矩形2
 *@return 如果相交，返回YES，否则，返回NO
 */
UIKIT_EXTERN BOOL BMKMapRectIntersectsRect(BMKMapRect rect1, BMKMapRect rect2);

/**
 *将投影后的直角坐标矩形转换为泳经纬度表示的范围
 *@param rect 待转换的直角坐标矩形
 *@return 转换后的经纬度范围
 */
UIKIT_EXTERN BMKCoordinateRegion BMKCoordinateRegionForMapRect(BMKMapRect rect);

/**
 *判断指定的直角坐标矩形是否跨越了180度经线
 *@param rect 待判断的矩形
 *@return 如果跨越，返回YES，否则返回NO
 */
UIKIT_EXTERN BOOL BMKMapRectSpans180thMeridian(BMKMapRect rect);

/**
 *对于跨越了180经线的矩形，本函数将世界之外的部分进行分割，并将分割下来的矩形转换到地球对面，例如将-185度经线对应的区域转换到5度经线对应的区域，并将转换后的矩形返回
 *@param rect 待处理的矩形
 *@return 返回转换后的矩形
 */
UIKIT_EXTERN BMKMapRect BMKMapRectRemainder(BMKMapRect rect);

/**
 *判断点是否在圆内
 *@param point 待判断的平面坐标点
 *@param center 目标圆形的中心点平面坐标
 *@param radius 目标圆形的半径，单位m
 *@return 如果在内，返回YES，否则返回NO
 */
UIKIT_EXTERN BOOL BMKCircleContainsPoint(BMKMapPoint point, BMKMapPoint center, double radius);

/**
 *判断点是否在圆内
 *@param point 待判断的经纬度坐标点
 *@param center 目标圆形的中心点经纬度坐标
 *@param radius 目标圆形的半径，单位m
 *@return 如果在内，返回YES，否则返回NO
 */
UIKIT_EXTERN BOOL BMKCircleContainsCoordinate(CLLocationCoordinate2D point, CLLocationCoordinate2D center, double radius);
/**
 *判断点是否在多边形内
 *@param point 待判断的平面坐标点
 *@param polygon 目标多边形的顶点数组
 *@param count 目标多边形顶点数组元素个数
 *@return 如果在内，返回YES，否则返回NO
 */
UIKIT_EXTERN BOOL BMKPolygonContainsPoint(BMKMapPoint point, BMKMapPoint *polygon, NSUInteger count);

/**
 *判断点是否在多边形内
 *@param point 待判断的经纬度点
 *@param polygon 目标多边形的顶点数组
 *@param count 目标多边形顶点数组元素个数
 *@return 如果在内，返回YES，否则返回NO
 */
UIKIT_EXTERN BOOL BMKPolygonContainsCoordinate(CLLocationCoordinate2D point, CLLocationCoordinate2D *polygon, NSUInteger count);

/**
 *获取折线外某点到这线上距离最近的点
 *@param point 待判断的经纬度点
 *@param polyline 目标折线的顶点数组
 *@param count 目标折线顶点数组元素个数
 *@return 返回折线上的点（距离point最近）
 */
UIKIT_EXTERN BMKMapPoint BMKGetNearestMapPointFromPolyline(BMKMapPoint point, BMKMapPoint* polyline, NSUInteger count);

/**
 *计算地理矩形区域的面积
 *@param leftTop 左上角经纬度坐标点
 *@param rightBottom 右下角经纬度坐标点
 *@return 返回区域面积，单位：平方米
 */
UIKIT_EXTERN double BMKAreaBetweenCoordinates(CLLocationCoordinate2D leftTop, CLLocationCoordinate2D rightBottom);

/**
 由百度经纬度坐标转换得到百度墨卡托坐标

 @param coordinate 百度经纬度坐标
 @return 百度墨卡托坐标
 */
UIKIT_EXTERN CGPoint BMKConvertToBaiduMercatorFromBD09LL(CLLocationCoordinate2D bd09llCoordinate);

/**
 由百度墨卡托坐标转换得到百度经纬度坐标

 @param coordinate 百度墨卡托坐标
 @return 百度经纬度坐标
 */
UIKIT_EXTERN CLLocationCoordinate2D BMKConvertToBD09LLFromBaiduMercator(CGPoint bdMCTCoordinate);

/**
 经纬度坐标之间的坐标转换
 支持WGS84LL->BD09LL, GCJ02LL->BD09LL, BD09LL->GCJ02LL
 输入输出坐标为其他类型时，认为是非法输入，返回的坐标中经纬度均为0

 @param coordinate 待转换的原始经纬度坐标
 @param fromType 原始经纬度坐标的坐标类型
 @param toType 目标的经纬度坐标类型
 @return 转换后的经纬度坐标
 */
UIKIT_EXTERN CLLocationCoordinate2D BMKCoordTrans(CLLocationCoordinate2D coordinate, BMK_COORD_TYPE fromType, BMK_COORD_TYPE toType);

/**
 *坐标转换函数，从原始GPS坐标，mapbar坐标,google坐标，51地图坐标，mapabc坐标转换为百度坐标（51地图坐标需要显出10000）
 *@param coordinate 待转换的坐标
 *@param type 待转换的坐标系类型，GPS为原始GPS坐标，COMMON为google坐标，51地图坐标，mapabc坐标
 *@return 返回的NSDictionry中包含“x”，“y”字段，各自对应经过base64加密之后的x，y坐标
 */
UIKIT_EXTERN NSDictionary* BMKConvertBaiduCoorFrom(CLLocationCoordinate2D coordinate,BMK_COORD_TYPE type) __attribute__((deprecated("使用BMKCoordTrans方法代替")));

/**
 *base64加密后的坐标字典解密函数
 *@param dictionary 带解密的NSDictionry，该NSDictionry中应包含“x”，“y”字段，各自对应经过base64加密之后的x，y坐标
 *@return 解密之后的坐标
 */
UIKIT_EXTERN CLLocationCoordinate2D BMKCoorDictionaryDecode(NSDictionary* dictionary);

