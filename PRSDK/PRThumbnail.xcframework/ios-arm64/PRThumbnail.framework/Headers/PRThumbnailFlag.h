//
//  PRThumbnailFlag.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 12.02.13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import "PRThumbnailObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRThumbnailFlag : PRThumbnailObject

+ (NSString *)buildKeyWithISO:(NSString *)ISO;

@property (nonatomic, strong, readonly) NSString *ISO;

@end

NS_ASSUME_NONNULL_END
