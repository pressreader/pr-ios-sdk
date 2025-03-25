//
//  PRNSBundle+LocalizedStrings.h
//  PRUtils
//
//  Created by Ivan Berezin on 17/06/2024.
//  Copyright © 2024 NewspaperDirect. All rights reserved.
//

#import <PRUtils/PRNSBundle.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRNSBundle (LocalizedStrings)

+ (nullable NSString *)localizedStringForKey:(nullable NSString *)key;

+ (nullable NSString *)localizedStringForKey:(nullable NSString *)key
                             preferredBundle:(PRPreferredBundle)preferredBundle;

+ (nullable NSString *)specificLocalizedStringForKey:(NSString *)key;

+ (nullable NSString *)adjustedLocalizedPluralStringForKey:(nullable NSString *)pluralStringKey
                                                    number:(NSUInteger)number;

@end

NS_ASSUME_NONNULL_END
