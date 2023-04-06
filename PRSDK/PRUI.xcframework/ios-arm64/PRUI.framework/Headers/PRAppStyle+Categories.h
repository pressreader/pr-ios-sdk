//
//  PRAppStyle+Categories.h
//  PR-UI
//
//  Created by berec on 25/06/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

@import PRUIKit.PRAppStyle;
@import PRAPI.NTFFeedSectionItem;

NS_ASSUME_NONNULL_BEGIN

@interface PRAppStyle (Categories)

+ (nullable UIColor *)colorForCategory:(NTFFeedSectionItemType)category;

+ (nullable UIImage *)imageForCategory:(NTFFeedSectionItemType)category;
+ (nullable UIImage *)imageForCategory:(NTFFeedSectionItemType)category large:(BOOL)large;

+ (nullable UIImage *)colouredImageForCategory:(NTFFeedSectionItemType)category;
+ (nullable UIImage *)colouredImageForCategory:(NTFFeedSectionItemType)category large:(BOOL)large;

+ (void)preloadColouredImagesForCategoriesLarge:(BOOL)large;

+ (CGFloat)categoryCardCornerRadius;

@end

NS_ASSUME_NONNULL_END
