//
//  VHTVideoConfig.h
//  VHRTC
//
//  Created by LiGuoliang on 2022/11/2.
//  Copyright © 2022 vhall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VHBroadCastDef.h"


NS_ASSUME_NONNULL_BEGIN

@interface VHTVideoConfig : NSObject
@property (nonatomic) BroadcastDefinition resolution;	///< 分辨率
@property (nonatomic) int fps;							///< 帧率 (0 为依据分辨率自动设置)
@property (nonatomic) int bitrate;						///< 码率 (0 为依据分辨率自动设置)
@property (nonatomic) int bitrateMin;					///< 最低码率 (0 为依据分辨率自动设置。"码率>=最低码率")
@property (nonatomic) VHScalingMode scalingMode;		///< 缩放模式
@property (nonatomic) BroadcastLayout broadCastLayout;	///< 旁路布局
@property (nonatomic) BOOL useCameraBack;   			///< 使用前后摄像头 (默认前)
@property (nonatomic) BOOL mirror;                  ///<  镜像设置
@end

NS_ASSUME_NONNULL_END
