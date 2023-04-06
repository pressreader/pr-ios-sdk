//
//  PRDateFormatter.h
//  PRComponents
//
//  Created by Jackie Cane on 6/7/12.
//  Copyright (c) 2012 Noname. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const kPRShortDateFormat;

@interface PRDateFormatter : NSObject

+ (instancetype)instance;

- (nullable NSDate *)dateFromISOFormattedString:(NSString *)dateString;
- (NSString *)ISOFormattedStringFromDate:(NSDate *)date;

- (nullable NSDate *)dateFromNDFormattedString:(NSString *)dateString;
- (nullable NSDate *)dateTimeFromNDFormattedString:(NSString *)dateString;
- (nullable NSDate *)dateTimeFromNDSentTimeFormattedString:(NSString *)dateString;

- (nullable NSDate *)dateFromCanonicalFormattedString:(NSString *)dateString;
- (NSString *)canonicalFormattedStringFromDate:(NSDate *)date;

- (nullable NSDate *)dateFromRFC3339FormattedString:(NSString *)dateString;
- (NSString *)rfc3339FormattedStringFromDate:(NSDate *)date;

- (nullable NSDate *)dateFromISO8601FormattedString:(NSString *)dateString;

- (nullable NSDate *)dateFromDictionaryValue:(id)item;
- (NSString *)dateToString:(NSDate *)date;
- (NSString*)dateToString:(NSDate *)date format:(NSString *)format;
- (nullable NSDate*)stringToDate:(NSString *)string format:(NSString *) format;
- (NSDate *)dateOnlyFromDate:(NSDate *)date;

@property (class, nonatomic, readonly) NSDateFormatter *serverDateFormatter;
@property (class, nonatomic, readonly) NSDateFormatter *appDateFormatter;
@property (class, nonatomic, readonly) NSDateFormatter *printDateFormatter;
@property (class, nonatomic, readonly) NSDateFormatter *iso8601DateFormatter;
@property (class, nonatomic, readonly) NSDateFormatter *canonicalDateFormatter;

@end

NS_ASSUME_NONNULL_END
