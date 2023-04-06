//
//  PRLinkedServicesProvider.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 3/15/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PRLinkedServiceInfo;
@class PRAccountItem;
@class PRSignInOption;

@interface PRLinkedServicesProvider : NSObject

- (NSArray<PRLinkedServiceInfo *> *)linkedServicesInfoForAccount:(PRAccountItem *)ai;
- (NSArray<PRSignInOption *> *)managedServicesToDisplay;

@end
