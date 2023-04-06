//
//  PRHotSpotServicesBannerVC.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 09.02.16.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PRMessageBar.h"

@interface PRHotSpotServicesBannerVC : UIViewController
@property (nonatomic, weak) id<PRMessageBarDelegate> delegate;
@property (nonatomic, readonly) PRMessageBar *messageBar;

@end
