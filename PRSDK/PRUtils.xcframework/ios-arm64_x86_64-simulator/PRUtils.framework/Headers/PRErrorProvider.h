//
//  PRErrorProvider.h
//  PRUtils
//
//  Created by Viacheslav Soroka on 12/11/20.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PRErrorProvider <NSObject>

+ (NSError *)errorWithCode:(NSInteger)code description:(nullable NSString *)description;
- (NSError *)errorWithCode:(NSInteger)code description:(nullable NSString *)description;

@end

NS_ASSUME_NONNULL_END
