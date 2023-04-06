//
//  NSURL+Service.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 5/12/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const kPRPressReaderImagePath;
extern NSString * const kPRAzureImagePath;
extern NSString * const kPRServicesImagePath;

extern NSString * const kPRUploadImagePath;

@interface NSURL (Services)

+ (nullable instancetype)imageURLWithPath:(NSString *)path;
+ (nullable instancetype)imageURLWithPath:(NSString *)path rootPath:(NSString *)rootPath;

+ (nullable NSString *)imageURLAbsoluteStringWithPath:(NSString *)path;
+ (nullable NSString *)imageURLAbsoluteStringWithPath:(NSString *)path rootPath:(NSString *)rootPath;

+ (nullable instancetype)uploadImageURL;

@end

NS_ASSUME_NONNULL_END
