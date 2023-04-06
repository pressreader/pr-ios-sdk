//
//  ReadingMapFrame.h
//  PRiphone
//
//  Created by Vitali Bounine on 11/8/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PRSubscription;

NS_ASSUME_NONNULL_BEGIN

@protocol ReadingMapOperations <NSObject>

// Reading map support
- (void) startReadingMapFrame;
- (void) suspendReadingWithAction:(nullable NSString *)actionType target:(nullable NSString *)targetId;
- (nullable NSString *)currentActionType;
- (void) resumeReading;
- (void) finalizeReadingMapFrame;

@end

@interface ReadingMapFrame : NSObject

@property (nonatomic, retain) PRSubscription *subs;

- (instancetype)init NS_UNAVAILABLE;

- (nullable instancetype) initWithType:(NSString *)type;
+ (nullable instancetype) readingMapFrameWithType:(NSString *)type;

- (void) addItem:(NSDictionary *)item forItemType:(NSString *)type;

- (void) suspendReadingWithAction:(nullable NSString *)actionType target:(nullable NSString *)targetId;
- (nullable NSString *)currentActionType;
- (nullable NSString *)currentActionTarget;
- (void) resumeReading;
- (void) finalizeReading;

@end

@interface ReadingMapPageFrame : ReadingMapFrame

+ (instancetype) readingMapPageFrameWithIssueId:(NSString *)issueId;
- (instancetype) initWithIssueId:(NSString *)issueId;

- (void) addPage:(NSUInteger)pageNo
            left:(float)left
             top:(float)top
           width:(float)width
          height:(float)height
           scale:(NSInteger)scale
            zoom:(float)zoom
  visibilityRate:(float)visibilityRate;

- (void) addPage:(NSDictionary *)pageDict;

@end

@interface ReadingMapArticleFrame : ReadingMapFrame

+ (instancetype) readingMapArticleFrameWithType:(NSString *)type;
+ (instancetype) readingMapArticleFrame;

- (void) addArticle:(NSString *)articleID
           expanded:(BOOL)expanded
  visibleAreaOffset:(float)visibleAreaOffset
    visibleAreaSize:(float)visibleAreaSize
     visibilityRate:(float)visibilityRate
     sourceLanguage:(nullable NSString *)sourceLanguage
    readingLanguage:(nullable NSString *)readingLanguage
           enriches:(nullable NSDictionary *)enriches;

- (void) addArticle:(NSDictionary *)articleDict;

@property (nonatomic) BOOL analizeNumberOfReadArticles;

@end

NS_ASSUME_NONNULL_END
