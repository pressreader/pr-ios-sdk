//
//  PROrderVC.h
//  PRiphone
//
//  Created by Jackie Cane on 23/01/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

@import PRUIKit.PRVC;

@class PROrder;
@class PRGroupedExemplarsCollectionVC;
@class PROrderModel;

NS_ASSUME_NONNULL_BEGIN

@interface PROrderVC : PRVC

- (instancetype)initWithOrder:(PROrder *)order;

@property (nonatomic, strong) PROrder *order;
@property (nonatomic, strong, readonly) PROrderModel *model;
@property (nonatomic, strong, readonly) PRGroupedExemplarsCollectionVC *otherIssuesVC;

@end

#ifdef TEST
@interface PROrderVC ()
- (void)openReaderWithCompletion:(nullable PRSimpleBlock)completion;
@end
#endif

NS_ASSUME_NONNULL_END
