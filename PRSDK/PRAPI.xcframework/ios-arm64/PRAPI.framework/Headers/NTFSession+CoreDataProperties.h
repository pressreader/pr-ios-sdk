//
//  NTFSession+CoreDataProperties.h
//  PRAPI
//
//  Created by berec on 12/02/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//
//

#import "NTFSession+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface NTFSession (CoreDataProperties)

+ (NSFetchRequest<NTFSession *> *)fetchRequest;

@property (nullable, nonatomic, copy) NSDate *created;
@property (nullable, nonatomic, copy) NSDate *userInterestsUpdateDate;
@property (nullable, nonatomic, retain) NSSet<Channel *> *channels;
@property (nullable, nonatomic, retain) NSSet<NTFFeed *> *feeds;
@property (nullable, nonatomic, retain) NSSet<Interest *> *interests;
@property (nullable, nonatomic, retain) NSSet<NTFChannelAccountItem *> *userChannels;
@property (nullable, nonatomic, retain) NSSet<Publication *> *publications;

@end

@interface NTFSession (CoreDataGeneratedAccessors)

- (void)addChannelsObject:(Channel *)value;
- (void)removeChannelsObject:(Channel *)value;
- (void)addChannels:(NSSet<Channel *> *)values;
- (void)removeChannels:(NSSet<Channel *> *)values;

- (void)addFeedsObject:(NTFFeed *)value;
- (void)removeFeedsObject:(NTFFeed *)value;
- (void)addFeeds:(NSSet<NTFFeed *> *)values;
- (void)removeFeeds:(NSSet<NTFFeed *> *)values;

- (void)addInterestsObject:(Interest *)value;
- (void)removeInterestsObject:(Interest *)value;
- (void)addInterests:(NSSet<Interest *> *)values;
- (void)removeInterests:(NSSet<Interest *> *)values;

- (void)addUserChannelsObject:(NTFChannelAccountItem *)value;
- (void)removeUserChannelsObject:(NTFChannelAccountItem *)value;
- (void)addUserChannels:(NSSet<NTFChannelAccountItem *> *)values;
- (void)removeUserChannels:(NSSet<NTFChannelAccountItem *> *)values;

- (void)addPublicationsObject:(Publication *)value;
- (void)removePublicationsObject:(Publication *)value;
- (void)addPublications:(NSSet<Publication *> *)values;
- (void)removePublications:(NSSet<Publication *> *)values;

@end

NS_ASSUME_NONNULL_END
