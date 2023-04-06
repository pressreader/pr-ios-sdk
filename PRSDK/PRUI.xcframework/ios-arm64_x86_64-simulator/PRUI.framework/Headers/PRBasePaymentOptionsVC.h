//
//  PRBasePaymentOptionsVC.h
//  PR-UI
//
//  Created by berec on 03/06/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PROrderDelivery.h"

NS_ASSUME_NONNULL_BEGIN

@class PRProduct;

@interface PRBasePaymentOptionsVC : UITableViewController

- (instancetype)initWithStyle:(UITableViewStyle)style
                  productList:(NSArray<PRProduct *> *)products
                          CID:(nullable NSString *)CID
                         date:(nullable NSDate *)date
                     delegate:(id<PRPurchaseSelectorProtocol>)delegate NS_DESIGNATED_INITIALIZER NS_SWIFT_NAME(init(style:productList:CID:date:delegate:));

- (instancetype)initWithStyle:(UITableViewStyle)style NS_UNAVAILABLE;
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil
                         bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;
- (void)restoreSelected;
- (void)updatePreferredContentSize;

@property (nonatomic, strong) NSArray<PRProduct *> *products;
@property (nullable, nonatomic, copy) NSString *CID NS_SWIFT_NAME(CID);
@property (nullable, nonatomic, copy) NSDate *date;
@property (nonatomic, weak) id<PRPurchaseSelectorProtocol> delegate;
@property (nonatomic, assign) BOOL showRestoreButton;
@property (nonatomic, assign) BOOL activatingHotSpot;

@end

@interface PRBasePaymentOptionsVC (/*Protected*/)
@property (nonatomic, readonly) NSArray<PRProduct *> *fullProductList;

- (void)updateHotSpotCell:(BOOL)activating;
@end

NS_ASSUME_NONNULL_END
