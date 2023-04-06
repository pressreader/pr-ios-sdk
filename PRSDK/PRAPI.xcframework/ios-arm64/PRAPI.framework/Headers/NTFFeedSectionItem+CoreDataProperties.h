//
//  NTFFeedSectionItem+CoreDataProperties.h
//  PR-API
//
//  Created by berec on 30/04/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//
//

#import "NTFFeedSectionItem.h"


NS_ASSUME_NONNULL_BEGIN

@interface NTFFeedSectionItem (CoreDataProperties)

+ (NSFetchRequest<NTFFeedSectionItem *> *)fetchRequest;

@property (nonatomic) int16_t sectionType;
@property (nullable, nonatomic, copy) NSString *title;
@property (nullable, nonatomic, copy) NSString *subtitle;
@property (nullable, nonatomic, retain) NSSet<NTFArticleItem *> *articles;
@property (nullable, nonatomic, strong) NSString *locale;
@property (nullable, nonatomic, strong) NSString *sectionId;

@end

@interface NTFFeedSectionItem (CoreDataGeneratedAccessors)

- (void)addArticlesObject:(NTFArticleItem *)value;
- (void)removeArticlesObject:(NTFArticleItem *)value;
- (void)addArticles:(NSSet<NTFArticleItem *> *)values;
- (void)removeArticles:(NSSet<NTFArticleItem *> *)values;

@end

NS_ASSUME_NONNULL_END
