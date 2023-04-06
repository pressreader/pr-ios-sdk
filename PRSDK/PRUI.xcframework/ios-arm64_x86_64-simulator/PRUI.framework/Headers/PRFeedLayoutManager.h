//
//  PRFeedLayoutManager.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 1/8/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

@import CoreData;
@protocol NTFArticle;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(uint8_t, NTFLayoutOption) {
    NTFLayoutOptionShowRelatedStories = 1 << 0,
    NTFLayoutOptionHideSections = 1 << 1,
    NTFLayoutOptionShowBanners = 1 << 2
};

typedef void(^PRUpdateLayoutHandler)(NSArray *items, NSArray<NSManagedObject *> *rawItems);

@protocol PRFeedLayoutManager <NSObject>

- (void)compileDataProviderWithItems:(NSArray<NSManagedObjectID *> *)items
                       targetContext:(NSManagedObjectContext *)targetContext
                          moreFollow:(BOOL)moreFollow
                          сompletion:(PRUpdateLayoutHandler)completion NS_SWIFT_NAME(compileDataProvider(items:targetContext:moreFollow:completion:));

- (NSArray *)compileDataProviderWithItems:(NSArray *)items NS_SWIFT_NAME(compileDataProvider(items:));

@property (nonatomic) NTFLayoutOption options;

@end

NS_ASSUME_NONNULL_END
