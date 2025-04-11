//
//  NTFDataItem.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 3/30/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <CoreData/CoreData.h>

@import PRUtils.NSDictionaryCIWrapper;
@class NTFUserItem;
@class DataItemContent;

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

@property (nonatomic, readonly) NTFDataItemType type;
@property (nullable, nonatomic, readonly) NTFUserItem *owner;

@end

@interface NTFDataItem (/*Protected*/)

+ (nullable NSString *)itemIdFromJSON:(NSDictionary<NSString *, id> *)json;

- (void)resetComputedProperties;
- (void)updateWithJSON:(NSDictionary *)json;
- (nullable NSDictionaryCIWrapper *)payloadWithJSON:(NSDictionary<NSString*, id> *)json;
- (nullable NSString *)languageFromJSON:(NSDictionary *)json;

@property (nullable, nonatomic, copy) NSString *contextKey;

@end

NS_ASSUME_NONNULL_END

#import "NTFDataItem+CoreDataProperties.h"
