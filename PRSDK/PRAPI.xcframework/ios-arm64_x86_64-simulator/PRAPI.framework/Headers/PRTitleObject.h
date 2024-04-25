//
//  PRTitleObject.h
//  PRAPI
//
//  Created by KeithC on 2019-03-27.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "PRCatalogItem.h"

@class PRTitleItem;
@class PRTitleItemExemplar;
@class PRMyLibraryItem;

NS_ASSUME_NONNULL_BEGIN

@protocol PRTitleObject <PRCatalogItem>
@required
@property (nonatomic, readonly) NSUInteger rate;
@property (nullable, nonatomic, readonly) NSDate *activationTime;
@property (nonatomic, readonly) BOOL isRead;
@property (nonatomic, readonly) NSInteger orderNumber;

@property (nullable, nonatomic, readonly) PRTitleItem *titleItem;
@property (nullable, nonatomic, readonly) PRTitleItemExemplar *exemplar;
@property (nullable, nonatomic, readonly) PRMyLibraryItem *libraryItem;

@end

NS_ASSUME_NONNULL_END

