//
//  PROpenableItem.h
//  PRAPI
//
//  Created by Artem Serbin on 02.11.2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@protocol PROpenableItem <NSObject>

- (void)markAsOpened;

@property (nonatomic, readonly) BOOL isNew;

@end

NS_ASSUME_NONNULL_END
