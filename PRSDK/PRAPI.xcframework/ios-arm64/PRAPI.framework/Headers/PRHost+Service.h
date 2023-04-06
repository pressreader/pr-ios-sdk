//
//  PRHost+Service.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 08.01.14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//
#import "PRHost.h"

@interface PRHost (Service)
- (void)requestWebTemplateInt:(NSString *)name locale:(NSString *)locale;
- (void)requestBaseServicesInfoWithCompletionBlock:(void(^)(BOOL success, NSError *error))completionBlock;
- (void)requestLocalServiceInfo:(void(^)(BOOL success, NSDictionary *serverInfo, NSError *error))completionBlock;
@end
