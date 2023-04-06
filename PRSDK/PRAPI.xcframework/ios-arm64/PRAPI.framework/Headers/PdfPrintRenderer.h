//
//  PdfPrintRenderer.h
//  PRiphone
//
//  Created by Vitali Bounine on 11/16/10.
//  Copyright 2010 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PrintRenderer.h"

@class PDFDoc;

@interface PdfPrintRendererPage : NSObject
@property (nonatomic, readonly) NSUInteger pageNo;
@property (nonatomic, readonly) CGRect bounds;
@property (nonatomic, copy, readonly) NSArray *excludeRects;
@property (nonatomic) BOOL mainPage;
+ (instancetype)page:(NSUInteger)pageNo withBounds:(CGRect)bounds excludeRects:(NSArray *)rects mainPage:(BOOL)isMainPage;
- (instancetype)init:(NSUInteger)pageNo withBounds:(CGRect)bounds excludeRects:(NSArray *)rects mainPage:(BOOL)isMainPage;
@end

@interface PdfPrintRenderer : PrintRenderer

+ (instancetype)pdfPrintRendererWithPdf:(PDFDoc *)pdfDoc
                                  pages:(NSArray<PdfPrintRendererPage *> *)printPages
                                 header:(NSString *)header
                                 footer:(NSString *)footer
                     useBitmapRendering:(BOOL)printingAsBitmap
                             doublePage:(BOOL)doublePageMode
                          addWatermarks:(BOOL)isWatermarked;

@property (nonatomic, strong) PDFDoc *pdfDoc;
@property (nonatomic, copy) NSArray<PdfPrintRendererPage *> *pages;
@property (nonatomic) BOOL isDoublePage;
@property (nonatomic) BOOL isWatermarked;
@property BOOL useBitmapRendering;

- (UIPrintInfoOrientation) preferredOrientation;
- (UIPrintPaper *) choosePaper:(NSArray<UIPrintPaper *> *)paperList;
@end
