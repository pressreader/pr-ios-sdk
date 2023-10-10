//
//  PRAttachmetsContainerView.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 9/19/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PRAttachmetsContainerView;
@class PRSubscription;

@protocol PRAttachmetsContainerDelegate <NSObject>

- (void)attachmentsViewDidUpdateArtifacts:(PRAttachmetsContainerView *)view;
- (void)attachmentsViewDidReceiveAddImageClick:(PRAttachmetsContainerView *)view;
- (void)attachmentsViewDidReceiveAddVideoClick:(PRAttachmetsContainerView *)view;

@end

@class PRSmartArtifact;
@class PRSmartCommentPost;

@interface PRAttachmetsContainerView : UIView
@property (nonatomic, assign) BOOL allowCollectionView;
@property (nonatomic, weak) id<PRAttachmetsContainerDelegate> delegate;
@property (nonatomic, readonly) BOOL valid;

+ (instancetype)viewWithPost:(PRSmartCommentPost *)post text:(NSString *)text subscription:(PRSubscription *)subscription;

- (NSArray<NSString *> *)newAddingArtifactsIdMinusDeletingArtifactsId;
- (void)addImage:(UIImage *)image completion:(void(^)(NSURL *url, NSError *error))completion;
- (void)addVideoWithURL:(NSString *)url completion:(void(^)(NSURL *url, NSURL *previewURL, NSError *error))completion;
- (void)updateHeight;

@end

@interface PRAttachmetsContainerView (/*Protected*/)
@property (nonatomic, strong) IBOutlet UIView *backgroundView;
@property (nonatomic, strong) IBOutlet UICollectionView *artifactCollectionView;
@end
