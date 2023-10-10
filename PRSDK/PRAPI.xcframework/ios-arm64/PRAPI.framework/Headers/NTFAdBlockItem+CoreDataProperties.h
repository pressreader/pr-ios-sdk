//
//  NTFAdBlockItem+CoreDataProperties.h
//  PR-API
//
//  Created by berec on 27/04/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//
//

#import "NTFAdBlockItem.h"


NS_ASSUME_NONNULL_BEGIN

@interface NTFAdBlockItem (CoreDataProperties)

+ (NSFetchRequest<NTFAdBlockItem *> *)fetchRequest;


@end

NS_ASSUME_NONNULL_END
