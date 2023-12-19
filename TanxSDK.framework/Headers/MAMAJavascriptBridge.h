//
//  MAMAJavascriptBridge.h
//  TanxSDK
//
//  Created by Yueyang Gu on 2022/5/31.
//  Copyright © 2022 tanx.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "MAMAJavascriptMessageCenter.h"
#import "MAMAJavascriptHandlerParam.h"
#import "MAMAJavascriptBridgeConfiguration.h"

#define MAMAJsBridgeHandler(METHOD_NAME) +(void)METHOD_NAME##WithHandlerParam:(MAMAJavascriptHandlerParam *)handlerParam

NS_ASSUME_NONNULL_BEGIN

@interface MAMAJavascriptBridge : NSObject

@property(nonatomic, weak, readonly) WKWebView * webView;

+ (instancetype)bridgeForWebView:(WKWebView *)webView;

+ (MAMAJavascriptBridgeConfiguration *)globalConfiguration;

- (instancetype)initWithWebView:(WKWebView *)webView;

- (void)registerHandler:(NSString *)handlerName handler:(nullable MAMAJsHandler)handler;

- (void)registerHandlerModuleClass:(Class)cls forModuleName:(NSString *)moduleName;

- (void)postEvent:(NSString *)eventName params:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
