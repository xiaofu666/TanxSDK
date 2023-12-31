//
//  TXAdEnum.h
//  TanxSDK-iOS
//
//  Created by guqiu on 2021/12/15.
//

#ifndef TXAdEnum_h
#define TXAdEnum_h

#define TXADSDK_ERROR_DOMAIN @"txadsdk.error.domain"

typedef NS_ENUM(NSInteger, TXAdSlideDirection){
    TXAdSlideTransDirection = 1, // 横向
    TXAdSlideVerDirection = 2 // 纵向
};

typedef NS_ENUM(NSInteger, TXAdInteractionType) {
    TXAdInteractionTypeShake = 1, // 摇一摇
    TXAdInteractionTypeClick = 2, // 点击；默认交互方式
    TXAdInteractionTypeSlide = 3 // 滑动样式
};

typedef NS_ENUM(NSInteger, TXAdExposeType) {
    TXAdTypeOpenScreen = 1, // 开屏
    TXAdTypeFeed = 2, // 信息流
    TXAdTypeRewardVideo = 3 // 激励视频
};


typedef NS_ENUM(NSInteger, TXAdSDKLogLevel) {
    TXAdSDKLogLevelNone,
    TXAdSDKLogLevelError,
    TXAdSDKLogLevelWarning,
    TXAdSDKLogLevelInfo,
    TXAdSDKLogLevelDebug,
    TXAdSDKLogLevelVerbose,
};





typedef NS_ENUM(NSInteger, TXAdSdkErrorCode) {
    TXAdErrorSplashError = 7000,
    TXAdErrorSplashDataInvalid = 8000,
    TXAdErrorSplashEmpty,
    TXAdErrorSplashExpired,
    TXAdErrorSplashAssetNotFound,
    TXAdErrorSplashUnsupportFormat,
    TXAdErrorSplashUnsupportSerialized,
    TXAdErrorSplashSerializedAssetNotFound,
    TXAdErrorSplashNoMatchFound,
    TXAdErrorSplashAlreadyStart,
    TXAdErrorCacheMd5Mismatch = 9000,
    TXAdErrorCacheLengthMismatch,
    TXAdErrorCacheFileExist,
    TXAdErrorSplashSizeTooSmall,    //尺寸太小
    TXAdErrorSplashTimeOut,          //开屏超时
    TXAdErrorSplashPidInvalid,
};



#endif /* TXAdEnum_h */
