//
//  PRGroupedExemplarsCollectionVC.h
//  PRiphone
//
//  Created by Jackie Cane on 03/11/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import "PRSourceCollectionVC.h"
#import "PRGrouppedIssuesCollection.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRGroupedExemplarsCollectionVC : PRSourceCollectionVC <PRGrouppedIssuesCollection>

+ (CGFloat)recommendedWidthForNumberOfColumns:(NSInteger)numberOFColumns
                                       insets:(UIEdgeInsets)insets;

@property (nonatomic, assign) NSUInteger recommendedColumnCount;
@property (nonatomic, assign) CGFloat firstHeaderHeight;
@property (nonatomic, assign) CGFloat groupTitleHeight;

@property (nonatomic, readonly) CGFloat recommendedWidth;

@end

NS_ASSUME_NONNULL_END
