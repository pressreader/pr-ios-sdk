//
//  UIDevice+Extended.h
//  PRiphone
//
//  Created by Jackie Cane on 10/24/11.
//  Copyright (c) 2011 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIDevice (Extended)
@property (class, nonatomic, readonly) BOOL isConnected;
@property (class, nonatomic, readonly) BOOL isWiFiAvailable;
@property (class, nonatomic, readonly) BOOL isUserIntefaceIdiomPad;

@property (nonatomic, readonly) NSString *appSpecificUniqueIdentifier;

@end
