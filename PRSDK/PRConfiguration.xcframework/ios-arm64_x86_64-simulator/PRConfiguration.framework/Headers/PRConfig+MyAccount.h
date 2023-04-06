//
//  PRConfig+MyAccount.h
//  PRSharedData
//
//  Created by KeithC on 2020-08-26.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <PRConfiguration/PRConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRConfig (MyAccount)

@property (class, nonatomic, readonly) BOOL showAccountVCEditBarButton;
@property (class, nonatomic, readonly) BOOL showAccountChangeEmailPermissionSection;
@property (class, nonatomic, readonly) BOOL showAccountProductSection;
@property (class, nonatomic, readonly) BOOL showAccountDetailSection;

@property (class, nonatomic, readonly) BOOL showAccountVCNicknameRow;
@property (class, nonatomic, readonly) BOOL showAccountVCServiceName;

@end

NS_ASSUME_NONNULL_END
