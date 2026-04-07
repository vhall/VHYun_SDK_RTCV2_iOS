//
//  VHRenderView.h
//  VHInteractive
//
//  Created by vhall on 2018/4/18.
//  Copyright © 2018年 www.vhall.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <VHRTCV2/VHIStream.h>

@protocol IVHBeautifyModule;
@class VHRtcPlayer;

NS_ASSUME_NONNULL_BEGIN

/// Block定义-流状态监听回调
typedef void(^StatsCallback)(NSString* mediaType, long kbps, NSDictionary<NSString *, NSString *> * values);
/// Block定义-事件结束回调
typedef void(^FinishBlock)(int code, NSString * _Nullable message);//code 200 成功

///推流摄像头view类，该类定义了摄像头视图的创建、推流等Api，通过此类进行互动推流。使用此类请先在plist文件中添加对于摄像头和麦克风的权限描述。
@interface VHRenderView : UIView <VHIStream>

@property (nonatomic) NSString *nickName;								///< 旁路画面中显示的昵称
@property (nonatomic) BOOL isPublish;									///< 是否在推流
@property (nonatomic) BOOL isSubscribe;									///< 是否已订阅
@property (nonatomic) int voiceChangeType;								///< 变音 注意只在本地相机renderview , 只能在推流成功后调用有效(0 不变音 1是变音)
@property (nonatomic) BOOL beautifyEnable;								///< 美颜开关 默认关，只对本地流有效，可随时设置
@property (nonatomic) NSDictionary *remoteMuteStream;					///< 此流的流音视频开启情况YES:Mute (推流端)
@property (nonatomic, readonly) VHInteractiveStreamType streamType;		///< 流类型 VHInteractiveStreamType
@property (nonatomic, copy, readonly) NSString *userData;				///< 用户数据进入房间时传的数据
@property (nonatomic, copy, readonly) NSString *streamAttributes;   	///< 用户推流上麦时所传数据
@property (nonatomic, copy, readonly) NSDictionary *options;        	///< 设置的音视频参数
@property (nonatomic, readonly) BOOL isLocal;							///< 是否是本地相机view
@property (nonatomic, readonly) int simulcastLayers;					///< 此流是否是支持大小流切换，支持几路切换(1 一路流  2两路流)
@property (nonatomic, readonly) NSDictionary *muteStream;				///< 本地相机view 只有这一个属性 (订阅端)
@property (nonatomic, readonly) CGSize videoSize;						///< 此流视频宽高

/// 创建本地摄像头view
/// @param frame 默认参数 使用服务器配置参数
- (instancetype)initCameraViewWithFrame:(CGRect)frame;

/// 创建本地摄像头view 使用自定义 视频参数
/// @param frame 默认参数 使用服务器配置参数
/// @param type 推流清晰度设置 设置后 options可设置为nil
/// @param options 仅当type为VHPushTypeCUSTOM时有效
/// @discussion optoins: 一般定义为: @{VHFrameResolutionTypeKey:@(VHFrameResolution192x144), VHStreamOptionStreamType:@(VHInteractiveStreamTypeAudioAndVideo)}
- (instancetype)initCameraViewWithFrame:(CGRect)frame pushType:(VHPushType)type options:(NSDictionary<VHStreamKey, id> *)options;


/// 创建本地摄像头view 使用自定义 视频参数
/// @param frame 默认参数 使用服务器配置参数
/// @param options  如：@{VHFrameResolutionTypeKey:@(VHFrameResolution192x144),VHStreamOptionStreamType:@(VHInteractiveStreamTypeAudioAndVideo)}
- (instancetype)initCameraViewWithFrame:(CGRect)frame options:(NSDictionary<VHStreamKey, id> *)options;

/// 创建本地录屏view 使用自定义 视频参数
/// @param frame frame
/// @param attributes  流自定义信息
/// @param isShowVideo 是否回显录屏画面 建议不回显 NO，后台运行会有离屏渲染
- (instancetype)initScreenViewWithFrame:(CGRect)frame attributes:(NSString*)attributes isShowVideo:(BOOL)isShowVideo;

/// 创建本地录屏view 使用自定义 视频参数
/// @param frame frame
/// @param attributes  流自定义信息
/// @param isShowVideo 是否回显录屏画面 建议不回显 NO，后台运行会有离屏渲染
/// @param port 默认 18999
- (instancetype)initScreenViewWithFrame:(CGRect)frame attributes:(NSString*)attributes isShowVideo:(BOOL)isShowVideo post:(uint16_t)port;

/// 创建本地录屏view 使用自定义 视频参数
/// @param frame frame
/// @param options  如：@{VHFrameResolutionTypeKey:@(VHFrameResolution192x144),VHStreamOptionStreamType:@(VHInteractiveStreamTypeAudioAndVideo)}
/// @param attributes  流自定义信息
/// @param isShowVideo 是否回显录屏画面 建议不回显 NO，后台运行会有离屏渲染
/// @param port 默认 18999
- (instancetype)initScreenViewWithFrame:(CGRect)frame options:(NSDictionary*)options attributes:(NSString*)attributes isShowVideo:(BOOL)isShowVideo post:(uint16_t)port;

/// 更新推流参数 要求推流之前设置有效 本地流有效
/// @param options  如：@{VHFrameResolutionTypeKey:@(VHFrameResolution192x144),VHStreamOptionStreamType:@(VHInteractiveStreamTypeAudioAndVideo)}
- (void)updateOptions:(NSDictionary<VHStreamKey, id> *)options;

/// 实时改变摄像头分辨率和帧率
/// @param resolution 分辨率
/// @param fps 帧率，0 < fps < 31
/// @link 推流过程中 尽量保持跟之前帧率一致
- (BOOL)changeCaptureResolution:(VHFrameResolutionValue)resolution fps:(NSInteger)fps;

/// 设置预览画面方向
- (BOOL)setDeviceOrientation:(UIDeviceOrientation)deviceOrientation;

/// 设置推流时流中携带自定义数据
/// @param attributes 通过订阅view 的 streamAttributes 读取
- (void)setAttributes:(NSString *_Nonnull)attributes;

/// 手动设置对焦点
/// @param focusPoint 对焦点
- (void)focusRenderViewPoint:(CGPoint)focusPoint;

/// 是否有音频
- (BOOL) hasAudio;

/// 是否有视频
- (BOOL) hasVideo;


/// 切换前后摄像头
- (AVCaptureDevicePosition) switchCamera;

/// 镜像前置摄像头
- (void)camVidMirror:(BOOL)mirror;

/// 获取流状态
/// @param callback 监听回调
/// @discussion 注意：如果开启了流状态监听，必须调用stopStats 停止监听，否则无法释放造成内存泄漏
- (void)getSsrcStats:(StatsCallback _Nonnull)callback;

/// 流状态监听
/// @param callback 监听回调
/// @discussion 注意：如果开启了流状态监听，必须调用stopStats 停止监听，否则无法释放造成内存泄漏
- (BOOL) startStatsWithCallback:(StatsCallback )callback __deprecated_msg("推荐使用新的监听逻辑 `-getSsrcStats:`");


/// 停止流状态监听
- (void)stopStats __deprecated_msg("若使用新监听逻辑`-getSrcStarts:`，则无需调用该方法");

/// 切换大小流
/// @param type 0 是小流 1是大流
/// @param finish 完成回调(code 200 成功)
- (void)switchDualType:(int)type finish:(void(^)(int code, NSString * _Nullable message))finish;

/// 配置旁路混流主屏
/// @param mode 默认传 nil
/// @param finish 完成回调(code 200 成功)
- (void)setMixLayoutMainScreen:(NSString*_Nullable)mode finish:(FinishBlock _Nullable)finish;

/// 当前设备支持的分辨率列表 移动端不建议设置480*360分辨率以上推流
+ (NSArray<NSString *> *)availableVideoResolutions;

/// 设置美颜参数，只对本地流起作用
/// @param distanceNormalizationFactor 4.0
/// @param brightness 1.15
/// @param saturation 1.1
/// @param sharpness 0.0
- (void)setFilterBilateral:(CGFloat)distanceNormalizationFactor Brightness:(CGFloat)brightness Saturation:(CGFloat)saturation Sharpness:(CGFloat)sharpness;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

@end

#pragma mark- 第三方美颜
@interface VHRenderView (ThirdpartyBeautify)
/// 使用VHBeautifyTool美颜
/// @param module 来自于VHBeautifyTool中的Module
- (void)useBeautifyModule:(id<IVHBeautifyModule>)module HandleError:(void(^)(NSError *error))handle;

@end

#pragma mark- 快直播
@interface VHRenderView (FastPlayer)
/// 快直播定义
+ (VHRtcPlayer *)fastLivePlayer;

@end
NS_ASSUME_NONNULL_END
