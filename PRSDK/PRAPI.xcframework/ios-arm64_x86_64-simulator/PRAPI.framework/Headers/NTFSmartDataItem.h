//
//  NTFSmartDataItem.h
//  PR-API
//
//  Created by berec on 30/05/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NTFDataItem+CoreDataClass.h"

NS_ASSUME_NONNULL_BEGIN

@interface NTFSmartDataItem : NSObject

- (instancetype) initWithType:(NTFDataItemType)type NS_DESIGNATED_INITIALIZER;

@property (nonatomic, readonly) NTFDataItemType type;
@property (nonatomic, readonly) NSInteger pageIndex;
@property (nullable, nonatomic, readonly) NSString *title;
@property (nullable, nonatomic, readonly) NSString *text;
@property (nullable, nonatomic, readonly) NSString *language;
@property (nullable, nonatomic, readonly) NSString *originalLanguage;

@end

NS_ASSUME_NONNULL_END
