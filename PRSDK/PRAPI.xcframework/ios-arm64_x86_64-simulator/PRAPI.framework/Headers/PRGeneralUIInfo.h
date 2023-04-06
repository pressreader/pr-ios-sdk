//
//  PRGeneralUIInfo.h
//  PRiphone
//
//  Created by Jackie Cane on 18/12/15.
//  Copyright © 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

BOOL PRIsAppWindowHorizontalSizeRegular(void);
BOOL PRAreBothAppWindowSizesRegular(void);
BOOL PRAppWindowOrientationIsLandscape(void);
CGSize PRAppWindowSize(void);

@interface PRGeneralUIInfo : NSObject

@end
