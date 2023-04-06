//
//  PRAppUIReadyDelegate.h
//  PRAPI
//
//  Created by Vitali Bounine on 2020-10-02.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

@class PRPromise;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(AppUIReady)
@protocol PRAppUIReadyDelegate <NSObject>
- (PRPromise *)getAppUIReady;
@end

NS_ASSUME_NONNULL_END
