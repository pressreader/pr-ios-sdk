//
//  NTFSession+CoreDataClass.h
//  PR-API
//
//  Created by berec on 27/04/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class NTFChannelAccountItem, NTFFeed, Interest, Channel, Publication;

NS_ASSUME_NONNULL_BEGIN

@interface NTFSession : NSManagedObject

+ (instancetype)newSessionWithDate:(NSDate *)date context:(NSManagedObjectContext *)context;

@property (nonatomic, strong, readonly) NTFFeed *homeFeed;
@property (nonatomic, strong, readonly) NTFFeed *trashFeed;
@property (nonatomic, strong, readonly) NTFFeed *globalSearchFeed;

@end

NS_ASSUME_NONNULL_END

#import "NTFSession+CoreDataProperties.h"
