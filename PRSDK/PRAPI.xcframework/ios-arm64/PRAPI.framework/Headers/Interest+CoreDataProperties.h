//
//  Interest+CoreDataProperties.h
//  PRAPI
//
//  Created by berec on 20/01/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//
//

#import "Interest+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface Interest (CoreDataProperties)

+ (NSFetchRequest<Interest *> *)fetchRequest;

@property (nonatomic) NSInteger id;
@property (nullable, nonatomic, copy) NSString *imageId;
@property (nonatomic, copy) NSString *name;
@property (nonatomic) BOOL selected;
@property (nullable, nonatomic, copy) NSString *subtitle;
@property (nullable, nonatomic, retain) NSSet<NTFFeedItem *> *feedItems;
@property (nullable, nonatomic, retain) NTFFeed *feed;
@property (nullable, nonatomic, retain) NTFSession *session;

@end

@interface Interest (CoreDataGeneratedAccessors)

- (void)addFeedItemsObject:(NTFFeedItem *)value;
- (void)removeFeedItemsObject:(NTFFeedItem *)value;
- (void)addFeedItems:(NSSet<NTFFeedItem *> *)values;
- (void)removeFeedItems:(NSSet<NTFFeedItem *> *)values;

@end

NS_ASSUME_NONNULL_END
