//
//  PRPremiumBannerView.h
//  PR-UI
//
//  Created by berec on 20/08/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

extern CGFloat const kPRPhoneTitleImageViewSuperViewWidthRatio;

@interface PRPremiumBannerView : UIView
@property (nullable, nonatomic, strong) NSString *title;
@property (nullable, nonatomic, strong) NSString *text;
@property (nullable, nonatomic, strong) NSAttributedString *attributedText;
@property (nullable, nonatomic, strong) NSString *proceedButtonTitle;
@property (nullable, nonatomic, strong) NSString *dismissButtonTitle;
@property (nullable, nonatomic, strong) UIImage *image;
@property (nullable, nonatomic, strong) UIImage *backgroundImage;

@end

@class BrandGradientView;

@interface PRPremiumBannerView (/*Protected*/)

- (void)setupLabels;

@property (nonatomic, strong) __kindof UIView *containerView;
@property (nonatomic, strong) BrandGradientView *backgroundGradient;
@property (nonatomic, strong) UIButton *dismissButton;
@property (nonatomic, strong) UIButton *proceedButton;
@property (nonatomic, strong) UIImageView *titleImageView;
@property (nonatomic, strong) UIImageView *backgroundImageView;
@property (nonatomic, strong) UILabel *textLabel;
@property (nonatomic, strong) UILabel *titleLabel;

@property (nonatomic, readonly) UIEdgeInsets containerInsets;

@end

NS_ASSUME_NONNULL_END
