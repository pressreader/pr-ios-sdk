//
//  PRCountableObject.h
//  PR-API
//
//  Created by berec on 27/09/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRCountableObject : NSObject

+ (instancetype)objectWithObject:(id)object;

- (instancetype)initWithObject:(id)object;
- (instancetype)init NS_UNAVAILABLE;

- (void)increment;
- (void)decrement;

@property (nonatomic, weak, readonly) id object;
@property (nonatomic, readonly) int count;

@end

NS_ASSUME_NONNULL_END
