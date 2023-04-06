//
//  PRAuthorizeView.h
//  PR-UI
//
//  Created by berec on 11/09/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@class EditableCell, PRTwoTextFieldsCell;

typedef NS_ENUM(int, PRAuthorizeVCMode) {
    PRAuthorizeVCModeSignIn = 0,
    PRAuthorizeVCModeSignUp
};

extern CGFloat const kRegularAuthorizeSectionFooterHeight;
extern CGFloat const kSocialLoginAuthorizeSectionFooterHeight;

@protocol PRAuthorizeViewDelegate <NSObject, UITextFieldDelegate>

- (void)forgotPasswordButtonTouch:(id)sender;
- (void)signButtonTouch:(id)sender;

@property (nonatomic, readonly) BOOL isAuthorizing;
@property (nonatomic, readonly) PRAuthorizeVCMode mode;
@property (nonatomic, readonly) BOOL displayBottomView;
@property (nonatomic, readonly) BOOL hasExternalAuthSection;
@property (nonatomic, readonly) BOOL hasForgotPassword;

@property (nullable, nonatomic, readonly) UITableView *externalAuthTableView;

@end

@interface PRAuthorizeView : UIView
{
    @public
    EditableCell *userNameCell;
    EditableCell *passwordCell;
    PRTwoTextFieldsCell *firstAndLastNamesCell;
}

- (UIView *)regularAuthorizeSectionFooterView;
- (EditableCell *)usernameCellForTableView:(UITableView *)tableView;
- (EditableCell *)passwordCellForTableView:(UITableView *)tableView showForgotPasswordButton:(BOOL)showForgotPasswordButton;
- (UITableViewCell *)actionCellForTableView:(UITableView *)tableView action:(NSString *)action;
- (UITableViewCell *)firstAndLastNamesCellForTableView:(UITableView *)tableView;
- (UITableViewCell *)emailOptionCellForTableView:(UITableView *)tableView;
- (UITableViewCell *)infoCellForTableView:(UITableView *)tableView;

@property (nonatomic, assign) UIViewController<PRAuthorizeViewDelegate, WKNavigationDelegate> *delegate;

@property (nonatomic, strong) NSString *userName;
@property (nonatomic, strong) NSString *password;

@property (nullable, nonatomic, strong) UIButton *authorizeButton;
@property (nonatomic, strong) UIActivityIndicatorView *authorizeButtonIndicator;
@property (nonatomic, readonly) CGFloat heightForAuthorizeSectionFooter;
@property (nonatomic, readonly) NSString *authorizeButtonTitle;
@property (nonatomic, readonly) CGFloat sidePadding;

@property (nonatomic) BOOL isBranded;

@end

NS_ASSUME_NONNULL_END
