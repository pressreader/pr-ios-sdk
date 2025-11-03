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

typedef NS_OPTIONS(NSUInteger, PRSafariOptions) {
    PRSafariOptionCleanCache  = 1 << 0,
};

typedef NS_ENUM(NSUInteger, PRSafariActivityIndicatorType) {
    PRSafariActivityIndicatorTypeNone = 0,
    PRSafariActivityIndicatorTypeInTopBar,
    PRSafariActivityIndicatorTypeInWebView,
};

/// Controller for loading web content in app.
@interface PRSafariVC : UIViewController <WKUIDelegate, WKNavigationDelegate, WKScriptMessageHandler>

- (instancetype)initWithURLRequest:(nullable NSURLRequest *)request
                           options:(PRSafariOptions)options;

- (instancetype)initWithURL:(nullable NSURL *)contentURL
                    options:(PRSafariOptions)options;

- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil
                         bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;

@property (nonatomic, readonly) WKWebView *webView;
@property (nullable, nonatomic, copy) NSURL *url;
@property (nullable, nonatomic, strong) NSURLRequest *urlRequest;
@property (nonatomic) BOOL hideBackForwardButtons;
@property (nonatomic) BOOL adjustContentSizeInPopover;
@property (nonatomic) BOOL fixedContentWidth; // YES by defaults
@property (nonatomic) BOOL enableOpenInSafariOption;
@property (nonatomic) PRSafariActivityIndicatorType activityIndicatorType;

/// method to override. call super before additional code
- (WKWebViewConfiguration *)newConfiguration;
- (void)unloadScriptsAndHandlers;

@end

@interface PRSafariVC () <UIPopoverPresentationControllerDelegate>
@end

NS_ASSUME_NONNULL_END

