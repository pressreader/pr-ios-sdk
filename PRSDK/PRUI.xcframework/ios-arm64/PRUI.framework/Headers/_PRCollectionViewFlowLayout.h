//
//  _PRCollectionViewFlowLayout.h
//  PR-UI
//
//  Created by berec on 02/01/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class _PRLayoutSection;
@class _PRLayoutParameters;

@interface _PRCollectionViewFlowLayout : UICollectionViewFlowLayout

- (_PRLayoutParameters *)layoutParametersForSection:(NSInteger)section;

@property (nonatomic, strong) NSArray<_PRLayoutSection *> *layoutInfoCache;

@end

NS_ASSUME_NONNULL_END
