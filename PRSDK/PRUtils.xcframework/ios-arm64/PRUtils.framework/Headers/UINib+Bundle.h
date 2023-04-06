//
//  UINib+Bundle.h
//  PressReader
//
//  Created by Oleg Stepanenko on 01/20/17.
//  Copyright (c) 2017 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UINib (Bundle)

+ (nullable UINib *)bundledNibWithName:(NSString *)name;

@end

NS_ASSUME_NONNULL_END
