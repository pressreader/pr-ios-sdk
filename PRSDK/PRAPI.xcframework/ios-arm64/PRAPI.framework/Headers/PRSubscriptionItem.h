//
//  PRSubscriptionItem.h
//  PRiphone
//
//  Created by Jackie Cane on 10/19/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PRSubscriptionItem : NSObject
{
	NSString* PrintCopies;
	BOOL	  PrintAsImage;
}

@property(nonatomic, assign) BOOL confirmed;

@property(nonatomic, strong, readonly) NSString* CID;
@property(nonatomic, strong, readonly) NSString* title;
@property(nonatomic, strong, readonly) NSString* parent;
@property(nonatomic, strong, readonly) NSString* supplement;
@property(nonatomic, strong, readonly) NSDate* start;
@property(nonatomic, strong, readonly) NSDate* end;
@property(nonatomic, strong, readonly) NSString* activationId;
@property(nonatomic, strong, readonly) NSString* orderID;
@property(nonatomic, strong, readonly) NSString* orderDescription;
@property(nonatomic, strong, readonly) NSString* schedule;
@property(nonatomic, readonly, getter=isGetLatestIssue) BOOL getLatestIssue;

- (instancetype) initWithCID:(NSString*)aCID start:(NSDate*)aStart end:(NSDate*)anEnd activationId:(NSString*)activationId confirmed:(BOOL)confirmed;
- (BOOL) titleContains:(NSString*)filter;
- (BOOL) titleStartWith:(NSString*)filter;

@end
