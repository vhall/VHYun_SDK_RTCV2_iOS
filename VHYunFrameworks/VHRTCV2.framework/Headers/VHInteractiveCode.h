//
//  VHInteractiveCode.h
//  VHInteractive
//
//  Created by Vhall on 2025/5/30.
//  Copyright © 2025 vhall. All rights reserved.
//

#ifndef VHInteractiveCode_h
#define VHInteractiveCode_h

/// 互动直播TRTC 推流网络质量类型  (TRTC)
typedef NS_ENUM(NSUInteger, VHRTCNetQualityType) {
     VHRTCNetQualityType_Unknow = 0,
     VHRTCNetQualityType_Excellent = 1,//网络非常好
     VHRTCNetQualityType_Good = 2,//网络比较好
     VHRTCNetQualityType_Poor = 3,//网络一般
     VHRTCNetQualityType_Bad = 4,//网络较差
     VHRTCNetQualityType_Vbad = 5,//网络很差
     VHRTCNetQualityType_Down = 6//网络不满足推流要求
};

typedef NS_ENUM(NSUInteger, VHRTCCodeNumber) {
     VHRTCCodeNumber_Unknow = 0,
     VHRTCCodeNumber_DISCONNECTED = 1,//网络断开
     VHRTCCodeNumber_INVALID_LICENSE= 2,//license 无效
     VHRTCCodeNumber_NET_REQUEST_ERROR = 3, //网络请求异常
     VHRTCCodeNumber_ERR_CAMERA = 4,// 摄像头未授权或打开失败
     VHRTCCodeNumber_ERR_AUDIO = 5,// 麦克风未授权或打开失败
     VHRTCCodeNumber_ERR_ENTER_ROOM = 6,// 进入房间失败，请检查相关网络
     VHRTCCodeNumber_ENTER_ROOM_REFUSED = 7,// 进入房间被拒绝，是否user重复进入
     VHRTCCodeNumber_ROOM_DISCONNECT = 8,// 房间链接已断开
     VHRTCCodeNumber_ROOM_CONNECTING = 9,// 房间链接正在重连
     VHRTCCodeNumber_ROOM_CONNECTED = 10,// 链接已恢复
};

/// 互动直播TRTC推流横竖屏设置  (TRTC)
typedef NS_ENUM(NSUInteger, VHPushMode) {
     VHPushMode_ResolutionModePortrait = 0, //竖屏模式
     VHPushMode_ResolutionModeLandscape = 1 //横屏模式
};

#endif /* VHInteractiveCode_h */
