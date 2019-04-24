

--------------------------------------------------------------------------------------

iOS地图SDK是适用于iOS系统移动设备的矢量地图开发包

--------------------------------------------------------------------------------------

【 注 意 】
 1、自v3.2.0起，百度地图iOS SDK全面支持HTTPS，需要广大开发者导入第三方openssl静态库：libssl.a和libcrypto.a（存放于thirdlib目录下）
 添加方法：在 TARGETS->Build Phases-> Link Binary With Libaries中点击“+”按钮，在弹出的窗口中点击“Add Other”按钮，选择libssl.a和libcrypto.a添加到工程中 。
 
 2、支持CocoaPods导入
 pod setup //更新CocoPods的本地库
 pod search BaiduMapKit  //查看最新地图SDK

--------------------------------------------------------------------------------------

地图SDK功能介绍（全功能开发包）：

地图：
	提供地图（2D、3D、室内图）的展示和缩放、平移、旋转、改变视角等地图操作；个性化地图展示、个性化地图与普通地图类型动态切换
POI检索：
	可根据关键字，对POI数据进行周边、区域和城市内三种检索，支持poi室内检索；
地理编码：
	提供地理坐标和地址之间相互转换的能力；
线路规划：
	支持公交信息查询、公交换乘查询、驾车线路规划和步行路径检索；
覆盖物：
	提供多种地图覆盖物（瓦片图层、自定义标注、几何图形、文字绘制、地形图图层、热力图图层等），满足开发者的各种需求；
定位：
	采用多种定位模式，使用定位SDK获取位置信息，使用地图SDK我的位置图层进行位置展示；
离线地图：
	支持使用离线地图，节省用户流量，同时为用户带来更好的地图体验；
调启百度地图：
	利用SDK接口，直接在本地打开百度地图客户端或WebApp，实现地图功能。
周边雷达：
	利用周边雷达功能，开发者可在App内低成本、快速实现查找周边使用相同App的用户位置的功能。
LBS云检索：
	支持用户检索存储在LBS云内的自有POI数据，并展示；
特色功能：
	提供短串分享、Place详情检索、热力图等特色功能，帮助开发者搭建功能更加强大的应用；

------------------------------------------------------------------------------------------------

【 更 新 日 志 】
------------------------------------------------------------------------------------------------
v4.3.2版本：
【优化】
1.优化瓦片图加载速度。
【修复】
1.修复自定义热力图外缘黑影问题。
2.修复驾车路线规划多个途径点算路不精确问题。
3.修复轻扫地图滑动时，regiondidchange回调时间的错误问题。
4.修复polyline绘制飞线问题
5.修复polygon特殊点崩溃问题
6.修复云检索中字段中含有json串转码问题
7.修复annotationview的paopao添加按钮无法响应的问题
8.修复其他小bugs若干。

------------------------------------------------------------------------------------------------

v4.3.0版本：

【新 增】
1.全面升级地图SDK Demo，采用全新UI设计，更严谨的代码风格，更丰富的演示样例。
2.全面升级短串分享、行政区域检索、公交信息检索、室内路线检索、公交路线检索、跨城公交路线检索、驾乘路线检索、步行路线检索、骑行路线检索服务，单CPU架构（以ARM64为例）Search组件对集成App的体积贡献减少30%。
3.新增paopaoView和annotationView添加事件和按钮的能力。
4.支持arm64e CPU架构。
【优 化】
1.升级优化地图手势，提高手势识别精准度，提升地图操作体验。
2.优化标注（BMKAnnotationView）使用体验，贴近开发者使用方式。
【修 复】
1.修复annotationView在地图以外的范围显示的问题。
2.修复罗盘模式下，罗盘旋转异常的问题。
3.修复瓦片图不使用缓存数据的问题。
4.修复BMKAnnotationView的属性draggable为NO时，长按泡泡可以发生拖拽行为的问题。
5.修复BMKMapView手势开关gestureEnable为NO时，ChangeCenterWithDoubleTouchPointEnabled为YES时，仍然可以旋转地图的问题。
6.修复地图放在UIScrollView中无法响应手势的问题。
7.修复多地图及其偶尔出现的纹理错乱的问题。
8.修改地图BMKMapView中属性buildingsEnabled默认为NO的问题，应该是为YES，以及buildingsEnable后需要拖动一下地图才会更新效果。
9.修复点击地图，region没有发生变化，但是触发regionDidChange的问题。
10.修复isUserLocationVisible属性失效。
11.修复单页面多地图场景下的内存泄漏问题。
12.修复其他小bugs若干。
------------------------------------------------------------------------------------------------

v4.2.1版本：
【新 增】
1.BMKAnnotationView新增hidePaopaoWhenSingleTapOnMap、hidePaopaoWhenDrag、displayPriority等新字段，提供更灵活的控制annotationView和paopaoView显示层级的解决方案。
2.BMKMapview新增 mapView:regionWillChangeAnimated:reason:和 mapView:regionDidChangeAnimated:reason: 两个回调，其中reason说明本次地图区域发生变化是由何种原因触发的。
3.BMKMapview的方法selectAnnotation:animated:开始支持动画效果。
4.支持长按paopaoView拖动annotationView。
5.BMKLocationViewDisplayParam新增属性locationViewImage，支持由开发者提供定位图标的图片。

【优 化】
1.提升底图加载渲染速度。
2.提升拖动地图时annotationView随地图移动的平滑度。

【修 复】
1.修复多页面多瓦片图切换时，瓦片图加载不出来的问题。
2.修复断网后应用退到杀进程界面，从杀进程界面进入应用，进行重复多次会导致手机重启的问题。
3.修复步行导航退出导航后，外部地图无法滑动的问题。
4.修复地图比例尺可能会超出屏幕边界的问题。
5.修复首次进入地图滑动地图没有mapView:regionWillChangeAnimated回调的问题。
6.修复屏幕上添加固定标注后，showAnnotations方法显示不准确的问题。
7.修复地图点击时，region没有发生变化，但是会触发regionchange回调的问题。
8.修复用户按住某个annotation缩放或拖动过程中，会触发didSelectAnnotationView而不触发regionDidChangeAnimated的问题。

------------------------------------------------------------------------------------------------


v4.2.0版本：
【新 增】
1.新增步骑行组件BaiduMapAPI_WalkNavi，WalkNavi组件需要和Base组件，Map_For_WalkNavi组件，Search组件，Location组件，Utils组件配合使用。其中需要注意的是，如果使用步骑行WalkNavi组件，则相应的地图功能需要使用Map_For_WalkNavi组件，而不是Map组件。
2.POI检索（城市检索，周边检索）新增加父子节点功能 。当scope=2时，Poi的详细信息字段（BMKPOIDetailInfo）下新增children <BMKPOIDetailChildrenInfo>字段
3.Sug检索 新增加父子节点功能（该功能需要权限）。当scope=2时，Suggestion检索结果（BMKSuggestionInfo）下新增children <BMKSuggestionChildrenInfo>字段
4.GC检索的返回结果BMKGeoCodeSearchResult中，新增precise, confidence, level等字段。
5.RGC检索的返回结果BMKReverseGeoCodeSearchResult中，新增poiRegions字段

【优 化】
1.不再区分普通版和Bitcode版，只发布支持Bitcode的版本，如果不需要Bitcode功能，可以自行剥离。以Base组件为例：
xcrun bitcode_strip -r BaiduMapAPI_Base -o BaiduMapAPI_Base
2.考虑到armv7兼容armv7s，因此不再提供armv7s的CPU架构。
3.Map组件的体积缩减了13%。
4.优化了地图引擎的内存管理
5.不再提供Radar周边雷达组件
6.不再提供Location定位组件，开发者可以使用定位SDK实现定位功能。

【修 复】
1.若干bug修复


------------------------------------------------------------------------------------------------

v4.1.0版本：

【新 增】
1. 个性化地图新增缩放级别控制
    功能说明：
        个性化地图的自定义样式可以根据地图缩放级别进行设置，即不同的缩放级别可以呈现不同的自定义样式。
    接口说明：
        A. Json样式的stylers中新增："level"字段，用来控制样式的生效级别，如果stylers中不配置"level"字段，则认为该样式在所有地图缩放级别生效;
	B. "level"字段的值在Json样式中以字符串表现，取值对标普通地图的缩放级别范围[4-21]。如果该字段值小于地图缩放级别的最小值，则取地图缩放级别的最小值；如果该字段大于地图缩放级别的最大值，则取地图缩放缩放级别的最大值；
        C. 如果Json样式，存在未指定缩放级别样式1和指定了生效的缩放级别样式2的同一元素，则在指定的缩放级别展示样式2，在其他缩放级别展示样式1；
    使用示例：
        [
				    {
                "featureType":"green",
                "elementType":"geometry",
                "stylers": {
                "color": "#232c3aff",
                "level": "14"
                }
            }
        ]
        
2. 个性化地图新增宽度样式
    功能说明：
	宽度样式可以控制点元素，线元素的宽度展示，当前生效的元素包括：点元素（poi类元素，字体），线元素（如高速，地铁等）；
			
    接口说明：
       A. Json样式的stylers中新增: "weight"字段，用于指定元素要展示的宽度，不设置该字段则以默认样式宽度展示；
       B. "weight"字段的值类型在Json样式中以字符串表现，取值范围为[0, 255]，当取值小于0时，实际以0值生效，当大于255时，以255生效；
       
    使用示例：
      [
         {
            "featureType":"green",
            "elementType":"geometry",
            "stylers": {
            "weight": "10"
            }
         }
      ]

3. 个性化地图开放更加细粒度的元素种类，提供更强的个性化能力。分别如下
   面元素，支持的样式同之前的面元素
       "estate"                         // 人造区域之地产小区区域
       "shopping"                       // 人造区域之购物区域，包括购物中心和商场
       "transportation"                 // 人造区域之交通设施区域，包括火车站，飞机场，跑到面，航站楼面，机场内停车场面，其它面
 
   点元素，支持的样式同之前的点元素
       "estatelabel"                    // 房产小区标注
       "businesstowerlabel"             // 商务大厦标注
       "companylabel"                   // 公司企业标注
       "governmentlabel"                // 政府机构标注
       "restaurantlabel"                // 餐饮类标注
       "hotellabel"                     // 宾馆类标注
       "shoppinglabel"                  // 购物类标注
       "lifeservicelabel"               // 生活服务类标注
       "carservicelabel"                // 汽车服务类标注
       "transportationlabel"            // 交通设施类标注
       "financelabel"                   // 金融类标注
       "otherlabel"                     // 其它类标注

4. 同一元素多个样式同时同级别设置，生效策略做调整
    功能说明：
       因为涉及到样式缩放级别的控制，所以可见性(visibility)，颜色（color），宽度（weight）等样式的生效策略做了调整，
       即：当同一元素的可见性（visibility）分别颜色（color），宽度（weight）一起设置时，以最后设置的样式生效；
       
    使用示例： 
      [ 
         {
            "featureType":"green",
            "elementType":"geometry",
            "stylers": {
                "weight": "10"
            }
         },
         {
            "featureType":"green",
            "elementType":"geometry",
            "stylers": {
                 "visibility": "off"
            }
         }
      ] 
   实际效果则以visibility样式生效。（注意：visibility默认为on）
 
【优 化】
 1.升级POI检索服务，包括城市检索、矩形检索、周边检索、详情检索、室内检索。注意：部分请求字段与结果字段会有变动，不完全向下兼容；请求和响应类对应的修改主要是：
    A.每种POI检索对应一个请求参数类，命名规则为 BMKPOIXXXSearchOption，主要变化为支持多个关键字检索、支持多标签检索、支持按过滤条件检索等。
    B.POI城市检索、POI周边检索、POI矩形区域检索服务都使用 BMKPOISearchResult 类
      POI详情检索使用 BMKPOIDetailSearchResult 类
      POI室内检索使用 BMKPOIIndoorSearchResult 类
 2.升级地理编码、反地理编码服务；
 3.优化引擎内存管理；
 4.优化资源文件体积，mapapi.bundle的体积由6.4MB减小到4.3MB，减少33%；
 
【修 复】
 1.修复某些场景下极小概率出现的crash。
------------------------------------------------------------------------------------------------

v4.0.0版本：
【新 增】
 1.升级引擎，提升底图加载速度。
 2.升级数据服务版本与地图客户端一致。
 3.适配V4.1.x(即以上)版本导航SDK。只有V4.0.0及以上版本的地图SDK才能与V4.1.x版本的导航SDK同时使用，否则会编译报错。
 4.新增海外离线地图下载控制。
 
【优 化】
 1.BMKPolyline采用多段纹理时，交接处更加绘制效果更平滑。
 2.优化高架桥、天桥等高精道路的显示效果，增加阴影，深度效果。
 3.室内图下，楼的侧立面增加玻璃罩效果。
 4.为了优化小比例尺下的显示效果，将zoomLevel的最小值由3改为4。
 5.优化地图释放内存回收机制。
 
【修 复】
 1.BMKPoiDetailResult无法获取到POI地理坐标的BUG。
 2.打开百度地图客户端返回后（前后台切换）黑屏的BUG。
 3.部分国家和地图的离线地图大小为负数的BUG。
 4.修复iOS7系统下使用定位服务会crash的BUG。
------------------------------------------------------------------------------------------------

v3.4.4版本：

 【新增】
 1.新增 BMKConvertToBaiduMercatorFromBD09LL 与 BMKConvertToBD09LLFromBaiduMercator 方法，用于百度经纬度和百度墨卡托之间的转换。
 2.新增 CLLocationCoordinate2D BMKCoordTrans(CLLocationCoordinate2D coordinate, BMK_COORD_TYPE fromType, BMK_COORD_TYPE toType); 方法，支持WGS84LL->BD09LL, GCJ02LL->BD09LL, BD09LL->GCJ02LL三种经纬度之间的直接转换。
 
 【修复】
 1.支持iOS11系统定位权限
 2.个性化地图部分catlog不显示的问题
 3.室内图无背景色的问题
 4.polygon绘制大量节点折线，超出数量，产生飞线问题
 5.部分场景下，点击离线地图crash的问题
------------------------------------------------------------------------------------------------

v3.4.2版本：

 【修复】
 1.修复多页面多地图场景下，切换页面导致的crash问题。
 2.修复检索对象对delegate的强引用问题。
 3.修复在一些罕见场景下，Bugly报告的crash问题。
 4.修复第一次通过setBuildingsEnabled接口设置不显示3D楼块效果失效的BUG。
 
 【优化】
 1.删除annotation后，不再删除其对应的annotationView的subView。开发者dequeue出可重用的annotationView后，为了避免内容堆叠问题，可以自行去避免，如remove subview或者使用不同的reuseIdentifier等。
 2.每个reuseIdentifier可缓存多个annotationView，当开发者removeAnnotation时，SDK会将对应的annotationView加入缓存队列。

------------------------------------------------------------------------------------------------

v3.4.0版本：
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
 ///根据当前mapView的窗口大小，预留insets指定的边界区域后，将mapRect指定的地理范围显示在剩余的区域内，并尽量充满
 ///@param mapRect 要显示的地图范围，用直角坐标系表示
 ///@param insets 屏幕四周预留的最小边界（mapRect的内容不会显示在该边界范围内）
 ///@param animate 是否采用动画效果
- (void)fitVisibleMapRect:(BMKMapRect)mapRect edgePadding:(UIEdgeInsets)insets withAnimated:(BOOL)animate;

【 优 化 】
1.解决反复创建和销毁mapView时内存泄漏的问题
2.对拖动标注时的弹跳动画效果进行优化
3.修复mapView调用selectAnnotation方法时，回调didSelectAnnotationView不调用的问题。
4.修复行政区域检索福建和浙江区域没有返回数据的问题
5.修复部分使用场景下，设置mapPadding时，overlay位置偏移的问题
6.修复部分使用场景下，加载mapView闪黑屏的问题
------------------------------------------------------------------------------------------------

v3.3.4版本：
 【 新 增 】
 1.BMKLocationViewDisplayParam类中增加 canShowCallOut 属性，用于设定用户点击定位图标时，是否弹出paopaoView。
 2.BMKLocationViewDisplayParam类中增加 locationViewHierarchy 属性，用于设定locationView始终处于视图层级的最下层或最上层。
 
 【 优 化 】
 1.修复添加Annotation时，Overlay偶尔绘制不完整的BUG。
 2.修复Swift调用SDK时，cityCode countryCode等字段类型不兼容的问题。
 3.保证新添加的Annotation会在mapView的视图层级的上层。
 4.DEMO中绘制路径规划结果时，修复计算显示区域的BUG。
------------------------------------------------------------------------------------------------

v3.3.2版本：
 【 优 化 】
 1.修复个性化地图在部分使用场景下，不显示的问题。（受影响版本v3.3.0、v3.3.1）
------------------------------------------------------------------------------------------------

v3.3.1版本：
 【 新 增 】
 1.逆地理编码返回结果新增2个属性：cityCode(城市编码) 和adCode（行政区域编码）
 
 【 优 化 】
 1.增加重试机制，优化鉴权时长
 2.解决Xcode8.3编译时出现大量warning的问题
 3.swift Demo：swift语言升级为 swift v3.1，优化升级swift Demo。
------------------------------------------------------------------------------------------------

v3.3.0版本：
 【 新 增 】
 [ 基 础 地 图 ]
 3D地图下，增加显示天空效果，无需设置
 
 [ 工 具 ]
 1．全面支持GCJ02坐标输入/输出，全局设置方法如下：
 [BMKMapManager setCoordinateTypeUsedInBaiduMapSDK:BMK_COORDTYPE_COMMON];//默认为BD09LL坐标，且此方法仅在国内生效，国外均为WGS84坐标
 
 2. 新增调启步行AR导航接口：openBaiduMapwalkARNavigation
 
 [ LBS云]
 云检索中，keywords 改为非必填项
 
 【 优 化 】
 优化个性化地图元素分类
 
 【 修 复 】
 少部分地铁线及室内图无法显示问题（v3.2.0引入的问题）。
 未下载全国离线基础包时，离线状态下全国（球）地图显示异常。
------------------------------------------------------------------------------------------------

v3.2.1版本：
 【 修  复 】
 修复下载离线地图时，delegate方法返回state错误问题
------------------------------------------------------------------------------------------------

v3.2.0版本：
 注：自v3.2.0起，百度地图iOS SDK全面支持HTTPS，需要广大开发者导入第三方openssl静态库：libssl.a和libcrypto.a（存放于thirdlib目录下）。
 
 【 新版提示 】
 1、自v3.2.0起，全面支持HTTPS
 2、自v3.2.0起，地图引擎全面升级，主要升级特征有：
    渲染架构技术升级，OpenGL ES从1.0升级到2.0
    地图数据加载升级，加载性能大幅提升
 
 【 新  增 】
   检索功能
 1、建议检索支持港澳台；建议检索可控制只返回指定城市的检索结果
 BMKSuggestionSearchOption新增属性：
 ///是否只返回指定城市检索结果（默认：NO）（提示：海外区域暂不支持设置cityLimit）
 @property (nonatomic, assign) BOOL cityLimit;
 2、反地址编码结果BMKReverseGeoCodeResult新增属性：
 ///结合当前位置POI的语义化结果描述
 @property (nonatomic, strong) NSString* sematicDescription;
 
 【 优  化 】
 1、建议检索和反地址编码检索服务升级，提供更加优质的服务
 
 【 修  复 】
 1、修复国外定位偏移的问题
 2、修复特殊情况下，移除BMKGroundOverlay时的问题
------------------------------------------------------------------------------------------------

v3.1.0版本：
 【 新  增 】
   基础地图
 1、开放高清4K地图显示（无需设置）
 2、瓦片图新增异步加载方法：
    新增异步加载类：BMKAsyncTileLayer
 3、新增地图渲染完成回调方法：
    - (void)mapViewDidFinishRendering:(BMKMapView *)mapView;
 4、新增定位显示类型：BMKUserTrackingModeHeading（在普通定位模式的基础上显示方向）
 
   检索功能
 1、新增室内路径规划
    BMKRouteSearch新增发起室内路径规划接口：
    - (BOOL)indoorRoutePlanSearch:(BMKIndoorRoutePlanOption*) indoorRoutePlanOption;
    BMKRouteSearchDelegate新增室内路径规划结果回调：
    - (void)onGetIndoorRouteResult:(BMKRouteSearch*)searcher result:(BMKIndoorRouteResult*)result errorCode:(BMKSearchErrorCode)error;
    新增室内路径规划检索参数类：BMKIndoorRoutePlanOption
    新增室内路径规划检索结果类：BMKIndoorRouteResult
 2、增加新的公共交通线路规划（支持同城和跨城）
    BMKRouteSearch增加新的公共交通线路规划接口：
    - (BOOL)massTransitSearch:(BMKMassTransitRoutePlanOption*)routePlanOption;
    BMKRouteSearchDelegate增加新的公共交通线路规划结果回调：
    - (void)onGetMassTransitRouteResult:(BMKRouteSearch*)searcher result:(BMKMassTransitRouteResult*)result errorCode:(BMKSearchErrorCode)error;
    增加新的公共交通线路规划检索参数类：BMKMassTransitRoutePlanOption
    增加新的公共交通线路规划检索结果类：BMKMassTransitRouteResult
 
   LBS云检索
 1、新增云RGC检索功能
    BMKCloudSearch新增发起云RGC检索接口：
    - (BOOL)cloudReverseGeoCodeSearch:(BMKCloudReverseGeoCodeSearchInfo*)searchInfo;
    BMKCloudSearchDelegate新增云RGC检索结果回调：
    - (void)onGetCloudReverseGeoCodeResult:(BMKCloudReverseGeoCodeResult*)cloudRGCResult searchType:(BMKCloudSearchType) type errorCode:(NSInteger) errorCode;
    新增云RGC检索参数类：BMKCloudReverseGeoCodeSearchInfo
    新增云RGC检索结果类：BMKCloudReverseGeoCodeResult
 
 【 优  化 】
 1、优化Marker加载性能：添加Marker和加载大量Marker时，性能大幅提高。
 2、优化地图内存
 
 【 修  复 】
 1、长按地图某区域，OnLongClick会被不停调用的问题
 2、绘制弧线，特殊case提示画弧失败的问题
 3、一次点击事件，点击地图空白处回调和点击覆盖物回调都会调用的问题
------------------------------------------------------------------------------------------------

v3.0.0版本：
【 新版提示 】
 1.自v3.0.0起，iOS SDK全面支持ipv6网络
 
 【 新  增 】
   基础地图
 1、新增室内地图功能
 新增室内地图信息类：BMKBaseIndoorMapInfo
 BMKMapView新增接口:
 /// 设定地图是否显示室内图（包含室内图标注），默认不显示
 @property (nonatomic, assign) BOOL baseIndoorMapEnabled;
 /// 设定室内图标注是否显示，默认YES，仅当显示室内图（baseIndoorMapEnabled为YES）时生效
 @property (nonatomic, assign) BOOL showIndoorMapPoi;
 // 设置室内图楼层
 - (BMKSwitchIndoorFloorError)switchBaseIndoorMapFloor:(NSString*)strFloor withID:(NSString*)strID;
 // 获取当前聚焦的室内图信息
 - (BMKBaseIndoorMapInfo*)getFocusedBaseIndoorMapInfo;
 BMKMapViewDelegate新增接口：
 //地图进入/移出室内图会调用此接口
 - (void)mapview:(BMKMapView *)mapView baseIndoorMapWithIn:(BOOL)flag baseIndoorMapInfo:(BMKBaseIndoorMapInfo *)info;
 2、普通地图与个性化地图切换可以自由切换，BMKMapView新增接口:
 + (void)enableCustomMapStyle:(BOOL) enable;
 3、个性化地图配置json文件出错时，打印log提示
 4、设置mapPadding时可控制地图中心是否跟着移动，BMKMapView新增接口:
 @property (nonatomic) BOOL updateTargetScreenPtWhenMapPaddingChanged;
 5、BMKMapPoi中新增属性：
 ///点标注的uid，可能为空
 @property (nonatomic,strong) NSString* uid;
 
   检索功能
 1、新增室内POI检索
 新增室内POI检索参数信息类：BMKPoiIndoorSearchOption
 新增室内POI搜索结果类：BMKPoiIndoorResult
 新增室内POI信息类：BMKPoiIndoorInfo
 BMKPoiSearch新增接口：
 //poi室内检索
 - (BOOL)poiIndoorSearch:(BMKPoiIndoorSearchOption*)option;
 BMKPoiSearchDelegate新增接口：
 //返回POI室内搜索结果
- (void)onGetPoiIndoorResult:(BMKPoiSearch*)searcher result:(BMKPoiIndoorResult*)poiIndoorResult errorCode:(BMKSearchErrorCode)errorCode;
 2、驾车路线规划结果新增3个属性：打车费用信息、拥堵米数、红路灯个数，BMKDrivingRouteLine新增接口：
 ///路线红绿灯个数
 @property (nonatomic, assign) NSInteger lightNum;
 ///路线拥堵米数，发起请求时需设置参数 drivingRequestTrafficType = BMK_DRIVING_REQUEST_TRAFFICE_TYPE_PATH_AND_TRAFFICE 才有值
 @property (nonatomic, assign) NSInteger congestionMetres;
 ///路线预估打车费(元)，负数表示无打车费信息
 @property (nonatomic, assign) NSInteger taxiFares;
 3、busline检索新增参考票价和上下线行信息，BMKBusLineResult新增接口：
 ///公交线路方向
 @property (nonatomic, strong) NSString* busLineDirection;
 ///起步票价
 @property (nonatomic, assign) CGFloat basicPrice;
 ///全程票价
 @property (nonatomic, assign) CGFloat totalPrice;
 4、poi检索结果新增是否有全景信息，BMKPoiInfo新增接口：
 @property (nonatomic, assign) BOOL panoFlag;
 
   计算工具
 新增调起百度地图客户端全景功能
 新增调起百度地图全景类：BMKOpenPanorama
 新增调起百度地图全景参数类：BMKOpenPanoramaOption
 新增调起百度地图全景delegate：BMKOpenPanoramaDelegate
 
 
 【 修  复 】
 1、修复反复添加移除离线瓦片图时偶现的crash问题
 2、修复上传AppStore时提示访问私有api:-setOverlayGeometryDelegate:的问题
 3、修复地图网络解析时偶现的crash问题
------------------------------------------------------------------------------------------------
