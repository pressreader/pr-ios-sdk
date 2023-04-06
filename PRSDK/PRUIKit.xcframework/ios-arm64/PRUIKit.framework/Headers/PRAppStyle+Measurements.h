//
//  PRAppStyle+Measurements.h
//  PRUIKit
//
//  Created by berec on 30/11/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <PRUIKit/PRUIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRAppStyle (Measurements)

+ (void)saveBarsHeight;

@property(class, nonatomic, readonly) CGFloat maxStatusBarHeight;
@property(class, nonatomic, readonly) CGFloat maxNavBarHeight;

@end

NS_ASSUME_NONNULL_END
