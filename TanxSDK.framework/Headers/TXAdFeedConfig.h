//
//  TXAdFeedConfig.h
//  TanxSDK
//
//  Created by 王飞 on 2022/9/8.
//  Copyright © 2022 tanx.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <TanxSDK/TXAdJSONModel.h>

#import <TanxSDK/TXAdShowModeModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TXAdFeedConfig :  TXAdJSONModel

@property (nonatomic, copy, readwrite) TXAdShowModeModel *night;
@property (nonatomic, copy, readwrite) TXAdShowModeModel *day;

@end

NS_ASSUME_NONNULL_END
