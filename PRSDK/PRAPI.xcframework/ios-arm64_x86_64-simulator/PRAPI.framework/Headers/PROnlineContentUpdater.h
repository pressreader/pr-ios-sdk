//
//  PROnlineContentUpdater.h
//  PRiphone
//
//  Created by Dmitry Melnik on 11-03-29.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum { updsNone, updsInprogress, updsVersion, updsDone, updsError } PRUpdateStatus;

@interface PRUpdateItem: NSObject

@property (nonatomic, readonly, copy) NSString* eid;
@property (nonatomic, readonly, copy) NSString* group;
@property (nonatomic, readonly) PRUpdateStatus updateStatus;

@property (nonatomic, copy) NSString* srcUrl;
@property (nonatomic, strong) NSString* dstPath;
@property (nonatomic, copy) NSString* remoteVersion;
@property (nonatomic) BOOL deleteBeforeUpdate;

- (instancetype) initWithParams:(NSDictionary*)params;

- (NSString*) path;
- (void) download;
- (NSString *) version;
- (NSString *) versionInUse;

@end

//
// extendible service for updating local cached files from the web-service
//
@interface PROnlineContentUpdater : NSObject
{
    int        m_retry;
    NSMutableDictionary*  m_pool; // array of elements to update. 
    NSMutableDictionary* m_groupsUpdated;
}

- (instancetype)initWithElement:(PRUpdateItem *)element;

- (void) AddElement:(PRUpdateItem*)elem;
- (void) Update:(NSString*)groupName; // Supposed to call when it is decided to update a group.

- (PRUpdateItem*) GetElement:(NSString*)elemId;
- (NSString*) GetPath:(NSString*)elemId;

- (void)stop;

@end

NS_ASSUME_NONNULL_END
