//
//  NTFDataItem+CoreDataProperties.h
//  PRAPI
//
//  Created by Vitalii Hudenko on 21.08.2024.
//  Copyright © 2024 NewspaperDirect. All rights reserved.
//
//

#import "NTFDataItem+CoreDataClass.h"

@class DataItemContent;

NS_ASSUME_NONNULL_BEGIN

@interface NTFDataItem (CoreDataProperties)

+ (NSFetchRequest<NTFDataItem *> *)fetchRequest;

@property (nonatomic) BOOL bookmarked;
@property (nullable, nonatomic, copy) NSString *itemId;
@property (nonatomic, copy) NSString *language;
@property (nullable, nonatomic, copy) NSString *token;
@property (nonatomic, retain) NSSet<DataItemContent *> *contents;

@end

@interface NTFDataItem (CoreDataGeneratedAccessors)

- (void)addContentsObject:(DataItemContent *)value;
- (void)removeContentsObject:(DataItemContent *)value;
- (void)addContents:(NSSet<DataItemContent *> *)values;
- (void)removeContents:(NSSet<DataItemContent *> *)values;

@end

NS_ASSUME_NONNULL_END
