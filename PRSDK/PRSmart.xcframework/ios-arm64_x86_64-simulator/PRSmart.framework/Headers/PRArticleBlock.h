//
//  PRArticleBlock.h
//  PR-API
//
//  Created by Viacheslav Soroka on 11/19/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, PRArticleBlockType) {
    PRArticleBlockTypeUnknown = 0,
    PRArticleBlockTypeText,
    PRArticleBlockTypeParatitle,
    PRArticleBlockTypeAnnotation,
    PRArticleBlockTypeImage,
    PRArticleBlockTypeVideo
};

@interface PRArticleBlock : NSObject

+ (__kindof PRArticleBlock *)blockWithJSON:(id)json;

- (instancetype)initWithType:(PRArticleBlockType)type
                        text:(nullable NSString *)text
                        info:(nullable NSDictionary *)info;

@property (nonatomic, readonly) PRArticleBlockType type;
@property (nullable, nonatomic, readonly) NSDictionary *info;
@property (nullable, nonatomic, strong) NSString *text;

@end

NS_ASSUME_NONNULL_END
