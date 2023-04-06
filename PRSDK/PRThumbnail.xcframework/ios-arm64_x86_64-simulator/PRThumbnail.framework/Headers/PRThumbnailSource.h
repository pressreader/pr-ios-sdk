//
//  PRThumbnailSource.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 01.02.13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import "PRThumbnailObject.h"

extern CGSize const kThumbnailSourceImageSizeNewsstand;

typedef NS_ENUM(NSInteger, PRThumbnailSourceType) {
    PRThumbnailSourceTypeNotDefined = 0,
    PRThumbnailSourceTypeNewspaper,
    PRThumbnailSourceTypeMagazine,
};

typedef NS_ENUM(NSInteger, PRThumbnailSourceSizeType) {
    PRThumbnailSourceSizeTypeNotDefined = -1,
    PRThumbnailSourceSizeTypeMicro = 0,
    PRThumbnailSourceSizeTypeMini,
    PRThumbnailSourceSizeTypeSmall,
    PRThumbnailSourceSizeTypeLibrary,
    PRThumbnailSourceSizeTypeNewsstand,
    /// Extreme size that represents issue in featured section and order screen on iPad.
    PRThumbnailSourceSizeTypeMax    
};

NS_ASSUME_NONNULL_BEGIN

@class PRThumbnailSource;

@protocol PRThumbnailSourceDelegate <NSObject>

- (void)updateLatestDownloadedInfoWithThumbnail:(PRThumbnailSource *)thumbnail;
- (PRThumbnailSource *)thumbnailWithThumbnail:(PRThumbnailSource *)thumbnail size:(CGSize)size;

@end

@interface PRThumbnailSource : PRThumbnailObject
@property (nonatomic, retain, readonly) NSString *CID;
@property (nonatomic, retain, readonly) NSDate *date;
@property (nonatomic, readonly) NSInteger issueVersion;
@property (nonatomic, readonly) NSString *expungeVersion;
@property (nonatomic, readonly) int pageNo;
@property (nonatomic, getter = isSetup) BOOL setup;
@property (nonatomic, copy) NSString * accessTicket;
@property (nonatomic) PRThumbnailSourceType type;

+ (NSString *)buildKeyWithCID:(NSString *)CID
                    issueDate:(NSDate *)date
                         size:(CGSize)size
                       square:(BOOL)square
                 issueVersion:(NSInteger)issueVersion
               expungeVersion:(NSString *)expungeVersion
                       pageNo:(int)pageNo;

+ (NSString *)buildKeyWithCID:(NSString *)CID
                    issueDate:(NSDate *)date
                         size:(CGSize)size
                 issueVersion:(NSInteger)issueVersion
               expungeVersion:(NSString *)expungeVersion;

- (instancetype)initWithKey:(NSString *)key info:(PRThumbnailInfo *)info delegate:(nonnull id<PRThumbnailSourceDelegate>)delegate;
- (instancetype)initWithKey:(NSString *)key info:(PRThumbnailInfo *)info NS_UNAVAILABLE;

- (void)setupWithCID:(NSString *)CID
           issueDate:(NSDate *)date
               color:(UIColor *)color
                type:(PRThumbnailSourceType)type
                size:(CGSize)size
              square:(BOOL)square
        issueVersion:(NSInteger)issueVersion
      expungeVersion:(NSString *)expungeVersion
              pageNo:(int)pageNo;

@end

@interface PRThumbnailSource (/*Deprecated*/)
+ (CGSize)sizeOfImageForSizeType:(PRThumbnailSourceSizeType)sizeType;
+ (CGSize)goodEnoughSize;
@end

NS_ASSUME_NONNULL_END
