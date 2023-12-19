//
//  TXAdCache.h
//  TanxCoreSDK
//
//  Created by XY on 2021/12/27.
//

#import <Foundation/Foundation.h>
#import "TXAdCacheMacro.h"

NS_ASSUME_NONNULL_BEGIN

@interface TXAdCache : NSObject

@property (nonatomic, copy) NSString *splashId;
@property (nonatomic, copy) NSString *creativeId;
@property (nonatomic, copy) NSString *templateId;
@property (nonatomic, copy) NSString *reqId;
@property (nonatomic, copy) NSString *seatId;
@property (nonatomic, copy) NSString *pid;

@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *md5;
@property (nonatomic, copy) NSString *name;

@property (nonatomic, copy) NSString *idKey;

@property (nonatomic, assign) TXAdType adType;
@property (nonatomic, assign) TXAdCacheFileType fileType;

- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END
