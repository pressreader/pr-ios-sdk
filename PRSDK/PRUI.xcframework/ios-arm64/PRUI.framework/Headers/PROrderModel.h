//
//  PROrderModel.h
//  PR-UI
//
//  Created by berec on 27/03/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PROrder;

NS_ASSUME_NONNULL_BEGIN

@interface PROrderModel : NSObject

- (instancetype)initWithOrder:(PROrder *)order;

@property (nonatomic, strong, readonly) PROrder *order;

@end

NS_ASSUME_NONNULL_END
