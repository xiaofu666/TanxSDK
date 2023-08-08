//
//  TXAdFeedManager.h
//  TanxSDK
//
//  Created by guqiu on 2022/1/4.
//  Copyright © 2022 tanx.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <TanxSDK/TXAdFeedManagerDelegate.h>
#import <TanxSDK/TXAdFeedTemplateConfig.h>
#import <TanxSDK/TXAdFeedModel.h>
#import <TanxSDK/TXAdFeedView.h>
#import <TanxSDK/TXAdFeedBinder.h>

#import <TanxSDK/TXAdModel.h>
#import <TanxSDK/TXAdFeedSlotModel.h>

@class TXAdFeedModule;

NS_ASSUME_NONNULL_BEGIN

/// 渲染模式枚举
typedef NS_ENUM(NSUInteger, TXAdFeedRenderMode) {
    TXAdFeedRenderModeTemplate = 1,     // 模板渲染
    TXAdFeedRenderModeCustom = 2,       // 自渲染
};

/// 广告类型
typedef NS_ENUM(NSUInteger, TXAdFeedAdType) {
    TXAdFeedAdTypeImage = 1,       // 图片广告
    TXAdFeedAdTypeVideo = 2,       // 视频广告
};

typedef void(^TXAdGetFeedAdBlock)(NSArray <TXAdFeedModel *> * _Nullable viewModelArray, NSError * _Nullable error);

typedef void(^TXAdFeedAdsBlock)(NSArray <TXAdModel *> * _Nullable viewModelArray, NSError * _Nullable error);

/// 获取模版block ，customTemplates与feedTemplates 互斥，二者只返回一个
///
/// feedTemplates          信息流返回模版数组
/// customTemplates     信息流返回自渲染模版数组，
typedef void(^TXFeedTemplatesBlock)(NSArray <TXAdFeedModule *> * _Nullable feedTemplates, NSArray <TXAdFeedBinder *> * _Nullable customTemplates, NSError * _Nullable error);

@interface TXAdFeedModule : NSObject

/// 模板内容
@property (nonatomic, strong) UIView *view;

/// 模板的size
@property (nonatomic, assign) CGSize size;

/// 当前数据源，即将废弃，使用adModel
@property (nonatomic, strong) TXAdFeedModel *feed DEPRECATED_MSG_ATTRIBUTE("即将废弃，使用adModel");;

/// 当前数据源
@property (nonatomic, strong) TXAdModel *adModel;

- (void)destoryFeedModule;

@end

@interface TXAdFeedManager : NSObject


@property (nonatomic, weak) id<TXAdFeedManagerDelegate> delegate;

/// 初始化配置参数model
@property (nonatomic, copy, readonly) TXAdFeedSlotModel *slotModel;

/**
 *  初始化方法
 *
 *  @param slotModel 广告配置参数model，存放pid等参数
 *  @return instancetype
 */
- (instancetype)initWithSlotModel:(TXAdFeedSlotModel *)slotModel NS_DESIGNATED_INITIALIZER;

/**
 *  初始化方法
 *
 *  @param pid 广告pid
 *  @return instancetype
 */
- (instancetype)initWithPid:(NSString *)pid NS_DESIGNATED_INITIALIZER;

/**
 *  发起feed广告请求，返回广告数据：
 *  1、媒体可获取通过 TXAdModel.bid.bidPrice 获取报价，并返回竞价结果，若为空则表明该媒体没有获取权限；
 *
 *  @param adCount                    获取多少个广告
 *  @param renderMode             渲染模式（模板渲染 or 自渲染）
 *  @param adsBlock                 广告数据block
 */
- (void)getFeedAdsWithAdCount:(NSInteger)adCount
                   renderMode:(TXAdFeedRenderMode)renderMode
                     adsBlock:(TXAdFeedAdsBlock)adsBlock;

/**
 *  上报竞价结果（媒体如果选择竞价，则调用；不需要，则忽略）
 *
 *  @param model 数据
 *  @param result 结果YES/NO
 */
- (void)uploadBidding:(TXAdModel *)model result:(BOOL)result;

/**
 *  通过广告数据获取广告模板
 *
 *  @param modelArray      广告数据
 *  @param config               广告模版配置
 *  @return NSArray             广告模板数组
 */
- (NSArray <TXAdFeedModule *> *)renderFeedTemplateWithModel:(NSArray <TXAdModel *> *)modelArray
                                                     config:(TXAdFeedTemplateConfig *)config;

/**
 *  媒体自己渲染广告UI，通过广告数据获取广告Binder
 *
 *  @param modelArray      广告数据
 *  @return NSArray             广告字渲染Binder数组
 */
- (NSArray <TXAdFeedBinder *> *)customRenderingBinderWithModels:(NSArray <TXAdModel *> *)modelArray;

/**
 *  重新设置一遍Feed信息流的UII配置（当发生了字体变化、暗黑模式和正常模式切换的情况）
 *
 *  @param config 配置
 */
- (void)resetFeedConfig:(TXAdFeedTemplateConfig *)config;

/**------------------------------------------------- 以下方法将要废弃，请使用最新方法 --------------------------------------------------------------**/

/// 自定义初始化
/// @param delegate 委托协议对象
- (instancetype)initWithDelegate:(id<TXAdFeedManagerDelegate>)delegate DEPRECATED_MSG_ATTRIBUTE("该接口已废弃，请使用 initWithSlotModel: or initWithPid:");

/// 发起获取feed广告请求
/// @param block 返回广告数据（@媒体可获取通过TXAdFeedModel的ecpm获取报价，若为空则表明该媒体没有获取权限）
/// @param pid 广告pid
/// @param postionArray 获取多少个广告（最多不超过三个），放在哪些坑位（比如 [@2，@6，@9]），⚠️⚠️这些坑位下标从0开始⚠️⚠️，⚠️⚠️和第几页无关不需要累加上页大小⚠️⚠️。
/// @param renderMode 渲染模式（模板渲染 or 自渲染）
- (void)getFeedAdWithBlock:(TXAdGetFeedAdBlock)block
                   withPid:(NSString * __nonnull)pid
               andPosArray:(NSArray <NSNumber *> *)postionArray
                renderMode:(TXAdFeedRenderMode)renderMode DEPRECATED_MSG_ATTRIBUTE("即将废弃，请使用getFeedAdsWithAdCount:renderMode:adsBlock:");

/// 通过广告数据，获取信息流广告模板（返回给媒体的模板是上下左右不留padding的，由媒体自己控制padding）
/// @param modelArray 信息流广告数据数组（必传）
/// @param isJoinBidding 是否参竞
/// @param creativeIdArray 参竞后，成功竞得的creativeId数组
/// @param config 模板的相关UI配置
- (NSArray <TXAdFeedModule *> *)renderFeedTemplateWithModel:(NSArray <TXAdFeedModel *> *__nonnull)modelArray
                                                joinBidding:(BOOL)isJoinBidding
                                             andCreativeIds:(NSArray <NSString *>*__nullable)creativeIdArray
                                          andTemplateConfig:(TXAdFeedTemplateConfig *)config DEPRECATED_MSG_ATTRIBUTE("即将废弃，请使用renderFeedTemplateWithModel:config:");

/// 通过广告数据，获取自渲染绑定器
/// @param modelArray 信息流广告数据数组（必传）
/// @param isJoinBidding 是否参竞
/// @param creativeIdArray 参竞后，成功竞得的creativeId数组
- (NSArray <TXAdFeedBinder *> *)customRenderingBinderWithModels:(NSArray <TXAdFeedModel *> *__nonnull)modelArray
                                                    joinBidding:(BOOL)isJoinBidding
                                                 andCreativeIds:(NSArray <NSString *>*__nullable)creativeIdArray DEPRECATED_MSG_ATTRIBUTE("即将废弃，请使用customRenderingBinderWithModels:");

#pragma mark - Unavailable
/// ("该接口已废弃，请使用 initWithSlotModel: or initWithPid:")
- (instancetype) init NS_UNAVAILABLE;

/// ("该接口已废弃，请使用 initWithSlotModel: or initWithPid:")
+ (instancetype) new  NS_UNAVAILABLE;

/// 自定义初始化
/// @param delegate 委托协议对象
/// @param scrollView 滑动容器
- (instancetype)initWithDelegate:(id<TXAdFeedManagerDelegate>)delegate andScrollView:(nullable UIScrollView *)scrollView DEPRECATED_MSG_ATTRIBUTE("该接口已废弃，请使用 initWithSlotModel: or initWithPid:");

@end

NS_ASSUME_NONNULL_END
