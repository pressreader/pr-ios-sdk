//
//  PRTitleItemsManager.h
//  PRiphone
//
//  Created by Jackie Cane on 16/01/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SPNode;
@class PRTitleItem;
@class PRAccountItem;

NS_ASSUME_NONNULL_BEGIN

@interface PRTitleItemsManager : NSObject

- (NSMutableDictionary *)dictFromXmlItem:(SPNode *)xmlItem;
- (PRTitleItem *)titleItemFromDictionary:(NSDictionary *)dict
                                 service:(PRAccountItem *)accountItem;
- (void)removeTitleItemWithCID:(NSString *)CID;

- (void)addToSpotlightSearch:(PRTitleItem *)item;

@end

NS_ASSUME_NONNULL_END
