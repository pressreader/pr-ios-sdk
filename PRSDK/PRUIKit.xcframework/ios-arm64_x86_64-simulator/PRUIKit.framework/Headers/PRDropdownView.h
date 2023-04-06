//
//  PRDropdownView.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 29.10.13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, PRDropdownDirection) {
    PRDropdownDirectionNone,
    PRDropdownDirectionUp,
    PRDropdownDirectionDown,
    PRDropdownDirectionCenter,
};

@class PRDropdownView;

NS_ASSUME_NONNULL_BEGIN

@protocol PRDropdownViewDelegate <NSObject>

@optional
- (void)dropdownOpened:(PRDropdownView *)dropdownView;
- (void)dropdownClosed:(PRDropdownView *)dropdownView;
- (BOOL)shouldDismissDropdown:(PRDropdownView *)dropdownView;

@end


@interface PRDropdownView : UIView

- (void)openDropdown:(PRDropdownDirection)direction;
- (void)openDropdown:(PRDropdownDirection)direction animated:(BOOL)animated;
- (void)closeDropdownAnimated:(BOOL)animated;
- (void)dismiss;

@property (nullable, nonatomic, strong) UIView *contentView;
@property (nullable, nonatomic, weak) UIView *backgroundView;
@property (nonatomic) CGRect anchorFrame;
@property (nonatomic, readonly) PRDropdownDirection droppedTo;
@property (nonatomic) BOOL isAutodismiss; //default YES
@property (nullable, nonatomic, weak) id<PRDropdownViewDelegate> delegate;
@property (nullable, nonatomic, copy) NSArray *passthroughViews;

@end

NS_ASSUME_NONNULL_END
