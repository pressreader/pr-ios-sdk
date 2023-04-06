//
//  PRBaseAuhorizeVC.h
//  PRiphone
//
//  Created by Jackie Cane on 1/28/13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

@import PRUIKit.PRVC;

#import "PRAuthorizeView.h"

#import "UIViewController+AccountObserver.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PREmailAuthorizing

- (void)save:(id)sender;

- (void)signInUser:(NSString *)username password:(NSString *)password NS_SWIFT_NAME(signIn(user:password:));
- (void)signUpUser:(NSString *)usr
               pwd:(NSString *)pwd
         firstName:(NSString *)firstName
          lastName:(NSString *)lastName NS_SWIFT_NAME(signUp(user:pwd:firstName:lastName:));

- (BOOL)isResponsibleNotification:(NSNotification*)notification NS_SWIFT_NAME(isResponsible(for:));

@property (nonatomic) PRAuthorizeVCMode mode;

@property (nonatomic, getter = isAuthorizing) BOOL authorizing;
@property (nonatomic, assign) BOOL linkToCurrentAccount;

@property (nonatomic, strong) NSString *userName;
@property (nonatomic, strong) NSString *password;
@property (nonatomic, strong) NSString *serviceName;
@property (nonatomic, strong) NSString *extAuthNetwork;

@end

@interface PRAuthorizeVC : PRVC <UITextFieldDelegate, PRAuthorizeViewDelegate, WKNavigationDelegate, PREmailAuthorizing>

@property (nullable, nonatomic, readonly) __kindof PRAuthorizeView *rootView;

@end

@interface PRAuthorizeVC (/*Protected*/)
@property (nonatomic) BOOL usernameTextFieldHasFocus;

@property (nonatomic) BOOL isExternalAuthEnabled;
@property (nonatomic) BOOL hasExternalAuthSection;

@end

NS_ASSUME_NONNULL_END
