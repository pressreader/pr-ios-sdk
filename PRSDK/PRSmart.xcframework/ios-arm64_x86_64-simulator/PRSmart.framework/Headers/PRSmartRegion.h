//
//  PRSmartRegion.h
//  PRiphone
//
//  Created by Jackie Cane on 26/08/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PRSmartBaseObject.h"

typedef NSString *PRSmartRegionType NS_TYPED_EXTENSIBLE_ENUM;

@class PageInfo;

NS_ASSUME_NONNULL_BEGIN

@interface PRSmartRegion : PRSmartBaseObject {
    NSUInteger pageNo;
    PRSmartRegionType type;
    NSMutableArray* rects;
}

- (instancetype)initWithType:(PRSmartRegionType)type page:(NSUInteger)page parent:(PRSmartBaseObject*)parentObject;
- (void) addRect:(CGRect)rect;
- (void) addRectInString:(NSString*)stringRep;
- (NSData *) extraDataFromFile:(NSString *)filePath;

- (PRSmartRegionType) type;
- (NSUInteger) pageNo;
- (nullable NSArray *)rects;
- (nullable NSString *)regionGuid;
- (nullable NSString *)regionId;
- (CGRect) unionRect;
- (CGRect) textUnionRect;
- (CGRect) firstRect;
- (CGRect) lastRect;
- (nullable NSArray *)partitionedUnionRectsAtThreshold:(CGSize)threshold;
- (BOOL) IsPointInRects:(CGPoint)point;
- (BOOL) IsPointInTextRects:(CGPoint)point;

- (nullable NSString *)text;
- (nullable NSString *)textWithISOLanguage:(NSString *)language;

- (void)setText:(NSString *)text isoLanguage:(NSString *)language;
- (void)setTextH:(NSString *)text isoLanguage:(NSString *)language;

- (nullable NSString *)textWithHyphens;
- (nullable NSString *)textWithHyphensISOLanguage:(NSString *)language;

- (void)textAppendChars:(NSString*)chars;
- (void)textAppendChars:(NSString*)chars isoLanguage:(NSString *)language;

- (nullable NSString *)htmlTextHyphenated:(BOOL)hyphenated lineBreakReplacement:(NSString *)br;
- (nullable NSString *)htmlTextHyphenated:(BOOL)hyphenated lineBreakReplacement:(NSString *)br isoLanguage:(NSString *)language;

- (void)textAppendCharsWithHyphens:(NSString*)chars;
- (void)textAppendCharsWithHyphens:(NSString*)chars isoLanguage:(NSString *)language;

@property (nullable, nonatomic, strong) PRSmartBaseObject *parent;
@property (nullable, nonatomic, strong) PageInfo *pageInfo;

@end

NS_ASSUME_NONNULL_END
