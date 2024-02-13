//
//  PRMyLibraryItem+Print.h
//  PR-API
//
//  Created by Vitali Bounine on 2018-10-05.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "PRMyLibraryItem.h"

NS_ASSUME_NONNULL_BEGIN

@class PdfPrintRendererPage;

@interface PRMyLibraryItem (Print) <ReadingViewItemPrintProtocol>

- (NSArray<PdfPrintRendererPage *> *)printingPagesWithNumbers:(NSArray<NSNumber *> *)pageNumbers;
- (NSString *)printHeader;

- (void)printAllPagesUsingBookletMode:(BOOL)bookletMode
                               inView:(nullable UIView *)view
                    fromBarButtonItem:(nullable UIBarButtonItem *)barButtonItem;
- (nullable NSString *)printFooterStringIncludingDeviceAccount:(BOOL)include;
@property (nonatomic, readonly) NSInteger maxNumberOfPagesToPrint;

@end

NS_ASSUME_NONNULL_END
