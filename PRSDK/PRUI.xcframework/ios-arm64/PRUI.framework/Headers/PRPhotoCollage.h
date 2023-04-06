//
//  PRPhotoCollage.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 6/20/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@import PRAPI.NTFArticle;

NS_ASSUME_NONNULL_BEGIN

@class PRSmartArtifact;
@class PRSmartImageRegion;
@protocol PRPhotoCollage;

@protocol PRPhotoCollageDelegate <NSObject>

@optional
- (void)photoCollage:(__kindof UIView<PRPhotoCollage> *)view didReceiveTapOnArtifact:(PRSmartArtifact *)artifact;
- (void)photoCollage:(__kindof UIView<PRPhotoCollage> *)view didReceiveTapOnImageRegion:(PRSmartImageRegion *)region;

@end

@protocol PRPhotoCollage <NSObject>
@property (nullable, nonatomic, weak) id<PRPhotoCollageDelegate> delegate;

+ (instancetype)view;

+ (CGFloat)heighForImageRegions:(NSArray<PRSmartImageRegion *> *)regions
                   contentWidth:(CGFloat)contentWidth
                 eligibleHeight:(CGFloat)eligibleHeight;

- (void)fillWithArticle:(id<NTFArticle>)article
                 images:(NSArray<PRSmartImageRegion *> *)images
         eligibleHeight:(CGFloat)eligibleHeight;

@end

NS_ASSUME_NONNULL_END
