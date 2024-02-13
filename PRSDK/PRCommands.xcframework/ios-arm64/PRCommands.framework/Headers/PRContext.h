//
//  PRContext.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 18.12.13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PRCommand;

NS_ASSUME_NONNULL_BEGIN

@interface PRContext : NSObject

- (id)initWithKey:(id)key;
- (void)addCommand:(PRCommand *)command;
- (void)removeCommand:(NSString *)commandName;
- (PRCommand *)command:(NSString *)commandName;

- (void)setParameter:(id)parameter forKey:(NSString *)key;
- (void)addParameters:(NSDictionary *)parameters;
- (nullable id)objectForKeyedSubscript:(id)key;
- (void)setObject:(nullable id)obj forKeyedSubscript:(id)key;


@property (nonatomic, readonly) id key;
@property (nullable, nonatomic, strong, readonly) NSDictionary *parameters;

@end

NS_ASSUME_NONNULL_END
