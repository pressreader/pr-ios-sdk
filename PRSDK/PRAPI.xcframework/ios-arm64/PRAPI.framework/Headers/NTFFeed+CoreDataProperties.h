//
//  NTFFeed+CoreDataProperties.h
//  PRAPI
//
//  Created by berec on 11/02/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//
//

#import "NTFFeed+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface NTFFeed (CoreDataProperties)

+ (NSFetchRequest<NTFFeed *> *)fetchRequest;

@property (nullable, nonatomic, copy) NSString *locale;
@property (nullable, nonatomic, copy) NSString *name;
@property (nullable, nonatomic, retain) NTFChannelAccountItem *userChannel;
@property (nullable, nonatomic, retain) NSSet<NTFFeedItem *> *feedItems;
@property (nullable, nonatomic, retain) NTFSession *session;
@property (nullable, nonatomic, retain) Channel *channel;
@property (nullable, nonatomic, retain) Interest *interest;

@end

@interface NTFFeed (CoreDataGeneratedAccessors)

- (void)addFeedItemsObject:(NTFFeedItem *)value;
- (void)removeFeedItemsObject:(NTFFeedItem *)value;
- (void)addFeedItems:(NSSet<NTFFeedItem *> *)values;
- (void)removeFeedItems:(NSSet<NTFFeedItem *> *)values;

@end

NS_ASSUME_NONNULL_END
