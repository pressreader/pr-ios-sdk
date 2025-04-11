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

typedef NSString * CID;

@protocol PRCatalogItem <NSObject>
@required
@property (nonatomic, readonly) CID CID;
@property (nullable, nonatomic, readonly) NSDate *date;
@property (nullable, nonatomic, readonly) NSString *title;

/// Size of downloaded content in bytes. Returns `0` in case of no content is downloaded.
@property (nonatomic, readonly) NSUInteger size;

@property (nullable, nonatomic, readonly) NSDate *sortingDate;
@property (nonatomic, readonly) PRSourceType sourceType;
@property (nullable, nonatomic, readonly) NSArray<NSString *> *countryCodes;
@property (nullable, nonatomic, readonly) NSString * originCountryCode;

@end

NS_ASSUME_NONNULL_END

#endif /* PRCatalogItem_h */
