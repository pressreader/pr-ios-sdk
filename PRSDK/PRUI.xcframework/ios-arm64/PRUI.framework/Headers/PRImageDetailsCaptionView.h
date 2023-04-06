//
//  PRImageDetailsCaptionView.h
//  PR-UI
//
//  Created by KeithC on 2019-10-08.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

@import UIKit;
@import PRUIKit.PRGradientLayerView;

NS_ASSUME_NONNULL_BEGIN

@interface PRImageDetailsCaptionView : PRGradientLayerView

- (void)updateWithCaption:(nullable NSString *)caption;
- (void)updateWithCaption:(nullable NSString *)caption
              imageNumber:(nullable NSString *)imageNumber
                   byline:(nullable NSString *)byline;

@end

@compatibility_alias PRMediaDetailsCaptionView PRImageDetailsCaptionView;

NS_ASSUME_NONNULL_END
