//
//  PRCatalogItem.h
//  PRAPI
//
//  Created by berec on 10/12/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#ifndef PRCatalogItem_h
#define PRCatalogItem_h

#import <Foundation/Foundation.h>
@import PRCatalogModel.PRSourceItem_Basics;
@class PRTitleItemExposer;

NS_ASSUME_NONNULL_BEGIN

typedef NSString * CID;

@protocol PRCatalogItem <NSObject>
@property (nonatomic, readonly) CID CID;
@property (nullable, nonatomic, readonly) NSDate *date;
@property (nullable, nonatomic, readonly) NSString *title;
@property (nullable, nonatomic, readonly) NSDate *sortingDate;

// for legacy objc compatibility
@property (nullable, nonatomic, readonly) PRTitleItemExposer *ti;

@end

NS_ASSUME_NONNULL_END

#endif /* PRCatalogItem_h */
