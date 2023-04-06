//
//  CompatibilityFactory.h
//  PRUI
//
//  Created by Viacheslav Soroka on 2021-07-12.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

#ifndef CompatibilityFactory_h
#define CompatibilityFactory_h

typedef NS_OPTIONS(NSUInteger, PROrderOption) {
    PROrderOptionNone = 0,
    PROrderOptionScrollToIssueDate = 1 << 0,
    PROrderOptionDisplayParentTitleOnly = 1 << 1,
    PROrderOptionPresentContentIfAvailable = 1 << 2,
    PROrderOptionHideLoadingView = 1 << 3
};

#endif /* CompatibilityFactory_h */
