//
//  NTFHomeFeedDataSource.h
//  PR-UI
//
//  Created by berec on 23/05/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "NTFBaseHomeFeedDataSource.h"

@interface NTFHomeFeedDataSource : NTFBaseHomeFeedDataSource

- (void)updateCurrentIndexWithCompletion:(void(^)(BOOL updated))completion;

@end
