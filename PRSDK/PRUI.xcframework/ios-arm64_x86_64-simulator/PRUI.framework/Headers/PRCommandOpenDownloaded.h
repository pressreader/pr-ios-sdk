//
//  PRCommandOpenDownloaded.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 09.01.13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

@import PRUIKit.PRCommand;

NS_ASSUME_NONNULL_BEGIN

@interface PRCommandOpenDownloaded : PRCommand

@end

@interface PRCommandOpenDownloaded (/*Protected*/)
@property (nonatomic, readonly) UIViewController *downloadedVC;

@end

NS_ASSUME_NONNULL_END
