//
//  NSArray+SortedInsert.h
//
#import <Foundation/Foundation.h>

@interface NSArray (SortedInsert)

-(NSUInteger)indexForInsertingObject:(id)anObject sortedUsingFunction:(NSInteger (*)(id, id, void *))compare context:(void*)context;
-(NSUInteger)indexForInsertingObject:(id)anObject sortedUsingSelector:(SEL)aSelector;
-(NSUInteger)indexForInsertingObject:(id)anObject sortedUsingDescriptors:(NSArray*)descriptors;

- (NSUInteger)indexOfObject:(id)anObject sortedUsingFunction:(NSInteger (*)(id, id, void *))compare context:(void*)context;
- (NSUInteger)indexOfObject:(id)anObject sortedUsingSelector:(SEL)aSelector;
- (NSUInteger)indexOfObject:(id)anObject sortedUsingDescriptors:(NSArray*)descriptors;

- (BOOL)containsObject:(id)anObject sortedUsingFunction:(NSInteger (*)(id, id, void *))compare context:(void*)context;
- (BOOL)containsObject:(id)anObject sortedUsingSelector:(SEL)aSelector; 
- (BOOL)containsObject:(id)anObject sortedUsingDescriptors:(NSArray*)descriptors;

@end


@interface NSMutableArray (SortedInsert)

-(void)insertObject:(id)anObject sortedUsingFunction:(NSInteger (*)(id, id, void *))compare context:(void*)context;
-(void)insertObject:(id)anObject sortedUsingSelector:(SEL)aSelector;
-(void)insertObject:(id)anObject sortedUsingDescriptors:(NSArray*)descriptors;

@end

