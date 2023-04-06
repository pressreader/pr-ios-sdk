//
//  PDFDoc.h
//  PRiphone
//
//  Created by Vitali Bounin on 12/5/11.
//  Copyright (c) 2011 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface PDFDoc : NSObject

// used for reading view in main and background generation threads
+ (instancetype) sharedPDFDoc;
// used for singele mli image generation operations in background threads
+ (instancetype) PDFDoc;
+ (nullable instancetype) pdfDocWithPath:(NSString *)path password:(NSString *)password startingPageNumber:(NSInteger)startingPageNumber error:(NSError *_Nullable __autoreleasing *)error;

@property(nonatomic, readonly) NSUInteger numberOfPages;
@property(nonatomic, readonly) NSUInteger startingPageNumber;
@property(nonatomic, readonly) NSUInteger lastPageNumber;

- (id) openPdf:(NSString *)path password:(NSString *)password error:(NSError *_Nullable __autoreleasing *)error;
- (void) close;
- (BOOL) reopen;

- (BOOL) isOpen;
- (NSUInteger) numberOfPagesInDoc:(id)docID error:(NSError *_Nullable __autoreleasing *)error;
- (CGRect) pdfDocID:(nullable id)docID cropBoxForPage:(NSUInteger)pageNum error:(NSError *_Nullable __autoreleasing *)error;
- (CGRect) cropBoxForPage:(NSUInteger)pageNum error:(NSError *_Nullable __autoreleasing *)error;
- (BOOL) pdfDocID:(nullable id)docID renderPage:(NSUInteger)pageNum inContext:(CGContextRef)context error:(NSError * __autoreleasing *)error;
- (id) docID;

/* **************************************
 * General pdf drawing method
 * pdfRect can be CGRectNull: renders whole page (crop box)
 * viewRect can be CGRectNull: uses scaled pdfRect with zero origin
 * if viewRect is not null, scale can be zero to use aspect fit mode
 */
- (BOOL) drawPage:(NSUInteger)pageNum
          pdfRect:(CGRect)pdfRect
        inContext:(CGContextRef)context
       inViewRect:(CGRect)viewRect
         pdfScale:(CGFloat)scale
       paperColor:(CGColorRef)bgColor
     clippedRects:(NSArray *)clippedRects
   flipUpsideDown:(BOOL)flip
            error:(NSError *_Nullable __autoreleasing *)error;
- (BOOL) pdfDocID:(nullable id)docID
         drawPage:(NSUInteger)pageNum
          pdfRect:(CGRect)pdfRect
        inContext:(CGContextRef)context
       inViewRect:(CGRect)viewRect
         pdfScale:(CGFloat)scale
       paperColor:(CGColorRef)bgColor
     clippedRects:(nullable NSArray *)clippedRects
   flipUpsideDown:(BOOL)flip
            error:(NSError *_Nullable __autoreleasing *)error;

- (nullable UIImage *) generateImageFromPdfDoc:(nullable id)docID
                                 page:(NSUInteger)pageNo
                              pdfRect:(CGRect)pdfRect
                             pdfScale:(CGFloat)scale
                   contentScaleFactor:(CGFloat)contentScale
                           paperColor:(CGColorRef)bgColor
                         clippedRects:(nullable NSArray *)clippedRects
                                error:(NSError *_Nullable __autoreleasing *)error;

- (nullable UIImage *) generateImageFromPdfDoc:(nullable id)docID
                                 page:(NSUInteger)pageNo
                              pdfRect:(CGRect)pdfRect
                                width:(CGFloat)width
                   contentScaleFactor:(CGFloat)contentScale
                           paperColor:(CGColorRef)bgColor
                         clippedRects:(nullable NSArray *)clippedRects
                                error:(NSError *_Nullable __autoreleasing *)error;

- (nullable UIImage *) generateImageFromPdfDoc:(nullable id)docID
                                 page:(NSUInteger)pageNo
                              pdfRect:(CGRect)pdfRect
                               height:(CGFloat)height
                   contentScaleFactor:(CGFloat)contentScale
                           paperColor:(CGColorRef)bgColor
                         clippedRects:(nullable NSArray *)clippedRects
                                error:(NSError *_Nullable __autoreleasing *)error;

- (nullable UIImage *) generateImageFromPdfDoc:(nullable id)docID
                                 page:(NSUInteger)pageNo
                              pdfRect:(CGRect)pdfRect
                                 size:(CGSize)size
                   contentScaleFactor:(CGFloat)contentScale
                           paperColor:(CGColorRef)bgColor
                         clippedRects:(nullable NSArray *)clippedRects
                                error:(NSError *_Nullable __autoreleasing *)error;

- (nullable UIImage *) generateImageFromPdfDoc:(nullable id)docID
                                 page:(NSUInteger)pageNo
                              pdfRect:(CGRect)pdfRect
                                scale:(CGFloat)scale
                   contentScaleFactor:(CGFloat)contentScale
                           paperColor:(CGColorRef)bgColor
                         clippedRects:(nullable NSArray *)clippedRects
                                error:(NSError *_Nullable __autoreleasing *)error;

#pragma mark -

- (nullable UIImage *) generateImageFromPdfPath:(NSString *)path
                              password:(NSString *)password
                                  page:(NSUInteger)pageNo
                               pdfRect:(CGRect)pdfRect
                                 width:(CGFloat)width
                    contentScaleFactor:(CGFloat)contentScale
                            paperColor:(CGColorRef)bgColor
                          clippedRects:(nullable NSArray *)clippedRects
                                 error:(NSError *_Nullable __autoreleasing *)error;

- (nullable UIImage *) generateImageFromPdfPath:(NSString *)path
                              password:(NSString *)pwd
                                  page:(NSUInteger)pageNo
                               pdfRect:(CGRect)pdfRect
                                height:(CGFloat)height
                    contentScaleFactor:(CGFloat)contentScale
                            paperColor:(CGColorRef)bgColor
                          clippedRects:(nullable NSArray *)clippedRects
                                 error:(NSError *_Nullable __autoreleasing *)error;

- (nullable UIImage *) generateImageFromPdfPath:(NSString *)path
                              password:(NSString *)pwd
                                  page:(NSUInteger)pageNo
                               pdfRect:(CGRect)pdfRect
                                  size:(CGSize)size
                    contentScaleFactor:(CGFloat)contentScale
                            paperColor:(CGColorRef)bgColor
                          clippedRects:(nullable NSArray *)clippedRects
                                 error:(NSError *_Nullable __autoreleasing *)error;

- (nullable UIImage *) generateImageFromPdfPath:(NSString *)path
                              password:(NSString *)pwd
                                  page:(NSUInteger)pageNo
                               pdfRect:(CGRect)pdfRect
                                 scale:(CGFloat)scale
                    contentScaleFactor:(CGFloat)contentScale
                            paperColor:(CGColorRef)bgColor
                          clippedRects:(nullable NSArray *)clippedRects
                                 error:(NSError *_Nullable __autoreleasing *)error;

- (CGPDFPageRef) _pdfPage:(NSUInteger)pageNum error:(NSError *_Nullable __autoreleasing *)error;

@end

@class PdfPrintRenderer, PdfPrintRendererPage;

@interface PDFDoc (Printing)

- (NSArray<NSNumber *> *)bookletReorderedPageNumbers;
- (NSArray<NSNumber *> *)pageNumbers;

- (void)printPages:(NSArray<PdfPrintRendererPage *> *)printPages
            header:(nullable NSString *)header
            footer:(nullable NSString *)footer
       doublePages:(BOOL)doublePageMode
useBitmapRendering:(BOOL)printingAsBitmap
        waterMarks:(BOOL)needWaterMarks
            inView:(nullable UIView *)view
 fromBarButtonItem:(nullable UIBarButtonItem *)barButtonItem;

@end

NS_ASSUME_NONNULL_END
