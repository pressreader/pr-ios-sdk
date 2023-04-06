//
//  PRGenerateImageForPDFOperation.h
//  PRiphone
//
//  Created by Jackie Cane on 16/05/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

@import UIKit;

@class PRMyLibraryItem;
@class PDFDoc;
@protocol ReadingViewItem;

@interface PRGenerateImageForPDFOperation : NSOperation

+ (void)queueForReadingOperation:(PRGenerateImageForPDFOperation *)operation;

+ (instancetype)generateImageForPdfOperationWithItem:(NSObject<ReadingViewItem> *)item page:(NSUInteger)page imageSize:(CGSize)imageSize;

+ (void)queueOperation:(PRGenerateImageForPDFOperation *)operation;

+ (instancetype)createAndQueueGenerateImageForPdfOperationWithItem:(NSObject<ReadingViewItem> *)item
                                                              page:(NSUInteger)page
                                                        imageWidth:(CGFloat)imageWidth
                                                     queuePriority:(NSOperationQueuePriority)priority
                                    imageGenerationCompletionBlock:(void(^)(UIImage * image, BOOL storeToCache))imageGenerationCompletionBlock
                                                   completionBlock:(void(^)(void))completionBlock;

+ (instancetype)createAndQueueGenerateImageForPdfOperationWithItem:(NSObject<ReadingViewItem> *)item
                                                              page:(NSUInteger)page
                                                       imageHeight:(CGFloat)imageHeight
                                                     queuePriority:(NSOperationQueuePriority)priority
                                    imageGenerationCompletionBlock:(void(^)(UIImage * image, BOOL storeToCache))imageGenerationCompletionBlock
                                                   completionBlock:(void(^)(void))completionBlock;

+ (instancetype)createAndQueueGenerateImageForPdfOperationWithItem:(NSObject<ReadingViewItem> *)item
                                                              page:(NSUInteger)page
                                                         imageSize:(CGSize)imageSize
                                                     queuePriority:(NSOperationQueuePriority)priority
                                    imageGenerationCompletionBlock:(void(^)(UIImage * image, BOOL storeToCache))imageGenerationCompletionBlock
                                                   completionBlock:(void(^)(void))completionBlock;

- (instancetype)initWithItem:(NSObject<ReadingViewItem> *)item page:(NSUInteger)page imageSize:(CGSize)imageSize;

@property (copy) void (^imageGenerationCompletionBlock)(UIImage * image, BOOL storeToCache);

@property (nonatomic, strong) NSObject<ReadingViewItem> *item;
@property (nonatomic) NSUInteger page;
@property (nonatomic, strong) PDFDoc *pdfDoc;
@property (nonatomic) CGFloat pdfScale;
@property (nonatomic, strong) NSArray *expungeList;
@property (nonatomic) BOOL saveImageAfterGenerating;

@property (nonatomic) CGSize imageSize;

@end
