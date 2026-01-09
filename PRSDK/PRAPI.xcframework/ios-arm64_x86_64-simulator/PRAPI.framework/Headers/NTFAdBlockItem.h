//
//  NTFAdBlockItem.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 8/18/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

@import CoreGraphics;

#import "NTFFeedItem+CoreDataClass.h"

@class PRTitleItemExemplar;

@interface NTFAdBlockItem : NTFFeedItem
@property (nonatomic, readonly) PRTitleItemExemplar *mainExemplar;
@property (nonatomic, readonly) NSArray<PRTitleItemExemplar *> *backIssueExemplars;

@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end

#import "NTFAdBlockItem+CoreDataProperties.h"
