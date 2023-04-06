//
//  PRSuggestionsManager.h
//  PRiphone
//
//  Created by berec on 7/20/16.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PRSuggestion.h"

@interface PRSuggestionsManager : NSObject

- (void)suggestionsForStrings:(NSArray *__nonnull)strings limit:(NSUInteger)limit completionBlock:(void (^__nonnull)(NSDictionary<NSNumber *, PRSuggestion *> *__nonnull suggestions))completionBlock;

@end
