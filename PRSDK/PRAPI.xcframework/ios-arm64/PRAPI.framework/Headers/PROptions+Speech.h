//
//  PROptions+Speech.h
//  PRAPI
//
//  Created by berec on 09/12/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "PROptions.h"

NS_ASSUME_NONNULL_BEGIN

@interface PROptions (Speech)

+ (float)minSpeechRate;
+ (float)maxSpeechRate;
+ (float)defaultSpeechRate;

@end

NS_ASSUME_NONNULL_END
