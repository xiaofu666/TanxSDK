//
//  TXAdSplashManager.h
//  TanxSDK
//
//  Created by XY on 2021/12/27.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <TanxSDK/TXAdSplashManagerDelegate.h>
#import <TanxSDK/TXAdModel.h>
#import <TanxSDK/TXAdSplashTemplateConfig.h>
#import <TanxSDK/TXAdSplashSlotModel.h>

/**------ TXAdSplashModel will Deprecated ------*/
#import <TanxSDK/TXAdSplashModel.h>

typedef void(^TXAdGetSplashAdDataBlock)(NSArray <TXAdModel *> * _Nullable splashModels, NSError * _Nullable error);
typedef void(^TXAdGetSplashTemplateBlock)(UIView * _Nullable template, NSError * _Nullable error);

/**------ TXAdGetSplashAdBlock will Deprecated ------*/
typedef void(^TXAdGetSplashAdBlock)(NSArray <TXAdSplashModel *> * _Nullable splashModels, NSError * _Nullable error) DEPRECATED_MSG_ATTRIBUTE("即将废弃");


NS_ASSUME_NONNULL_BEGIN

@interface TXAdSplashManager : NSObject

@property (nonatomic, weak) id<TXAdSplashManagerDelegate> delegate;     //代理需要实现的协议

/// 初始化配置参数model
@property (nonatomic, copy, readonly) TXAdSplashSlotModel *slotModel;

/**
 *  初始化方法
 *
 *  @param slotModel 广告配置参数model，存放pid等参数
 *  @return instancetype
 */
- (instancetype)initWithSlotModel:(TXAdSplashSlotModel *)slotModel NS_DESIGNATED_INITIALIZER;

/**
 *  初始化方法
 *
 *  @param pid 广告pid
 *  @return instancetype
 */
- (instancetype)initWithPid:(NSString *)pid NS_DESIGNATED_INITIALIZER;

/**
 *  预请求，建议在开屏展示完毕后再发起请求
 */
- (void)preGetSplashAdData;

/**
 *  发起获取开屏广告请求获取广告数据
 *
 *  @param adsDataBlock    返回广告数据
 */
- (void)getSplashAdsWithAdsDataBlock:(TXAdGetSplashAdDataBlock)adsDataBlock;

/**
 *  上报竞价结果（媒体如果选择竞价，则调用；不需要，则忽略）
 *
 *  @param model 数据
 *  @param result 结果YES/NO
 */
- (void)uploadBidding:(TXAdModel *)model result:(BOOL)result;

/**
 *  通过广告数据获取开屏广告模板
 *
 *  @param model     开屏广告数据
 *  @return UIView   开屏广告模板
 */
- (UIView *)renderSplashTemplateWithAdModel:(TXAdModel *)model config:(TXAdSplashTemplateConfig *)config;

/**
 *  删除本地缓存的开屏素材
 *
 *  @param finishBlock block
 */
- (void)removeLocalMaterials:(dispatch_block_t)finishBlock;

/**
 *  删除缓存JSON数据
 */
- (void)removeLocalData;

/**
 *  删除开屏的所有缓存数据
 */
- (void)removeLocalAssets;

/**------------------------------------------------- 以下方法将要废弃，请使用最新方法 --------------------------------------------------------------**/

/// 发起获取开屏广告请求，即将废弃，使用 getSplashAdsWithAdsDataBlock:
/// @param block 返回广告数据（@媒体可获取通过TXAdSplashModel的ecpm获取报价，若为空则表明该媒体没有获取权限）
/// @param pid 广告pid
- (void)getSplashAdsWithBlock:(TXAdGetSplashAdBlock)block withPid:(NSString * __nonnull)pid DEPRECATED_MSG_ATTRIBUTE("即将废弃，使用getSplashAdsWithAdsDataBlock:");


/// 预请求，建议在开屏展示完毕后再发起请求，即将废弃，使用 preGetSplashAdData
/// @param pid 广告pid
- (void)preGetSplashAdWithPid:(NSString * __nonnull)pid DEPRECATED_MSG_ATTRIBUTE("即将废弃，使用preGetSplashAdData");

/// 上报竞价成功，即将废弃
/// @param model 数据
/// @param result 结果YES/NO
- (void)uploadBidding:(TXAdSplashModel *)model isWin:(BOOL)result DEPRECATED_MSG_ATTRIBUTE("即将废弃，请使用uploadBidding:result:");

/// 通过广告数据获取开屏广告模板（媒体如果参竞，上报竞价后调用），即将废弃，使用 renderSplashTemplateWithModel:
/// @param model 开屏广告数据
- (UIView *)renderSplashTemplateWithModel:(TXAdSplashModel *)model config:(TXAdSplashTemplateConfig *)config DEPRECATED_MSG_ATTRIBUTE("即将废弃，使用renderSplashTemplateWithAdModel:config:");


///无竞价，直接获取开屏广告模板，即将废弃
/// @param block 返回广告模板
/// @param pid 广告pid
- (void)getSplashTemplateWithBlock:(TXAdGetSplashTemplateBlock)block withPid:(NSString * __nonnull)pid DEPRECATED_MSG_ATTRIBUTE("即将废弃");

/// 即将废弃 请求出错后最大支持的重试次数
@property (nonatomic, assign) NSUInteger retryCount DEPRECATED_MSG_ATTRIBUTE("即将废弃");

/// 即将废弃 允许开屏请求最长时间(推荐设置3秒)
@property (nonatomic, assign) NSTimeInterval waitSyncTimeout DEPRECATED_MSG_ATTRIBUTE("即将废弃");

- (instancetype)init DEPRECATED_MSG_ATTRIBUTE("即将废弃，请使用initWithSlotModel: or initWithPid:");

@end

NS_ASSUME_NONNULL_END
