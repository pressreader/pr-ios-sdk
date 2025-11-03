//
//  CalendarStyle.h
//  Kal
//
//  Created by Jackie Cane on 11/13/12.
//
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface CalendarStyle : NSObject
@property (nonatomic, readonly) UIColor *calendarBackgroundColor;
@property (nonatomic, readonly) UIColor *calendarHeaderBackgroundColor;
@property (nonatomic, readonly) UIColor *calendarHeaderTextColor;
@property (nonatomic, readonly) UIColor *calendarHeaderSelectedTextColor;
@property (nonatomic, readonly) UIColor *calendarTilesTextColor;
@property (nonatomic, readonly) UIFont *calendarTilesFont;
@property (nonatomic, readonly) UIColor *calendarTilesSelectedTextColor;
@property (nonatomic, readonly) UIColor *calendarTilesTodayTextColor;
@property (nonatomic, readonly) UIColor *calendarTilesTodaySelectedTextColor;
@property (nonatomic, readonly) UIColor *calendarTilesBelongsToAdjacentMonthTextColor;
@property (nonatomic, readonly) UIColor *calendarTilesMarkedTextColor;
@property (nonatomic, readonly) UIColor *cellTodayBackgroundColor;
@property (nonatomic, readonly) UIColor *cellTodaySelectedBackgroundColor;
@property (nonatomic, readonly) UIColor *cellSelectedBackgroundColor;
@property (nonatomic, readonly) UIColor *cellHighlitedBackgroundColor;

@property (nonatomic, readonly) UIColor *calendarColumnTitlesTextColor;
@property (nonatomic, readonly) BOOL calendarColumnTitlesHasShadow;
@property (nonatomic, readonly) UIFont *headerTitleFont;
@property (nonatomic, readonly) UIImage *headerNextMonthImage;
@property (nonatomic, readonly) UIImage *headerNextMonthPressedImage;
@property (nonatomic, readonly) UIImage *headerPrevMonthImage;
@property (nonatomic, readonly) UIImage *headerPrevMonthPressedImage;
@property (nonatomic, readonly) UIFont *weekdayNamesFont;
@property (nonatomic, readonly) UIImage *markerImage;
@property (nonatomic, readonly) UIImage *markerTodaySelectedImage;
@property (nonatomic, readonly) UIImage *markerSelectedImage;
@property (nonatomic, readonly) UIImage *markerTodayImage;

@property (nonatomic, readonly) BOOL blurred;
@property (nonatomic, readonly) UIBlurEffectStyle blurStyle;
@property (nonatomic, readonly) UIColor *blurColor;

@property (nonatomic, readonly) CGFloat cornerRadius;
@property (nonatomic, readonly) UIColor *borderColor;
@property (nonatomic, readonly) CGFloat borderWidth;

@property (nonatomic, assign) BOOL adjustForArrowedPopover;

+ (instancetype)defaultStyle;
+ (instancetype)blackStyle;
+ (instancetype)whiteStyle;
+ (instancetype)blackStyleForPopover;
+ (instancetype)whiteStyleForPopover;

- (nullable UIImage *)headerBackground:(CGSize)size;
- (nullable UIImage *)imageCellBackgroundTodaySelected:(CGSize)size;
- (nullable UIImage *)imageCellBackgroundToday:(CGSize)size;
- (nullable UIImage *)imageCellBackgroundSelected:(CGSize)size;
- (nullable UIImage *)imageCellBackgroundHighlited:(CGSize)size;
- (nullable UIImage *)tiledImage:(CGSize)size;

@end

NS_ASSUME_NONNULL_END
