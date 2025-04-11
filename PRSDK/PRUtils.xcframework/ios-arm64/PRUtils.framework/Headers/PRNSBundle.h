//
//  PRNSBundle.h
//  PRiphone
//
//  Created by Jackie Cane on 6/8/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <PRSyntacticSugar/PRMacros.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const kPRNibExtension;
extern NSString * const kPRStoryboardExtension;

@protocol PRNSBundleUpdatable <NSObject>
@optional
+ (nullable NSBundle *)updatedResourceBundle;

@end

typedef NS_ENUM(NSUInteger, PRPreferredBundle) {
    PRPreferredBundleNone = 0,
    PRPreferredBundleDefault,
    PRPreferredBundleCustom
};

/// Utility class for providing access to bundled resources.
@interface PRNSBundle : NSObject <PRNSBundleUpdatable>

+ (nullable NSBundle *)bundleForResource:(nullable NSString *)name
                                  ofType:(nullable NSString *)ext
                         preferredBundle:(nullable NSBundle *)preferredBundle;

+ (nullable NSString *)pathForResource:(nullable NSString *)name 
                                ofType:(nullable NSString *)ext
                       preferredBundle:(nullable NSBundle *)preferredBundle;

+ (nonnull UIStoryboard *)storyboardWithName:(nonnull NSString *)name
                             preferredBundle:(nullable NSBundle *)preferredBundle;

+ (nullable UINib *)nibWithName:(nonnull NSString *)name
                preferredBundle:(nullable NSBundle *)preferredBundle;

+ (nullable NSArray *)loadNibNamed:(NSString *)name
                             owner:(id)owner
                   preferredBundle:(nullable NSBundle *)preferredBundle;

@property (class, nonatomic, readonly) NSBundle *localizedStringsBundle;
@property (nullable, class, nonatomic, readonly) NSBundle *customResourcesBundle;
@property (nullable, class, nonatomic, strong) NSBundle *_updatedResourcesBundle;
@property (nullable, class, nonatomic, readonly) NSBundle *SFBundle;

@end

NS_ASSUME_NONNULL_END

#define _PRLStringWithComment(key, comment) [PRNSBundle localizedStringForKey:(key)]
#define _PRLString(key) _PRLStringWithComment(key, @"")

#define PRLocalizedString(...) __GET_MACRO2(__VA_ARGS__, _PRLStringWithComment, _PRLString)(__VA_ARGS__)
#define PRLocalizedPluralString(pluralStringKey, num) [PRNSBundle adjustedLocalizedPluralStringForKey:(pluralStringKey) number:(num)]

#import <PRUtils/PRNSBundle+LocalizedStrings.h>
