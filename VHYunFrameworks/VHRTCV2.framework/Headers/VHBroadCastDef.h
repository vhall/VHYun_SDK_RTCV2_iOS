//
//  VHBroadCastDef.h
//  VhallRTC
//
//  Created by vhall on 2020/6/1.
//  Copyright © 2020 ilong. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef VHBroadCastDef_h
#define VHBroadCastDef_h

typedef NSString * VHStreamKey NS_STRING_ENUM;


/// 推流参数-同时推流数 (默认:1)
/// - 1 : 只推1路流
/// - 2 : 发起端推送大小两路流，用于超多人互动场景
FOUNDATION_EXTERN VHStreamKey const VHSimulcastLayersKey;

/// 推流类型 (默认:VHInteractiveStreamTypeAudioAndVideo)
/// @link VHInteractiveStreamType
FOUNDATION_EXTERN VHStreamKey const VHStreamOptionStreamType;

/// 推流分辨率 (默认:VHFrameResolution192x144)
/// @link VHFrameResolutionValue
FOUNDATION_EXTERN VHStreamKey const VHFrameResolutionTypeKey;

/// 旁路混流是否加入视频
FOUNDATION_EXTERN VHStreamKey const VHStreamOptionMixVideo;

/// 旁路混流是否加入音频
FOUNDATION_EXTERN VHStreamKey const VHStreamOptionMixAudio;

/// 视频
FOUNDATION_EXTERN VHStreamKey const VHStreamOptionVideo;

/// 音频
FOUNDATION_EXTERN VHStreamKey const VHStreamOptionAudio;


typedef NSString * VHVideoKey NS_STRING_ENUM;
/// 推流视频宽度 (默认 : 192)
/// @discussion 如果设置了VHFrameResolutionTypeKey此参数可不设置
FOUNDATION_EXTERN VHVideoKey const VHVideoWidthKey;

/// 推流视频高度 (默认 : 144)
/// @discussion 如果设置了VHFrameResolutionTypeKey此参数可不设置
FOUNDATION_EXTERN VHVideoKey const VHVideoHeightKey;

/// 推流视频帧率 (默认 : 30)
/// @discussion 如果设置了VHFrameResolutionTypeKey此参数可不设置
FOUNDATION_EXTERN VHVideoKey const VHVideoFpsKey;

/// 推流最大码率 (默认 : 300)
/// @discussion 如果设置了VHFrameResolutionTypeKey此参数可不设置
FOUNDATION_EXTERN VHVideoKey const VHMaxVideoBitrateKey;

/// 当前推流码率
/// @discussion 如果设置了VHFrameResolutionTypeKey此参数可不设置
FOUNDATION_EXTERN VHVideoKey const VHCurrentBitrateKey;

/// 推流最小码率 (默认 : 100)
/// @discussion 如果设置了VHFrameResolutionTypeKey此参数可不设置
FOUNDATION_EXTERN VHVideoKey const VHMinBitrateKbpsKey;


#pragma mark - ENUMS

/// 互动直播核心类型  (通用)
typedef NS_ENUM(NSUInteger, VHRTCCoreType) {
	VHRTCCoreTypeVRTC = 1,
	VHRTCCoreTypeTRTC = 2
};

/// 缩放模式 (通用)
typedef NS_ENUM(NSUInteger, VHScalingMode) {
	VHScalingModeFill,			///< 不按内容比例缩放填充，会变形，不裁切。内容和容器尺寸比例不一致时会导致内容宽高比改变
	VHScalingModeAspectFit,		///< 按照内容比例缩放填充，不变形，不裁切。内容和容器尺寸比例不一致时会露出容器背景色
	VHScalingModeAspectFill,	///< 按照内容比例缩放填充，不变形，会裁切。内容和容器尺寸比例不一致时会保证容器填充满，超出容器的部分会被裁切
};

/// 互动房间状态 (VRTC)
typedef NS_ENUM(NSInteger, VHInteractiveRoomStatus) {
	VHInteractiveRoomStatusReady,
	VHInteractiveRoomStatusConnected,
	VHInteractiveRoomStatusDisconnected,
	VHInteractiveRoomStatusError
};

/// 房间类型 (VRTC)
typedef NS_ENUM(NSInteger, VHInteractiveRoomMode) {
	VHInteractiveRoomModeRTC,       // 默认为互动房间 实时通信场景，例如互动连麦
	VHInteractiveRoomModeLive       // 无延迟直播房间 直播场景，例如无延迟直播
};

/// 用户角色 (VRTC)
typedef NS_ENUM(NSInteger, VHInteractiveRoomRole) {
	VHInteractiveRoomRoleHost,      // 可以发布和订阅互动流
	VHInteractiveRoomRoleAudience   // 只能订阅互动流，无法发布
};

/// 流定义  (TRTC)
typedef NS_ENUM(NSUInteger, VHRTCStreamType) {
	VHRTCStreamTypeBig = 0,
	VHRTCStreamTypeSmall = 1,
	VHRTCStreamTypeSub = 2,
};

/// 摄像头及推流参数设置 (VRTC)
typedef NS_ENUM(NSInteger, VHPushType) {
	VHPushTypeNone, //未知，使用默认设置
	VHPushTypeSD,   //默认192x144
	VHPushTypeHD,   //352x288
	VHPushTypeUHD,  //480x360
	VHPushTypeCUSTOM//
};

/// 互动流类型 (通用)
typedef NS_ENUM(int, VHInteractiveStreamType) {
	VHInteractiveStreamTypeOnlyAudio		= 0,	///< 仅音频
	VHInteractiveStreamTypeOnlyVideo		= 1,	///< 仅视频
	VHInteractiveStreamTypeAudioAndVideo	= 2,	///< 视频+音频 ** 主路默认 **
	VHInteractiveStreamTypeScreen			= 3,	///< 屏幕共享 ** 辅路默认 **
	VHInteractiveStreamTypeFile				= 4,	///< 文件插播
	VHInteractiveStreamTypeVideoPatrol		= 5,	///< 视频轮询
	VHInteractiveStreamTypeCustom			= 6,	///< 自定义
	VHInteractiveStreamTypeSoftWare			= 7,	///< 移动端不使用该项
	VHInteractiveStreamTypeDocumentMix		= 100,	///< 文档融屏
     VHInteractiveStreamTypeCloudPlayer
};

/// 分辨率 (VRTC)
typedef NS_ENUM(int, VHFrameResolutionValue) {
	VHFrameResolution192x144 = 0,
	VHFrameResolution240x160 = 1,
	VHFrameResolution320x240 = 2,
	VHFrameResolution480x360 = 3,
	VHFrameResolution570x432 = 4,
	VHFrameResolution640x480 = 5
};

/// 旁路设置 宽高比+分辨率+帧率+码率  (通用)
typedef NS_ENUM(NSInteger,  BroadcastDefinition) {
	BROADCAST_VIDEO_PROFILE_480P_0   = 0,			///< (横屏) 4:3	| Size:(640x480)	| FPS : 25	| Bitrate : 700
	BROADCAST_VIDEO_PROFILE_480P_1   = 1,			///< (横屏) 16:9	| Size:(852x480)	| FPS : 25	| Bitrate : 750
	BROADCAST_VIDEO_PROFILE_540P_0   = 2,			///< (横屏) 4:3	| Size:(720x540)	| FPS : 25	| Bitrate : 950
	BROADCAST_VIDEO_PROFILE_540P_1   = 3,			///< (横屏) 16:9	| Size:(960x540)	| FPS : 25	| Bitrate : 1150
	BROADCAST_VIDEO_PROFILE_720P_0   = 4,			///< (横屏) 4:3	| Size:(960x720)	| FPS : 25	| Bitrate : 1400
	BROADCAST_VIDEO_PROFILE_720P_1   = 5,			///< (横屏) 16:9	| Size:(1280X720)	| FPS : 25	| Bitrate : 1600
	BROADCAST_VIDEO_PROFILE_960P_0   = 6,			///< (横屏) 4:3	| Size:(1280x960)	| FPS : 25	| Bitrate : 1600
	BROADCAST_VIDEO_PROFILE_960P_1   = 7,			///< (横屏) 16:9	| Size:(1712x960)	| FPS : 25	| Bitrate : 1900
	BROADCAST_VIDEO_PROFILE_1080P_0  = 8,			///< (横屏) 4:3	| Size:(1440X1080)	| FPS : 25	| Bitrate : 1800
	BROADCAST_VIDEO_PROFILE_1080P_1  = 9,			///< (横屏) 16:9	| Size:(1920X1080)	| FPS : 25	| Bitrate : 2200
	BROADCAST_VIDEO_PROFILE_480P_1_VERTICAL = 10,	///< (竖屏) 9:16	| Size:(480x852)	| FPS : 25	| Bitrate : 750
	BROADCAST_VIDEO_PROFILE_540P_1_VERTICAL = 11,	///< (竖屏) 9:16	| Size:(540x960)	| FPS : 25	| Bitrate : 1150
	BROADCAST_VIDEO_PROFILE_720P_1_VERTICAL = 12,	///< (竖屏) 9:16	| Size:(720x1280)	| FPS : 25	| Bitrate : 1600
	BROADCAST_VIDEO_PROFILE_1080P_1_VERTICAL = 13,	///< (竖屏) 9:16	| Size:(1080x1920)	| FPS : 25	| Bitrate : 2200
};

/// 旁路混流布局  (通用)
typedef NS_ENUM(NSInteger, BroadcastLayout) {
	CANVAS_LAYOUT_PATTERN_GRID_1  				= 0,	///< 一人铺满
	CANVAS_LAYOUT_PATTERN_GRID_2_H				= 1,	///< 左右两格
	CANVAS_LAYOUT_PATTERN_GRID_3_E				= 2,	///< 正品字
	CANVAS_LAYOUT_PATTERN_GRID_3_D				= 3,	///< 倒品字
	CANVAS_LAYOUT_PATTERN_GRID_4_M				= 4,	///< 2行x2列
	CANVAS_LAYOUT_PATTERN_GRID_5_D				= 5,	///< 2行，上2下3
	CANVAS_LAYOUT_PATTERN_GRID_6_E				= 6,	///< 2行x3列
	CANVAS_LAYOUT_PATTERN_GRID_9_E				= 7,	///< 3行x3列
	CANVAS_LAYOUT_PATTERN_FLOAT_2_1DR   		= 8,	///< 主次悬浮，大屏铺满，小屏悬浮右下角 (小窗宽=画布宽度/5，比例为4:3)
	CANVAS_LAYOUT_PATTERN_FLOAT_2_1DL   		= 9,	///< 主次悬浮，大屏铺满，小屏悬浮左下角 (小窗宽=画布宽度/5，比例为4:3)
	CANVAS_LAYOUT_PATTERN_FLOAT_3_2DL   		= 10,	///< 大屏铺满，2小屏悬浮右上角 (小窗宽=画布宽度/6，比例为4:3)
	CANVAS_LAYOUT_PATTERN_FLOAT_6_5D    		= 11,	///< 主次悬浮，大屏铺满，一行5个悬浮于下面 (小窗宽=画布宽度/5，比例为4:3)
	CANVAS_LAYOUT_PATTERN_FLOAT_6_5T    		= 12,	///< 主次悬浮，大屏铺满，一行5个悬浮于上面 (小窗宽=画布宽度/5，比例为4:3)
	CANVAS_LAYOUT_PATTERN_TILED_5_1T4D  		= 13,	///< 主次平铺，一行4个位于底部
	CANVAS_LAYOUT_PATTERN_TILED_5_1D4T  		= 14,	///< 主次平铺，一行4个位于顶部
	CANVAS_LAYOUT_PATTERN_TILED_5_1L4R  		= 15,	///< 主次平铺，一列4个位于右边
	CANVAS_LAYOUT_PATTERN_TILED_5_1R4L  		= 16,	///< 主次平铺，一列4个位于左边
	CANVAS_LAYOUT_PATTERN_TILED_6_1T5D  		= 17,	///< 主次平铺，一行5个位于底部
	CANVAS_LAYOUT_PATTERN_TILED_6_1D5T  		= 18,	///< 主次平铺，一行5个位于顶部
	CANVAS_LAYOUT_PATTERN_TILED_9_1L8R  		= 19,	///< 主次平铺，右边为（2列x4行=8个块）
	CANVAS_LAYOUT_PATTERN_TILED_9_1R8L  		= 20,	///< 主次平铺，左边为（2列x4行=8个块）
	CANVAS_LAYOUT_PATTERN_TILED_13_1L12R		= 21,	///< 主次平铺，右边为（3列x4行=12个块）
	CANVAS_LAYOUT_PATTERN_TILED_17_1TL16GRID  	= 22,	///< 主次平铺，1V16，主屏在左上角
	CANVAS_LAYOUT_PATTERN_TILED_9_1D8T        	= 23,	///< 主次平铺，主屏在下，8个（2行x4列）在上
	CANVAS_LAYOUT_PATTERN_TILED_13_1TL12GRID  	= 24,	///< 主次平铺，主屏在左上角，其余12个均铺于其他剩余区域
	CANVAS_LAYOUT_PATTERN_TILED_17_1TL16GRID_E	= 25,	///< 主次平铺，主屏在左上角，其余16个均铺于其他剩余区域
	CANVAS_LAYOUT_PATTERN_CUSTOM              	= 27,	///< 自定义，当使用坐标布局接口时，请使用此
	CANVAS_LAYOUT_EX_PATTERN_GRID_12_E        	= 28,	///< 3行4列等分布局
	CANVAS_LAYOUT_EX_PATTERN_GRID_16_E        	= 29,	///< 4行4列等分布局
	CANVAS_LAYOUT_EX_PATTERN_FLOAT_2_1TR      	= 30,	///< 主次悬浮，大屏铺满，小屏悬浮右上角 (小窗宽=画布宽度/5，比例为4:3)支持竖版布局，参考PaaS需求： paas pm
	CANVAS_LAYOUT_EX_PATTERN_FLOAT_2_1TL      	= 31,	///< 主次悬浮，大屏铺满，小屏悬浮左上角 (小窗宽=画布宽度/5，比例为4:3)支持竖版布局，参考PaaS需求： paas pm
	CANVAS_ADAPTIVE_LAYOUT_GRID_MODE        	= 101,	///< 自适应均分模式
	CANVAS_ADAPTIVE_LAYOUT_TILED_MODE       	= 102,	///< 自适应平铺模式
	CANVAS_ADAPTIVE_LAYOUT_FLOAT_MODE       	= 103,	///< 自适应悬浮模式
	CANVAS_ADAPTIVE_LAYOUT_TILED_EXT1_MODE  	= 104,	///< 窗格位于主屏上方，最多16窗格
};

@interface VHBroadCastDef : NSObject
/// 配置旁路混流参数(自适应)
/// @param definition 视频质量参数，推荐使用。即（分辨率+帧率+码率）
/// @param url 推流地址
/// @param layout 布局模式(包括了手动布局和自适应布局)
+ (NSDictionary *)baseConfigRoomBroadCast:(BroadcastDefinition)definition broadCastUrl:(NSString*)url layout:(BroadcastLayout)layout;
@end

#endif /* VHBroadCastDef_h */
