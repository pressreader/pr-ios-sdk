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

NS_ASSUME_NONNULL_BEGIN

@interface NTFPageSetItem : NTFFeedItem
@property (nonatomic, readonly) PRSmartPageset *pageSet;
@property (nullable, nonatomic, readonly) PRMyLibraryItem *mli;
@property (nullable, nonatomic, readonly) NSArray<NSValue *> *pageSizes;
@property (nullable, nonatomic, readonly) NSArray<NSString *> *pageTickets;
@property (nullable, nonatomic, readonly) NSNumber *firstPageNumber;

- (CGSize)pageSizeForPageNo:(NSNumber *)pageNumber;
- (NSString *)pageTicketForPageNo:(NSInteger)pageNumber;

@end

NS_ASSUME_NONNULL_END

#import "NTFPageSetItem+CoreDataProperties.h"
