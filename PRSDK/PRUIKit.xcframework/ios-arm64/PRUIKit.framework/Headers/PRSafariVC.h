//
//  PRSafariVC.h
//  PRiphone
//
//  Created by Jackie Cane on 9/28/11.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

@import UIKit;
@import WebKit;

NS_ASSUME_NONNULL_BEGIN

/// Controller for loading web content in app.
@interface PRSafariVC : UIViewController <WKUIDelegate, WKNavigationDelegate, WKScriptMessageHandler>

- (instancetype)initWithURL:(nullable NSURL *)contentURL
            scalesPageToFit:(BOOL)scalesToFit
                     opaque:(BOOL)opaque
            backgroundColor:(nullable UIColor *)backgroundColor;
- (instancetype)initWithURL:(nullable NSURL *)contentURL
                     opaque:(BOOL)opaque
            backgroundColor:(nullable UIColor *)backgroundColor;
- (instancetype)initWithURL:(nullable NSURL *)contentURL scalesPageToFit:(BOOL)scalesToFit;
- (instancetype)initWithURL:(nullable NSURL *)contentURL;

@property (nullable, nonatomic, readonly) WKWebView *webView;
@property (nullable, nonatomic, readonly) UIScrollView *scrollView;
@property (nullable, nonatomic, strong) NSURL *url;
@property (nonatomic) BOOL hideBackForwardButtons;
@property (nonatomic) BOOL adjustContentSizeInPopover;
@property (nonatomic) BOOL fixedContentWidth; // YES by defaults
@property (nonatomic) BOOL showActivityIndicatorInTopBar;
@property (nonatomic) BOOL showActivityIndicatorInWebView;
@property (nonatomic) BOOL enableOpenInSafariOption;

/// method to override. call super before additional code
- (void)configureWebView:(WKWebView *)webView;
- (void)unloadScriptsAndHandlers;

@end

@interface PRSafariVC () <UIPopoverPresentationControllerDelegate>
@end

NS_ASSUME_NONNULL_END
