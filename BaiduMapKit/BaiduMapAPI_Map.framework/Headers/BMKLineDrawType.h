//
//  BMKLineDrawType.h
//  MapComponent
//
//  Created by zhangbaojin on 2019/8/7.
//  Copyright © 2019 Baidu. All rights reserved.
//


#ifndef BMKLineDrawType_h
#define BMKLineDrawType_h
///line拐角处理方式（不支持虚线）
enum BMKLineJoinType
{
    kBMKLineJoinBevel = 0,   ///< 平角衔接
    kBMKLineJoinMiter,      ///< 尖角衔接(尖角过长(大于线宽)按平角处理)
    kBMKLineJoinRound      ///< 圆⻆角衔接
};
typedef enum BMKLineJoinType BMKLineJoinType;

///line头尾处理方式(不支持虚线)
enum BMKLineCapType
{
    kBMKLineCapButt = 0,     ///< 普通头
    kBMKLineCapRound        ///< 圆形头
};
typedef enum BMKLineCapType BMKLineCapType;

///虚线绘制样式
 enum BMKLineDashType
{
    kBMKLineDashTypeNone = 0,      ///<实折线
    kBMKLineDashTypeSquare,       ///<方块样式
    kBMKLineDashTypeDot,         ///<圆点样式
};
typedef enum BMKLineDashType BMKLineDashType;


#endif /* BMKLineDrawType_h */
