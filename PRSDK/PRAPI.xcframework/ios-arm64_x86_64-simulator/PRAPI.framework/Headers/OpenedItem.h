//
//  OpenedItem.h
//  PRAPI
//
//  Created by Artem Serbin on 02.11.2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@protocol OpenedItem <NSObject>

@property (nonatomic, readonly) BOOL isNew;
- (void)markAsOpened;

@end

NS_ASSUME_NONNULL_END
