//
//  PRUnzip.h
//  PRiphone
//
//  Created by Dmitry Melnik on 12-02-07.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRUnzip : NSObject

+ (BOOL)unzipArchiveAtPath:(NSString *)path toDestination:(NSString *)destination;
+ (BOOL)unzipArchiveAtPath:(NSString *)path toDestination:(NSString *)destination error:(NSError **)error;
+ (BOOL)unzipArchiveAtPath:(NSString *)path
             toDestination:(NSString *)destination
                 overwrite:(BOOL)overwrite
                  password:(nullable NSString *)password
                    filter:(NSString *_Nullable (^_Nullable)(NSString *filename))filterBlock
                     error:(NSError **)error;

+ (BOOL)checkFile:(NSString *)fileName inArchive:(NSString *)path error:(NSError **)error;
+ (BOOL)checkFile:(NSString *)fileName inArchive:(NSString *)path regex:(BOOL)regex error:(NSError **)error;
+ (BOOL)checkFile:(NSString *)fileName inArchive:(NSString *)path password:(nullable NSString *)password regex:(BOOL)regex error:(NSError **)error;

+ (nullable NSData *)extractDataFromFile:(NSString *)fileName inArchive:(NSString *)path error:(NSError **)error;
+ (nullable NSData *)extractDataFromFile:(NSString *)fileName inArchive:(NSString *)path regex:(BOOL)regex error:(NSError **)error;
+ (nullable NSData *)extractDataFromFile:(NSString *)fileName inArchive:(NSString *)path password:(nullable NSString *)password regex:(BOOL)regex error:(NSError **)error;

+ (void) extractFiles:(NSString*)srcArchive dst:(NSMutableDictionary<NSString *, NSData *> *)dst;

@end

NS_ASSUME_NONNULL_END
