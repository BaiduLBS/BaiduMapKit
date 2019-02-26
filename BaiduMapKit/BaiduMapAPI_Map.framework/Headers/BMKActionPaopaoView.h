/*
 *  BMKActionPaopaoView.h
 *  BMapKit
 *
 *  Copyright 2011 Baidu Inc. All rights reserved.
 *
 */

#import <UIKit/UIKit.h>
/**
 * 该类用于定义一个PaopaoView
 * 注意：如果在BMKActionPaopaoView中添加手势，会覆盖原本的点击和长按拖动的事件，不推荐这样使用。
 * 如必须添加，请将手势的delegate设置到BMKActionPaopaoView中。
 */
@interface BMKActionPaopaoView : UIView
/**
 *初始化并返回一个BMKActionPaopaoView
 *@param customView 自定义View，customView＝nil时返回默认的PaopaoView
 *@return 初始化成功则返回BMKActionPaopaoView,否则返回nil
 */
- (id)initWithCustomView:(UIView *)customView;

@end

