//
//  PRCoreDataController
//  PRiphone
//
//  Created by Jackie Cane on 8/02/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <CoreData/CoreData.h>

@class PRPromise;

NS_ASSUME_NONNULL_BEGIN

@interface PRCoreDataController : NSObject

+ (instancetype)instance;

- (NSManagedObjectContext *)getPrivateQueueContext;
- (NSManagedObjectContext *)threadAppropriateContext;
- (NSManagedObjectContext *)newContextWithConcurrencyType:(NSManagedObjectContextConcurrencyType)type;

- (PRPromise *)loadIfNeeded;

@property (nonatomic, strong, readonly) NSManagedObjectModel *managedObjectModel;
@property (nonatomic, strong, readonly) NSPersistentStoreCoordinator *persistentStoreCoordinator;
@property (nonatomic, strong, readonly) NSManagedObjectContext *mainQueueContext;

@property (nonatomic, readonly) NSURL *dataStoreDirectoryURL;
@property (nonatomic, readonly) NSString *databaseName;
@property (nonatomic, readonly) NSString *managedObjectModelName;
@property (nullable, nonatomic, readonly) NSBundle *managedObjectModelBundle;

@property (nonatomic, readonly) BOOL isLoaded;

@end

NS_ASSUME_NONNULL_END

@import PRCoreDataUtils.NSManagedObjectContext_Save;
