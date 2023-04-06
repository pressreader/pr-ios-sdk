//
//  NSKeyedArchiver+Convenience.h
//  PRUtils
//
//  Created by Viacheslav Soroka on 8/20/20.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSKeyedArchiver (Convenience)

+ (NSData *)archivedDataWithObject:(id)object;

@end

NS_ASSUME_NONNULL_END
