//
//  PRSchemeProvider.h
//  PRAPI
//
//  Created by Viacheslav Soroka on 22.07.2022.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRSchemeProvider : NSObject

- (void)loadConfigurationJSON:(NSArray<NSString *> *)names;

@property (nullable, nonatomic, strong) NSArray<NSDictionary<NSString *, id> *> *configurationJSON;

@end

NS_ASSUME_NONNULL_END
