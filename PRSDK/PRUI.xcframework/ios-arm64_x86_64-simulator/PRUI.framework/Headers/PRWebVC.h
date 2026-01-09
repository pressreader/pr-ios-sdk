//
//  WebViewController.h
//  PRiphone
//
//  Created by Vitali Bounin on 11/23/11.
//  Copyright (c) 2011 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
@import WebKit;

@interface PRWebVC : UIViewController <WKScriptMessageHandler>

@property (nonatomic, readonly) WKWebView * webView;
@property (nonatomic, readonly) UIScrollView * scrollView;
@property (nonatomic, strong) id userData;

- (void) unloadResources;

@end


@interface WKWebView ( PRWebView )

- (void) processScriptMessage:(WKScriptMessage *)message logPrefix:(NSString *)prefix commandHandler:(void(^)(NSString* cmd, NSArray<NSURLQueryItem *> *urlparams, NSDictionary *map))handler;

- (void) performJavaScript:(NSString*)script completionHandler:(void (^)(id result, NSError *error))completionHandler;
- (void) performJavaScript:(NSString *)script;

@end
