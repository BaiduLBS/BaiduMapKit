//
//  BMKSuggestionSearchResult.h
//  SearchComponent
//
//  Created by Xin,Qi on 04/06/2018.
//  Copyright © 2018 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#pragma mark - Sug检索子节点结果类
@interface BMKSuggestionChildrenInfo : NSObject
/// poi子点uid
@property (nonatomic, copy) NSString *uid;
/// poi子点名称
@property (nonatomic, copy) NSString *name;
/// poi子点简称
@property (nonatomic, copy) NSString *showName;

@end
#pragma mark - Sug检索结果类

@interface BMKSuggestionInfo : NSObject

/// 联想词联想词名称
@property (nonatomic, copy) NSString *key;
/// 联想结果经纬度坐标
@property (nonatomic, assign) CLLocationCoordinate2D location;
/// 联想结果唯一标示，ID
@property (nonatomic, copy) NSString *uid;
/// 联想结果所在城市
@property (nonatomic, copy) NSString *city;
/// 联想结果所在区县
@property (nonatomic, copy) NSString *district;
/// 联想结果分类，默认不召回，需要权限。
@property (nonatomic, copy) NSString *tag;
/// 联想结果地址，默认不召回，需要权限。
@property (nonatomic, copy) NSString *address;
/// 联想结果子节点，默认不召回，需要权限。
@property (nonatomic, copy) NSArray <BMKSuggestionChildrenInfo *> *children;

@end

@interface BMKSuggestionSearchResult : NSObject

/// Sug检索结果列表
@property (nonatomic, copy) NSArray <BMKSuggestionInfo *> *suggestionList;

@end
