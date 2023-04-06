//
//  NSObject+APINotifications.h
//  PRAPI
//
//  Created by Viacheslav Soroka on 2021-07-02.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (PRAPINotifications)

- (void)postAccountRequestError:(nullable NSError *)error;

@end

NS_ASSUME_NONNULL_END
