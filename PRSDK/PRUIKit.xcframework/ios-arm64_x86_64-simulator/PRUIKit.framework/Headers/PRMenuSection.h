//
//  PRMenuSection.h
//  PR-API
//
//  Created by Viacheslav Soroka on 10/31/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PRMenuItem;
@class PRMenuSection;

@protocol PRMenuSectionDelegate <NSObject>

- (void)section:(PRMenuSection *)section didChangeItem:(PRMenuItem *)item;

@end

@interface PRMenuSection : NSObject
@property (nonatomic, readonly) NSInteger sectionId;
@property (nonatomic, readonly) NSString *title;
@property (nonatomic, readonly) NSArray<PRMenuItem *> *items;

@property (nonatomic, weak) id<PRMenuSectionDelegate> delegate;

+ (instancetype)sectionWithTitle:(nullable NSString *)title items:(NSArray<PRMenuItem *> *)items;
- (instancetype)initWithTitle:(nullable NSString *)title items:(NSArray<PRMenuItem *> *)items;

- (BOOL)hasEnabledItems;
- (nullable PRMenuItem *)deleteItemAtIndex:(NSInteger)index;

@end

NS_ASSUME_NONNULL_END
