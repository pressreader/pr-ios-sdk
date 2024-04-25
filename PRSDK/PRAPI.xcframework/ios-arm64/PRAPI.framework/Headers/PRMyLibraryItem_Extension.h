//
//  PRMyLibraryItem_Extension.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 13.08.13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import "PRMyLibraryItem.h"

typedef NS_OPTIONS(NSInteger, mlProcessStatus) { inPdnProcess = 1<<0, inImgPackProcess = 1<<1, inImgPack2Process = 1<<2, inSmartProcess = 1<<3, inIndexProcess = 1<<4 };

@protocol HotSpotInfo;

@interface PRMyLibraryItem () {
    NSString* m_encryptionKey;

@public
    BOOL		isUpdateMessage;

    NSArray<NSString *> *m_pdnUrls;
    NSDictionary<NSValue *, NSArray<NSString *> *> *m_pageRangePdnUrls;
    NSArray<NSString *> *m_thumbUrls;
    NSArray<NSString *> *m_imgPackUrls;
    NSArray<NSString *> *m_imgPack2Urls;
    NSArray<NSString *> *m_smartUrls;
    NSArray<NSString *> *m_indexUrls;
    NSArray<PRPage *> *m_pages;
    NSArray<NSArray *> *m_sections;

    NSInteger		inProcess;
    NSInteger       progressTotalMask;
    NSMutableSet<NSValue *>   *_inRangeProcess;
    BOOL			inThumbProcess;
    BOOL			m_loaded;
    BOOL			m_requestingLicense;
    int				m_licenseRetry;
    dispatch_queue_t _parameterAccessQ;
}
@property(nonatomic, strong) PRDownload* dnlPdn;
@property(nonatomic, strong) NSMutableDictionary* dnlPdnRange;
@property(nonatomic, strong) PRDownload* dnlSmart;
@property(nonatomic, strong) PRDownload* dnlThumb;
@property(nonatomic, strong) PRDownload* dnlIndex;
@property(nonatomic, strong) PRDownload* dnlImgPack;
@property(nonatomic, strong) PRDownload* dnlImgPack2;

@property(nonatomic, strong) NSProgress* progress;

@property (nonatomic, strong) NSMutableDictionary *parameters;
@property (nonatomic, strong) NSMutableDictionary *itemParameters;
@property (nonatomic) BOOL isDealloc;

@property (nonatomic, strong) NSMutableSet *pageImageGenerationSet;
@property (nonatomic, strong) id semUnpack;
@property (nonatomic, strong) NSDate *messageDate;
@property (nonatomic, readonly) NSString *languageUnlocalized;
@property (nonatomic, readonly) NSString *countryUnlocalized;
@property (nonatomic, readonly) NSString *countryISOCode;
@property (nonatomic, copy, readwrite) NSString *MID;
@property (nonatomic, strong) id<HotSpotInfo> hotSpot;

- (BOOL)pdnDownloadedForPageRange:(NSRange)pageRange;
- (BOOL)pdnDownloadingForPageRange:(NSRange)pageRange;

@end
