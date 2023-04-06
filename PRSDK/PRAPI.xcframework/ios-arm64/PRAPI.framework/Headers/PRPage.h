//
//  PRPage.h
//  PRiphone
//
//  Created by Jackie Cane on 10/18/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SPNode, PRExpunge;

@interface PRPage : NSObject

@property (nonatomic, readonly) int pageNumber;
@property (nonatomic, readonly, copy) NSString * pageName;
@property (nonatomic, copy) NSString * section;
@property (nonatomic, readonly) int w;
@property (nonatomic, readonly) int h;
@property (nonatomic, readonly) int scale;
@property (nonatomic, readonly, strong) NSArray *zoomScales;
@property (nonatomic, strong) NSArray<PRExpunge *> * expunges;
@property (nonatomic, copy) NSString *bookmarkId;
@property (nonatomic, copy) NSString *bookmarkUrl;

+ (instancetype)pageWithSPNode:(SPNode *)xmlNode;
- (instancetype)initWithSPNode:(SPNode *)xmlNode;
- (instancetype)initWithNumber:(int)pageNumber width:(int)width height:(int)height;
- (NSString *)xmlString;

@end
