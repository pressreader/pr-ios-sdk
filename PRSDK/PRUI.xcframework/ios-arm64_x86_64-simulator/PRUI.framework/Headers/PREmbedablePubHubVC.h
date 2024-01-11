//
//  PREmbedablePubHubVC.h
//  PRiphone
//
//  Created by berec on 3/11/16.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import "PRSourcesVC.h"

@import PRAPI.PRCatalogSection;

#import <PRUI/PRHotspotStatusViewManagerProtocol.h>
#import <PRUI/PRPubHubDataSource.h>

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const PRCatalogHeightWasChanged;
extern NSNotificationName const PRCatalogSectionWasDisclosed;

typedef NS_OPTIONS(NSUInteger, PRPubHubOption) {
    PRPubHubOptionRefreshControl = 1 << 0
};

@interface PREmbedablePubHubVC : PRSourcesVC

- (instancetype)initWithDataSource:(PRPubHubDataSource *)dataSource;
- (instancetype)initWithSourceList:(PRSourceList *)sourceList NS_UNAVAILABLE;

@property (nullable, nonatomic, strong) id<CatalogFacade> sourceList NS_UNAVAILABLE;

@property (nonatomic) PRCatalogSectionType sectionToDisclose;

@property (nonatomic, readonly) CGSize contentSize;
@property (nonatomic) CGFloat contentTopInset;

@property (nonatomic, strong, readonly) PRPubHubDataSource *dataSource;
@property (nonatomic, readonly) BOOL isEmpty;

@property (nonatomic, readonly) PRPubHubOption hubOptions;

@property (nonatomic, readonly) BOOL shouldDiscard;

@end

NS_ASSUME_NONNULL_END

#import "PRPubHubVC+HotSpot.h"
