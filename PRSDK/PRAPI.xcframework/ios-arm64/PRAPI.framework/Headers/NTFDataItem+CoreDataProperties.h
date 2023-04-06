//
//  NTFDataItem+CoreDataProperties.h
//  PRAPI
//
//  Created by berec on 05/03/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//
//

#import "NTFDataItem+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface NTFDataItem (CoreDataProperties)

+ (NSFetchRequest<NTFDataItem *> *)fetchRequest;

@property (nonatomic) BOOL bookmarked;
@property (nullable, nonatomic, copy) NSString *itemId;
@property (nullable, nonatomic, retain) NSData *json_;
@property (nullable, nonatomic, copy) NSString *language;
@property (nullable, nonatomic, copy) NSString *token;

@end

NS_ASSUME_NONNULL_END
