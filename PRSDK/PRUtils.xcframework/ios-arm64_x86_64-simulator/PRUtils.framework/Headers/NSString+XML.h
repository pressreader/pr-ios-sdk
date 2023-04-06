//
//  NSString+XML.h
//  ExternalSources
//
//  Created by Jackie Cane on 5/29/13.
//  Copyright (c) 2013 ND. All rights reserved.
//

#define XMLEncode xmlEncodedString

#import <Foundation/Foundation.h>

@interface NSString (PRXML)

- (nonnull NSString *)xmlEncodedString;

@end
