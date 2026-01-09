//
//  PRGiftedIssueContainer.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 5/10/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class NTFGiftedIssueItem, PROrder, PRThumbnailSource;
@protocol PRCatalogItem;

@interface PRGiftedIssueContainer : UIView

+ (instancetype)containerWithGiftItem:(NTFGiftedIssueItem *)item;

- (void)refreshIssueImageViewSize;

@property (nonatomic, strong) IBOutlet UIImageView *issueImageView;

@property (nullable, nonatomic, strong) id<PRCatalogItem> titleItem;
@property (nullable, nonatomic, strong) PROrder *order;
@property (nullable, nonatomic, strong) NSDate *issueDate;
@property (nullable, nonatomic, strong) PRThumbnailSource *thumbnail;

@end

NS_ASSUME_NONNULL_END
