//
//  TupleArray.h
//  PR-API
//
//  Created by berec on 21/03/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRTupleArray : NSObject {
@public
    id objs[3];
    NSUInteger count;
}

@end

#define PR_TUPLE(UpToThreeArgs...) __PR_TUPLE(UpToThreeArgs, 3, 2, 1)
#define __PR_TUPLE(_1, _2, _3, N, ...) __TupleArrayWithCount(N, _1, _2, _3)
id __TupleArrayWithCount(NSUInteger, ...);

NS_ASSUME_NONNULL_END
