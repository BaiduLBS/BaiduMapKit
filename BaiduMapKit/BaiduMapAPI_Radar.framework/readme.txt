周边雷达：包含位置信息上传和检索周边相同应用的用户位置信息功能；




--------------------------------------------------------------------------------------

iOS 地图 SDK v3.4.0是适用于iOS系统移动设备的矢量地图开发包

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
 
 
 【 新 版 提 示 】
 【 注 意 】
 1、自v3.2.0起，百度地图iOS SDK全面支持HTTPS，需要广大开发者导入第三方openssl静态库：libssl.a和libcrypto.a（存放于thirdlib目录下）
 添加方法：在 TARGETS->Build Phases-> Link Binary With Libaries中点击“+”按钮，在弹出的窗口中点击“Add Other”按钮，选择libssl.a和libcrypto.a添加到工程中 。
 
 2、支持CocoaPods导入
 pod setup //更新CocoPods的本地库
 pod search BaiduMapKit  //查看最新地图SDK
 
 【 新 增 】
 【基 础 地 图】
 1.新增当双击手势放大地图时，可以设置地图中心点是否移动至点击处的属性
   BMKMapView新增：
   ///双击手势放大地图时, 设置为YES, 地图中心点移动至点击处; 设置为NO，地图中心点不变；默认为YES;
   @property(nonatomic, getter=isChangeCenterWithDoubleTouchPointEnabled) BOOL ChangeCenterWithDoubleTouchPointEnabled;

 2.支持标注锁定在屏幕固定位置
    BMKPointAnnotation新增：
    ///Annotation固定在指定屏幕位置,  必须与screenPointToLock一起使用。 注意：拖动Annotation isLockedToScreen会被设置为false。
    ///若isLockedToScreen为true，拖动地图时annotaion不会跟随移动；
    ///若isLockedToScreen为false，拖动地图时annotation会跟随移动。
    @property (nonatomic, assign) BOOL isLockedToScreen;

    ///标注在屏幕中锁定的位置，注意：地图初始化后才能设置screenPointToLock。可以在地图加载完成的回调方法：mapViewDidFinishLoading中使用此属性。
    @property (nonatomic, assign) CGPoint screenPointToLock;

 3.新增接口：设定地理范围在屏幕中的显示区域
   BMKMapView新增：
/**
 *根据当前mapView的窗口大小，预留insets指定的边界区域后，将mapRect指定的地理范围显示在剩余的区域内，并尽量充满
 *@param mapRect 要显示的地图范围，用直角坐标系表示
 *@param insets 屏幕四周预留的最小边界（mapRect的内容不会显示在该边界范围内）
 *@param animate 是否采用动画效果
 */
- (void)fitVisibleMapRect:(BMKMapRect)mapRect edgePadding:(UIEdgeInsets)insets withAnimated:(BOOL)animate;

 【 优 化 】
 1.解决反复创建和销毁mapView时内存泄漏的问题
 2.对拖动标注时的弹跳动画效果进行优化
 3.修复mapView调用selectAnnotation方法时，回调didSelectAnnotationView不调用的问题。
 4.修复行政区域检索福建和浙江区域没有返回数据的问题
 5.修复部分使用场景下，设置mapPadding时，overlay位置偏移的问题 
 6.修复部分使用场景下，加载mapView闪黑屏的问题
