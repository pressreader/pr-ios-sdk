//
//  ArticleLink+CoreDataProperties.h
//  PRAPI
//
//  Created by berec on 15/05/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//
//

#import "ArticleLink+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface ArticleLink (CoreDataProperties)

+ (NSFetchRequest<ArticleLink *> *)fetchRequest;

@property (nullable, nonatomic, copy) NSString *url;
@property (nullable, nonatomic, copy) NSString *title;
@property (nullable, nonatomic, retain) NTFArticleItem *article;

@end

NS_ASSUME_NONNULL_END
