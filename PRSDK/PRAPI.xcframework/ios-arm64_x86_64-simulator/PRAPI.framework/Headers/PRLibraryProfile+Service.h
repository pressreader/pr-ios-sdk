//
//  PRLibraryProfile+Service.h
//  PR-API
//
//  Created by Viacheslav Soroka on 3/14/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "PRLibraryProfile.h"

@class PRPromise;

NS_ASSUME_NONNULL_BEGIN

@interface PRLibraryProfile (Service)

+ (PRPromise *)getLibraryProfile;

@end

NS_ASSUME_NONNULL_END
