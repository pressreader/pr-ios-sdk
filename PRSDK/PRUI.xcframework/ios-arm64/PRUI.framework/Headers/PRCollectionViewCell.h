//
//  PRCollectionViewCell.m
//  PressReader
//
//  Created by Oleg Stepanenko on 30.11.16.
//
//

@import UIKit;
@import PRUIKit.PRPickable;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const PRCollectionViewDeletionModeChangedNotification;

typedef NS_ENUM(NSUInteger, PRCollectionViewCellImageScalingMode) {
    /// Scaling is applied only when image is shorter than standard catalog thumbnail.
    PRCollectionViewCellImageScalingModeDefault,
    PRCollectionViewCellImageScalingModeAlways,
    PRCollectionViewCellImageScalingModeNever,
};

@class PRCollectionViewCell;

@protocol PRCollectionViewCellDelegate <NSObject>
- (void)cell:(PRCollectionViewCell *)cell action:(NSString *)action;
@end

@interface PRCollectionViewCell : UICollectionViewCell <PRPickable>
@property (nullable, nonatomic, strong) NSString *title;
@property (nullable, nonatomic, strong) NSString *subTitle;
@property (nonatomic) BOOL hasSupplements;
@property (nullable, nonatomic, strong) UIImage *image;
@property (nullable, nonatomic, weak) id<PRCollectionViewCellDelegate> delegate;
@property (nonatomic, getter=isDeletingMode) BOOL deletingMode;
@property (nonatomic, getter=isDeleteAllowed) BOOL deleteAllowed;

@property (nonatomic, readonly) PRCollectionViewCellImageScalingMode thumbnailScalingMode;

@property (nullable, strong, nonatomic) IBOutlet UILabel *titleLabel;
@property (nullable, strong, nonatomic) IBOutlet UILabel *subTitleLabel;
@property (nullable, strong, nonatomic) IBOutlet UIView *coverView;
@property (nullable, strong, nonatomic) IBOutlet UIImageView *imageView;
@property (nullable, strong, nonatomic) IBOutlet UIImageView *shadowView;
@property (nullable, strong, nonatomic) IBOutlet UIImageView *supplementView;
@property (nullable, strong, nonatomic) IBOutlet UIImageView *selectionView;
@property (nullable, strong, nonatomic) IBOutlet UIView *thumbnailView;
@property (nullable, strong, nonatomic) IBOutlet UIView *logoView;
@property (nullable, strong, nonatomic) IBOutlet UIImageView *ribbonView;
@property (nullable, strong, nonatomic) IBOutlet UILabel *ribbonLabel;
@property (nullable, strong, nonatomic) IBOutlet NSLayoutConstraint *imageConstraint;
@property (nullable, strong, nonatomic) IBOutlet NSLayoutConstraint *imageCentreYConstraint;
@property (nullable, strong, nonatomic) IBOutlet UIView *infoBar;
@property (nullable, strong, nonatomic) IBOutlet UIButton *infoBarButton;
@property (nullable, strong, nonatomic) IBOutlet UIButton *actionButton;
@property (nullable, strong, nonatomic) IBOutlet UIButton *radioButton;

@property (nullable, strong, nonatomic) IBOutlet UIImageView *logoImageView;

@end


@interface PRCollectionViewCell (/*Protected*/)

- (void)setupDefaults;
- (void)registerAsObserver;

- (void)refreshSupplementsView;
- (void)refreshShadowView;

- (IBAction)infoBarTouchUp:(id)sender;
- (IBAction)downloadButtonTouchUp:(id)sender;
- (IBAction)actionButtonTouchUp:(id)sender;
- (IBAction)deleteButtonTouchUp:(id)sender;

@property (nonatomic, readonly) UIImage *selectionImage;
@property (nonatomic, readonly) CGFloat thumbnailAspectRatio;

@end


@interface PRCollectionViewCell (Theme)
@property (nonatomic, readonly) UIImage *shadowImage;
@property (nonatomic, readonly) UIColor *actionButtonTintColor;

@end

NS_ASSUME_NONNULL_END
