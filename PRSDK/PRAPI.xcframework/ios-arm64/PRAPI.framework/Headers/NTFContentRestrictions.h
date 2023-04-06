//
//  NTFContentRestrictions.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 5/29/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NTFContentRestrictions : NSObject
@property (nonatomic, readonly) BOOL emailSharing;
@property (nonatomic, readonly) BOOL translate;
@property (nonatomic, readonly) BOOL listening;
@property (nonatomic, readonly) BOOL commenting;
@property (nonatomic, readonly) BOOL blogging;

+ (instancetype)restrictionsWithJSON:(NSDictionary *)json;
- (instancetype)initWithJSON:(NSDictionary *)json;

@end

NS_ASSUME_NONNULL_END
