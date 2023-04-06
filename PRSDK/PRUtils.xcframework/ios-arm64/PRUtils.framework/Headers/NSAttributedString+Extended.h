//
//  NSAttributedString+Extended.h
//  PR-API
//
//  Created by Viacheslav Soroka on 6/1/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface NSAttributedString (Extended)

- (CGRect)boundingRectWithSize:(CGSize)size;

@end

NS_ASSUME_NONNULL_END
