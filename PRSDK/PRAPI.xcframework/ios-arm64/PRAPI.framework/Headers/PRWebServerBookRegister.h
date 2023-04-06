//
//  PRWebServerBookRegister.h
//  PRAPI
//
//  Created by Vitali Bounine on 2020-07-09.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

typedef NSData* _Nullable (^BookResourceDataProviderBlock)(NSString *resourcePath);

@protocol PRWebServerBookRegister<NSObject>

- (nullable NSURL *)registerBookWithId:(NSString *)bookId bookFileDirURL:(NSURL *)bookFileDirURL;
- (nullable NSURL *)registerBookWithId:(NSString *)bookId resourceDataProvider:(BookResourceDataProviderBlock)dataProvider;

- (void)unregisterBookWithId:(NSString *)bookId;

@end

NS_ASSUME_NONNULL_END

