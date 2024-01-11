//
//  PRSourceCategoriesCollectionVC.h
//  PRiphone
//
//  Created by Jackie Cane on 25/04/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import "PRCollectionVC.h"

@protocol CatalogNavigation;

NS_ASSUME_NONNULL_BEGIN

@protocol PRSourceCategoriesCollectionDelegate <NSObject>
- (void)discloseCategory:(id<CatalogNavigation>)value sender:(nullable UIView *)sender;
@end

/// The abstract controller not to be used directly.
@interface PRSourceCategoriesCollectionVC : PRCollectionVC

@property (nullable, nonatomic, weak) id<PRSourceCategoriesCollectionDelegate> delegate;
@property (null_resettable, nonatomic, strong) NSArray<id<CatalogNavigation>> *dataProvider;

@property (nonatomic) UIEdgeInsets sectionInsets;

@end

NS_ASSUME_NONNULL_END
