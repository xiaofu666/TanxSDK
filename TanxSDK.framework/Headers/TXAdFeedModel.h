//
//  TXAdFeedModel.h
//  TanxSDK
//
//  Created by guqiu on 2021/12/28.
//  Copyright © 2021 tanx.com. All rights reserved.
//

#import <TanxSDK/TXAdJSONModel.h>
#import <TanxSDK/TXAdFeedConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface TXAdFeedModel : TXAdJSONModel

@property(nonatomic, copy, readwrite) NSString *reqId;

@property(nonatomic, copy, readonly) NSString *eCPM;      //返回广告的eCPM，单位：分

@property(nonatomic, copy, readonly) NSString *creativeId;
@property(nonatomic, copy, readonly) NSString *templateId;

@property(nonatomic, copy, readonly) NSString *startStamp;
@property(nonatomic, copy, readonly) NSString *endStamp;
@property(nonatomic, copy, readonly) NSString *seatId;
@property(nonatomic, copy, readonly) NSString *rankId;

@property (nonatomic, copy, readonly) NSString *assetUrl;
@property (nonatomic, assign, readonly) NSInteger templateWidth;
@property (nonatomic, assign, readonly) NSInteger templateHeight;
@property (nonatomic, assign, readonly) NSInteger width;
@property (nonatomic, assign, readonly) NSInteger height;
@property (nonatomic, assign, readonly) NSInteger position;
@property (nonatomic, copy, readonly) NSString *title;
@property (nonatomic, copy, readonly) NSString *adName;
@property (nonatomic, copy, readonly) NSString *adWords;
@property (nonatomic, copy, readonly) NSString *adImage;
@property (nonatomic, copy, readonly) NSString *sourceName;

/// 广告主信息
@property (nonatomic, copy) NSString *smImageUrl;
@property (nonatomic, copy) NSString *smImageWidth;
@property (nonatomic, copy) NSString *smImageHeight;
@property (nonatomic, copy) NSString *smImageMD5;

@property (nonatomic, assign, readonly) NSInteger openType;
@property (nonatomic, copy, readonly) NSString *dpUrl;
@property (nonatomic, copy, readonly) NSString *destUrl;

@property (nonatomic, copy, readonly) TXAdFeedConfig *template_conf;
@property (nonatomic, copy) NSArray *interactType;

- (void)reManageData;

@end

NS_ASSUME_NONNULL_END
