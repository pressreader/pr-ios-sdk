//
//  UIImage+Initialization.h
//  PR-API
//
//  Created by Viacheslav Soroka on 8/17/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (Initialization)

+ (instancetype)scaledImageWithData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
