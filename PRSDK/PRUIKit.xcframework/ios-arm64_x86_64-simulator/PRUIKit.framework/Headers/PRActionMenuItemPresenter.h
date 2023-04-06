//
//  PRActionMenuItemPresenter.h
//  PRUIKit
//
//  Created by Viacheslav Soroka on 12/10/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PRMenu, PRMenuItem;

NS_ASSUME_NONNULL_BEGIN

@protocol PRActionMenuItemPresenter <NSObject>

- (void)presentVC:(UIViewController *)vc fromMenuItem:(PRMenuItem *)item;

@end

NS_ASSUME_NONNULL_END
