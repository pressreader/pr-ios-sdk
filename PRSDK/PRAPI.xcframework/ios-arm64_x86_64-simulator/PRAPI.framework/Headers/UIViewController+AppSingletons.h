//
//  UIViewController+Model.h
//  PRiphone
//
//  Created by Jackie Cane on 08/05/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PRModel;

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (AppSingletons)
@property (class, nonatomic, readonly) PRModel *appModel;
@property (nonatomic, readonly) PRModel *appModel;

@end

NS_ASSUME_NONNULL_END
