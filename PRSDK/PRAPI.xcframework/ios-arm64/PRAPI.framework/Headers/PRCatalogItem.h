//
//  PRCatalogItem.h
//  PRAPI
//
//  Created by berec on 10/12/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#ifndef PRCatalogItem_h
#define PRCatalogItem_h

@import Foundation;
@import PRCatalogModel.PRSourceItem_Basics;

NS_ASSUME_NONNULL_BEGIN

@protocol PRCatalogItem <NSObject>
@required
@property (nonatomic, readonly) NSString *CID;
@property (nullable, nonatomic, readonly) NSDate *date;
@property (nullable, nonatomic, readonly) NSString *title;

@property (nullable, nonatomic, readonly) NSDate *sortingDate;
@property (nonatomic, readonly) PRSourceType sourceType;

@end

NS_ASSUME_NONNULL_END

#endif /* PRCatalogItem_h */
