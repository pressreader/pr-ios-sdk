//
//  UIScrollView+Extended.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 9/27/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, PRSide) {
    PRSideTop = 0,
    PRSideRight,
    PRSideBottom,
    PRSideLeft
};

@interface UIScrollView (Extended)

- (CGFloat)contentInsetForSide:(PRSide)side;

- (void)scrollToBeginning;

@end

NS_ASSUME_NONNULL_END
