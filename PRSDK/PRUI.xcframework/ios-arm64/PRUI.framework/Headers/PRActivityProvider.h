//
//  PRActivityProvider.h
//  PRiphone
//
//  Created by Keith Choi on 2016-11-08.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

@import UIKit;

// Type1 (Default) : simple title text, URL, image
//extern UIActivityType const UIActivityTypeMessage;
//extern UIActivityType const UIActivityTypePostToTwitter;
//extern UIActivityType const UIActivityTypePostToFacebook;
extern UIActivityType const kExtensionShareLinkedIn;
extern UIActivityType const kExtensionSharePinterest;
extern UIActivityType const kExtensionShareGoogleplus;
extern UIActivityType const kExtensionShareFBMessenger;
extern UIActivityType const kExtensionShareSkype;
extern UIActivityType const kExtensionShareKakao;
extern UIActivityType const kExtensionShareMailOutlook;
extern UIActivityType const kExtensionShareMailYahoo;
extern UIActivityType const kExtensionShareTumblr;
extern UIActivityType const kExtensionShareTelegram;

// Type2 : simple full article text, no URL, image
extern UIActivityType const kExtensionShareNotes;
extern UIActivityType const kExtensionShareEvernote;
extern UIActivityType const kExtensionShareOnenote;
extern UIActivityType const kExtensionShareInstapaper;
extern UIActivityType const kExtensionShareReadQuick;

// Type3 : attributed summary text, no URL, image
//extern UIActivityType const UIActivityTypeMail;

// Type4 : simple summary text, no URL, image
extern UIActivityType const kExtensionShareMailGmail;
extern UIActivityType const kExtensionShareMailInbox;
extern UIActivityType const kExtensionShareMailSpark;

// Type5 : no text, URL, no image
extern UIActivityType const kCopyLinkToPasteboard;

@interface PRActivityProvider : NSObject
+ (NSArray<UIActivityType>*) activitiesWithURLSnippet;
+ (NSArray<UIActivityType>*) unreliableActivities;
@end

