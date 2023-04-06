//
//  PRPickable.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 8/15/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PRPickable <NSObject>
@property (nonatomic, getter=isPicked) BOOL picked;

@end

NS_ASSUME_NONNULL_END
