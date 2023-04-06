//
//  PROnlineCommand.h
//  PRiphone
//
//  Created by Jackie Cane on 25/06/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

@import PRUIKit.PRCommand;

NS_ASSUME_NONNULL_BEGIN

@interface PROnlineCommand : PRCommand
@property (class, nonatomic, readonly) BOOL isEligible;
@property (class, nonatomic, readonly) BOOL isEnabledLight;

@end

NS_ASSUME_NONNULL_END
