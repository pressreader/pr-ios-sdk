//
//  PROnlineValidator.h
//  PRUI
//
//  Created by berec on 12/05/2021.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PROnlineValidator : NSObject

+ (BOOL)validate;

@property (class, nonatomic, readonly) BOOL isEligible;
@property (class, nonatomic, readonly) BOOL isEnabledLight;
@property (class, nonatomic, readonly) BOOL isEnabled;

@end

NS_ASSUME_NONNULL_END
