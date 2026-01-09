//
//  PRSpotlightSearch.h
//  PRAPI
//
//  Created by Ivan Berezin on 15/04/2025.
//  Copyright © 2025 NewspaperDirect. All rights reserved.
//

@import CoreSpotlight;

NS_ASSUME_NONNULL_BEGIN

@interface PRSpotlightSearch : NSObject
- (void)process:(NSArray<CSSearchableItem *> *)items;

@end

NS_ASSUME_NONNULL_END
