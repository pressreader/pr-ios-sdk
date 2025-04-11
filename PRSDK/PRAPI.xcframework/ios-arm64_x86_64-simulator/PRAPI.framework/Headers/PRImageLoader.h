//
//  PRImageLoader.h
//  PRiphone
//
//  Created by Vitali Bounine on 2017-05-31.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface PRImageLoader : NSObject

- (instancetype) initWithPath:(nullable NSString *)folderPath operationQueue:(nullable NSOperationQueue *)opQueue;

- (void) loadImageWithKey:(NSString *)imgKey
                 filePath:(nullable NSString *)filePath
                cacheOnly:(BOOL)cacheOnly
         displayVideoIcon:(BOOL)displayVideoIcon
                   opName:(NSString *)opName
          generationBlock:(nullable UIImage * _Nullable (^)(NSError * _Nullable * error)) generationBlock
               completion:(nullable void (^)(UIImage * __Nullable, NSError * _Nullable err)) completionBlock;

- (void) cancelLoadingImageWithKey:(NSString *)imgKey opName:(NSString *)opName;

@end

NS_ASSUME_NONNULL_END
