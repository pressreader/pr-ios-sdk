//
//  PRCustomCellMenuItem.h
//  PR-API
//
//  Created by berec on 25/11/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "PRMenuItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRCustomCellMenuItem : PRMenuItem

+ (instancetype)itemWithCustomCellClass:(Class)customCellClass
                            configBlock:(void(^)(__kindof UITableViewCell *))configBlock;
+ (instancetype)itemWithCustomCellId:(NSString *)cellId
                                 nib:(UINib *)nib
                         configBlock:(void(^)(__kindof UITableViewCell *))configBlock;

@property (nonatomic, copy) NSString *customCellId;
@property (nonatomic, strong) Class customCellClass; // use either custom cell class or custom cell nil
@property (nonatomic, strong) UINib *customCellNib;
@property (nonatomic, copy) void (^configCustomCellBlock)(__kindof UITableViewCell *);

@end

NS_ASSUME_NONNULL_END
