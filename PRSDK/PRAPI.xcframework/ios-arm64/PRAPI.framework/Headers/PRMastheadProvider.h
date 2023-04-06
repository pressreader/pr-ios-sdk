//
//  PRMastheadProvider.h
//  PR-API
//
//  Created by Vitali Bounine on 2019-05-10.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

@import UIKit;
@import PRThumbnail.PRThumbnailMasthead;

NS_ASSUME_NONNULL_BEGIN

@protocol PRMastheadProvider

/// returns YES if article has a masthead, otherwise - NO.
- (BOOL)mastheadWithHeight:(CGFloat)height
                     style:(NTFMastheadStyle)style
                   options:(NTFMastheadOption)options
                completion:(void(^_Nullable)(UIImage * _Nullable image, NSError * _Nullable error))completion;

@optional
@property (nonatomic, readonly) BOOL hasMasthead;

@end

NS_ASSUME_NONNULL_END

