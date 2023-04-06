//
//  PRSmartArticle+PreferredImage.h
//  PRSmart
//
//  Created by berec on 11/12/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "PRSmartArticle.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRSmartArticle (PreferredImage)

/// @return -1 if preferred image is not found
+ (int)preferredImageIndex:(NSArray<PRSmartImageRegion *> *)imageRegions
             rejectReasons:(NSArray<NSString *> *_Nullable *_Nullable)reasons;

@end

NS_ASSUME_NONNULL_END
