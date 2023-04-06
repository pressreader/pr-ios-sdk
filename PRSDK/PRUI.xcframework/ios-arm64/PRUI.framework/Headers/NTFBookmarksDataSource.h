//
//  NTFBookmarksDataSource.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 11/28/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "PRCollectionDataSource.h"

NS_ASSUME_NONNULL_BEGIN

@class PRCollectionsModel;
@class NTFCollectionItem;

@interface NTFBookmarksDataSource : PRCollectionDataSource

+ (instancetype)dataSourceWithUserId:(nullable NSString *)userId NS_SWIFT_NAME(init(withUserId:));

+ (instancetype)dataSourceWithUserId:(nullable NSString *)userId
                    collectionsModel:(nullable PRCollectionsModel *)collectionsModel
                          collection:(nullable NTFCollectionItem *)collection NS_SWIFT_NAME(init(withUserId:collectionsModel:collection:));

- (instancetype)initWithUserId:(nullable NSString *)userId
              collectionsModel:(nullable PRCollectionsModel *)collectionsModel
                    collection:(nullable NTFCollectionItem *)collection;

@property (nullable, nonatomic, strong) PRCollectionsModel *collectionsModel;
@property (nullable, nonatomic, strong) NTFCollectionItem *collection;

@end

@interface NTFBookmarksDataSource (/*Protected*/)
- (NTFCollectionItem *)defaultCollectionWithCollections:(NSArray<NTFCollectionItem *> *)collections;
@end

NS_ASSUME_NONNULL_END
