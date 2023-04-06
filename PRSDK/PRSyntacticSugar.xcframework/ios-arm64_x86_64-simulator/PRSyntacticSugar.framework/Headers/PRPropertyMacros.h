//
//  PRPropertyMacros.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 7/5/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#ifndef PRPropertyMacros_h
#define PRPropertyMacros_h

// Returns @"property" string if target.poperty exists. Gives compile time error otherwise.
#ifdef DEBUG
#define PRQuoteProperty(target, property) (0 ? (__bridge id)(void *)sizeof(target.property) : @#property)
#else
#define PRQuoteProperty(target, property) @#property
#endif

// Returns @"property" string if self.poperty exists. Gives compile time error otherwise.
#define PRQuoteSelfProperty(property) PRQuoteProperty(self, property)

#define PRQuoteSelector(sel) NSStringFromSelector(@selector(sel))

#ifdef DEBUG
#define PRQuoteClass(cls) (0 ? (id)[cls class] : @#cls)
#else
#define PRQuoteClass(cls) @#cls
#endif

#endif /* PRPropertyMacros_h */
