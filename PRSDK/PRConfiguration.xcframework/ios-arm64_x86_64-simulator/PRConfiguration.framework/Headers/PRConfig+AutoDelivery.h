//
//  PRConfig+AutoDelivery.h
//  PR-API
//
//  Created by berec on 14/05/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <PRConfiguration/PRConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRAutoDeliveryConfig : NSObject

- (void)useSuggestionAttempt;

@property (nonatomic, readonly) NSInteger suggestionAttempts;
@property (nonatomic, readonly) NSTimeInterval suggestionInterval;

@property (nonatomic, readonly) NSDate *lastSuggestionDate;

@end


@interface PRConfig (AutoDelivery)
@property (class, nonatomic, readonly) PRAutoDeliveryConfig *autoDeliveryConfig;
@end

NS_ASSUME_NONNULL_END
