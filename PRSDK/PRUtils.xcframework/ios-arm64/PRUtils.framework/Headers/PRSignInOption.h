//
//  PRSignInOption.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 3/1/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * PRAuthProviderName NS_TYPED_ENUM;
extern PRAuthProviderName const PRAuthProviderNameFacebook;
extern PRAuthProviderName const PRAuthProviderNameTwitter;
extern PRAuthProviderName const PRAuthProviderNameGoogle;
extern PRAuthProviderName const PRAuthProviderNameApple;
extern PRAuthProviderName const PRAuthProviderNameEmail;
extern PRAuthProviderName const PRAuthProviderNameLibrary;
extern PRAuthProviderName const PRAuthProviderNamePiano;
extern PRAuthProviderName const PRAuthProviderNameGigya;
extern PRAuthProviderName const PRAuthProviderNameAuth0;
extern PRAuthProviderName const PRAuthProviderNameOAuth2;

@interface PRSignInOption : NSObject

+ (instancetype)authWithName:(PRAuthProviderName)name
              offerForSignIn:(BOOL)offerForSignIn
                   isPrimary:(BOOL)isPrimary
                   hasBanner:(BOOL)hasBanner;

- (instancetype)initWithName:(PRAuthProviderName)name
              offerForSignIn:(BOOL)offerForSignIn
                   isPrimary:(BOOL)isPrimaryh
                   hasBanner:(BOOL)hasBanner;

- (instancetype)initWithName:(PRAuthProviderName)name displayName:(nullable NSString *)displayName;
- (instancetype)initWithName:(PRAuthProviderName)name;

@property (nonatomic, readonly) PRAuthProviderName name;
@property (nonatomic, readonly) BOOL offerForSignIn;
@property (nonatomic, readonly) BOOL isPrimary;
@property (nonatomic, readonly) BOOL hasBanner;

@property (nullable, nonatomic, strong, readonly) NSString *displayName;
@property (nonatomic, readonly) NSString *displayNameEx;
@property (nullable, nonatomic, readonly) NSString *iconURL;

@end

NS_ASSUME_NONNULL_END
