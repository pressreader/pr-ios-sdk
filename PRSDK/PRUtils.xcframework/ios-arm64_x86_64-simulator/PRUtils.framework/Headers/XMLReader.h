//
//  XMLReader.h
//
//

#import <Foundation/Foundation.h>

extern NSString *const _Nonnull kXMLReaderTextNodeKey;

@interface XMLReader : NSObject

+ (nullable NSDictionary<NSString*, id> *)dictionaryForXMLData:(nonnull NSData *)data error:(NSError * _Nullable __autoreleasing * _Nullable)errorPointer;
+ (nullable NSDictionary<NSString*, id> *)dictionaryForXMLString:(nonnull NSString *)string error:(NSError * _Nullable __autoreleasing * _Nullable)errorPointer;

@end
