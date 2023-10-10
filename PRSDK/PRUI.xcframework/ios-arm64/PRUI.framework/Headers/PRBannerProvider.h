//
//  PRBannerProvider.h
//  PRUI
//
//  Created by Viacheslav Soroka on 5/20/20.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PRBannerPresentationConfig;
@class PRCatalogSection;
@protocol BannerDelegate;

@interface PRBannerProvider : NSObject

- (instancetype)initWithConfig:(PRBannerPresentationConfig *)config;

@property (nonatomic, strong, readonly) PRBannerPresentationConfig *presentationConfig;

@end

NS_ASSUME_NONNULL_END
