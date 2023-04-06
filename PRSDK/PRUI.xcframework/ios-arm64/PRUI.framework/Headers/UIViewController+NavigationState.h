//
//  UIViewController+NavigationState.h
//  PR-UI
//
//  Created by berec on 17/02/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController (NavigationState)
- (void)saveNavigationState;
- (void)restoreNavigationState;
@end
