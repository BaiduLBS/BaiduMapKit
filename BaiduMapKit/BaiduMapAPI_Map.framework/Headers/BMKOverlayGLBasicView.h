/*
*  BMKOverlayGLBasicView.h
*  BMapKit
*
*  Copyright 2011 Baidu Inc. All rights reserved.
*
*/

#import <UIKit/UIKit.h>
#import "BMKOverlayView.h"

/// 该类定义了一个用opengl绘制的OverlayView的基类，如果需要用gdi进行绘制请继承于BMKOverlayPathView类
@interface BMKOverlayGLBasicView : BMKOverlayView {

}

/// 填充颜色
/// 注：请使用 - (UIColor *)initWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha; 初始化UIColor，使用[UIColor ***Color]初始化时，个别case转换成RGB后会有问题
@property (strong, nonatomic) UIColor *fillColor;

/// 画笔颜色
/// 注：请使用 - (UIColor *)initWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha; 初始化UIColor，使用[UIColor ***Color]初始化时，个别case转换成RGB后会有问题
@property (strong, nonatomic) UIColor *strokeColor;

/// 画笔宽度，默认为0
@property  (nonatomic,assign) CGFloat lineWidth;

/// path对象
@property CGPathRef path;

/// 是否为虚线样式，默认NO
@property (nonatomic) BOOL lineDash __deprecated_msg("已废弃since 5.0.0，已废弃，请使用lineDashType绘制虚线");

/// 是否纹理图片平铺绘制，默认NO
@property (assign, nonatomic) BOOL tileTexture __deprecated_msg("已废弃since 5.0.0");

/// 纹理图片是否缩放，默认NO
@property (assign, nonatomic) BOOL keepScale;

/// LineJoinType,默认是kBMKLineJoinBevel（不支持虚线）
@property(assign,nonatomic)BMKLineJoinType lineJoinType;

/// LineCapType,默认是kBMKLineCapButt (不支持虚线)
@property(assign,nonatomic)BMKLineCapType lineCapType;

/// 虚线类型, since 5.0.0，默认kBMKLineDashTypeNone(仅支持颜色虚线)
@property(assign,nonatomic)BMKLineDashType lineDashType;
@end
