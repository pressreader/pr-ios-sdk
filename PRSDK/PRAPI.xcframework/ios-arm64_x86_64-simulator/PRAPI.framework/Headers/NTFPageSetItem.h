//
//  NTFPageSetItem.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 6/6/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "NTFFeedItem+CoreDataClass.h"

@import CoreGraphics;

@class NTFUserItem;
@class PRSmartPageset;
@class PRMyLibraryItem;

@interface NTFPageSetItem : NTFFeedItem
@property (nonatomic, readonly) PRSmartPageset *pageSet;
@property (nonatomic, readonly) PRMyLibraryItem *mli;
@property (nonatomic, readonly) NSArray<NSValue *> *pageSizes;
@property (nonatomic, readonly) NSArray<NSString *> *pageTickets;
@property (nonatomic, readonly) NSNumber *firstPageNumber;

- (CGSize)pageSizeForPageNo:(NSNumber *)pageNumber;
- (NSString *)pageTicketForPageNo:(NSInteger)pageNumber;

@end

#import "NTFPageSetItem+CoreDataProperties.h"
