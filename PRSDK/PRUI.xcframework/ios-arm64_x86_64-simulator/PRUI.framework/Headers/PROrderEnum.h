//
//  PROrderEnum.h
//  PRiphone
//
//  Created by Keith Choi on 2018-08-20.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

@import Foundation;

#ifndef PROrderEnum_h
#define PROrderEnum_h

//PROrderStatus
typedef NS_ENUM(NSInteger, PROrderStatus) {
    PROrderStatusIdle, //no one request in the moment
    PROrderStatusSubscribingAutomaticDelivery, // sent request for subscribing for automatic delivery
    PROrderStatusRemovingSubscribtionForAutomaticDelivery // sent request to remove subscribtion for automatic delivery
};

//PROrderIssueState
typedef NS_ENUM(NSInteger, PROrderIssueState) {
    PROrderIssueStateBuy, // issue should be paid before download
    PROrderIssueStateDownload, // issue can be downloaded free
    PROrderIssueStateRead // issue is already downloaded
};

typedef NS_ENUM(NSInteger, PROrderAction) {
    PROrderActionNone,
    PROrderActionOpen,
    PROrderActionDownload,
    PROrderActionPostpone
};

typedef NS_ENUM(NSUInteger, PROrderDeliveryResult) {
    PROrderDeliveryResultNone = 0,
    PROrderDeliveryResultSuccess,
    PROrderDeliveryResultFail,
    PROrderDeliveryResultCancelled
};

typedef void(^DeliveryCompletionBlock)(PROrderDeliveryResult result,
                                       NSError *_Nullable error,
                                       PROrderAction selectedAction);

#endif /* PROrderEnum_h */
