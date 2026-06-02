//
//  PRLoadMoreView.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 8/5/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <PRUIKit/PRUIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRLoadMoreView : UIView
@property (nonatomic) BOOL loading;
@property (nullable, nonatomic, copy) PRUIControlEventHandler moreButtonTouchHandler;

@end

NS_ASSUME_NONNULL_END
