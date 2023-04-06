//
//  NSString+Validation.h
//  PRiphone
//
//  Created by connection on 2/2/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Validation)
@property (nonatomic, readonly) BOOL isValidAsEmail;
@property (nonatomic, readonly) BOOL isValidAsPassword;
@property (nonatomic, readonly) BOOL isValidAsURL;

@end
