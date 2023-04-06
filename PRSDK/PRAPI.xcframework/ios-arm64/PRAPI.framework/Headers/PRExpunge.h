//
//  PRExpunge.h
//  PRiphone
//
//  Created by Vitali Bounine on 3/13/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

@import UIKit;

@class SPNode;

@interface PRExpunge : NSObject

@property (nonatomic, readonly, copy) NSString *xmlString;

@property (nonatomic) CGRect pdfRect;
@property (nonatomic, strong) UIColor *fillColor;

@property (nonatomic, copy) NSAttributedString *labelText;

@property (nonatomic) CGFloat borderWidth;
@property (nonatomic, strong) UIColor *borderColor;

+ (instancetype) expungeFromSPNode:(SPNode *)xmlNode;
- (instancetype) initFromSPNode:(SPNode *)xmlNode;

@end
