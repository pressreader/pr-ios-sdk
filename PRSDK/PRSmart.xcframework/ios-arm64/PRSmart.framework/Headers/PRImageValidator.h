//
//  PRImageValidator.h
//  PR-UI
//
//  Created by berec on 31/07/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRImageValidationCriteria : NSObject

+ (instancetype)defaultCriteria;

@property (nonatomic) CGFloat maxHeight;
/// how many times image is allowed to be smaller than required
@property (nonatomic) CGFloat scaleThreshold;
/// percent of minimal acceptable vertical portion of image to display
@property (nonatomic) CGFloat heightPortionThreshold;

@property (nonatomic) CGFloat maxRatio;

@end

@interface PRImageValidator : NSObject

+ (instancetype)validatorWithMinSize:(CGSize)minSize criteria:(PRImageValidationCriteria *)criteria;

- (BOOL)validateSize:(CGSize)size reason:(NSString * _Nullable __autoreleasing *_Nullable)info;
- (BOOL)validateImage:(UIImage *)image;

@property (nonatomic) CGSize minSize;
@property (nonatomic, strong) PRImageValidationCriteria *criteria;

@end

NS_ASSUME_NONNULL_END
