//
//  PRNavigationBarManagementProtocol.h
//  PRiphone
//
//  Created by Jackie Cane on 08/10/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

@protocol PRNavigationBarManagementProtocol <NSObject>
- (void)cancelDelayedBarsHidding;
- (void)hideBarsWithDelay;
- (void)hideBars;
- (void)setBarsHidden:(BOOL)isHidden animated:(BOOL)animated;
- (void)setBarsHidden:(BOOL)isHidden animated:(BOOL)animated onUserTap:(BOOL)onUserTap;
@end

