//
//  PRAccountItem+Image.h
//  PR-API
//
//  Created by Viacheslav Soroka on 12/17/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "PRAccountItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRAccountItem (Image)

- (void)getPlaceholderImageWithSize:(CGSize)size
                         completion:(void(^)(UIImage *))completion;

@end

NS_ASSUME_NONNULL_END
