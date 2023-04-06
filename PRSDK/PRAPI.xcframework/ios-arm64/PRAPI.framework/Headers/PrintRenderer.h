//
//  PrintRenderer.h
//  PRiphone
//
//  Created by Vitali Bounine on 11/16/10.
//  Copyright 2010 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// The point size to use for the height of the text in the
// header and footer.
#define HEADER_FOOTER_TEXT_HEIGHT     9

// The left edge of text in the header will be offset from the left 
// edge of the imageable area of the paper by HEADER_LEFT_TEXT_INSET.
#define HEADER_LEFT_TEXT_INSET	      20

// The header and footer will be inset this much from the edge of the
// imageable area just to avoid butting up right against the edge that
// will be clipped.
#define HEADER_FOOTER_MARGIN_PADDING  5

// The right edge of text in the footer will be offset from the right 
// edge of the imageable area of the paper by FOOTER_RIGHT_TEXT_INSET.
#define FOOTER_RIGHT_TEXT_INSET	      20

@interface PrintRenderer : UIPrintPageRenderer {
}

@property (strong) NSString * header;
@property (strong) NSString * footer;

@end

@interface UIPrintInteractionController (PRPresenting)

- (void)presentInView:(UIView *)view fromBarButtonItem:(UIBarButtonItem *)barButtonItem;
- (void)printJobWithInfo:(UIPrintInfo *)printInfo
           printRenderer:(UIPrintPageRenderer *)pageRenderer
                delegate:(id<UIPrintInteractionControllerDelegate>)delegate
                  inView:(UIView *)view fromBarButtonItem:(UIBarButtonItem *)buttonItem;

@end
