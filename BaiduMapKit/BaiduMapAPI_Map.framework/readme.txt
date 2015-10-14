基础地图：包括基本矢量地图、卫星图、实时路况图和各种地图覆盖物，此外还包括各种与地图相关的操作和事件监听；


--------------------------------------------------------------------------------------
地图SDK功能介绍（全功能开发包）：

地图：提供地图展示和地图操作功能；
POI检索：支持周边检索、区域检索和城市内兴趣点检索；
地理编码：提供经纬度和地址信息相互转化的功能接口；
线路规划：支持公交、驾车、步行三种方式的线路规划；
覆盖物图层：支持在地图上添加覆盖物（标注、几何图形、热力图、地形图图层等），展示更丰富的LBS信息；
定位：获取当前位置信息，并在地图上展示（支持普通、跟随、罗盘三种模式）；
离线地图：使用离线地图可节省用户流量，提供更好的地图展示效果；
调启百度地图：利用SDK接口，直接在本地打开百度地图客户端或WebApp，实现地图功能；
周边雷达：利用周边雷达功能，开发者可在App内低成本、快速实现查找周边使用相同App的用户位置的功能；
LBS云检索：支持查询存储在LBS云内的自有数据；
特色功能：提供短串分享、Place详情检索、热力图等特色功能，帮助开发者搭建功能更加强大的应用；

--------------------------------------------------------------------------------------
较之v2.8.1，升级功能：

注：百度地图iOS SDK向广大开发者提供了配置更简单的 .framework形式的开发包，请开发者选择此种类型的开发包使用。自v2.9.0起，百度地图iOS SDK将不再提供 .a形式的开发包。
   自v2.9.0起，采用分包的形式提供 .framework包，请广大开发者使用时确保各分包的版本保持一致。其中BaiduMapAPI_Base.framework为基础包，使用SDK任何功能都需导入，其他分包可按需导入。

【新版提示】1.自V2.9.0起，将启用新的地图资源服务，旧地图离线包在新版上不可使用；同时官方不再支持地图离线包下载，所以V2.9.0起，去掉“手动离线导入接口”，SDK离线下载接口维持不变。2.自V2.9.0起，iOS SDK采用分包形式，旧包无法与新包同时混用，请将之前所有旧包(包含bundle资源)并全部替换为新包。3.自V2.9.0起，iOS SDK使用新的矢量地图样式，地图显示更加清新，和百度地图客户端保持一致

【 新  增  / 废  弃 】
    基础地图
	1.适配iOS 9和 iPhone 6s
	2.新增点聚合功能开源	  增加点聚合功能，并在demo中开放源代码，具体请参考demo	3.支持线绘制功能扩展：支持纹理图片平铺绘制，缩放，分段颜色设置	 BMKOverlayGLBasicView新增属性：	 /// 是否纹理图片平铺绘制，默认NO	 @property (assign, nonatomic) BOOL tileTexture;	 /// 纹理图片是否缩放（tileTexture为YES时生效），默认NO	 @property (assign, nonatomic) BOOL keepScale;	 BMKOverlayView新增属性：	 /// 使用分段颜色绘制时，必须设置（内容必须为UIColor）	 @property (nonatomic, strong) NSArray *colors;	4.支持底图标注控制 	 BMKMapView 新增属性:  	 ///设定地图是否显示底图poi标注，默认YES	 @property(nonatomic, assign) BOOL showMapPoi;	5.新增TileOverlay图层，分为离线、在线tileOverlay绘制(使用方法请参考demo)。	 新增类： BMKTileLayer、BMKURLTileLayer、BMKSyncTileLayer、BMKTileLayerView	6.BMKMapStatus新增只读属性：visibleMapRect
	7.BMKOfflineMap废弃扫描导入离线包接口，不再支持离线包导入
	 废弃接口：
	 - (BOOL)scan:(BOOL)deleteFailedr __deprecated_msg("废弃方法(空实现),自2.9.0起废弃,不支持扫描导入离线包");
	8.更新离线城市BMKOLUpdateElement status状态
	
   检索功能
	反geo检索结果新增商圈
 	BMKReverseGeoCodeResult新增属性：
 	///商圈名称
 	@property (nonatomic, strong) NSString* businessCircle;	
   定位功能	废弃接口（空实现）：	+ (void)setLocationDistanceFilter:(CLLocationDistance) distanceFilter __deprecated_msg("废弃方法	（空实现），使用distanceFilter属性替换");	+ (CLLocationDistance)getCurrentLocationDistanceFilter __deprecated_msg("废弃方法（空实现），使用distanceFilter属性替换");	+ (void)setLocationDesiredAccuracy:(CLLocationAccuracy) desiredAccuracy __deprecated_msg("废弃方法（空实现），使用desiredAccuracy属性替换");	+ (CLLocationAccuracy)getCurrentLocationDesiredAccuracy __deprecated_msg("废弃方法（空实现），使用desiredAccuracy属性替换");	新增属性：	/// 设定定位的最小更新距离。默认为kCLDistanceFilterNone	@property(nonatomic, assign) CLLocationDistance distanceFilter;	/// 设定定位精度。默认为kCLLocationAccuracyBest。	@property(nonatomic, assign) CLLocationAccuracy desiredAccuracy;	/// 设定最小更新角度。默认为1度，设定为kCLHeadingFilterNone会提示任何角度改变。	@property(nonatomic, assign) CLLocationDegrees headingFilter;	/// 指定定位是否会被系统自动暂停。默认为YES。只在iOS 6.0之后起作用。	@property(nonatomic, assign) BOOL pausesLocationUpdatesAutomatically;	///指定定位：是否允许后台定位更新。默认为NO。只在iOS 9.0之后起作用。设为YES时，Info.plist中 UIBackgroundModes 必须包含 "location"	@property(nonatomic, assign) BOOL allowsBackgroundLocationUpdates;

【 修  复 】
    1、修复不加载@3x图片的问题；
    2、修复公交路线规划，换乘方案内容缺失的问题；    3、修复iOS 8.2系统版本以前，AnnotationView 中加入约束会卡住的问题；    4、修复使用xcode 7编译时SDK产生的编译警告；    5、修复BMKMapView在特定的使用条件下crash的问题