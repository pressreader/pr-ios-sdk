//
//  PRSourceCategoriesCollectionVC.h
//  PRiphone
//
//  Created by Jackie Cane on 25/04/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import "PRCollectionVC.h"

@import PRAPI.PRCountableValue;

@class PRSourceList;
@class PRSourceCategoriesCollectionVC;

NS_ASSUME_NONNULL_BEGIN

@protocol PRSourceCategoriesCollectionDelegate <NSObject>
- (void)discloseCategory:(PRCountableValue *)value sender:(nullable UIView *)view;
@end

@interface PRSourceCategoriesCollectionVC : PRCollectionVC

- (instancetype)initWithSourceList:(nullable PRSourceList *)sourceList;
- (instancetype)initWithSourceList:(nullable PRSourceList *)sourceList
                          delegate:(nullable id<PRSourceCategoriesCollectionDelegate>)delegate NS_DESIGNATED_INITIALIZER;

@property (nullable, nonatomic, weak) id<PRSourceCategoriesCollectionDelegate> delegate;
@property (null_resettable, nonatomic, strong) NSArray<PRCountableValue *> *dataProvider;

@property (nonatomic) UIEdgeInsets sectionInsets;

@end


@interface PRSourceCategoriesCollectionVC (/*PROTECTED*/)
- (NSArray<PRCountableValue *> *)getCategories;
@end

NS_ASSUME_NONNULL_END
