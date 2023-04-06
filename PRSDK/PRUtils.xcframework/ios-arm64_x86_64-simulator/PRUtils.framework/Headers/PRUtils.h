//
//  PRUtils.h
//  PRUtils
//
//  Created by berec on 20/08/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <PRUtils/NSObject+PerformSelector.h>
#import <PRUtils/NSObject+KVO.h>
#import <PRUtils/NSObject+Notification.h>
#import <PRUtils/NSObject+Unwrap.h>
#import <PRUtils/NSObject+Normalising.h>

#import <PRUtils/NSNotificationCenter+ConvenienceAPI.h>
#import <PRUtils/NSNotificationCenter+PRExtension.h>
#import <PRUtils/NSNotificationCenter+Auxiliary.h>

#import <PRUtils/PRDownload.h>
#import <PRUtils/PRDownload+Error.h>

#import <PRUtils/PRFunctions.h>

#import <PRUtils/NSString+Extended.h>
#import <PRUtils/NSString+NumberOfLines.h>
#import <PRUtils/NSString+BoundingRect.h>
#import <PRUtils/NSString+Validation.h>
#import <PRUtils/NSString+Encoding.h>
#import <PRUtils/NSString+Bits.h>
#import <PRUtils/NSString+Search.h>
#import <PRUtils/PRStringExtendedByRegEx.h>

#import <PRUtils/NSError+HTTPURLResponse.h>
#import <PRUtils/NSError+Initialization.h>
#import <PRUtils/NSError+InvalidParameter.h>
#import <PRUtils/PRErrorProvider.h>

#import <PRUtils/NSArray+Extended.h>
#import <PRUtils/NSArray+SortedInsert.h>
#import <PRUtils/NSArray+Search.h>

#import <PRUtils/NSData+String.h>

#import <PRUtils/NSURL+Extended.h>
#import <PRUtils/NSURL+Parsing.h>

#import <PRUtils/XMLReader.h>
#import <PRUtils/SPNode.h>
#import <PRUtils/SPXML.h>

#import <PRUtils/PRUnzip.h>
#import <PRUtils/SSZipArchive.h>
#include <PRUtils/zip.h>
#include <PRUtils/ioapi.h>
#include <PRUtils/crypt.h>
#include <PRUtils/mztools.h>

#import <PRUtils/UIColor+PRExtensions.h>
#import <PRUtils/UIColor+Gradient.h>

#import <PRUtils/PRCanonicalDateFormatter.h>
#import <PRUtils/ISO8601DateFormatter.h>
#import <PRUtils/PRDateFormatter.h>

#import <PRUtils/NSDictionary+Parsing.h>
#import <PRUtils/NSDictionary+CIKey.h>
#import <PRUtils/NSDictionaryCIWrapper.h>

#import <PRUtils/UIImage+Bundle.h>
#import <PRUtils/UIImage+Video.h>

#import <PRUtils/UIScreen+Size.h>

#import <PRUtils/NSAttributedString+Markup.h>
#import <PRUtils/NSAttributedString+Extended.h>

#import <PRUtils/PRBlockHandlersQueue.h>

#import <PRUtils/PRCache.h>
#import <PRUtils/PRCountableObject.h>
#import <PRUtils/PRDebouncer.h>
#import <PRUtils/PRForwarder.h>
#import <PRUtils/PRLIFOOperationQueue.h>

#import <PRUtils/PRNSBundle.h>
#import <PRUtils/UINib+Bundle.h>

#import <PRUtils/PRsqliteDb.h>

#import <PRUtils/PlistUtil.h>
#import <PRUtils/PRExceptionUtil.h>

#import <PRUtils/CCCryptor.h>
#import <PRUtils/CryptoData.h>
#import <PRUtils/NSData+Hash.h>

#import <PRUtils/UIDevice+Extended.h>

#import <PRUtils/NSKeyedArchiver+Convenience.h>
#import <PRUtils/NSKeyedUnarchiver+Convenience.h>

#import <PRUtils/PRNotification.h>

#import <PRUtils/NSLocale+PRExtensions.h>

#import <PRUtils/PRDynamicSubclassing.h>

#import <PRUtils/PRMacAddress.h>
#import <PRUtils/UIDevice+Info.h>

#import <PRUtils/NSData+Base64.h>

#import <PRUtils/PRReachability.h>

#import <PRUtils/PRSharedPreferences.h>
#import <PRUtils/PRSharedPreferences+ResourceServiceURLs.h>

#import <PRUtils/PRConcurrentOperation.h>

#import <PRUtils/PRSignInOption.h>

#import <PRUtils/PRError.h>

#import <PRUtils/PRSynchronizedMutableArray.h>
#import <PRUtils/PRSynchronizedMapTable.h>

#import <PRUtils/NSAttributedString+HTML.h>
#import <PRUtils/NSString+XML.h>
#import <PRUtils/UIColor+Text.h>
#import <PRUtils/UIFont+Pixel.h>
#import <PRUtils/UIImage+animatedGIF.h>
#import <PRUtils/UIImage+BarButtonSystemItem.h>
#import <PRUtils/UIImage+Text.h>
#import <PRUtils/UIImage+FontIcons.h>
#import <PRUtils/UIImageView+Alignment.h>

//! Project version number for PRUtils.
FOUNDATION_EXPORT double PRUtilsVersionNumber;

//! Project version string for PRUtils.
FOUNDATION_EXPORT const unsigned char PRUtilsVersionString[];
