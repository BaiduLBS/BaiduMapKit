/*
 *  BMKPolygon.h
 *  BMapKit
 *
 *  Copyright 2011 Baidu Inc. All rights reserved.
 *
 */
#import <Foundation/Foundation.h>

#import "BMKMultiPoint.h"
#import "BMKOverlay.h"

/// 此类用于定义一个多边形区域
@interface BMKPolygon : BMKMultiPoint <BMKOverlay>

/// 设置中空区域，用来创建中间带空洞的复杂图形。注意：传入的overlay只支持BMKPolgon类型和BMKCircle类型. since 5.0.0
@property (nonatomic, strong) NSArray<id<BMKOverlay>> *hollowShapes;

/**
 *根据多个点生成多边形
 *@param points 直角坐标点数组，这些点将被拷贝到生成的多边形对象中
 *@param count points数组中点的个数
 *@return 新生成的多边形对象
 */
+ (BMKPolygon *)polygonWithPoints:(BMKMapPoint *)points count:(NSUInteger)count;

/**
 *根据多个点生成多边形
 *@param coords 经纬度坐标点数组，这些点将被拷贝到生成的多边形对象中
 *@param count coords数组中点的个数
 *@return 新生成的多边形对象
 */
+ (BMKPolygon *)polygonWithCoordinates:(CLLocationCoordinate2D *)coords count:(NSUInteger)count;

/**
 *重新设置多边形顶点
 *@param points 指定的直角坐标点数组
 *@param count points数组中坐标点的个数
 *@return 是否设置成功
 */
- (BOOL)setPolygonWithPoints:(BMKMapPoint *)points count:(NSInteger) count;

/**
 *重新设置多边形顶点
 *@param coords 指定的经纬度坐标点数组
 *@param count coords数组中坐标点的个数
 *@return 是否设置成功
 */
- (BOOL)setPolygonWithCoordinates:(CLLocationCoordinate2D *)coords count:(NSInteger) count;


@end
