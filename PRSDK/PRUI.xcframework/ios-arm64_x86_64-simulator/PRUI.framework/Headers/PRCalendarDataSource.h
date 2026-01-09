//
//  PRCalendarDataSource.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 3/11/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "KalDataSource.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^PRDateSelectionHandler)(NSDate *, BOOL);

@interface PRCalendarDataSource : NSObject <KalDataSource>

@property (nullable, nonatomic, copy) PRDateSelectionHandler dateSelectionHandler;
@property (nullable, nonatomic, copy) void(^onDataSourceUpdated)(void);

@end

NS_ASSUME_NONNULL_END
