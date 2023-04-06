//
//  NSString+Search.h
//  PRUtils
//
//  Created by Artem Serbin on 18.05.2021.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, PRStringSearchOption) {
    PRStringSearchOptionSoftHyphenInsensitive = 1 << 0
};

@interface NSString (Search)

- (nullable NSArray<NSValue *> *)rangesOfString:(NSString *)string options:(PRStringSearchOption)options;

@end

NS_ASSUME_NONNULL_END
