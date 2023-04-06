//
//  PRMacros.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 1/8/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#ifndef PRMacros_h
#define PRMacros_h

#import <PRSyntacticSugar/PRPropertyMacros.h>
#import <PRSyntacticSugar/SyntacticSugarMacros.h>
#import <PRSyntacticSugar/PerformSelectorMacros.h>

#define __GET_MACRO2(_1, _2, name, ...) name
#define __GET_MACRO3(_1, _2, _3, name, ...) name
#define __GET_MACRO4(_1, _2, _3, _4, name, ...) name
#define __GET_MACRO5(_1, _2, _3, _4, _5, name, ...) name
#define __GET_MACRO6(_1, _2, _3, _4, _5, _6, name, ...) name

#define IS_BETA() [[[NSBundle mainBundle] objectForInfoDictionaryKey:(__bridge NSString *)kCFBundleIdentifierKey] isEqualToString:@"com.NewspaperDirect.PressReader"]

#endif /* PRMacros_h */
