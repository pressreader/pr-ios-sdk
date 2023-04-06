//
//  PRAlignedImageView.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 7/27/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, PRAlignmentStyle) {
    PRAlignmentToTopStyle = 0,
    PRAlignmentAspectFillStyle = 1
};

@interface PRAlignedImageView : UIView

+ (instancetype)view;

@property (nonatomic, assign) PRAlignmentStyle alignment;
@property (nonatomic, assign) CGFloat tintAlpha;

@property (nullable, nonatomic, strong) UIImage *image;

@end

NS_ASSUME_NONNULL_END
