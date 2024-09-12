//
//  PRAccountItem+HotSpotWelcomeMessage.h
//  PRUI
//
//  Created by Vitalii Hudenko on 25.06.2024.
//  Copyright © 2024 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
@import PRAPI;

NS_ASSUME_NONNULL_BEGIN

@interface PRAccountItem (HotSpotWelcomeMessage)

- (void)presentHotSpotWelcomeMessage:(BOOL)forced NS_SWIFT_NAME(presentHotSpotWelcomeMessage(forced:));
- (BOOL)shouldPresentHotSpotWelcomeMessage:(BOOL)forced NS_SWIFT_NAME(shouldPresentHotSpotWelcomeMessage(forced:));
- (void)updateHotSpotWelcomeMessageInfo;

@end

NS_ASSUME_NONNULL_END
