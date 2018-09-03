//
//  BMKUserLocation.h
//  BaseComponent
//
//  Created by Baidu on 3/26/14.
//  Copyright (c) 2014 baidu. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

#ifndef BMKUserLocation_h
#define BMKUserLocation_h
@interface BMKUserLocation : NSObject

/// 位置更新状态，如果正在更新位置信息，则该值为YES
@property (nonatomic, assign, getter=isUpdating) BOOL updating;

/// 位置信息，尚未定位成功，则该值为nil
@property (nonatomic, strong) CLLocation *location;

/// heading信息，尚未定位成功，则该值为nil
@property (nonatomic, strong) CLHeading *heading;

/// 定位标注点要显示的标题信息
@property (nonatomic, copy) NSString *title;

/// 定位标注点要显示的子标题信息
@property (nonatomic, copy) NSString *subtitle;

@end

#endif
