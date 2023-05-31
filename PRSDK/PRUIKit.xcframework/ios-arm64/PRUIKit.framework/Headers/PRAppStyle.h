//
//  PRAppStyle.h
//  PRiphone
//
//  Created by Jackie Cane on 2/26/13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//
//  This class contains styles which can be applied to
//  different parts of the app's UI.
//

#import <UIKit/UIKit.h>

#import "PRAppStyleProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRAppStyle : NSObject

+ (UIImage *)navigationBarBottomDecorationLineImage;
+ (NSDictionary *)titleTextAttributesIfBarIsLight:(BOOL)isBarLight;
+ (NSDictionary *)detailTitleTextAttributesIfBarIsLight:(BOOL)isBarLight;

+ (UIView *)greenSelectionBackgroundView;

@end

@interface UISegmentedControl (PRAppStyle)<PRAppStyleProtocol>
- (void)refreshSectionImages;
@end

NS_ASSUME_NONNULL_END

#import "UIColor+AppStyle.h"
#import "UIColor+Theme.h"
#import "UIButton+AppStyle.h"
#import "PRAppStyle+Measurements.h"
