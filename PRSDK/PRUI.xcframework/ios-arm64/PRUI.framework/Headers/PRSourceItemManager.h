//
//  PRSourceItemDownloadManager.h
//  PRiphone
//
//  Created by Jackie Cane on 10/11/15.
//  Copyright © 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PRUI/PROrderDelivery.h>

@class PRSubscription;
@class PRMyLibraryItem;
@protocol PRCatalogItem;
@class PRTitleItemExemplar;

NS_ASSUME_NONNULL_BEGIN

@interface PRSourceItemManager : NSObject

- (void)readLibraryItem:(PRMyLibraryItem *)libraryItem
             parameters:(nullable NSDictionary *)parameters
                 sender:(nullable id)sender;

- (void)readItem:(id<PRCatalogItem>)item
preferableSubscription:(nullable PRSubscription *)subscription
      parameters:(nullable NSDictionary *)parameters
          sender:(nullable id)sender;

- (void)readExemplar:(PRTitleItemExemplar *)exemplar
preferableSubscription:(nullable PRSubscription *)subscription
          parameters:(nullable NSDictionary *)parameters;

- (void)downloadItem:(id<PRCatalogItem>)item
preferableSubscription:(nullable PRSubscription *)subscription
              sender:(id)sender;

- (void)downloadExemplar:(PRTitleItemExemplar *)exemplar
  preferableSubscription:(nullable PRSubscription *)subscription
         deliveryOptions:(PROrderDeliveryOption)deliveryOptions
         completionBlock:(nullable DeliveryCompletionBlock)completionBlock;

- (void)orderExemplar:(PRTitleItemExemplar *)exemplar
preferableSubscription:(nullable PRSubscription *)subscription
      deliveryOptions:(PROrderDeliveryOption)deliveryOptions
      completionBlock:(nullable DeliveryCompletionBlock)completionBlock;

- (void)stopWaitingForItemReadiness;

@property (class, nonatomic, readonly) PRSourceItemManager *instance;

@end

NS_ASSUME_NONNULL_END
