//
//  PRBannerPresentationConfig.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 5/13/20.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@import PRConfiguration.PRConfig_AppPanels;

NS_ASSUME_NONNULL_BEGIN

@protocol CatalogFacade;
@class ContentCardsPresentationConfig;

@interface PRBannerPresentationConfig : NSObject

- (instancetype)initWithSourceList:(id<CatalogFacade>)sourceList;

@property (class, nonatomic, readonly) PRAppPanelID panelToShowBanners;
@property (nonatomic, strong, readonly) id<CatalogFacade> sourceList;
@property (nonatomic, strong, readonly) ContentCardsPresentationConfig *contentCards;

@end

NS_ASSUME_NONNULL_END
