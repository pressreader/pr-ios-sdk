//
//  PRTooltipsController.h
//  PRiphone
//
//  Created by Jackie Cane on 16/04/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PRTooltipType) {
    PRTooltipTypeNone = 0,
   
    PRTooltipTypePublications,
    PRTooltipTypePublicationsHub,
    PRTooltipTypePublicationsBreadcrumb,
    
    PRTooltipTypeOrder,
    
    PRTooltipTypeDownloaded,
    PRTooltipTypeDownloadedGroup,
    
    PRTooltipTypeHotSpotMap,
    PRTooltipTypeHotSpotMapRightListHeader,
    PRTooltipTypeHotSpotMapRightListDistanceButton,
    PRTooltipTypeHotSpotMapCurrentLocationButton,
    
    PRTooltipTypeAppMenu,
    
    PRTooltipTypeReadingViewArticleHighlighting,
    PRTooltipTypeReadingViewLongTap,
    
    PRTooltipTypeSmartFlowExpandArticle,
    PRTooltipTypeSmartFlowReplicaTextSwitch,

    PRTooltipTypeRadio,
    
    PRTooltipTypeFirst = PRTooltipTypePublications,
    PRTooltipTypeLast = PRTooltipTypeRadio
};

@interface PRTooltipsController : NSObject
+ (BOOL)isTooltipsDisplayed:(PRTooltipType)tooltipType;
+ (void)markTooltipsAsDisplayed:(PRTooltipType)tooltipType;
+ (BOOL)areTooltipsReset;
+ (void)resetTooltips;
@end
