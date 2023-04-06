//
//  NTFDataItem.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 3/30/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <CoreData/CoreData.h>

@import PRUtils.NSDictionaryCIWrapper;

@class NSDictionaryCIWrapper;
@class PRWeakLink;

typedef NS_ENUM(NSInteger, NTFDataItemType) {
    NTFDataItemTypeNone,
    NTFDataItemTypeArticle = 1,
    NTFDataItemTypeSection,
    NTFDataItemTypeRecentIssues = 5,
    NTFDataItemTypeAdBlock = 16,
    NTFDataItemTypePageset = 18,
    NTFDataItemTypeGift = 22,
    NTFDataItemTypePersonalization = 26,
    NTFDataItemTypeArticleSet
};

NS_ASSUME_NONNULL_BEGIN

@interface NTFDataItem : NSManagedObject

+ (instancetype)itemWithJSON:(NSDictionary *)json context:(NSManagedObjectContext *)context;
+ (instancetype)itemWithJSON:(NSDictionary *)json
                 isoLanguage:(nullable NSString *)language
                     context:(NSManagedObjectContext *)context;

+ (instancetype)itemWithJSON:(NSDictionary *)json
                 isoLanguage:(nullable NSString *)language
                     context:(NSManagedObjectContext *)context
                  standalone:(BOOL)isTemporary;

- (void)updateWithJSON:(NSDictionary *)json;

@property (nonatomic, readonly) NTFDataItemType type;
@property (nullable, nonatomic, strong, readonly) NSDictionaryCIWrapper *info;
@property (nullable, nonatomic, strong, readonly) NSDictionaryCIWrapper *payload;
@property (nullable, nonatomic, strong, readonly) NSDictionary *json;

@end

@interface NTFDataItem (/*Protected*/)

- (void)resetComputedProperties;

@property (nullable, nonatomic, copy) NSString *contextKey;

@end

NS_ASSUME_NONNULL_END

#import "NTFDataItem+CoreDataProperties.h"
#import "NTFDataItem+Convenience.h"
