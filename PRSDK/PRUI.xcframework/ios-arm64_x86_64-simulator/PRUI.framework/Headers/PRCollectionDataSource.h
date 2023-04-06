//
//  PRCollectionDataSource.h
//  PR-UI
//
//  Created by berec on 12/04/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <PRUI/NTFFeedDataSource.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRCollectionDataSource : NTFFeedDataSource

- (instancetype)initWithUserId:(nullable NSString *)userId
                collectionName:(nullable NSString *)collectionName;

@property (nullable, nonatomic, copy) NSString *userId;
@property (nullable, nonatomic, copy) NSString *collectionName;

@end

@interface PRCollectionDataSource (/*PROTECTED*/)
- (NSManagedObjectID *)getFeedId:(BOOL *_Nullable)online;
@end

NS_ASSUME_NONNULL_END
