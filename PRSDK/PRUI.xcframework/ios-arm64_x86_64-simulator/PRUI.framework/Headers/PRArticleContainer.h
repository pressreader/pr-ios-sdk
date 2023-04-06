//
//  PRArticleContainer.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 10/26/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "VerticalTextFlowVC.h"

NS_ASSUME_NONNULL_BEGIN

@class PRMenuView;

@protocol PRArticleContainer <UIPopoverPresentationControllerDelegate>
@property (nonatomic, readonly) PRMenuView *menuView;
@property (nonatomic) NTFTextFlowType openedFromTextFlowType;

@end

NS_ASSUME_NONNULL_END
