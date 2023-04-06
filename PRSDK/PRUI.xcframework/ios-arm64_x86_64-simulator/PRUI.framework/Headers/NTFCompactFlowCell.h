//
//  NTFCompactFlowCell.h
//  PR-UI
//
//  Created by berec on 09/08/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "VerticalTextFlowBaseCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface NTFCompactFlowCell : VerticalTextFlowBaseCell

- (void)setupWithRow:(NSInteger)row
          dataSource:(nullable NTFDataSource *)dataSource
         actionBlock:(nullable TextFlowItemAction)actionBlock
        contentWidth:(CGFloat)contentWidth NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
