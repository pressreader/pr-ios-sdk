//
//  NTFFeed+CoreDataClass.h
//  PR-API
//
//  Created by berec on 27/04/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class NTFChannelAccountItem, NTFFeedItem, NTFSession, NTFOpinion, Channel, Interest;

NS_ASSUME_NONNULL_BEGIN

@interface NTFFeed : NSManagedObject

/// CAUTION. Using this method you become responsible
/// for the created feed's life cycle.
/// Consider using NTFFeed+Session API as a safe alternative.
+ (instancetype)feedWithName:(NSString *)name
                      locale:(nullable NSString *)locale
                     context:(NSManagedObjectContext *)context;

+ (instancetype)feedWithName:(NSString *)name
                     context:(NSManagedObjectContext *)context;

@end

/// IMPORTANT. Accessing feed via methods of this category is preferrable.
@interface NTFFeed (Session)

+ (instancetype)newFeedWithName:(NSString *)name
                         locale:(nullable NSString *)locale
                        session:(NTFSession *)session;

+ (instancetype)existingFeedWithName:(NSString *)name
                              locale:(nullable NSString *)locale
                             session:(NTFSession *)session;

+ (instancetype)feedWithName:(NSString *)name
                      locale:(nullable NSString *)locale
                     session:(NTFSession *)session;

@end

NS_ASSUME_NONNULL_END

#import "NTFFeed+CoreDataProperties.h"
