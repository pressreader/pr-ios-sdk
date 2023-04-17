//
//  PRSourceItem_Protected.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 13.08.13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import "PRSourceItem.h"

@interface PRSourceItem () {
    PRSubscription * _defaultSubscription;
}

@property (nonatomic, retain, readwrite) NSString *CID;
@property (nonatomic, retain, readwrite) NSString *title;
@property (nonatomic, retain, readwrite) NSString *localizedTitle;
@property (nonatomic, retain, readwrite) NSString *parentName;
@property (nonatomic, retain, readwrite) NSArray *parentCIDs;
@property (nonatomic, retain, readwrite) NSString *supplementName;
@property (nonatomic, retain, readwrite) NSDate *orderDate;
@property (nonatomic, assign, readwrite) PRSourceType sourceType;
@property (nonatomic, retain, readwrite) UIColor *paperColor;

@property (nonatomic, retain) NSArray<NSValue *> *subscriptions;

@end
