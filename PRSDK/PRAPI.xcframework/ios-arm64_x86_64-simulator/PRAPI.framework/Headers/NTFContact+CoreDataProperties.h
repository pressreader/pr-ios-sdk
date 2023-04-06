//
//  NTFContact+CoreDataProperties.h
//  PR-API
//
//  Created by berec on 30/04/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//
//

#import "NTFContact+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface NTFContact (CoreDataProperties)

+ (NSFetchRequest<NTFContact *> *)fetchRequest;

@property (nullable, nonatomic, copy) NSString *facebook;
@property (nullable, nonatomic, copy) NSString *email;
@property (nullable, nonatomic, copy) NSString *google;
@property (nullable, nonatomic, copy) NSString *phone;
@property (nullable, nonatomic, copy) NSString *twitter;
@property (nullable, nonatomic, copy) NSString *website;
@property (nullable, nonatomic, retain) NTFChannelAccountItem *channel;

@end

NS_ASSUME_NONNULL_END
