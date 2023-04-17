//
//  PRAccountManager+ExternalAuthUI.h
//  PR-UI
//
//  Created by berec on 16/09/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

@import PRAPI.PRAccountManager;

NS_ASSUME_NONNULL_BEGIN

@interface PRAccountManager (ExternalAuthUI)

- (nullable UIImage *)imageForNetwork:(PRSignInOption *)network
                      backgroundColor:(UIColor *_Nonnull *_Nullable)backgroundColor
                          borderColor:(UIColor *_Nullable *_Nullable)borderColor
                           titleColor:(UIColor *_Nonnull *_Nullable)titleColor
                        renderingMode:(UIImageRenderingMode *_Nullable)renderingMode;

- (nullable UIImage *)downloadImageForNetwork:(PRSignInOption *)network
                                   completion:(void(^_Nonnull)(UIImage *image))completion;

- (void)signInWithNetwork:(PRSignInOption *)network
     navigationController:(UINavigationController *_Nullable)navigationController
               completion:(void(^_Nullable)(BOOL success, NSError *_Nullable error))completion;

- (void)signInWithNetwork:(PRSignInOption *)network
     navigationController:(UINavigationController *_Nullable)navigationController;

- (void)presentExternalAuthUIForNetwork:(PRSignInOption *)networkInfo
                 inNavigationController:(UINavigationController *_Nullable)navigationController
                               animated:(BOOL)animated
                   linkToCurrentAccount:(BOOL)linkToCurrentAccount
                             completion:(void(^_Nullable)(void))presentationCompletion;

- (void)trackSignInWithProvider:(NSString *)networkId isLocalProvider:(BOOL)isLocalProvider isNewUser:(BOOL)isNewUser successful:(BOOL)success;

@end

NS_ASSUME_NONNULL_END
