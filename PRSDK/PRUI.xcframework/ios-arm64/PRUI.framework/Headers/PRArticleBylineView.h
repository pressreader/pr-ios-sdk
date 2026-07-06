//
//  PRArticleBylineView.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 12/27/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <PRUIKit/PRUIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRArticleBylineView : UIView <PRDynamicFontSupportable>

+ (instancetype)view;

@property (nullable, nonatomic, strong) NSString *title;
@property (nullable, nonatomic, strong) NSAttributedString *byline;
@property (nullable, nonatomic, strong) UIImage *masthead;

@end

NS_ASSUME_NONNULL_END
