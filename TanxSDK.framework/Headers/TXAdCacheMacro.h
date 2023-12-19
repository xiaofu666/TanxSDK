//
//  TXAdCacheMacro.h
//  TanxSDK-iOS
//
//  Created by tongyuecheng on 2023/7/20.
//  Copyright © 2023 tanx.com. All rights reserved.
//

#ifndef TXAdCacheMacro_h
#define TXAdCacheMacro_h

/// 广告位
typedef NS_ENUM(NSInteger, TXAdType) {
    TXAdTypeUnknown      = -1,
    TXAdTypeSplash       = 1,
    TXAdTypeFeeds        = 2,
    TXAdTypeTableScreen  = 3,
    TXAdTypeReward       = 4,
};

/// 广告素材类型，不支持zip文件
typedef NS_ENUM(NSInteger, TXAdCacheFileType) {
    TXAdCacheFileTypeUnknown = -1,
    TXAdCacheFileTypeVideo   = 1,
    TXAdCacheFileTypeImage   = 2,
    TXAdCacheFileTypeFile    = 3,
};


#endif /* TXAdCacheMacro_h */
