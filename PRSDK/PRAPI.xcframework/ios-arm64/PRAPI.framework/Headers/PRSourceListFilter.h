//
//  PRSourceListFilter.h
//  PRiphone
//
//  Created by Jackie Cane on 10/02/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

@import Foundation;
@import CoreGraphics;

NS_ASSUME_NONNULL_BEGIN

extern CGSize const kCategoryLargeImageSize;
extern CGSize const kCountryImageSize;

@interface PRSourceListFilter : NSObject

@property (nonatomic, strong, nullable) id value;
@property (nonatomic, strong, nullable) NSString *title;
@property (nonatomic, readonly) NSString *path;
@property (nonatomic, readonly) NSString *urlComplientPath;

@property (nonatomic, assign) BOOL rootFilter;

@end

NS_ASSUME_NONNULL_END
