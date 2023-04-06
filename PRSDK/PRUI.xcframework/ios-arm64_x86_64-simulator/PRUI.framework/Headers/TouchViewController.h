//
//  TouchViewController.h
//  PRiphone
//
//  Created by devuser on 02/03/09.
//  Copyright 2009 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

#define kDisableSingleTap	1
#define kDisableDoubleTap	2

#define kDisableAllTaps		3

@protocol TouchViewControllerDelegate <NSObject>

@optional
- (void) singleTap:(CGPoint)location inView:(UIView*)view userData:(id)data;
- (void) doubleTap:(CGPoint)location inView:(UIView*)view userData:(id)data;

@end

@interface TouchViewController : UIViewController

@property (nonatomic, weak) id<TouchViewControllerDelegate> touchDelegate;
@property (nonatomic, readonly) CGPoint tapLocation;
@property (nonatomic, assign) NSUInteger disableTapMask;
@property (nonatomic, assign) NSTimeInterval doubleTapThreshold;
@property (nonatomic, retain) id userData;

// helper methods
-(void) disableAll;
-(void) enableAll;
-(void) disableSingleTap;
-(void) enableSingleTap;
-(void) disableDoubleTap;
-(void) enableDoubleTap;

@end
