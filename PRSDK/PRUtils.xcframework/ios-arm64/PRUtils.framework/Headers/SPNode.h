/*
 Created by Alexander Povkh.
 Copyright 2008 NetMove. All rights reserved.
 
 */

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SPNode : NSObject

- (instancetype)initWithName:(NSString *)nodeName;

- (nullable SPNode *)childAtIndex:(int)index;

				///// nodes
- (nullable SPNode *)nodeAtIndex:(NSUInteger)index;
- (nullable SPNode*)firstChildWithName:(NSString *)nodeName;
- (void)appendChild:(SPNode *)childSource;
- (void)appendChild:(SPNode *)childSource atIndex:(NSUInteger)index;
- (BOOL)hasChildNodes;
- (NSUInteger)length;

				///// attributes
- (void)addAttributes:(NSDictionary *)dict;
- (void)appendAttribute:(NSString *)attributeName value:(id)attributeValue;
- (nullable NSString *)attribute:(NSString *)attributeName;
- (nullable NSString *)attribute:(NSString *)attributeName atIndex:(NSUInteger)index;
- (NSDictionary *)allAttributes;
- (BOOL)hasAttributes;

				///// name
- (nullable NSString *)nodeNameAtIndex:(NSUInteger)index;

				///// value
- (NSString *)stringValue;

- (void)addValueChars:(NSString *)chars;


				///// parent
/*-(void)			setParent:(id)nodeParent;
-(id)			getParent;*/

- (void)appendToData:(NSMutableData *)buf;
- (void)appendToString:(NSMutableString *)sBuf indent:(NSUInteger)indent;

@property (nonatomic, readonly, strong) NSArray *childs;
@property (nonatomic, readonly, strong) NSDictionary *attributes;
@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, copy, readonly) NSString *value;
@property (nonatomic, weak) SPNode *parent;

@end

NS_ASSUME_NONNULL_END
