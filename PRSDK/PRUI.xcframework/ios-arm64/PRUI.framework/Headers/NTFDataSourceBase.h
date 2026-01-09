//
//  NTFDataSourceBase.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 9/12/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PRAccountItem;

NS_ASSUME_NONNULL_BEGIN

@protocol NTFDataSourceBase <NSObject>

- (nullable NSString *)idForItem:(id)item;
- (NSDictionary *)contextForItemAtIndex:(NSInteger)idx;
- (void)suspendReadingFrameWithAction:(NSString *)actionType forItem:(id)item;

@property (nullable, nonatomic, readonly) PRAccountItem *defaultAccount;

@end

NS_ASSUME_NONNULL_END
