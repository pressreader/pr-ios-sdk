//
//  PRFilterableCollectionVC.h
//  PRiphone
//
//  Created by berec on 4/22/16.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import "PRCollectionVC.h"
#import "AdditionalContentInsetable.h"

@import PRAPI.Swift;
@import PRAds;

NS_ASSUME_NONNULL_BEGIN

@interface PRFilterableCollectionVC : PRCollectionVC<UIPopoverPresentationControllerDelegate,
                                                     AdditionalContentInsetable>

@property (nonatomic, readonly) NSString *viewTraits;

/// View to show as a first section's header
@property (nullable, nonatomic, strong) UIView *headerView;
@property (nonatomic, assign) CGFloat headerViewHeight;

@property (nonatomic, readonly) AdBannerScreen adBannerScreen;

@end

NS_ASSUME_NONNULL_END

#import "PRFilterableCollectionVC_Protected.h"
