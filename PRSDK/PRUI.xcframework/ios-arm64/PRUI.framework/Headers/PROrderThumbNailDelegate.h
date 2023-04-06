//
//  PROrderThumbNailDelegate.h
//  PRiphone
//
//  Created by Jacob Chappelle on 2017-03-10.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#ifndef PROrderThumbNailDelegate_h
#define PROrderThumbNailDelegate_h

#import <Foundation/Foundation.h>

@protocol PROrderThumbNailDelegate <NSObject>
@required
- (BOOL)hasOrderAdBanner;
@end

#endif /* PROrderThumbNailDelegate_h */
