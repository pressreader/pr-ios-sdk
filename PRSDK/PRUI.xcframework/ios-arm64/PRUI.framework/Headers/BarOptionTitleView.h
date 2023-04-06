//
//  BarOptionTitleView.h
//  PRiphone
//
//  Created by Jackie Cane on 10/29/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(uint8_t, PRBarOptionTitleArrowColor) {
    PRBarOptionTitleArrowColorDefault,
    PRBarOptionTitleArrowColorGray,
    PRBarOptionTitleArrowColorWhite
};

@protocol BarOptionTitleViewDelegate <NSObject>

@optional
- (void)barOptionTitleViewTouchUpInside;

@end

@interface BarOptionTitleView : UIView

+ (instancetype)barOptionTitleViewWithText:(NSString *)titleText
                                detailText:(NSString *)detailText
                                  delegate:(id<BarOptionTitleViewDelegate>)delegate;

+ (instancetype)barOptionTitleViewWithText:(NSString *)titleText
                                detailText:(NSString *)detailText
                                  delegate:(id<BarOptionTitleViewDelegate>)delegate
                                  barLight:(BOOL)barLight
                                arrowColor:(PRBarOptionTitleArrowColor)arrowColor;

+ (instancetype)barOptionTitleViewWithImage:(UIImage *)image
                                   delegate:(id<BarOptionTitleViewDelegate>)delegate
                                   barLight:(BOOL)barLight
                                 arrowColor:(PRBarOptionTitleArrowColor)arrowColor;

+ (instancetype)barOptionTitleViewWithImage:(UIImage *)image
                                       text:(NSString *)titleText
                                 detailText:(NSString *)detailText
                                   delegate:(id<BarOptionTitleViewDelegate>)delegate
                                   barLight:(BOOL)barLight
                                 arrowColor:(PRBarOptionTitleArrowColor)arrowColor;

@property (nonatomic, strong) UIImageView *imageView;
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UILabel *detailLabel;
@property (nonatomic, strong) UIImageView *arrowIndicator;
@property (nonatomic, weak) id<BarOptionTitleViewDelegate> delegate;

@property (nonatomic, readonly) NSString *title;
@property (nonatomic, readonly) NSString *detail;

@end
