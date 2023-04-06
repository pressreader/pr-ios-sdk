//
//  PRTitleItem+NightEdition.h
//  PRAPI
//
//  Created by KeithC on 2020-11-21.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <PRAPI/PRAPI.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRTitleItem (NightEdition)

@property (nullable, nonatomic, readonly) NSString *nightEditionCID;
@property (nonatomic, readonly) PRTitleItem *latestTitleNightTitleItem;

@end

NS_ASSUME_NONNULL_END
