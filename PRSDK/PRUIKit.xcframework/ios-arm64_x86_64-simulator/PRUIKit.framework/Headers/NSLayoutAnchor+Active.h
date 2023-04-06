//
//  NSLayoutAnchor+Active.h
//  PR-UI
//
//  Created by berec on 21/03/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSLayoutAnchor<AnchorType> (Active)
- (NSLayoutConstraint *)activeConstraintEqualToAnchor:(NSLayoutAnchor<AnchorType> *)anchor NS_SWIFT_NAME(activeConstraint(equalTo:));
- (NSLayoutConstraint *)activeConstraintEqualToAnchor:(NSLayoutAnchor<AnchorType> *)anchor constant:(CGFloat)c NS_SWIFT_NAME(activeConstraint(equalTo:constant:));

- (NSLayoutConstraint *)activeConstraintGreaterThanOrEqualToAnchor:(NSLayoutAnchor<AnchorType> *)anchor;
- (NSLayoutConstraint *)activeConstraintGreaterThanOrEqualToAnchor:(NSLayoutAnchor<AnchorType> *)anchor constant:(CGFloat)c;

- (NSLayoutConstraint *)activeConstraintLessThanOrEqualToAnchor:(NSLayoutAnchor<AnchorType> *)anchor;
- (NSLayoutConstraint *)activeConstraintLessThanOrEqualToAnchor:(NSLayoutAnchor<AnchorType> *)anchor constant:(CGFloat)c;

@end

@interface NSLayoutDimension (Active)
- (NSLayoutConstraint *)activeConstraintEqualToConstant:(CGFloat)c NS_SWIFT_NAME(activeConstraint(equalToConstant:));
- (NSLayoutConstraint *)activeConstraintGreaterThanOrEqualToConstant:(CGFloat)c NS_SWIFT_NAME(activeConstraint(greaterThanOrEqualToConstant:));
- (NSLayoutConstraint *)activeConstraintLessThanOrEqualToConstant:(CGFloat)c NS_SWIFT_NAME(activeConstraint(lessThanOrEqualToConstant:));

- (NSLayoutConstraint *)activeConstraintEqualToAnchor:(NSLayoutDimension *)anchor multiplier:(CGFloat)m NS_SWIFT_NAME(activeConstraint(equalTo:multiplier:));
- (NSLayoutConstraint *)activeConstraintEqualToAnchor:(NSLayoutDimension *)anchor multiplier:(CGFloat)m constant:(CGFloat)c NS_SWIFT_NAME(activeConstraint(equalTo:multiplier:constant:));


@end

NS_ASSUME_NONNULL_END
