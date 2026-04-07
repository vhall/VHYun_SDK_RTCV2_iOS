//
//  VHInteractiveRoom.h
//  VHInteractive
//
//  Created by vhall on 2018/4/17.
//  Copyright © 2018年 www.vhall.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VHRTCV2/VHInteractiveRoomDelegate.h>
#import <VHRTCV2/VHIStream.h>
#import <VHRTCV2/VHRenderView.h>
#import <VHRTCV2/VHTVideoConfig.h>
#import <VHRTCV2/VHInteractiveCode.h>

NS_ASSUME_NONNULL_BEGIN

@interface VHInteractiveRoom : NSObject

@property (nonatomic, weak) id <VHInteractiveRoomDelegate> delegate;
@property (nonatomic, readonly) VHRTCCoreType coreType;         ///< 标记使用 VRTC 还是 TRTC
@property (nonatomic, readonly) VHInteractiveRoomStatus status; ///< 当前房间状态
@property (nonatomic, readonly, weak) VHRenderView *cameraView; ///< 当前推流的cameraView (只在推流过程中存在)
@property (nonatomic, readonly) NSDictionary *renderViewsById;  ///< 所有其他进入本房间的视频view
@property (nonatomic, readonly) NSArray<NSString *> *streams;   ///< 房间中所有可以观看的流id列表
@property (nonatomic, readonly) NSString *roomId;               ///< 房间id
@property (nonatomic, readonly) NSString *broadCastId;      	///< 旁路房间ID
@property (nonatomic, readonly) BOOL isPublishing;          	///< 当前推流状态 (是否正在推流)
@property (nonatomic, readonly) VHInteractiveRoomMode mode; 	///< 房间类型
@property (nonatomic, readonly) VHInteractiveRoomRole role; 	///< 房间权限
@property (nonatomic) int reconnectTimes;                   	///< 房间重连次数 (默认 5次)
@property (nonatomic) BOOL isOnlyAudioSubscribe;            	///< 是否只订阅音频流 (默认为NO 订阅音视频流 YES只订阅音频流) (可以中途 unmuteVideo 打开视频)
@property (nonatomic) BOOL isAdaptResolution;					///< 自适应分辨率 (默认开启, 根据网速来降低分辨率)
@property (nonatomic) BOOL isAutoSubscribeDocStream;				///< 是否开启文档融屏流的订阅
@property (nonatomic) BOOL isAutoSubscribeVideoPatroStream;                    ///< 是否开启视频轮训的订阅
@property (nonatomic) BOOL isAutoSubscribeCloudPlayer;	///< 是否开启云端插播的订阅
@property (nonatomic) VHScalingMode scalingMode;				///< 画面推流的填充模式
@property (nonatomic, readonly) NSArray *permission;
@property (nonatomic, readonly) VHTStream *localStream;			///< TRTC 本地流
@property (nonatomic) VHTVideoConfig *localVideoConfig;			///< TRTC 本地流设置项
@property(nonatomic) NSString* streamAttributes;
@property (nonatomic, strong) id<IVHBeautifyModule> beautifyModule;


/*
 * 进入互动房间后可用权限
 * 注: didEnterRoom 后调用有效 具体权限如下：
 kick_inav              踢出互动房间 / 取消踢出互动房间
 kick_inav_stream       踢出路流 / 取消踢出流
 publish_inav_another   推旁路直播 / 结束推旁路直播
 apply_inav_publish     申请上麦
 publish_inav_stream    推流
 askfor_inav_publish    邀请用户上麦推流
 audit_inav_publish     审核申请上麦
 force_leave_inav       强制用户下线
 */

- (instancetype)initWithLogParam:( NSDictionary* _Nullable )logParam AndvancedBeautify:(id<IVHBeautifyModule>)module;

#pragma mark - 房间操作
/// 加入房间
/// @param inav_id 互动房间id
/// @param accessToken accessToken
/// @discussion 调用完成等待代理回调确认接下来操作
- (void)enterRoomWithRoomId:(NSString *)inav_id accessToken:(NSString *)accessToken;

/// 加入房间
/// @param inav_id 互动房间id
/// @param accessToken accessToken
/// @param userData 用户数据可以携带不超过255字符的字符串 可在VHRenderView中获取此值
/// @discussion 调用完成等待代理回调确认接下来操作
- (void)enterRoomWithRoomId:(NSString *)inav_id accessToken:(NSString *)accessToken userData:(NSString * _Nullable )userData;

/// 加入房间
/// @param inav_id 互动房间id
/// @param broadCastId 旁路房间id
/// @param accessToken accessToken
/// @param userData 用户数据可以携带不超过255字符的字符串 可在VHRenderView中获取此值
/// @discussion 调用完成等待代理回调确认接下来操作
- (void)enterRoomWithRoomId:(NSString *)inav_id broadCastId:(NSString *)broadCastId accessToken:(NSString *)accessToken userData:(NSString*)userData;

/// 加入房间
/// @param inav_id 互动房间id
/// @param broadCastId 旁路房间id
/// @param accessToken accessTokenx
/// @param userData 用户数据可以携带不超过255字符的字符串 可在VHRenderView中获取此值
/// @param mode 应用场景模式，选填，可选值参考 VHInteractiveRoomMode。支持版本：2.3.2及以上
/// @param role 用户角色，选填，可选值参考下文VHInteractiveRoomRole。当mode为rtc模式时，不需要配置role。支持版本：2.3.2及以上
/// @discussion 调用完成等待代理回调确认接下来操作
- (void)enterRoomWithRoomId:(NSString *)inav_id broadCastId:(NSString *)broadCastId accessToken:(NSString *)accessToken userData:(NSString*)userData mode:(VHInteractiveRoomMode)mode role:(VHInteractiveRoomRole)role;

/// 加入房间
/// @param inav_id 互动房间id
/// @param broadCastId 旁路房间id
/// @param accessToken  accessToken
/// @param userData  用户数据可以携带不超过255字符的字符串 可在VHRenderView中获取此值
/// @param isScreenShare  是否录屏互动
/// 调用完成等待代理回调确认接下来操作
- (void)enterRoomWithRoomId:(NSString *)inav_id broadCastId:(NSString *)broadCastId accessToken:(NSString *)accessToken userData:(NSString*)userData screenShare:(BOOL )isScreenShare;


/// 离开房间
- (void)leaveRoom;

#pragma mark - 本地设备操作 (TRTC)
///开启本地预览（TRTC）
-(void)startLocalPreview;

///日志上报内容
-(void)setExtraReportParam:(NSString*)param;

///停止本地预览（TRTC）
-(void)stopLocalPreview;

///设置推流分辨率(TRTC)
-(void)updatePushResolution:(BroadcastDefinition)config;

/// 禁画(TRTC)
- (void)muteVideo:(BOOL)isMute;

/// 禁画(TRTC)
- (void)muteRemoteVideo:(NSString*)streamId mute:(BOOL)mute;

///设置图片推流(TRTC)
- (void)startVirtualCamera:(UIImage *)image;

/// 静音(TRTC)
- (void)muteAudio:(BOOL)isMute;
-(void)muteRemoteAudio:(NSString*)streamId mute:(BOOL)mute;

/// 镜像本地回显画面(TRTC)
- (void)camVidMirror:(BOOL)mirror;

#pragma mark - 上下麦操作

/// 上麦推流（通用）
/// @param cameraView 本地摄像头view 也可以是录屏view 尝试推录屏流 需要同步启动 系统录屏界面触发正式推流
/// @return 如果False:请检查cameraView 是否创建， 进入房间角色是否是观众
- (BOOL)publishWithCameraView:(VHRenderView*)cameraView error:(NSError **)error;
- (BOOL)publishWithCameraView:(VHRenderView*) cameraView __deprecated_msg("use -[publishWithCamerView: error:]");
- (void)publishWithScreenSharedWithError:(NSError **)error;

/// 下麦停止推流（通用）
- (BOOL)unpublish;

#pragma mark - 视频处理
/// 切换摄像头（通用）
- (void)switchLocalCamera;

/// 接收他人视频数据（VRTC）
/// @param streamId 他人视频 streamId
- (BOOL)addVideo:(NSString*)streamId;

/// 不接收他人视频数据
/// @param streamId 他人视频 streamId
- (BOOL)removeVideo:(NSString*)streamId;

#pragma mark - 上下麦许可操作

/// 互动房间用户列表
/// @param block 结果回调
/// @link
///     userList 结构: [{third_party_user_id:"", status:""}]
///     third_party_user_id 第三方用户ID
///     status 用户状态 1:推流中 2:观看中 3:受邀中 4:申请上麦中
- (BOOL)inviteUserList:(void(^)(NSArray *userList, NSError *error))block;

/// 互动房间被踢出用户列表
/// @param block 结果回调
/// @link
///     userList 结构: [{third_party_user_id:"", status:""}]
///     third_party_user_id 第三方用户ID
///     status 用户状态 1:推流中 2:观看中 3:受邀中 4:申请上麦中
- (BOOL)kickoutUserList:(void(^)(NSArray *userList,NSError *error)) block;

#pragma mark - 旁路操作
/// 设置是否加入混流
- (void)setRoomBroadCastMixOption:(NSDictionary *)dict mode:(NSString *)modeStr finish:(void(^)(int code, NSString * message))handle;

/// 开启/关闭旁路直播 (使用该方法前提:加入房间初始化方法使用enterRoomWithRoomId:broadCastId:accessToken:userData:)
/// @param isOpen Yes开启旁路直播   NO关闭旁路直播
/// @param param [self baseConfigRoomBroadCast:4 layout:4]; 调用此函数配置视频质量参数和旁路布局
/// @discussion 设置成功后会自动推旁路
- (BOOL)publishAnotherLive:(BOOL)isOpen param:(NSDictionary*)param completeBlock:(void(^)(NSError *error))block;

/// 基础配置旁路混流参数
/// @param definition 视频质量参数，推荐使用。即（分辨率+帧率+码率）
/// @param layout 旁路布局模板（非自定义布局）
- (NSDictionary*)baseConfigRoomBroadCast:(BroadcastDefinition)definition layout:(BroadcastLayout)layout;

/// 修改旁路混流布局
/// @param layoutMode VHBroadCastDef.h ==> BroadcastLayout
/// @param mode mode 默认nil
/// @param finish 完成的回调
- (void)setMixLayoutMode:(int)layoutMode mode:(NSString*_Nullable)mode finish:(VhallFinishBlock _Nullable)finish;


/// 设置某一路流为主屏
/// @param stream 流 @link VHTStream || VHRenderView
/// @param finish 完成的回调
- (void)settingRoomBroadCastMainScreenFromStream:(id<VHIStream>)stream finish:(VhallFinishBlock)finish;

/// 设置当前画面为主屏
/// @param handle 完成的回调
- (void)settingRoomBroadCastMainScreenFromCamera:(VhallFinishBlock _Nullable)handle __deprecated_msg(" 使用 settingRoomBroadCastMainScreenFromStream:finish: 更加灵活");

/// 设置当前文档融屏为主屏
/// @param handle 完成的回调
- (void)settingRoomBroadCastMainScreenFromDocMix:(VhallFinishBlock _Nullable)handle;

/// 设置旁路背景图
/// @param url 背景图URL,如果为空，则为取消背景图
/// @param cropType 填充类型 : VHScalingMode
/// @param finish 设置后的回调, 成功 : 200
- (void)settingRoomBroadCastBackgroundImageURL:(NSURL *_Nullable)url cropType:(VHScalingMode)cropType finishHandle:(VhallFinishBlock _Nullable)finish;


/// 设置旁路头像占位图
/// @param url 头像占位图URL,如果为空，则为取消占位图
/// @param finish 设置后的回调,成功:200
- (void)settingRoomBroadCastPlaceholderImageURL:(NSURL *_Nullable)url finishHandle:(VhallFinishBlock _Nullable)finish;

/// 是否开启文档融屏旁路
/// @param enable 开启/关闭
/// @param channelID 文档channelID
/// @param finish 设置后的回调,成功:20041
- (void)settingRoomBroadCastDocMixEnable:(BOOL)enable channelID:(NSString *)channelID finishHandle:(VhallFinishBlock _Nullable)finish;

/// 获得当前SDK版本号
+ (NSString *)getSDKVersion;

/// 是否开启扬声器输出音频
- (void)setSpeakerphoneOn:(BOOL)on;

/// 切换大小流
/// @param streamId 他人视频 streamId
/// @param type 0 是小流 1是大流
/// @param finish code 200 成功 message具体信息
- (void)switchDualStream:(NSString *)streamId type:(int)type finish:(void(^)(int code, NSString * _Nullable message))finish;

/// 强制用户离开(下线)互动房间
- (BOOL)forceLeaveRoomWithInavId:(NSString *)inavId kickUserId:(NSString *)kick_user_id accessToken:(NSString *)accessToken onRequestFinished:(void(^)(id data))success onRequestFailed:(void(^)(NSError *error))failed;
@end

@interface VHInteractiveRoom(DEPRECATED)
/// 踢出互动房间并加入黑名单 或 从黑名单解禁
- (BOOL)kickoutRoom:(BOOL)isKickout thirdUserId:(NSString *)third_user_id __deprecated_msg("该操作已被移除，后续可通过业务逻辑自行实现");

/// 帮别人下麦
/// @param third_user_id 被下麦人的第三方id
- (BOOL)kickoutStreamWithThirdUserId:(NSString *)third_user_id __deprecated_msg("该操作已被移除，后续可通过业务逻辑自行实现");

/// 主播 邀请 上麦推流
/// @param third_user_id 被邀请/取消邀请人的第三方id
- (BOOL)invitePublishWithThirdUserId:(NSString *)third_user_id __deprecated_msg("该操作已被移除，后续可通过业务逻辑自行实现");
/// 拒绝被邀请上麦推流
- (BOOL)refusePublish __deprecated_msg("该操作已被移除，后续可通过业务逻辑自行实现");

/// 观众 申请上麦推流
- (BOOL)requestPublish;

/// 主播 是否接受 上麦推流申请
/// @param third_user_id 互动观众的第三方id
- (BOOL)acceptPublishRequest:(BOOL)isAccept thirdUserId:(NSString *)third_user_id __deprecated_msg("该操作已被移除，后续可通过业务逻辑自行实现");
@end

NS_ASSUME_NONNULL_END

