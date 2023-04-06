//
//  PROperationController.h
//  PRiphone
//
//  Created by Jackie Cane on 4/20/11.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

@import Foundation;
@import PRProtocols;
@class SPNode;
@class PRSubscription;
@class SKProductsResponse;
@class PRSmartMediaRegion;
@class PRUserProfile;
@class PRHotSpotAnnotation;
@class PRCatalog;
@class PRTitleItem;


@interface PROperationController : NSObject<Singleton> {

@private
	NSOperationQueue *operationQueue_;
}

+ (instancetype)instance;

- (void)processGetBundlesResponse:(SPNode *)response subscription:(PRSubscription *)subscription;
- (void)processGetUserBundlesResponse:(SPNode *)response subscription:(PRSubscription *)subscription;
- (void)processGetUserBundlesByCidResponse:(SPNode *)response
                                  userdata:(NSMutableDictionary *)userdata
                              subscription:(PRSubscription *)subscription;
- (void)processGetTitlesResponse:(SPNode *)response
                   customCatalog:(SPNode *)customCatalog
                    subscription:(PRSubscription *)subscription;
- (void)processCustomCatalogResponse:(SPNode *)response
                        subscription:(PRSubscription *)subscription;
- (void)saveCatalog:(PRSubscription *)subscription;
- (void)saveCatalog:(PRSubscription *)subscription afterDelay:(NSTimeInterval)delay;
- (void)refreshCatalog:(PRCatalog *)catalog cancelable:(BOOL)cancelable completion:(void(^)(void))completion;

- (void)reportAppOpenToAdMob;
- (void)processSmartMediaContentForURL:(NSURL *)url smartMediaRegion:(PRSmartMediaRegion *)region;
- (void)processConfig:(NSXMLParser *)response;

- (void)searchForSources:(NSString *)searchString limit:(NSUInteger)limit completionBlock:(void(^)(NSArray<PRTitleItem *>  *sources))completionBlock;


@property (nonatomic, strong, readonly) NSOperationQueue *operationQueue;;

@end

