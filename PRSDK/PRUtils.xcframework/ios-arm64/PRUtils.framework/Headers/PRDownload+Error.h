//
//  PRDownload+Error.h
//  PRUtils
//
//  Created by Viacheslav Soroka on 12/11/20.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <PRUtils/PRDownload.h>
#import <PRUtils/PRErrorProvider.h>

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain const PRDownloadErrorDomain;
typedef NS_ERROR_ENUM(PRDownloadErrorDomain, PRDownloadError) {
    PRDownloadErrorCancel = 1,
    PRDownloadErrorNoUrl
};

@interface PRDownload (Error) <PRErrorProvider>

+ (NSError *)errorWithCode:(PRDownloadError)code description:(nullable NSString *)description;
- (NSError *)errorWithCode:(PRDownloadError)code description:(nullable NSString *)description;

@end

NS_ASSUME_NONNULL_END
