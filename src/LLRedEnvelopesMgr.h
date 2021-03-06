//
//  LLRedEnvelopesMgr.h
//  test
//
//  Created by fqb on 2017/12/12.
//  Copyright © 2017年 kevliule. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import "WCRedEnvelopesHelper.h"

@class POIInfo;

@interface LLRedEnvelopesMgr : NSObject

@property (nonatomic, assign) BOOL haveNewRedEnvelopes; //是否有新的红包
@property (nonatomic, assign) BOOL isHiddenRedEnvelopesReceiveView; //是否隐藏红包接受页面
@property (nonatomic, assign) BOOL isHongBaoPush; //是否是红包push
@property (nonatomic, assign) BOOL isOpenRedEnvelopesHelper; //是否开启红包助手
@property (nonatomic, assign) BOOL isOpenSportHelper; //是否开启步数助手
@property (nonatomic, assign) BOOL isOpenBackgroundMode; //是否开启后台模式
@property (nonatomic, assign) BOOL isOpenRedEnvelopesAlert; //是否开启红包提醒
@property (nonatomic, assign) BOOL isOpenVirtualLocation; //是否打开虚拟定位
@property (nonatomic, assign) CGFloat openRedEnvelopesDelaySecond; //打开红包延迟时间
@property (nonatomic, assign) NSInteger wantSportStepCount; //想要的运动步数
@property (nonatomic, assign) UIBackgroundTaskIdentifier bgTaskIdentifier; //后台任务标识符
@property (nonatomic, strong) NSTimer *bgTaskTimer; //后台任务定时器
@property (nonatomic, strong) AVAudioPlayer *blankPlayer; //无声音频播放器
@property (nonatomic, strong) CMessageWrap *lastMsgWrap; //上一个消息model
@property (nonatomic, strong) CMessageWrap *msgWrap; //当前的消息model
@property (nonatomic, strong) BaseMsgContentLogicController *logicController;
@property (nonatomic, strong) NSMutableDictionary *filterRoomDic; //过滤群组字典
@property (nonatomic, strong) POIInfo *virtualLocation; //虚拟位置POIInfo

@property (nonatomic, copy) void(^openRedEnvelopesBlock)(void); //打开红包block

+ (LLRedEnvelopesMgr *)shared;

- (void)reset;

//判断是否抢红包
- (BOOL)isSnatchRedEnvelopes:(CMessageWrap *)msgWrap;

- (void)openRedEnvelopes:(NewMainFrameViewController *)mainVC;

- (void)handleRedEnvelopesPushVC:(BaseMsgContentViewController *)baseMsgVC;

- (void)successOpenRedEnvelopesNotification;

//程序进入后台处理
- (void)enterBackgroundHandler;

@end
