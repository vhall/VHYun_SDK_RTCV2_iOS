//
//  VHInteractiveRoomDelegate.h
//  VHInteractive
//
//  Created by LiGuoliang on 2022/10/14.
//  Copyright © 2022 vhall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VHRTCV2/VHBroadCastDef.h>


@class VHInteractiveRoom;
@class VHTStream;
@class VHRenderView;

// param code 200 success ,otherwise fail;
typedef void(^VhallFinishBlock)(int code, NSString * _Nonnull message);

NS_ASSUME_NONNULL_BEGIN
@protocol VHInteractiveRoomDelegate <NSObject>
/// 房间错误回调
- (void)room:(VHInteractiveRoom *)room error:(NSError*)error;

/// 房间状态变化
- (void)room:(VHInteractiveRoom *)room didChangeStatus:(VHInteractiveRoomStatus)status;

/// 进入互动房间
- (void)room:(VHInteractiveRoom *)room didEnterRoom:(NSString *)third_user_id;

/// 离开互动房间
- (void)room:(VHInteractiveRoom *)room didLeaveRoom:(NSString *)third_user_id isKickOutRoom:(BOOL)isKickOut;

/// 他人上麦消息
- (void)room:(VHInteractiveRoom *)room didAddAttendView:(VHRenderView *)attendView;

/// 他人下麦消息
- (void)room:(VHInteractiveRoom *)room didRemovedAttendView:(VHRenderView *)attendView;

/// TRTC 有流进入
- (void)room:(VHInteractiveRoom *)room didRoomPublishStartWithStream:(VHTStream *)stream;

/// TRTC 有流停止
- (void)room:(VHInteractiveRoom *)room didRoomPublishStopWithStream:(VHTStream *)stream;

/// TRTC 有流更新
- (void)room:(VHInteractiveRoom *)room didRoomUpdateWithStream:(VHTStream *)stream;

/// 文档融屏流上线(订阅)
- (void)room:(VHInteractiveRoom *)room didAddDocmentAttendView:(VHRenderView *)attendView;

/// 文档融屏流下线(订阅)
- (void)room:(VHInteractiveRoom *)room didRemovedDocmentAttendView:(VHRenderView *)attendView;

/// TRTC 网络推流质量。quality 参考VHRTCNetQualityType
- (void)room:(VHInteractiveRoom *)room onNetworkQuality:(NSInteger )quality;

/// TRTC错误事件
- (void)room:(VHInteractiveRoom *)room onError:(NSInteger )code msg:(NSString*)msg;

/// TRTC警告事件
- (void)room:(VHInteractiveRoom *)room onWarning:(NSInteger )code msg:(NSString*)msg;
#pragma mark - 上下麦推流信息回调

/// 上下麦
/// @param room 房间信息
/// @param canPublish 是否可以上麦推流
/// @param type 1、进入房间后有无上麦推流权限 2、申请上麦 审核后有无上麦推流权限 3、收到邀请上麦消息 获得上麦推流权限
- (void)room:(VHInteractiveRoom *)room canPublish:(BOOL)canPublish type:(int) type;

/// 房间人员信息变化
/// @param info 数据结构
/// @link
///   info {...}
///     status 0 人员变化 1 上麦 2 下麦 3拒绝上麦
///     third_party_user_id 操作人id
///     online 在线人数
///     nick_name 昵称
///     avatar 头像
- (void)room:(VHInteractiveRoom *)room userChangeInfo:(NSDictionary * _Nullable)info;

/// 推流成功
- (void)room:(VHInteractiveRoom *)room didPublish:(VHRenderView *)cameraView;

/// 停止推流成功
/// @param reason  "主动下麦" "被动下麦"
- (void)room:(VHInteractiveRoom *)room didUnpublish:(NSString *)reason;

/// 强制用户下线的消息
- (void)room:(VHInteractiveRoom *)room force_leave_inav:(NSString *)third_user_id;

/// 流音视频开启情况
/// @param streamId 流id
/// @param muteStream 流音视频开启情况
- (void)room:(VHInteractiveRoom *)room didUpdateOfStream:(NSString *)streamId muteStream:(NSDictionary *)muteStream;

/// 服务器已准备好混流可以调用混流接口
/// @param msg 详细消息
- (void)room:(VHInteractiveRoom *)room onStreamMixed:(NSDictionary *)msg;

/// 文档融屏开启成功
/// @param room VHInteractiveRoom
/// @param msg 详细消息
- (void)room:(VHInteractiveRoom *)room didInternalStreamAdded:(NSDictionary *)msg;

/// 文档容屏停止
/// @param room VHInteractiveRoom
/// @param msg 详细消息
- (void)room:(VHInteractiveRoom *)room didInternalStreamRemoved:(NSDictionary *)msg;

/// 接收到自定义消息(TRTC有效)
/// @param room VHInteractiveRoom
/// @param message 消息内容
- (void)room:(VHInteractiveRoom *)room receiveMessage:(NSString *)message;

/// 接收到自定义SEI消息(TRTC有效)
/// @param room VHInteractiveRoom
/// @param message 消息内容
- (void)room:(VHInteractiveRoom *)room receiveSEIMessage:(NSString *)message;
@end
NS_ASSUME_NONNULL_END
