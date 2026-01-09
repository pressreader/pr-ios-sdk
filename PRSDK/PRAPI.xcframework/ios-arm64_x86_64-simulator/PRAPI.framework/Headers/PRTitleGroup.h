//
//  PRTitleGroup.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 25.06.15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PRAPI/PRCatalogItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRTitleGroup : NSObject

+ (instancetype)titleGroupWithName:(NSString *)name 
                             items:(NSArray<id<PRCatalogItem>> *)list
                             title:(nullable NSString *)title;

@property (nullable, nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSArray<id<PRCatalogItem>> *list;

@end

NS_ASSUME_NONNULL_END
