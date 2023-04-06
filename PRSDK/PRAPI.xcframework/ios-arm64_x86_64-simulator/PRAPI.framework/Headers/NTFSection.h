//
//  NTFSection.h
//  PR-API
//
//  Created by berec on 09/10/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#ifndef NTFSection_h
#define NTFSection_h

typedef NS_ENUM(uint8_t, NTFFeedSectionItemType) {
    NTFFeedSectionItemTypeNotDefined = 0,
    NTFFeedSectionItemTypeTopStories,
    NTFFeedSectionItemTypeBusiness,
    NTFFeedSectionItemTypeTechnology,
    NTFFeedSectionItemTypeEntertainment,
    NTFFeedSectionItemTypeSport,
    NTFFeedSectionItemTypeEditorial,
    NTFFeedSectionItemTypeOpinions,
    NTFFeedSectionItemTypeInternational,
    NTFFeedSectionItemTypeReadersChoice,
    NTFFeedSectionItemTypePolitics,
    NTFFeedSectionItemTypeScience,
    NTFFeedSectionItemTypeArts,
    NTFFeedSectionItemTypeHealth,
    NTFFeedSectionItemTypeRecommended,
    NTFFeedSectionItemTypeTopic,
};

NS_ASSUME_NONNULL_BEGIN

@protocol NTFSection <NSObject>

- (nullable NSString *)title;
- (nullable NSString *)subtitle;
- (NTFFeedSectionItemType)presentationType;

@end

NS_ASSUME_NONNULL_END

#endif /* NTFSection_h */
