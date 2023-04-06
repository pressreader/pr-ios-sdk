//
//  PRArticleImageGenerator.h
//  PRAPI
//
//  Created by berec on 02/10/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

@import UIKit;

@class PRMyLibraryItem;

NS_ASSUME_NONNULL_BEGIN

@interface PRImageCacheManager: NSObject
{
    int      m_poolPosition;
    NSMutableArray* m_pool;
}

+ (PRImageCacheManager*) inst;

- (NSData*) getImageDataFromCache:(NSString*)name messageId:(NSString*)messageId;
- (void) StoreImageToCache:(NSData*)image name:(NSString *)name messageId:(NSString*)messageId;
- (BOOL) IsImageStoredInCache:(NSString *)name messageId:(NSString*)messageId;

@end


@interface PRArticleImageGenerator : NSObject
{
    NSMutableDictionary* m_pool; // pool of PDFItems
}

+ (PRArticleImageGenerator*) inst;

- (UIImage*)generateArticleImage:(PRMyLibraryItem *)mli page:(NSInteger)page articleOnPageIdx:(int)articleOnPageIdx imgIdx:(int)imgIdx scale:(CGFloat)scale error:(NSError **)error;
- (NSData*)getArticleImageData:(PRMyLibraryItem*)mli page:(int)page articleOnPageIdx:(int)articleOnPageIdx imgIdx:(int)imgIdx scale:(CGFloat)scale error:(NSError **)error;
- (NSData*)getArticleImageData:(NSString*)name error:(NSError **)error;

- (void) clean;

@end

NS_ASSUME_NONNULL_END
