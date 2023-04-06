//
//  PRForwarder.h
//  PR-API
//
//  Created by berec on 12/10/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRForwarder : NSProxy

- (instancetype)initWithRecipients:(NSObject *)recipient, ... NS_REQUIRES_NIL_TERMINATION;

- (void)addForwarderRecipient:(NSObject *)recipient;
- (void)removeForwarderRecipient:(NSObject *)recipient;

@property (nonatomic, readonly) NSArray *allRecipients;

@end

NS_ASSUME_NONNULL_END
