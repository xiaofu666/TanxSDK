//
//  TXAdFeedManagerDelegate.h
//  TanxCoreSDK
//
//  Created by guqiu on 2022/1/4.
//  Copyright © 2022 tanx.com. All rights reserved.
//

#ifndef TXAdFeedManagerDelegate_h
#define TXAdFeedManagerDelegate_h

#import <TanxSDK/TXAdManagerDelegate.h>
@class TXAdFeedModel;

@protocol TXAdFeedManagerDelegate <NSObject,TXAdManagerDelegate>

@optional

/**
 *  广告滑动跳转回调
 *
 *  @param model 数据model
 */
- (void)onAdSliding:(TXAdModel *)model;

/**
 *  点击了“不喜欢”菜单中的选项
 *
 *  @param model 数据model
 *  @param index  选项次序索引
 */
- (void)onAdClickDislikeOptions:(TXAdModel *)model index:(NSInteger)index;

/**
 *   自渲染支持可点击区域
 *
 *  @param model            数据model
 *  @param clickView   点击的clickView
 */
- (void)onAdClick:(TXAdModel *)model clickView:(UIView *)clickView;

/// 跳转到h5，需要接入方实现
- (void)jumpToWebH5:(NSString *)webUrl DEPRECATED_MSG_ATTRIBUTE("已经废弃，内部统一处理跳转");

/// 点击了广告
- (void)onClickingFeed:(TXAdFeedModel *)feedModel DEPRECATED_MSG_ATTRIBUTE("即将废弃，请使用 onAdClick:");

/// 在广告上滑动
- (void)slidingFeed:(TXAdFeedModel *)feedModel DEPRECATED_MSG_ATTRIBUTE("即将废弃，请使用 onAdSliding:");

/// 广告渲染成功
- (void)onRenderSuc:(TXAdFeedModel *)feedModel DEPRECATED_MSG_ATTRIBUTE("即将废弃，请使用 onAdRenderSuccess:");

/// 广告展示（曝光）
- (void)onExposingFeed:(TXAdFeedModel *)feedModel DEPRECATED_MSG_ATTRIBUTE("即将废弃，请使用 onAdExposing:");

/// 点击了广告关闭按钮
- (void)onClickCloseFeed:(TXAdFeedModel *)feedModel DEPRECATED_MSG_ATTRIBUTE("即将废弃，请使用 onAdClose:");

/// 点击了“不喜欢”菜单中的选项
/// @param feedModel  feedModel模型
/// @param index  选项次序索引
- (void)didCloseFeed:(TXAdFeedModel*)feedModel atIndex:(NSInteger)index DEPRECATED_MSG_ATTRIBUTE("即将废弃，请使用 onAdClickDislikeOptions:index:");

/// 广告加载失败
/// @param feedModel  feedModel模型
/// @param error 错误信息
- (void)onFailureFeed:(TXAdFeedModel *)feedModel andError:(NSError *)error DEPRECATED_MSG_ATTRIBUTE("即将废弃，请使用 onAdLoadFail:error:");


@end


#endif /* TXAdFeedManagerDelegate_h */
