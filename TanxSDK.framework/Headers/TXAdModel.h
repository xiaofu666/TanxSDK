//
//  TXAdModel.h
//  TanxSDK-iOS
//
//  Created by Evan on 2023/2/22.
//  Copyright © 2023 tanx.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TXAdJSONModel.h"

typedef NS_ENUM(NSInteger ,TanXAdType) {
    TanXAdTypeSplash = 1,         // 开屏
    TanXAdTypeFeedImage,          // 信息流-图片
    TanXAdTypeFeedVideo,          // 信息流-视频
    TanXAdTypeRewardVideo,        // 激励视频
    TanXAdTypeTableScreen,        // 插屏
};

@class TXAdBidModel;

@interface TXAdModel : TXAdJSONModel

@property (nonatomic, copy, readonly)   NSString *adId;
@property (nonatomic, copy, readonly)   NSString *adSource;
@property (nonatomic, copy, readonly)   NSString *sessionId;
@property (nonatomic, copy, readonly)   NSString *creativeId;
@property (nonatomic, strong, readonly) TXAdBidModel *bid;
@property (nonatomic, assign, readonly) NSTimeInterval start;
@property (nonatomic, assign, readonly) NSTimeInterval end;

/**
 *  对外媒体暴露 渲染素材
 *
 *  @"title":  @"",
 *  @"advName":  @"",
 *  @"assetUrl":  @"",
 *  @"advLogo": @"",
 *  @"height": @"",
 *  @"width":  @"",
 *
 *  @"smImageUrl": @"", 广告主信息
 *  @"smImageWidth" : @"",
 *  @"smImageHeight" :  @"",
 */
@property (nonatomic, copy, readonly)   NSDictionary *adMaterialDict;
@property (nonatomic, assign) TanXAdType adType;

@end
