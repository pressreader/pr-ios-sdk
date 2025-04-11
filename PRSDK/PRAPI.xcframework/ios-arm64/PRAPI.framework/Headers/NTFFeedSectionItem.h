//
//  NTFHomeFeedSectionItem.h
//  PressReader
//
//  Created by Oleg Stepanenko on Jun 02, 2017.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "NTFFeedItem+CoreDataClass.h"

#import "NTFSection.h"

@class NTFArticleItem;

typedef NSString * NTFFeedSectionItemId NS_TYPED_EXTENSIBLE_ENUM;

NS_ASSUME_NONNULL_BEGIN

extern NTFFeedSectionItemId const NTFFeedSectionItemIdTopnews;
extern NTFFeedSectionItemId const NTFFeedSectionItemIdTopic;

@interface NTFFeedSectionItem : NTFFeedItem <NTFSection>

+ (instancetype)sectionWithInfo:(NSDictionary *)info feed:(NTFFeed *)feed;

+ (NTFFeedSectionItemType)presentationTypeForSectionId:(NSString *)name;

- (BOOL)isEqualToSectionWithInfo:(NSDictionary *)json;

@property (nonatomic, readonly) NTFFeedSectionItemType presentationType;
@property (nonatomic, readonly) BOOL hasMoreContent;

@end

NS_ASSUME_NONNULL_END

#import "NTFFeedSectionItem+CoreDataProperties.h"
