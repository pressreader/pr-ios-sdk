//
//  PRCollectionVC.h
//  FlowLayoutNoNIB
//
//  Created by Oleg Stepanenko on 22.11.12.
//
//

#import "PRCollectionView.h"
#import "PRSourceItemCell.h"
#import "PRCollectionViewFlowLayout.h"
#import "PRViewLayoutProtocol.h"

@import PRUIKit.PRVC;
@import PRAPI.PROptions;
@import PRAccessibility;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kCellId;
extern NSString *const kSectionHeaderId;
extern NSString *const kSectionFooterId;

extern NSString * const kPRCellGridCompactIdentifier;
extern NSString * const kPRCellGridSmallIdentifier;
extern NSString * const kPRCellListIdentifier;
extern NSString * const kPRCellListCompactIdentifier;

typedef NS_OPTIONS(NSUInteger, PRCollectionOption) {
    PRCollectionOptionEmbedded = 1 << 0,
    PRCollectionOptionDisableSelection = 1 << 1,
    PRCollectionOptionShowDatesOnly = 1 << 2,
    PRCollectionOptionShowSingleLineTitle = 1 << 3
};

@protocol PRCollectionVCDelegate <NSObject>
- (void)registerReusableCells;
@end

@interface PRCollectionVC : PRVC <UICollectionViewDataSource, UICollectionViewDelegate, PRCollectionViewCellDelegate, PRCollectionVCDelegate, UICollectionViewDelegateFlowLayout, PRViewLayoutProtocol>

- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;

- (void)setupCell:(PRSourceItemCell *)cell atIndexPath:(NSIndexPath *)indexPath;
- (void)setupSupplementaryView:(UICollectionReusableView *)supplementaryView
                          kind:(NSString *)kind
                   atIndexPath:(NSIndexPath *)indexPath;
- (BOOL)showDatesOnlyForSection:(NSInteger)section;

- (void)reloadData;
- (void)reloadDataAfterDelay:(NSTimeInterval)delay;
- (void)setNeedsReloadData;

- (void)reloadTitle;

- (void)scrollToTopAnimated:(BOOL)animated;
- (void)scrollToTop;

@property (nonatomic, strong, readonly) PRCollectionView *collectionView;

@property (nonatomic) UIEdgeInsets collectionViewInsets;
@property (nonatomic, readonly) CGFloat parentThumbnailHeight;
@property (nonatomic, readonly) PRCollectionViewFlowLayout *collectionViewLayout;
@property (nonatomic, strong, readonly) NSString *presentationCellId;
@property (nonatomic, assign) PRRibbonStyleMask allowedRibbonStyleMask;
@property (nullable, nonatomic, copy) void(^scrollHandler)(UIScrollView *);

@property (nonatomic) PRSourceItemCellPresentationStyle cellPresentationStyle;

@property (nonatomic) NSString *identifier;

@property (nonatomic) PRCollectionOption viewOptions;

@end


@interface PRCollectionVC (/*Protected*/)

- (void)refreshCollectionLayout:(BOOL)animated;
- (void)registerAsObserver;
- (void)reloadData;
- (void)processLongTapOnItemWithIndexPath:(NSIndexPath *)indexPath;

@property (nonatomic, readonly) BOOL canReloadData;
@property (nonatomic, readonly) BOOL isEmbedded;
@property (nonatomic, readonly) PRCellInfoBarStyle infoBarStyle;

@property (nonatomic, strong) NSIndexPath *selectedIndexPath;
@property (nonatomic, assign) PRPresentationStyle presentationStyle;
@property (nonatomic, assign) PRPresentationStyle preferablePresentationStyle;
@property (nonatomic, assign) PRPresentationStyle forcedPresentationStyle;
@property (nonatomic, readonly) PRSourceItemCellPresentationStyle preferableCellPresentationStyle;
@property (nonatomic, getter=isViewVisible) BOOL viewVisible;

@property (nullable, nonatomic, readonly) PRCollectionViewFlowLayout *layoutForCurrentPresentationStyle;

@property (nonatomic, readonly) UIColor *backgroundColor;

@property (nonatomic, readonly) PRCollectionViewFlowLayout *layoutForRegularList;
@property (nonatomic, readonly) PRCollectionViewFlowLayout *layoutForRegularSmallGrid;
@property (nonatomic, readonly) PRCollectionViewFlowLayout *layoutForRegularGrid;
@property (nonatomic, readonly) PRCollectionViewFlowLayout *layoutForCompactList;
@property (nonatomic, readonly) PRCollectionViewFlowLayout *layoutForCompactSmallGrid;
@property (nonatomic, readonly) PRCollectionViewFlowLayout *layoutForCompactGrid;

@end

NS_ASSUME_NONNULL_END
