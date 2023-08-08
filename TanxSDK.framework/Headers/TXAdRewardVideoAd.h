//
//  TXAdRewardVideoAd.h
//  TanxSDK
//
//  Created by Yueyang Gu on 2022/5/31.
//  Copyright © 2022 tanx.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <TanxSDK/TXAdRewardVideoRewardInfo.h>
#import <TanxSDK/TXAdRewardVideoAdConfiguration.h>
#import <TanxSDK/TXAdModel.h>
#import <TanxSDK/TXAdManagerDelegate.h>
#import <TanxSDK/TXAdRewardVideoSlotModel.h>


NS_ASSUME_NONNULL_BEGIN

@class TXAdRewardVideoAd;

typedef void(^TXAdGetRewardVidelAdDataBlock)(NSArray <TXAdModel *> * _Nullable rewardVideoModels, NSError * _Nullable error);

@protocol TXAdRewardVideoAdDelegate <NSObject,TXAdManagerDelegate>
@optional

/**
 * 视频下载成功回调
 * @param model 数据model
 */
- (void)onAdDidDownLoadSuccessWithModel:(TXAdModel *)model;

/**
 * 广告渲染失败回调
 * @param error 错误
 * @param model 数据model
 */
- (void)onAdDidShowFailError:(NSError *)error withModel:(TXAdModel *)model;

/**
 * 广告跳过回调
 * @param model 数据model
 */
- (void)onAdDidSkipWithModel:(TXAdModel *)model;

/**
 * 激励视频播放完成或者出错
 * @param error nil代表播放成功
 * @param model 数据model
 */
- (void)onAdDidFinishPlayingError:(nullable NSError *)error withModel:(TXAdModel *)model;

/**
 * 发奖回调
 * @param rewardInfo 发奖信息
 * @param model 数据model
 */
- (void)onAdDidReceiveRewardInfo:(TXAdRewardVideoRewardInfo *)rewardInfo withModel:(TXAdModel *)model;

@end



/// 激励视频广告管理对象
@interface TXAdRewardVideoAd : NSObject

/// 回调代理
@property(nonatomic, weak) id<TXAdRewardVideoAdDelegate> delegate;
/**
 * 初始化方法
 * @param pid 广告pid
 */
- (instancetype)initWithPid:(NSString *)pid NS_DESIGNATED_INITIALIZER;

/**
 *  初始化方法
 *  @param slotModel 广告配置参数model，存放pid等参数
 *  @return instancetype
 */
- (instancetype)initWithSlotModel:(TXAdRewardVideoSlotModel *)slotModel NS_DESIGNATED_INITIALIZER;

/// 加载广告
- (void)getRewardVideoAdsWithAdsDataBlock:(TXAdGetRewardVidelAdDataBlock)adsDataBlock;

/**
 * 上报竞价结果
 * param model 数据model(请求数据的回调里拿到的model)
 * @param  result 竞价结果yes/no
 */
- (void)uploadBidding:(TXAdModel *)model result:(BOOL)result;

/**
 * 展示激励视频，在 rewardVideoAdDidLoad: 或者 rewardVideoAdDidDownloadVideo: 回调过后调用
 * @param viewController 当前所在VC
 * @param adModel 数据model
 */
- (void)showAdFromRootViewController:(UIViewController *)viewController withModel:(TXAdModel *)adModel;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

#ifdef DEBUG
+ (void)setDebugWebViewURL:(nullable NSURL *)url;
#endif

@end

NS_ASSUME_NONNULL_END
