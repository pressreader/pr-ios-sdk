//
//  PlistUtil.h
//  PRiphone
//
//  Created by Jackie Cane on 10/21/11.
//  Copyright (c) 2011 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PlistUtil : NSObject

+ (NSString *)documentsDirectoryPath;
+ (id)readPlistWithName:(NSString *)fileName; 
+ (BOOL)writePlist:(id)plist toFileWithName:(NSString *)fileName ;

@end
