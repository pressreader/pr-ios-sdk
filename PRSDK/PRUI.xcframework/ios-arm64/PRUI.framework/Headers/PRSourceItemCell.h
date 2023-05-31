//
//  PRSourceItemCell.h
//  PRiphone
//
//  Created by Jackie Cane on 25/06/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import "PRCollectionViewCell.h"

@class PRTitleItemExemplar;
@class PRThumbnailObject;
@class PRTitleItem;
@protocol PRCatalogItem;

typedef NS_ENUM(NSUInteger, PRRibbonStyle) {
    PRRibbonStyleNone = 0,
    PRRibbonStyleNew  = 1 << 0,
    PRRibbonStyleFree = 1 << 1,
    PRRibbonStyleLatest = 1 << 2,
    PRRibbonStyleSample = 1 << 3
};

typedef NS_OPTIONS(NSUInteger, PRRibbonStyleMask) {
    PRRibbonStyleMaskNone = PRRibbonStyleNone,
    PRRibbonStyleMaskNew  = PRRibbonStyleNew,
    PRRibbonStyleMaskFree = PRRibbonStyleFree,
    PRRibbonStyleMaskLatest = PRRibbonStyleLatest,
    PRRibbonStyleMaskSample = PRRibbonStyleSample,
    PRRibbonStyleMaskAll  = (PRRibbonStyleMaskNew | PRRibbonStyleMaskFree | PRRibbonStyleMaskLatest | PRRibbonStyleMaskSample )
};

typedef NS_ENUM(NSInteger, PRCellActionButtonState) {
    PRCellActionButtonStateUndefined = 0,
    PRCellActionButtonStateHidden,
    PRCellActionButtonStateDownload,
    PRCellActionButtonStatePause,
    PRCellActionButtonStateRestore,
    PRCellActionButtonStateRead,
    PRCellActionButtonStateLock,
    PRCellActionButtonStatePurchaseFailed
};

typedef NS_ENUM(uint8_t, PRCellInfoBarStyle) {
    PRCellInfoBarStyleDefault = 0,
    PRCellInfoBarStyleDateOnly,
    PRCellInfoBarStyleTitleOnly,
    PRCellInfoBarStyleSingleLineTitle
};

typedef NS_ENUM(int8_t, PRSourceItemCellPresentationStyle) {
    PRSourceItemCellPresentationStyleUndefined = -1,
    PRSourceItemCellPresentationStylePublications = 0,
    PRSourceItemCellPresentationStyleTitleExemplars,
    PRSourceItemCellPresentationStyleOnboarding,
    PRSourceItemCellPresentationStyleSimple
};

typedef NS_OPTIONS(int8_t, PRSourceItemCellPresentationOption) {
    PRSourceItemCellPresentationOptionNone = 0,
    /// Present error action state in case `CatalogItem` state contains `licensePurchaseFailed`
    PRSourceItemCellPresentationOptionErrorStateAvailable = 1 << 0,
    /// Use action state for sample content in case it is downloaded OR downloading and `Catalogitem` has no regular content downloaded
    PRSourceItemCellPresentationOptionSampleContentStateAvailable = 1 << 1,
    PRSourceItemCellPresentationOptionShowRadioButton = 1 << 2,
    PRSourceItemCellPresentationOptionAdditionalInfoAllowed = 1 << 3
};

typedef NS_OPTIONS(NSUInteger, PRSourceThumbnailOption) {
    PRSourceThumbnailOptionUseLatestAvailableThumb = 1 << 0,
    PRSourceThumbnailOptionReplaceImageImmediately = 1 << 1,
    /// in case need for custom thumbnail with a alternative titleExemplar (i.e nightEdition)
    PRSourceThumbnailOptionUseAltTitleExemplar = 1 << 2
};

NS_ASSUME_NONNULL_BEGIN

@interface PRSourceItemCell : PRCollectionViewCell

+ (CGFloat)infoBarHeightForStyle:(PRCellInfoBarStyle)style;
+ (CGFloat)infoBarHeightForPresentationStyle:(PRSourceItemCellPresentationStyle)style;
+ (PRCellInfoBarStyle)infoBarStyleForPresentationStyle:(PRSourceItemCellPresentationStyle)style;
+ (PRCellInfoBarStyle)defaultInfoBarStyle;


- (void)setupCellWithTitleExemplar:(PRTitleItemExemplar *)exemplar NS_SWIFT_NAME(setupCell(titleExemplar:));
- (void)setupCellWithTitleExemplar:(PRTitleItemExemplar *)exemplar
                  thumbnailOptions:(PRSourceThumbnailOption)thumbnailOptions;

- (void)updateRibbonLabel;
- (void)updateListenButtonState;
- (void)setupInfoBarWithStyle:(PRCellInfoBarStyle)style;

@property (class, nonatomic, readonly) CGFloat infoBarHeight;

@property (nonatomic, readonly) PRTitleItem *titleItem;
@property (nullable, nonatomic, readonly) PRTitleItemExemplar *titleExemplar;

@property (nonatomic) PRSourceItemCellPresentationStyle presentationStyle;
@property (nonatomic) PRSourceItemCellPresentationOption presentationOptions;

@property (nonatomic) PRCellActionButtonState actionState;
@property (nonatomic) PRRibbonStyle ribbonStyle;
@property (nonatomic) PRCellInfoBarStyle infoBarStyle;
@property (nonatomic) PRRibbonStyleMask allowedRibbonStyleMask;
@property (nonatomic, getter=isDimmed) BOOL dimmed;
@property (nonatomic, getter=isLocked) BOOL locked;
@property (nonatomic) NSUInteger downloadProgress;
@property (strong, nonatomic) IBOutlet NSLayoutConstraint *ribbonToBackgroundRightConstraint;

@property (nonatomic) BOOL smartXMLExist;
@property (nonatomic) BOOL smartXMLReady;

@end

NS_ASSUME_NONNULL_END

#import "PRSourceItemCell_Protected.h"
