//
//  PRExternalAuthManager.h
//  PRiphone
//
//  Created by Jackie Cane on 28/07/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

@import UIKit;
@import PRSyntacticSugar;

NS_ASSUME_NONNULL_BEGIN

typedef void(^PRExternalAuthCompletion)(NSString * _Nullable authKey, BOOL isNewUser);

@protocol PRExternalAuthManagerDelegate <NSObject>
- (void) registerExternalAuthProvider:(NSString *)provider;
- (UIView *)presentationView;
@end

@class PRAccountItem;

@interface PRExternalAuthManager : NSObject

- (instancetype)initWithDelegate:(nullable id<PRExternalAuthManagerDelegate>)delegate;

- (void)performExternalAuth:(PRAccountItem *)ai
                   provider:(NSString *)provider
                   authType:(NSString *)authType
                    command:(nullable NSString *)command
          completionHandler:(nullable PRExternalAuthCompletion)completionHandler;

- (void)performExternalAuth:(PRAccountItem *)ai
                   provider:(NSString *)provider
                 forSharing:(BOOL)forSharing
                    command:(nullable NSString *)command
          completionHandler:(nullable PRExternalAuthCompletion)completionHandler;

- (void)performExternalAuth:(PRAccountItem *)ai
                   provider:(NSString *)provider
                 forSharing:(BOOL)forSharing
                    command:(nullable NSString *)command
                  presented:(nullable PRSimpleBlock)presented
          completionHandler:(nullable PRExternalAuthCompletion)completionHandler;

@end

NS_ASSUME_NONNULL_END
