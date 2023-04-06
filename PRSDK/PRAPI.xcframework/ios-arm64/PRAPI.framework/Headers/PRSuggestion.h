//
//  PRSuggestion.h
//  PRiphone
//
//  Created by berec on 7/20/16.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    PRSuggestionTypeNone = 0,
    PRSuggestionTypeChannels,
} PRSuggestionType;

@interface PRSuggestion : NSObject

+ (instancetype)suggestionWithType:(PRSuggestionType)type title:(NSString *)title items:(NSArray *)items;

@property (nonatomic) PRSuggestionType type;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSArray *items;

@end
