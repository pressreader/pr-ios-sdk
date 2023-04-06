//
//  UIView+SubviewSearch.h
//  PR-UI
//
//  Created by berec on 26/07/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (SubviewSearch)

/// Calls `subviewUsingDeepSearch:criterion` with deepSearch on.
- (nullable __kindof UIView *)subviewWithCriterion:(BOOL(^)(__kindof UIView *view))criterion;
- (nullable __kindof UIView *)subviewUsingDeepSearch:(BOOL)deepSearch
                                           criterion:(BOOL(^)(__kindof UIView *view))criterion
NS_SWIFT_NAME(subview(deepSearch:criterion:));

/// Calls `subviewOfClassKind:deepSearch` with deepSearch off.
- (nullable __kindof UIView *)subviewOfClassKind:(Class)classOfView;
- (nullable __kindof UIView *)subviewOfClassKind:(Class)classOfView deepSearch:(BOOL)deepSearch;

/// Calls `subviewOfClassMember:deepSearch` with deepSearch off.
- (nullable __kindof UIView *)subviewOfClassMember:(Class)myclass;
- (nullable __kindof UIView *)subviewOfClassMember:(Class)classOfView deepSearch:(BOOL)deepSearch;

@end

NS_ASSUME_NONNULL_END
