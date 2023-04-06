//
//  NTFDataSourcable.h
//  PR-API
//
//  Created by berec on 09/06/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NTFDataSource;

@protocol NTFDataSourcable <NSObject>

- (nullable NTFDataSource *)dataSource;

@end
