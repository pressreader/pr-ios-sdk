//
//  PRFunctions.h
//  PRDataUtils
//
//  Created by berec on 22/04/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

@import Foundation;
@import CoreGraphics;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Nullable Equality

BOOL EqualObjects(NSObject *_Nullable object1, NSObject *_Nullable object2);
BOOL EqualStrings(NSString *_Nullable string1, NSString *_Nullable string2);
BOOL EqualNumbers(NSNumber *_Nullable object1, NSNumber *_Nullable object2);
BOOL EqualArrays(NSArray *_Nullable object1, NSArray *_Nullable object2);

#pragma mark - Core Graphics

CGRect PRCGRectMake(CGPoint origin, CGSize size);
BOOL PRCGSizeIsZero(CGSize size);

NS_ASSUME_NONNULL_END
