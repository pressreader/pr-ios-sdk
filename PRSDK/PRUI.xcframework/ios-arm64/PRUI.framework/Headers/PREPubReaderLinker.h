//
//  PREPubReaderLinker.h
//  PRUI
//
//  Created by Vitali Bounine on 2020-07-10.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class UIViewController;
@class PRPromise;
@class EpubContent;
@protocol PRSubscriptionCatalogProtocol;
@protocol PRWebServerBookRegister;

@interface PREPubReaderLinker : NSObject

@property (class, readonly) BOOL isEPubReaderAvailable;

+ (PRPromise *) getEPubReader:(EpubContent *)epub
                   httpServer:(id<PRWebServerBookRegister>) httpServer
                 subscription:(nullable id<PRSubscriptionCatalogProtocol>) subscription;

@end

NS_ASSUME_NONNULL_END
