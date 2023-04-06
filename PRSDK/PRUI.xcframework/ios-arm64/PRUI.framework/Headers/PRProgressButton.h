//
//  PRProgressButton.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 12/21/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

@import UIKit;
@import PRAPI.PRTitleItemExemplar;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, PRProgressButtonSize) {
    PRProgressButtonSmall = 0,
    PRProgressButtonMedium
};

@interface PRProgressButton : UIButton
@property (nonatomic, assign) NSInteger downloadProgress;
@property (nonatomic, assign) PRTitleItemExemplarState exemplarState;
@property (nullable, nonatomic, strong) UIColor *preferredTintColor;

+ (instancetype)button;
+ (instancetype)buttonWithSize:(PRProgressButtonSize)size;

@end

NS_ASSUME_NONNULL_END
