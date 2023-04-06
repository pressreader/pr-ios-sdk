//
//  NTFPageSetItem+CoreDataProperties.h
//  PR-API
//
//  Created by berec on 26/04/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//
//

#import "NTFPageSetItem.h"


NS_ASSUME_NONNULL_BEGIN

@interface NTFPageSetItem (CoreDataProperties)

+ (NSFetchRequest<NTFPageSetItem *> *)fetchRequest;

@property (nullable, nonatomic, copy) NSDate *issueDate;
@property (nullable, nonatomic, copy) NSString *cid;
@property (nullable, nonatomic, copy) NSString *publicationName;

@end

NS_ASSUME_NONNULL_END
