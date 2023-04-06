//
//  UINavigationItem+OptionTitle.h
//  PRiphone
//
//  Created by Jackie Cane on 10/29/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BarOptionTitleView.h"

@interface UINavigationItem (OptionTitle)

- (void)setupOptionTitleViewWithText:(NSString *)titleText
                             details:(NSString *)detailText
                            delegate:(id<BarOptionTitleViewDelegate>)delegate
                            barLight:(BOOL)barLight
                          arrowColor:(PRBarOptionTitleArrowColor)arrowColor;

- (void)setupOptionTitleViewWithText:(NSString *)titleText
                             details:(NSString *)detailText
                            delegate:(id<BarOptionTitleViewDelegate>)delegate;

- (void)setupOptionTitleViewWithImage:(UIImage *)image
                             delegate:(id<BarOptionTitleViewDelegate>)delegate
                             barLight:(BOOL)barLight
                           arrowColor:(PRBarOptionTitleArrowColor)arrowColor;

- (void)setupOptionTitleViewWithText:(NSString *)titleText details:(NSString *)detailText;

@end
