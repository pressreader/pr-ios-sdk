//
//  NSString+BoundingRect.h
//  PRDataUtils
//
//  Created by berec on 11/10/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (BoundingRect)

- (CGRect)boundingRectWithSize:(CGSize)size
                    attributes:(NSDictionary<NSAttributedStringKey,id> *)attributes;
- (CGRect)boundingRectWithSize:(CGSize)size font:(UIFont *)font;

@end

NS_ASSUME_NONNULL_END
