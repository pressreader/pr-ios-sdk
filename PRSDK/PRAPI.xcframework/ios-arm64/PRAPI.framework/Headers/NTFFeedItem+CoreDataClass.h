//
//  NTFFeedItem+CoreDataClass.h
//  PR-API
//
//  Created by berec on 27/04/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import "NTFDataItem+CoreDataClass.h"

@class NTFChannelAccountItem, NTFFeed;

NS_ASSUME_NONNULL_BEGIN

@interface NTFFeedItem : NTFDataItem

+ (nullable instancetype)itemWithJSON:(NSDictionary *)json
                                 feed:(NTFFeed *)feed
                              context:(NSManagedObjectContext *)context;

+ (nullable instancetype)itemWithJSON:(NSDictionary *)json
                          isoLanguage:(nullable NSString *)language
                                 feed:(NTFFeed *)feed
                              context:(NSManagedObjectContext *)context;

/// Looks for an item with a given id in a given feed
+ (nullable instancetype)getItemWithId:(NSString *)itemId feed:(NTFFeed *)feed;
+ (nullable instancetype)getItemWithId:(NSString *)itemId feed:(NTFFeed *)feed predicate:(nullable NSPredicate *)predicate;
/// Looks for an item with an id extracted from provided info in a feed
+ (nullable instancetype)getItemWithJSON:(NSDictionary *)json feed:(NTFFeed *)feed;
+ (nullable instancetype)getItemWithJSON:(NSDictionary *)json feed:(NTFFeed *)feed predicate:(nullable NSPredicate *)predicate;

@end

NS_ASSUME_NONNULL_END

#import "NTFFeedItem+CoreDataProperties.h"
