//
//  SliderControlProto.h
//  PRiphone
//
//  Created by Dmitry Melnik on 10-11-01.
//  Copyright 2010 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>


@protocol SliderControlProto <NSObject>

- (BOOL) PageChange:(int)page;
- (void) SetScrollOffset:(CGFloat)x;
- (CGFloat) GetScrollOffset;
- (void) CancelCurrentDecelerationIfAny;

@optional
- (void) ActivateAnimated:(BOOL)animated;
- (void) DeactivateAnimated:(BOOL)animated;
- (BOOL) isActive;

@end
