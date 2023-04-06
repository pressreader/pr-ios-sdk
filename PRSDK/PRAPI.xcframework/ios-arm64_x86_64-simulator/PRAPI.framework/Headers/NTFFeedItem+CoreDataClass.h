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

/// Inserts new item into feed and fill it with provided JSON
+ (instancetype)itemWithJSON:(NSDictionary *)json
                 isoLanguage:(nullable NSString *)language
                        feed:(NTFFeed *)feed;

/// Inserts into or fetches from feed (if exists) and returns a Feed Item based on provided info
+ (instancetype)itemWithJSON:(NSDictionary *)json feed:(NTFFeed *)feed;

+ (instancetype)itemWithJSON:(NSDictionary *)json
                     context:(NSManagedObjectContext *)context NS_UNAVAILABLE;
+ (instancetype)itemWithJSON:(NSDictionary *)json
                 isoLanguage:(nullable NSString *)language
                     context:(NSManagedObjectContext *)context NS_UNAVAILABLE;

/// Looks for an item with a given id in a given feed
+ (nullable instancetype)getItemWithId:(NSString *)itemId feed:(NTFFeed *)feed;
/// Looks for an item with an id extracted from provided info in a feed
+ (nullable instancetype)getItemWithJSON:(NSDictionary *)json feed:(NTFFeed *)feed;

@end

NS_ASSUME_NONNULL_END

#import "NTFFeedItem+CoreDataProperties.h"
