//
//  NSArray+SearchByTag.h
//  PressReader
//
//  Created by Oleg Stepanenko on 01.11.11.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray<ObjectType> (Search)

- (BOOL)containsObjectKindOf:(Class)class;

- (ObjectType)objectByTag:(NSInteger)tag;
- (ObjectType)objectWithTag:(NSUInteger)tag index:(NSUInteger *)index;
- (NSUInteger)indexOfObjectWithTag:(NSInteger)tag;

/// Returns first item that satisfies predicate
- (ObjectType)objectWithPredicate:(BOOL(^)(ObjectType item))predicate;

@end

@interface NSArray (StringSearch)

- (BOOL)containsString:(NSString *)string options:(NSStringCompareOptions)mask;

/// Performs containsString:options: with options = 0
- (BOOL)containsString:(NSString *)string;

/// Performs containsString:options: with options = NSCaseInsensitiveSearch
- (BOOL)containsStringCI:(NSString *)string;

@end
