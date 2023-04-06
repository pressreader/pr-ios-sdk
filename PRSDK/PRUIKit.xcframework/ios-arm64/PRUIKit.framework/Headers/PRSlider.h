//
//  PRSlider.h
//  PRUIKit
//
//  Created by Viacheslav Soroka on 10/30/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRSlider : UISlider
@property (nonatomic, assign) CGFloat trackHeight;
@property (nonatomic, assign) BOOL disableTrackingOnTap;

@end

NS_ASSUME_NONNULL_END
