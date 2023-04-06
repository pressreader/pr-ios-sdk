//
//  NTFArticleCompactView_Constants.h
//  PRUI
//
//  Created by berec on 21/01/2021.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

#ifndef NTFArticleCompactView_Constants_h
#define NTFArticleCompactView_Constants_h

typedef NS_ENUM(unsigned int, NTFArticleCompactViewStyle) {
    NTFArticleCompactViewStyleLarge = 0,
    NTFArticleCompactViewStyleLargeTwoColumns,
    NTFArticleCompactViewStyleLargeThreeColumns,
    NTFArticleCompactViewStyleWide,
    NTFArticleCompactViewStyleWideNoImage,
    NTFArticleCompactViewStyleCompact,
    NTFArticleCompactViewStyleCompactHorizontalPlusOne,
    NTFArticleCompactViewStyleCompactHorizontalPlusOneWide,
    NTFArticleCompactViewStyleCompactHorizontalPlusOneWideReversed,
    NTFArticleCompactViewStyleCompactHorizontalPlusTwo,
    NTFArticleCompactViewStyleSubcompact,
    NTFArticleCompactViewStyleSubsubcompact,
    NTFArticleCompactViewStyleMini
};

typedef NS_ENUM(unsigned int, NTFArticleCompactViewBylineStyle) {
    NTFArticleCompactViewBylineStyleMastheadAndDate = 0,
    NTFArticleCompactViewBylineStyleTraditional
};

typedef NS_OPTIONS(unsigned int, NTFArticleCompactTextualViewOption) {
    NTFArticleCompactTextualViewOptionNone = 0,
    NTFArticleCompactTextualViewOptionHideSimilarStories = 1 << 0,
    NTFArticleCompactTextualViewOptionHideMasthead = 1 << 1,
    NTFArticleCompactTextualViewOptionHideBodyText = 1 << 2,
    NTFArticleCompactTextualViewOptionHighlight = 1 << 3,
    NTFArticleCompactTextualViewOptionHideTags = 1 << 4,
    NTFArticleCompactTextualViewOptionHideMetaInfo = 1 << 5,
    NTFArticleCompactTextualViewOptionDisplayAllText = 1 << 6,
    /// Fixes corrupted article body text due to insufficient height in complex multi-column layout.
    NTFArticleCompactTextualViewOptionJoinTitleAndBodyInSingleLabel = 1 << 7,
    NTFArticleCompactTextualViewOptionHideDate = 1 << 8,
    NTFArticleCompactTextualViewOptionTitleFontSemibold = 1 << 9
};

#endif /* NTFArticleCompactView_Constants_h */
