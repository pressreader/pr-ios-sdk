//
//  PROptions+Downloaded.h
//  PRiphone
//
//  Created by Jackie Cane on 12/11/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import "PROptions.h"

extern NSString *const kDownloadedOrderByOrderTimeTitle;
extern NSString *const kDownloadedOrderByIssueDateTitle;
extern NSString *const kDownloadedOrderByAlphabetTitle;

@interface PROptions (Downloaded)

@property (nonatomic, assign) NSString *downloadedOrderByValue;
@property (nonatomic, assign) NSString *downloadedSelectedYear;
@property (nonatomic, readonly) NSString *downloadedAutoRemovalOptionDetails;

@end
