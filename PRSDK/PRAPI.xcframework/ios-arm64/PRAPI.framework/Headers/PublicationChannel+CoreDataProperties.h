//
//  PublicationChannel+CoreDataProperties.h
//  PRAPI
//
//  Created by berec on 11/02/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//
//

#import "PublicationChannel+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface PublicationChannel (CoreDataProperties)

+ (NSFetchRequest<PublicationChannel *> *)fetchRequest;

@property (nullable, nonatomic, retain) NSSet<Publication *> *publications;

@end

@interface PublicationChannel (CoreDataGeneratedAccessors)

- (void)addPublicationsObject:(Publication *)value;
- (void)removePublicationsObject:(Publication *)value;
- (void)addPublications:(NSSet<Publication *> *)values;
- (void)removePublications:(NSSet<Publication *> *)values;

@end

NS_ASSUME_NONNULL_END
