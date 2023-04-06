//
//  ReadingViewItem.h
//  PRAPI
//
//  Created by Vitali Bounine on 2020-11-04.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PRTitleObject.h"
@import PRConfiguration.PRConfig_ScreenshotProtection;

NS_ASSUME_NONNULL_BEGIN

@class PRSmartObject;
@class PRPage;
@class PRAccountItem;
@class PRSubscription;
@class PDFDoc;
@class PdfPrintRendererPage;

@protocol ReadingViewItem <PRCatalogItem, OpenedItem>
@property NSUInteger viewerPage;

@property (readonly) NSUInteger numberOfPages;
@property (readonly) NSUInteger pagesCount;
@property (readonly) BOOL rightToLeft;
@property (readonly) BOOL isPurchaseAdvise;
@property (readonly) BOOL isMarkedToDeleteContent;

- (BOOL) isEqualToItem:(NSObject<ReadingViewItem> *)mli NS_SWIFT_NAME(isEqual(to:));

- (BOOL)done;
- (BOOL)pdnDone;

- (BOOL)pdnDownloadedForPage:(NSUInteger)pageNumber;
- (BOOL)printingDisabled;
- (BOOL)pagePrintingDisabled;
- (BOOL)issuePrintingEnabled;

- (nullable PRPage*)getPage:(NSUInteger) pageNumber;

- (void)saveToPersistentStore;

- (NSString*) encryptionKey;

- (nullable NSProgress *) progress;
- (nullable NSProgress *) pdnProgress;
- (nullable NSProgress *) pdnProgressForPage:(NSUInteger)page;

- (void) recordIssuePrint;
- (void) recordPagePrint:(NSUInteger)numberOfPages;

- (nullable PDFDoc *)pdfDoc;
- (nullable PDFDoc *)pdfDocForPage:(NSUInteger)pageNo;
- (nullable PDFDoc *)pdfDocForPage:(NSUInteger)pageNo loadPdfIfNotAvailable:(BOOL)loadPdfIfNotAvailable error:(NSError **)error;
- (nullable UIImage *) imageFromPdfPage:(NSUInteger)pageNo
                       pdfRect:(CGRect)pdfRect
                     imageSize:(CGSize)imageSize
            contentScaleFactor:(CGFloat)contentScale
                         error:(NSError *_Nullable __autoreleasing *)error;


- (UIColor *)paperColor;
- (BOOL)printingAsBitmap;

- (NSString*)defaultImagePathForPage:(NSUInteger)page;
- (nullable NSString*)imagePathForPage:(NSUInteger)page width:(CGFloat)width useDefaultIfNotExist:(BOOL)useDefault;
- (nullable NSString*)imagePathForPage:(NSUInteger)page width:(CGFloat)width defaultIfNotExist:(inout BOOL *)pUseDefault;
- (NSString*)fgImagePathForPath:(NSString *)path;
@end

@protocol ReadingViewItemPrintProtocol <NSObject>

- (NSArray<PdfPrintRendererPage *> *) printingPagesWithNumbers:(NSArray<NSNumber *> *)pageNumbers;
- (NSString *)printHeader;

- (void) printAllPagesUsingBookletMode:(BOOL)bookletMode inView:(nullable UIView *)view fromBarButtonItem:(nullable UIBarButtonItem *)barButtonItem;

@end

@protocol ReadingViewItemScreenshotProtectionProtocol <NSObject>

@property (nonatomic, readonly) PRScreenshotProtectionLevel screenshotProtectionLevel;

@property (nonatomic, readonly) BOOL requiresScreenshotProtection;
@property (nonatomic, readonly) BOOL shouldPresentScreenshotWarning1;
@property (nonatomic, readonly) BOOL shouldPresentScreenshotWarning2;
@property (nonatomic, readonly) BOOL shouldBlockScreenshot;

@property (nonatomic, readonly) NSInteger screenshotCounter;
- (void) incrementScreenshotCounter;

@end

@protocol PRSmartLayoutItem <NSObject>

- (void)processSmart;

@property (nullable, nonatomic, readonly) PRSmartObject *smart;
@property (nullable, nonatomic, readonly) PRSmartObject *processedSmart;
@property (nonatomic, readonly) BOOL isSmartDone;
@property (nonatomic, readonly) BOOL isSmartUpdated;

@end

NS_ASSUME_NONNULL_END
