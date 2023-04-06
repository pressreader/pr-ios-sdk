//
//  PRCommandShowEmailSignIn.h
//  PR-UI
//
//  Created by berec on 19/09/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "PRAuthorizeView.h"

NS_ASSUME_NONNULL_BEGIN

@interface PREmailSignInOptions : NSObject
@property (nonatomic, strong) NSString *userName;
@property (nonatomic, strong) NSString *password;
@property (nonatomic, strong) NSString *serviceName;
@property (nonatomic) BOOL linkToCurrentAccount;

@end


NS_ASSUME_NONNULL_END
