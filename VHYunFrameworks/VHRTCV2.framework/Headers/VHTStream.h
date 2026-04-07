//
//  VHallTrtcStreamModel.h
//  VHRTC
//
//  Created by LiGuoliang on 2022/10/21.
//  Copyright © 2022 vhall. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <VHRTCV2/VHTVideoConfig.h>
#import <VHRTCV2/VHIStream.h>



NS_ASSUME_NONNULL_BEGIN
@interface VHTStream : NSObject <VHIStream>
@property (nonatomic, readonly) BOOL isLocal;		///< 是否是本地流
@property (nonatomic) VHRTCStreamType type;			///< 流类型
@property (atomic) CGSize size;					///< 流尺寸
@property (nonatomic) UIView *preview;				///< 预览画面
@property (nonatomic) int streamType;				///< 外部传入 (本地)
@property (nonatomic) VHTVideoConfig *config;		///< 配置信息
@property (nonatomic) BOOL isPublishing;			///< 是否在推流
@property (nonatomic) BOOL isSubscribed;			///< 是否被订阅
@property (atomic) uint32_t sentBytes;			///< 总发送字节数
@property (atomic) uint32_t receivedBytes;		///< 总接收字节数
@property (nonatomic) uint32_t frameRate;			///< 视频帧率
@property (atomic) uint32_t videoBitrate;		///< 视频码率
@property (atomic) uint32_t audioBitrate;		///< 音频码率
@property(nonatomic) NSString* attributes;
@property (atomic, copy) NSString *extraParam;
@property (nonatomic) NSString *loginUserId;
- (instancetype)initWithStreamId:(NSString *)streamId userId:(NSString *)userId core:(id)core;

/// 设置当前流为旁路主屏画面
- (void)settingBroadCastMain;

- (instancetype)init NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
