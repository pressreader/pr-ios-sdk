//
//  PRConfig+AppMode.h
//  PRUtils
//
//  Created by berec on 02/02/2021.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

#import <PRConfiguration/PRConfig.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PRAppMode) {
    PRAppModeRegular = 0,
    PRAppModeFramework
};

@interface PRConfig (AppMode)
@property (class, nonatomic, readonly) PRAppMode appMode;

@end

NS_ASSUME_NONNULL_END
