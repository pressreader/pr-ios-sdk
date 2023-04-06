//
//  PRLinkedServiceInfo.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 3/15/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PRLinkedServiceInfo : NSObject
@property (nonatomic, readonly) NSString *serviceName;
@property (nonatomic, readonly) NSString *accountName;
@property (nonatomic, readonly) NSString *associatedSubscriptionBehaviourProfileName;

@property (nonatomic, readonly) BOOL linked;

+ (instancetype)infoWithServiceName:(NSString *)serviceName
                        accountName:(NSString *)accountName
            associatedBehaviourName:(NSString *)associatedName
                             linked:(BOOL)linked;

- (instancetype)initWithServiceName:(NSString *)serviceName
                        accountName:(NSString *)accountName
            associatedBehaviourName:(NSString *)associatedName
                             linked:(BOOL)linked;

@end
