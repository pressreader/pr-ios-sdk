//
//  PRMyLibrary+Notification.h
//  PRiphone
//
//  Created by Jackie Cane on 1/18/13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import "PRMyLibrary.h"

extern NSNotificationName const PRMyLibraryUpdatedNotification;
extern NSNotificationName const PRMyLibraryItemAvailableNotification;
extern NSNotificationName const PRMyLibraryItemMessageProcessedNotification;
extern NSNotificationName const PRMyLibraryItemImgPackDoneNotification;
extern NSNotificationName const PRMyLibraryGetMessagesProcessedNotification;
extern NSNotificationName const PRMyLibraryPurchaseAdviseUpdatedNotification;
extern NSNotificationName const PRMyLibraryDidReceiveMessages;
extern NSNotificationName const PRMyLibraryItemLicenseUpdatedNotification;

@interface PRMyLibrary (Notification)

- (void)presentLibraryNotification:(NSString *)body mid:(NSString *)MID type:(NSString *)type;

@end
