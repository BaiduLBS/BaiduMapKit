//
//  BMKCustomMapOption.h
//  MapComponent
//
//  Created by zhaoxiangru on 2019/9/10.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BMKCustomMapStyleOption : NSObject
/// 个性化地图样式ID，可从百度地图开放平台控制台http://lbsyun.baidu.com/apiconsole/custommap获取个性化样式ID
@property(nonatomic, copy)NSString *customMapStyleID;
/// 个性化地图文件路径，通过id加载失败时，将会从本地加载此路径下的个性化样式
@property(nonatomic, copy)NSString *customMapStyleFilePath;
@end

