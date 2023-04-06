//
//  UILabel+TappableLink.h
//  PRUIKit
//
//  Created by Vitali Bounine on 12/02/2021.
//  Copyright © 2021 PressReader. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@interface UILabel (TappableLink)
/// dynamically subclass to make UILabel able to handle standard links/attachments with URL attribute value in its attributed text
- (void)makeLinksTappable;

- (void)makeLinksTappableWithAction:(void(^)(NSURL * link))action;

/// check if tap gesture recognizer location is in specified character range
- (BOOL)isTap:(UITapGestureRecognizer *)tapGestureRecognizer inCharacterRange:(NSRange)range;
@end
NS_ASSUME_NONNULL_END
