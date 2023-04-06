//
//  PRDownloadedSourceList.h
//  PR-API
//
//  Created by Viacheslav Soroka on 12/4/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "PRSourceList.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRDownloadedSourceList : PRSourceList

@end

@interface PRDownloadedSourceList (/*PRIVATE*/)
- (void)_reloadList;
@property (nonatomic, strong) id observer;
@end

NS_ASSUME_NONNULL_END
