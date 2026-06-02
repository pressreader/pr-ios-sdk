//
//  PRSmartVideoPreviewRegion.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 8/2/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <PRSmart/PRSmartImageRegion.h>

@class PRArticleVideo;

@interface PRSmartVideoPreviewRegion : PRSmartImageRegion
@property (nonatomic, strong) PRArticleVideo *video;

@end
