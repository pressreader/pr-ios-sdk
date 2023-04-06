//
//  NTFCoreDataController+Session.h
//  PR-API
//
//  Created by berec on 18/08/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "NTFCoreDataController.h"

NS_ASSUME_NONNULL_BEGIN

@interface NTFCoreDataController (Session)

- (nullable NTFSession *)currentSessionInContext:(NSManagedObjectContext *)context online:(BOOL *_Nullable)online;
- (nullable NTFSession *)currentSessionInContext:(NSManagedObjectContext *)context;
- (nullable NTFSession *)currentSessionInMainQueueContext;

- (BOOL)isCurrentSessionOnline;
- (BOOL)isSessionOnline:(NTFSession *)session;

@end

@interface NTFCoreDataController (Feed)
/**
 @brief Current session's feedID for a given name and locale
 @param feedName feed's unique identifier
 @param locale string identifier
 @param online indicates whether feed is from online session
 */
- (NSManagedObjectID *)feedIdForName:(NSString *)feedName
                              locale:(nullable NSString *)locale
                              online:(BOOL *_Nullable)online;

- (NSManagedObjectID *)feedIdForName:(NSString *)feedName;

@end

NS_ASSUME_NONNULL_END
