//
//  NTFCollectionItem+CoreDataProperties.h
//  PRAPI
//
//  Created by berec on 11/02/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//
//

#import "NTFCollectionItem+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface NTFCollectionItem (CoreDataProperties)

+ (NSFetchRequest<NTFCollectionItem *> *)fetchRequest;

@property (nullable, nonatomic, copy) NSString *itemId;
@property (nullable, nonatomic, copy) NSString *webName;
@property (nullable, nonatomic, copy) NSString *name;
@property (nonatomic) int32_t contentCount;
@property (nonatomic) int16_t type;
@property (nonatomic) BOOL isPublic;
@property (nullable, nonatomic, retain) Channel *channel;

@end

NS_ASSUME_NONNULL_END
