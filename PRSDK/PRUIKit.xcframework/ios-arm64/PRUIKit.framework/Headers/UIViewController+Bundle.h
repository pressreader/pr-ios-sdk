//
//  UIViewController+Bundle.h
//  PRiphone
//
//  Created by Vitali Bounine on 9/23/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

// This category provides easy access to bundled nibs.
@interface UIViewController (PRNSBundle)

- (instancetype)initWithBundledNibName:(NSString *)nibNameOrNil;

@end
