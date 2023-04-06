//
//  PRAccountManager+Error.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 12/11/20.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PRAccountManager.h"

@import PRUtils.PRErrorProvider;

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain const PRAccountManagerErrorDomain;
typedef NS_ERROR_ENUM(PRAccountManagerErrorDomain, PRAccountManagerError) {
    PRAccountManagerErrorUnknown,
    PRAccountManagerErrorRegisterGiftAccess
};

@interface PRAccountManager (Error) <PRErrorProvider>

+ (NSError *)errorWithCode:(PRAccountManagerError)code description:(nullable NSString *)description;
- (NSError *)errorWithCode:(PRAccountManagerError)code description:(nullable NSString *)description;

@end

NS_ASSUME_NONNULL_END
