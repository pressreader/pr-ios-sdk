//
//  ShareComponent.h
//  PRiphone
//
//  Created by Oleg Bilozor on 11-02-02.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MessageUI/MessageUI.h>

@class PRSmartArticle;
@class NTFArticleItem;
@class PRAccountItem;
@class PRMyLibraryItem;

NS_ASSUME_NONNULL_BEGIN

extern NSString * const SHARE_TYPE_EMAIL;
extern NSString * const SHARE_TYPE_TWITTER;
extern NSString * const SHARE_TYPE_FACEBOOK;
extern NSString * const SHARE_TYPE_INSTAPAPER;
extern NSString * const SHARE_TYPE_EVERNOTE;

@interface PRShareComponent : NSObject

- (instancetype)initWithViewController:(UIViewController*)presentingViewController ai:(PRAccountItem*)ai issue:(NSDictionary*)issue article:(PRSmartArticle *)article isoLanguage:(NSString *)language;
- (instancetype)initWithViewController:(UIViewController*)presentingViewController mli:(PRMyLibraryItem *)mli page:(NSInteger)pageNo;
- (instancetype)initWithViewController:(UIViewController*)presentingViewController mli:(PRMyLibraryItem *)mli pages:(NSSet<NSNumber *> *)pages;
- (instancetype)initWithViewController:(UIViewController*)presentingViewController account:(PRAccountItem *)account;

- (void)shareTo:(NSString *)shareType;
- (void)shareTo:(NSString *)shareType params:(nullable NSDictionary *)params;

@property (nonatomic, copy, readonly) NSString* shareType;
@property (nonatomic, copy) NSString* commentKey;
@property (nonatomic, copy, readonly) NSString* articleText;
@property (nonatomic, copy, readonly) NSString* articleHTML;
@property (nonatomic, copy, readonly) NSString* articleId;
@property (nonatomic, strong) NSString* sharingUrl;
@property (nonatomic, strong) NSString* sharingCommentUrl;

@property (nonatomic, strong, readonly) PRSmartArticle *article;
@property (nonatomic, strong) PRMyLibraryItem *mli;
@property (nullable, nonatomic, strong) NTFArticleItem *item;

@property (nonatomic, readonly) NSString* CID;
@property (nonatomic, readonly) NSString* issueId;
@property (nonatomic, readonly) NSString* issueDate;
@property (nonatomic, readonly) NSString* title;

@end

NS_ASSUME_NONNULL_END
