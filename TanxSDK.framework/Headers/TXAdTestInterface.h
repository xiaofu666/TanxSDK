//
//  TXAdTestInterface.h
//  TanxSDK
//
//  Created by Evan on 2023/5/6.
//  Copyright © 2023 tanx.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  仅为sdk测试使用，不对外开放
 */
@interface TXAdTestInterface : NSObject


/* ----------- videoCaches ----------- */
+ (NSArray *)videoCache_getAllCacheURL;
+ (void)videoCache_cleanAllCaches;
+ (void)videoCache_cleanCacheWithMaxItems;
+ (void)videoCache_cacheDeleteWithUrl:(NSURL *)url;
+ (void)videoCache_handleVideoCacheFiles:(NSString *)url
                           maxCacheCount:(NSInteger)maxCacheCount;

/* ----------- splash Caches action ----------- */
+ (NSArray *)splash_getMaterials ;
+ (NSString *)splash_loadResponse ;
+ (void)splash_saveResponse:(NSString *)res ;
+ (void)splash_deleteResponse;
+ (void)splash_deleteMaterial:(NSString *)path;

/* ----------- Ad debug config action ----------- */
+ (BOOL)debugConfig_isAdDev;
+ (void)setDebugConfig_isAdDev:(BOOL)isAdDev;

+ (BOOL)debugConfig_isConfigDev;
+ (void)setDebugConfig_isConfigDev:(BOOL)isConfigDev;

+ (BOOL)debugConfig_isUtDev;
+ (void)setDebugConfig_isUtDev:(BOOL)isUtDev;

@end


