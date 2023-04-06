//
//  PRPromise+Swift.h
//  PR-API
//
//  Created by Viacheslav Soroka on 5/28/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <PRPromiseKit/PRTupleArray.h>
#import <PRPromiseKit/PRPromise.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRTupleArray (Swift)
- (instancetype) initWithArray:(NSArray *)array;
@end

@interface PRPromise (Swift)

- (PRPromise *)__thenVoid_Void:(NSError *_Nullable(^)(void))block;
- (PRPromise *)__thenVoid_id:(NSError *_Nullable(^)(id _Nullable))block;
- (PRPromise *)__thenVoid_idid:(NSError *_Nullable(^)(id _Nullable, id _Nullable))block;
- (PRPromise *)__thenVoid_ididid:(NSError *_Nullable(^)(id _Nullable, id _Nullable, id _Nullable))block;
- (PRPromise *)__thenid_Void:(id _Nullable(^)(void))block;
- (PRPromise *)__thenid_id:(id _Nullable(^)(id _Nullable))block;
- (PRPromise *)__thenid_idid:(id _Nullable(^)(id _Nullable, id _Nullable))block;
- (PRPromise *)__thenid_ididid:(id _Nullable(^)(id _Nullable, id _Nullable, id _Nullable))block;

- (PRPromise *)__failVoid:(void(^)(NSError * _Nullable))block;
- (PRPromise *)__failid:(id _Nullable(^)(NSError * _Nullable))block;

- (PRPromise *)__thenVoid_VoidOn:(dispatch_queue_t)queue block:(NSError *_Nullable(^)(void))block;
- (PRPromise *)__thenVoid_idOn:(dispatch_queue_t)queue block:(NSError *_Nullable(^)(id _Nullable))block;
- (PRPromise *)__thenVoid_ididOn:(dispatch_queue_t)queue block:(NSError *_Nullable(^)(id _Nullable, id _Nullable))block;
- (PRPromise *)__thenVoid_idididOn:(dispatch_queue_t)queue
                             block:(NSError *_Nullable(^)(id _Nullable, id _Nullable, id _Nullable))block;
- (PRPromise *)__thenid_VoidOn:(dispatch_queue_t)queue block:(id _Nullable(^)(void))block;
- (PRPromise *)__thenid_idOn:(dispatch_queue_t)queue block:(id _Nullable(^)(id _Nullable))block;
- (PRPromise *)__thenid_ididOn:(dispatch_queue_t)queue block:(id _Nullable(^)(id _Nullable, id _Nullable))block;
- (PRPromise *)__thenid_idididOn:(dispatch_queue_t)queue
                           block:(id _Nullable(^)(id _Nullable, id _Nullable, id _Nullable))block;

- (PRPromise *)__failVoidOn:(dispatch_queue_t)queue block:(void(^)(NSError * _Nullable))block;
- (PRPromise *)__failidOn:(dispatch_queue_t)queue block:(id _Nullable(^)(NSError * _Nullable))block;

@end

NS_ASSUME_NONNULL_END
