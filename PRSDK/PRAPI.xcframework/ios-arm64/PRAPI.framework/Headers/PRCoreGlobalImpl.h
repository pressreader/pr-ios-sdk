
@import Foundation;

@interface PRCoreGlobal: NSObject
- (void) GetBookmarkUrl:(NSString*)artID page:(NSInteger)page issueId:(NSString*)issueId ai:(id)ai userData:(id)userData
                success:(void (^)(NSString* bookmarkLink))success
                failure:(void (^)(NSError * error))failure;

- (void) RequestShare:(NSString*)type artID:(NSString*)artID page:(NSInteger)page issueId:(NSString*)issueId ai:(id)ai accessToken:(NSString*)accessToken secret:(NSString*)secret comment:(NSString*)comment
          messageOnly:(BOOL)messageOnly userData:(id)userData
              success:(void (^)(void))success
              failure:(void (^)(NSError * error))failure;

@end
