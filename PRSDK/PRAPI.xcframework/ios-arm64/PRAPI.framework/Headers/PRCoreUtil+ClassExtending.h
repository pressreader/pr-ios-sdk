//
//  PRCoreUtil+ClassExtending.h
//  PRiphone
//
//  Created by Jackie Cane on 20/11/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import "PRCoreUtil.h"

#define NOTIFY_PRCLASSEXT [[[PRModel instance] util] notifyPRClassExtentions:NSStringFromSelector(_cmd) instance:self notif:nil];
#define NOTIFY_PRCLASSEXTNOTIF( notification ) [[[PRModel instance] util] notifyPRClassExtentions:NSStringFromSelector(_cmd) instance:self notif:notification];

@interface PRCoreUtil (ClassExtending)
- (void)notifyPRClassExtentions:(NSString*)name instance:(NSObject*)instance notif:(NSNotification*)notif;
- (void)injectPRClassExtention:(Class)cls name:(NSString*)name sel:(SEL)sel;
- (void)injectPRClassExtention:(Class)cls name:(NSString*)name impl:(IMP)impl;
@end
