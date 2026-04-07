//
//  VHIStream.h
//  VHInteractive
//
//  Created by LiGuoliang on 2022/11/7.
//  Copyright © 2022 vhall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VHRTCV2/VHBroadCastDef.h>

NS_ASSUME_NONNULL_BEGIN

@class VHTStream;
@class VHRenderView;

@protocol VHIStream <NSObject>

@property (nonatomic) NSString *streamId;			///< 设置[main | auxiliary | uuid]
@property (nonatomic) NSString *userId;				///< 设置UserId
@property (atomic) BOOL isMuteVideo;				///< 设置静画
@property (atomic) BOOL isMuteAudio;				///< 设置静音
@property (nonatomic) VHScalingMode scalingMode;	///< 设置画面填充模式 (默认 VHScalingModeAspectFit) @link VHScalingMode
@required

- (NSString *)descStream;

/// 关闭音频
- (void) muteAudio;

/// 取消关闭音频
- (void) unmuteAudio;

/// 关闭视频
- (void) muteVideo;

/// 取消关闭视频
- (void) unmuteVideo;

@end

NS_ASSUME_NONNULL_END
