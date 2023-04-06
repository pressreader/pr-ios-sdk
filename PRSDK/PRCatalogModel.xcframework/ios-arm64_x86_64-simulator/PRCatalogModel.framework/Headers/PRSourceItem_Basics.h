//
//  PRSourceItem_Basics.h
//  PRiphone
//
//  Created by Jackie Cane on 11/02/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, PRSourceType) {
    PRSourceTypeNotDefined = 0,
    PRSourceTypeNewspaper,
    PRSourceTypeMagazine,
    PRSourceTypeDocument,
    PRSourceTypeBook,

    PRSourceTypeAll = PRSourceTypeNotDefined,
    PRSourceTypeFirst = PRSourceTypeNotDefined,
    PRSourceTypeLast = PRSourceTypeBook
};
