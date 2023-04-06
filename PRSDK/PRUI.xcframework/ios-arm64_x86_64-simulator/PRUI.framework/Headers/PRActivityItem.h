//
//  PRActivityItem.h
//  PRiphone
//
//  Created by Keith Choi on 2016-10-28.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface PRActivityItem : NSObject <UIActivityItemSource>

- (instancetype)initWithItem:(id)item;

- (nullable id)itemForActivityType:(UIActivityType)activityType;

@property (strong, nonatomic) id item;

@end

NS_ASSUME_NONNULL_END

