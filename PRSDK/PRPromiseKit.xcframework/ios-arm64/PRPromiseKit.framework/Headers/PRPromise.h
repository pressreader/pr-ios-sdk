//
//  PRPromise.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 4/6/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

@import Foundation;

@class PRPromise;

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain const PRPromiseErrorDomain;
typedef NS_ERROR_ENUM(PRPromiseErrorDomain, PRPromiseError) {
    PRPromiseErrorTimeout,
    PRPromiseErrorReset
};

typedef NS_ENUM(uint8_t, PRPromiseState) {
    PRPromiseStateDefault = 0,
    PRPromiseStateResolved,
    PRPromiseStateRejected
};

typedef void (^PRPromiseResolverBlock) (BOOL success, id _Nullable result, NSError *_Nullable error);
typedef void (^PRPromiseRunBlock) (PRPromiseResolverBlock);
typedef BOOL (^PRPromiseExpirationConditionBlock) (PRPromise *promise);
typedef PRPromise *_Nonnull(^PRPromiseReturnBlock)(id);
typedef PRPromise *_Nonnull(^PROnPromiseReturnBlock)(dispatch_queue_t, id);
typedef PRPromise *_Nonnull(^PRFinalyPromiseReturnBlock)(void(^)(void));
typedef PRPromise *_Nonnull(^PRFinallyOnPromiseReturnBlock)(dispatch_queue_t, void(^)(void));
typedef PRPromise *_Nonnull(^PRPromiseRejectOnTimeoutBlock)(NSTimeInterval);

typedef id _Nonnull (^PRTransformBlock)(id data);

NS_SWIFT_NAME(Promise) @interface PRPromise : NSObject
@property (nullable, nonatomic, strong, readonly) id<NSCopying> key;

@property (nonatomic, readonly) id result;
@property (nonatomic, readonly) NSError *error;

@property (nonatomic, readonly) BOOL resolved;
@property (nonatomic, readonly) BOOL rejected;

@property (nonatomic, readonly) PRPromiseState state;
@property (nonatomic, strong, readonly) NSDate *expirationDate;

+ (instancetype)promise;

/*! typical usage:
 @code
 [PRPromise run:^(void(^resolver)(BOOL isResolved, id result, NSError *error)) {
     [someInstance someLongOperationWithCompletion:^(NSDictionary *result, NSError *error) {
         resolver(error == nil, result, error);
     }];
 }].then (....);
 @endcode
 */
+ (instancetype)run:(PRPromiseRunBlock)runBlock;

+ (instancetype)promiseWithId:(nullable id<NSCopying>)key;
+ (instancetype)manuallyExpiringPromiseWithId:(id<NSCopying>)key NS_SWIFT_NAME(manuallyExpiringPromise(id:));

/*! typical usage for request protected from multiple runs simultaniously
 should be adopted in PRPromise+Service <i>[PRPromise request....];</i>
 @code
 [PRPromise promiseWihtId:<hash_from_request_account_type_path_and_params>
                      run:^(void(^resolver)(BOOL isReject, id data, NSError *error))
 {
     [someInstance requestWithPath:path httpType:@"POST" account:ai params:params
                           success:^(NSDictionary *result) {
                                       resolver(NO, result, nil);
                                   }
                              fail:^(NSError *error) {
                                       resolver(YES, nil, error);
                                   }];
 }].then (....);
 @endcode
 */
+ (instancetype)promiseWithId:(nullable id<NSCopying>)key
                          run:(nullable PRPromiseRunBlock)runBlock;

+ (instancetype)manuallyExpiringPromiseWithId:(id<NSCopying>)key
                                          run:(nullable PRPromiseRunBlock)runBlock NS_SWIFT_NAME(manuallyExpiringPromise(id:run:));

+ (instancetype)promiseWithId:(nullable id<NSCopying>)key
          expirationCondition:(nullable PRPromiseExpirationConditionBlock)conditionBlock
                          run:(nullable PRPromiseRunBlock)runBlock;

/// @return Allready resolved promise.
+ (instancetype)resolved:(nullable id)data;

/// @return Allready rejected promise.
+ (instancetype)rejected:(nullable NSError *)error;

/**
 * @returns A promise which is resolved after all promises are performed but filter out nulls and rejected. */
+ (PRPromise *)combineAll:(NSArray<PRPromise *> *)promises;
/**

 * @returns A promise which is resolved after all promises are performed but filter out nulls and rejected if `skipRejected` is true. */
+ (PRPromise *)combineAll:(NSArray<PRPromise *> *)promises skipRejected:(BOOL)skipRejected;

/**
 * @returns A promise which is resolved after  all promises are resolved.
 * @warning If any promise fails, result promise will fail immediately.
 */
+ (PRPromise *)combineResolved:(NSArray<PRPromise *> *)promises;

- (instancetype)initWithId:(nullable id<NSCopying>)key
       expirationCondition:(nullable PRPromiseExpirationConditionBlock)conditionBlock NS_DESIGNATED_INITIALIZER;

- (PRPromise *)resolve:(nullable id)data;
- (PRPromise *)resolveVA:(NSUInteger)count,...;
- (PRPromise *)reject:(NSError *)error;

/**
 Handle Timeout:
 Fail with PRPromise Timeout error after specified interval if not resolved/rejected before
 @returns A promise itself for chaining
 */
- (PRPromise *)rejectAfterTimeout:(NSTimeInterval)timeoutInterval;
// property version
@property (nonatomic, readonly) PRPromiseRejectOnTimeoutBlock rejectAfterTimeout;

// expiration
@property (nullable, readonly, strong) NSDate *completionTime;
@property (nullable, copy) PRPromiseExpirationConditionBlock expirationConditionBlock;

/// Expires registered promise.
- (void)expire;
/// Expires registered promise.
+ (void)expirePromiseWithId:(id<NSCopying>)key;

/// Rejects incompleted promise and expires it.
- (void)reset;
/// Rejects incompleted promise and expires it.
+ (void)resetPromiseWithId:(id<NSCopying>)key;


/*!
 You perform run block after creating promise:
 @code
 [PRPromise promiseWithId:<some_id>]
 .run(^(void(^resolver)(BOOL, id, NSError *) {
    longOperationWithCompletion(^{
        resolver(YES, result, nil);
    });
 })
 @endcode
 When resolving you can wrap up to three objects in tuple
 and later handle them in 'then' block as the list of arguments:
 @code resolver(YES, PR_TUPLE(obj1, obj2, obj3), nil);@endcode or @code[promise resolve:PR_TUPLE(obj1, obj2, obj3); @endcode
 and later
 @code
 promise.then(^(id res1, id res2) { // not intereseted in the value of the last obj - is perfectly OK
    // do something with obj1 and obj2
 }
 @endcode
 */
- (PRPromiseReturnBlock)run;
/*!
 Consumers of your Promise are not compelled to consume any arguments and in fact may specify one or no parameters.
 And not returning anything is propagating previous result or failure, essentialy returning [PRPromise resolved:previousResult] or [PRPromise rejected:previousError].
 Returning non-promise object or scalar will wrap it in resolved promise and if returned from 'fail` recovers the error
 !!! Retruning nil returns [PRPromise resolved:nil] as expected and so recovers the error from 'fail`
 Rerurning NSError or just throwing it would return failed promise.
 */
- (PRPromiseReturnBlock)then NS_REFINED_FOR_SWIFT;
- (PRPromiseReturnBlock)fail NS_REFINED_FOR_SWIFT;
- (PRFinalyPromiseReturnBlock)finally;
// corresponding methods to reduce block wrapping
- (PRPromise *)then:(id)block NS_REFINED_FOR_SWIFT;
- (PRPromise *)fail:(id)block NS_REFINED_FOR_SWIFT;
- (PRPromise *)finally:(void(^)(void))block NS_REFINED_FOR_SWIFT;

/// You can perform corresponding 'then', 'fail' and "finally' blocks on any disptach queue
- (PROnPromiseReturnBlock)thenOn NS_REFINED_FOR_SWIFT;
- (PROnPromiseReturnBlock)failOn NS_REFINED_FOR_SWIFT;
- (PRFinallyOnPromiseReturnBlock)finallyOn NS_REFINED_FOR_SWIFT;

- (PRPromise *)thenOn:(dispatch_queue_t)queue block:(id)block NS_REFINED_FOR_SWIFT;
- (PRPromise *)failOn:(dispatch_queue_t)queue block:(id)block NS_REFINED_FOR_SWIFT;
- (PRPromise *)finallyOn:(dispatch_queue_t)queue block:(void(^)(void))block NS_REFINED_FOR_SWIFT;

- (PRPromise *)map:(PRTransformBlock)transform; //__attribute__( (deprecated("use `then` instead with the same result", "then")) );

@end

@interface PRPromise (Expiration)

+ (PRPromiseExpirationConditionBlock) manualExpire;

+ (PRPromiseExpirationConditionBlock) expirationConditionBlockWithResolveTimeout:(NSTimeInterval)resolveExpirationTimeout
                                                                   rejectTimeout:(NSTimeInterval)rejectExpirationTimeout;

@end


NS_ASSUME_NONNULL_END
