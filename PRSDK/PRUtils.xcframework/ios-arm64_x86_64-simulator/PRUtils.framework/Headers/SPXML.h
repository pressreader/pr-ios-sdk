/*
 Created by Alexander Povkh.
 Copyright 2008 NetMove. All rights reserved.

 */

#import <UIKit/UIKit.h>
@class SPNode;

@interface SPXML : NSObject

///////////////////////////////////////////////////////////////////////////

@property (nonatomic, strong) SPNode			*root;
//@property (nonatomic, assign) SPNode				*currentNode;

///////////////////////////////////////////////////////////////////////////

+(instancetype) xmlWithNode:(SPNode *)node;

-(instancetype) initWithXMLParser:(NSXMLParser *)parser;

-(instancetype) initWithURLString:(NSString *)URLString;

-(instancetype) initWithData:(NSData*)data;

-(instancetype) initWithNode:(SPNode *)node;

-(SPNode*) FirstNode;

-(NSData *) save;

-(NSString *) description;

@end
