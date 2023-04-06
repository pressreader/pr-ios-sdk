//
//  PRSourceItemDownloadManager.h
//  PRiphone
//
//  Created by Jackie Cane on 10/11/15.
//  Copyright © 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
@import PRProtocols;
#import "PROrderEnum.h"

@class PRSubscription;
@class PRMyLibraryItem;
@class PRSourceItem;
@class PRTitleItemExemplar;

NS_ASSUME_NONNULL_BEGIN

@interface PRSourceItemManager : NSObject <Singleton>

- (void)readLibraryItem:(PRMyLibraryItem *)libraryItem
             parameters:(nullable NSDictionary *)parameters
                 sender:(nullable id)sender;

- (void)readItem:(PRSourceItem *)item
preferableSubscription:(nullable PRSubscription *)subscription
      parameters:(nullable NSDictionary *)parameters
          sender:(nullable id)sender;

- (void)readExemplar:(PRTitleItemExemplar *)exemplar
preferableSubscription:(nullable PRSubscription *)subscription
          parameters:(nullable NSDictionary *)parameters;

- (void)downloadItem:(PRSourceItem *)item
preferableSubscription:(nullable PRSubscription *)subscription
              sender:(id)sender;

- (void)downloadExemplar:(PRTitleItemExemplar *)exemplar
  preferableSubscription:(nullable PRSubscription *)subscription
         completionBlock:(nullable DeliveryCompletionBlock)completionBlock;

- (void)orderExemplar:(PRTitleItemExemplar *)exemplar
preferableSubscription:(nullable PRSubscription *)subscription
   includeSupplements:(BOOL)includeSupplements
             download:(BOOL)download
    usePremiumProduct:(BOOL)usePremiumProduct
      completionBlock:(nullable DeliveryCompletionBlock)completionBlock;

- (void)stopWaitingForItemReadiness;

@property (class, nonatomic, readonly) PRSourceItemManager *instance;

@end

NS_ASSUME_NONNULL_END
