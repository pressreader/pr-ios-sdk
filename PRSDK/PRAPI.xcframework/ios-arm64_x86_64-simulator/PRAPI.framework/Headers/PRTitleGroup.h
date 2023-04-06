//
//  PRTitleGroup.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 25.06.15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import "PRTitleObject.h"

#import "PRTitleItemExemplar.h"

@interface PRTitleGroup : NSObject <PRTitleObject>
+ (instancetype)titleGroupWithName:(NSString *)name items:(NSArray *)list title:(NSString *)title;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSArray *list;
@property (nonatomic, weak, readonly) PRTitleItemExemplar *exemplar;

@end
