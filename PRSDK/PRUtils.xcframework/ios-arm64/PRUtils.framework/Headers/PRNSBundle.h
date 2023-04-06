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
+ (NSBundle *)updatedResourceBundle;

@end

typedef NS_ENUM(NSUInteger, PRPreferredBundle) {
    PRPreferredBundleNone = 0,
    PRPreferredBundleDefault,
    PRPreferredBundleCustom
};

// This class-singleton is for providing access to resources inside 
// of the PressReaderResources bundle. It must be used instead 
// of [NSBundle mainBundle] standard instance for accessing to PressReader 
// app's specific table localized strings, JS, html, images, xib and other 
// resources.
// In case of no PressReaderResources.bundle this singleton 
// is initialized with [NSBundle mainBundle].
@interface PRNSBundle : NSBundle <PRNSBundleUpdatable>

+ (NSBundle *)instance;
+ (void)dismiss;

+ (nullable NSString *)localizedStringForKey:(nullable NSString *)key;
+ (nullable NSString *)localizedStringForKey:(nullable NSString *)key preferredBundle:(PRPreferredBundle)preferredBundle;
+ (nullable NSString *)specificLocalizedStringForKey:(NSString *)key;
+ (nullable NSString *)adjustedLocalizedPluralStringForKey:(nullable NSString *)pluralStringKey number:(NSUInteger)number;
+ (nullable NSBundle *)customResourcesBundle;
+ (nullable NSBundle *)bundleForResource:(nullable NSString *)name ofType:(nullable NSString *)ext;

+ (nullable NSString *)pathForResource:(nullable NSString *)name ofType:(nullable NSString *)ext;
+ (nonnull UIStoryboard *)storyboardWithName:(nonnull NSString *)name;
+ (nullable UINib *)nibWithName:(nonnull NSString *)name;
+ (nullable NSArray *)loadNibNamed:(NSString *)name owner:(id)owner;

+ (void)resetUpdatedBundle;

@property (nullable, class, nonatomic, strong) NSBundle *_updatedResourcesBundle;
@property (nullable, class, nonatomic, readonly) NSBundle *SFBundle;

@end

NS_ASSUME_NONNULL_END

#define _PRLStringWithComment(key, comment) [PRNSBundle localizedStringForKey:(key)]
#define _PRLString(key) _PRLStringWithComment(key, @"")

#define PRLocalizedString(...) __GET_MACRO2(__VA_ARGS__, _PRLStringWithComment, _PRLString)(__VA_ARGS__)
#define PRLocalizedPluralString(pluralStringKey, num) [PRNSBundle adjustedLocalizedPluralStringForKey:(pluralStringKey) number:(num)]
