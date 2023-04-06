//
//  PRAccountItem+KYM.h
//  PRiphone
//
//  Created by KeithC on 2020-10-26.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PRAccountItem.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSString * PRAppTokenOperation NS_STRING_ENUM;
extern PRAppTokenOperation const PRAppTokenOperationWebView;
extern PRAppTokenOperation const PRAppTokenOperationBuy;

@interface PRAccountItem (KYM)

- (NSString *)kymUserParameter;
- (NSString *)encryptedAuthTokenParameter;
- (NSString *)encryptedAppTokenWithOperation:(PRAppTokenOperation)operation;

@end

NS_ASSUME_NONNULL_END
