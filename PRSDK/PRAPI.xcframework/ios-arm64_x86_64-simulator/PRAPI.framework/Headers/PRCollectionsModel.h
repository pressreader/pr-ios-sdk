//
//  PRCollectionsModel.h
//  PR-API
//
//  Created by Viacheslav Soroka on 12/3/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "PRArrayModel.h"

NS_ASSUME_NONNULL_BEGIN

@class NTFCollectionItem;
@class PRCollectionsModel;

@protocol PRCollectionsModelObserver <PRArrayModelObserver>

@optional
- (void)model:(PRCollectionsModel *)model didFailDeletingCollectionWithError:(NSError *)error;

@end

@protocol PRCollectionsModelSpecific <NSObject>
- (void)addObserver:(id<PRCollectionsModelObserver>)observer NS_SWIFT_NAME(addObserver(_:));

@end

@interface PRCollectionsModel<ObjectType: NTFCollectionItem *> : PRArrayModel<ObjectType> <PRCollectionsModelSpecific>

+ (instancetype)collectionsModelWithUserId:(nullable NSString *)userId;
+ (instancetype)collectionsModelWithUserId:(nullable NSString *)userId
                     excludedCollectionIds:(nullable NSSet<NSString *> *)excludedCollectionIds;

- (nullable NTFCollectionItem *)collectionWithId:(NSString *)itemId;
- (NSInteger)collectionIndexWithId:(NSString *)itemId;

@property (nonatomic) BOOL keepServerOrder;

@property (nonatomic, readonly) NSArray<ObjectType> *systemCollections;
@property (nonatomic, readonly) NSArray<ObjectType> *userCollections;
@property (nonatomic, readonly) NSArray<ObjectType> *sharedCollections;

@property (nonatomic, strong, readonly) NSSet<NSString *> *excludedCollectionIds;

@property (nullable, nonatomic, strong, readonly) NSString *userId;
@property (nonatomic, readonly) BOOL isPersonal;
@property (nonatomic, readonly) NSInteger allCollectionIndex;

@end

NS_ASSUME_NONNULL_END
