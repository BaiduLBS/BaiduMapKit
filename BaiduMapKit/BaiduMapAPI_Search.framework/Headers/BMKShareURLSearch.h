/*
 *  BMKShareUrlSearch.h
 *  BMapKit
 *
 *  Copyright 2014 Baidu Inc. All rights reserved.
 *
 */

#import "BMKShareUrlSearchOption.h"
#import "BMKSearchBase.h"

#pragma mark - 短串分享结果类
///分享URL结果类
@interface BMKShareURLResult : NSObject
///返回结果url
@property (nonatomic, copy) NSString *url;
@end


@protocol BMKShareURLSearchDelegate;
#pragma mark - 短串分享请求类
///短串搜索服务
@interface BMKShareURLSearch : BMKSearchBase
/// 检索模块的Delegate，此处记得不用的时候需要置nil，否则影响内存的释放
@property (nonatomic, weak) id<BMKShareURLSearchDelegate> delegate;

/**
 *获取poi详情短串分享url
 *异步函数，返回结果在BMKShareUrlSearchDelegate的onGetPoiDetailShareURLResult通知
 *@param poiDetailShareUrlSearchOption poi详情短串分享检索信息类
 *@return 请求发送成功返回YES，否则返回NO
 */
- (BOOL)requestPoiDetailShareURL:(BMKPoiDetailShareURLOption *) poiDetailShareUrlSearchOption;

/**
 *获取反geo短串分享url
 *异步函数，返回结果在BMKShareUrlSearchDelegate的onGetLocationShareURLResult通知
 *@param reverseGeoShareUrlSearchOption 反geo短串分享检索信息类
 *@return 请求发送成功返回YES，否则返回NO
 */
- (BOOL)requestLocationShareURL:(BMKLocationShareURLOption *)reverseGeoShareUrlSearchOption;

/**
 *获取路线规划短串分享url
 *异步函数，返回结果在BMKShareUrlSearchDelegate的onGetRoutePlanShareURLResult通知
 *@param routePlanShareUrlSearchOption 取路线规划短串分享检索信息类
 *@return 请求发送成功返回YES，否则返回NO
 */
- (BOOL)requestRoutePlanShareURL:(BMKRoutePlanShareURLOption *)routePlanShareUrlSearchOption;

@end

#pragma mark - 短串分享结果代理回调类
///搜索delegate，用于获取搜索结果
@protocol BMKShareURLSearchDelegate <NSObject>
@optional
/**
 *返回poi详情分享url
 *@param searcher 搜索对象
 *@param result 返回结果
 *@param error 错误号，@see BMKSearchErrorCode
 */
- (void)onGetPoiDetailShareURLResult:(BMKShareURLSearch *)searcher result:(BMKShareURLResult *)result errorCode:(BMKSearchErrorCode)error;

/**
 *返回位置信息分享url
 *@param searcher 搜索对象
 *@param result 返回结果
 *@param error 错误号，@see BMKSearchErrorCode
 */
- (void)onGetLocationShareURLResult:(BMKShareURLSearch *)searcher result:(BMKShareURLResult *)result errorCode:(BMKSearchErrorCode)error;

/**
 *返回路线规划分享url
 *@param searcher 搜索对象
 *@param result 返回结果
 *@param error 错误号，@see BMKSearchErrorCode
 */
- (void)onGetRoutePlanShareURLResult:(BMKShareURLSearch *)searcher result:(BMKShareURLResult *)result errorCode:(BMKSearchErrorCode)error;

@end
