//
//  Publication+CoreDataProperties.h
//  PRAPI
//
//  Created by berec on 12/02/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//
//

#import "Publication+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface Publication (CoreDataProperties)

+ (NSFetchRequest<Publication *> *)fetchRequest;

@property (nonatomic, copy) NSString *cid;
@property (nullable, nonatomic, retain) PublicationChannel *channel;
@property (nullable, nonatomic, retain) NTFSession *session;

@end

NS_ASSUME_NONNULL_END
