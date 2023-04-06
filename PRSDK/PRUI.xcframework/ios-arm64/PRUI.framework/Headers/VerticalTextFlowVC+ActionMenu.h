//
//  VerticalTextFlowVC+ActionMenu.h
//  PR-UI
//
//  Created by berec on 14/04/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "VerticalTextFlowVC.h"

@class PRMenuItem;

NS_ASSUME_NONNULL_BEGIN

@interface VerticalTextFlowVC (ActionMenu)

@property (nonatomic, readonly) NSArray<PRMenuItem *> *actionMenuItems;
@property (nonatomic, readonly) PRMenuItem *fontAdjustmentMenuItem;
@property (nonatomic, readonly, nullable) PRMenuItem *translationMenuItem;

@end

NS_ASSUME_NONNULL_END
