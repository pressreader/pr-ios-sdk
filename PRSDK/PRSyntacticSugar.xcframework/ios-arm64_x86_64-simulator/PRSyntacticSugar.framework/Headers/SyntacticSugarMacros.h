//
//  SyntacticSugarMacros.h
//  PRiphone
//
//  Created by berec on 12/04/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#ifndef SyntacticSugarMacros_h
#define SyntacticSugarMacros_h

#define __let __auto_type const
#define __var __auto_type
#define __weakvar __weak __auto_type
#define __blockvar __block __auto_type

#define performBlock(block, ...) if (block) { block(__VA_ARGS__); }

#define REUSE_ID(Class) [NSStringFromClass(Class) componentsSeparatedByString:@"."].lastObject //Return class name without module prefix
#define REUSE_ID_T(type) REUSE_ID([type class])

#define PR_NON_SWIFT NS_SWIFT_UNAVAILABLE("Use native Swift functions instead");
#define PROptionSetOption(option, set, options) \
    (set ? (options | option) : (options &~ option))

#endif /* SyntacticSugarMacros_h */
