//
//  PRExceptionUtil.h
//  PRUtils
//
//  Created by berec on 16/11/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRExceptionUtil : NSObject

+ (void) ThrowError:(NSString*)what file:(const char*)file line:(int)line code:(int)code;
+ (void) ThrowErrorWithName:(NSString*)name what:(NSString*)what file:(const char*)file line:(int)line code:(int)code;

@end

NS_ASSUME_NONNULL_END

#define EXC_S( what ) [PRExceptionUtil ThrowError:(what) file:__FILE__ line:__LINE__ code:-1]
#define EXC_C( errorcode, what ) [PRExceptionUtil ThrowError:(what) file:__FILE__ line:__LINE__ code:errorcode]
#define EXC_NS( errname, message ) [PRExceptionUtil ThrowErrorWithName:errname what:(message) file:__FILE__ line:__LINE__ code:-1]
#define EXC_NC( errname, errorcode, message ) [PRExceptionUtil ThrowErrorWithName:errname what:(message) file:__FILE__ line:__LINE__ code:errorcode]
