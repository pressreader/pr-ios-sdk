//
//  PRAskReviewUtil.h
//  PR-API
//
//  Created by berec on 02/07/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRAskReviewUtil : NSObject

+ (BOOL)shouldAskForReview;
+ (void)askForReview;

@end

NS_ASSUME_NONNULL_END
