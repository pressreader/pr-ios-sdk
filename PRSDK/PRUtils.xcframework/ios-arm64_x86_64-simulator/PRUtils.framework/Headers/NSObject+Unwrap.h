//
//  NSObject+Unwrap.h
//  PRUtils
//
//  Created by berec on 16/10/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@import PRSyntacticSugar;

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (Unwrap)

- (void)unwrap:(void(^)(id me))block PR_NON_SWIFT;
- (nullable id)map:(id _Nullable(^)(id me))block PR_NON_SWIFT;

- (nullable id)unwrapAs:(Class)class PR_NON_SWIFT;
- (nullable id)unwrapAsAny:(NSArray<Class> *)classes PR_NON_SWIFT;
- (void)unwrapAs:(Class)class
           block:(void(^)(id me))block PR_NON_SWIFT;
- (nullable id)unwrapAs:(Class)class
                    map:(id _Nullable(^)(id me))block PR_NON_SWIFT;

- (void)unwrapAsProtocol:(Protocol *)protocol
                   block:(void(^)(id me))block PR_NON_SWIFT;
- (nullable id)unwrapAsProtocol:(Protocol *)protocol PR_NON_SWIFT;
- (nullable id)unwrapAsProtocols:(NSArray<Protocol *> *)protocols PR_NON_SWIFT;

@end

NS_ASSUME_NONNULL_END
