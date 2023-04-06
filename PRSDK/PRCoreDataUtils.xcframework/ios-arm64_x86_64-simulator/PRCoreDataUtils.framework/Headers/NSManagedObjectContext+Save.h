//
//  NSManagedObjectContext+Save.h
//  PR-API
//
//  Created by berec on 15/05/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

@import CoreData;

NS_ASSUME_NONNULL_BEGIN

@interface NSManagedObjectContext (Save)

- (void)verboseSave;

- (void)performBlockAndSave:(void (^)(void))block NS_SWIFT_NAME(performAndSave(_:));
- (void)performBlockAndWaitAndSave:(void (^)(void))block NS_SWIFT_NAME(performAndWaitAndSave(_:));

@end

NS_ASSUME_NONNULL_END
