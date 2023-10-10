//
//  PRGrouppedIssuesCollection.h
//  PR-UI
//
//  Created by berec on 28/01/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#ifndef PRGrouppedIssuesCollection_h
#define PRGrouppedIssuesCollection_h

@class PRIssuesGroup;
@class PRSubscription;

@protocol PRGrouppedIssuesCollection <NSObject>
@property (nonatomic, strong) UICollectionView *collectionView;
@property (nonatomic, strong, readonly) UICollectionViewLayout *collectionViewLayout;
@property (nonatomic, weak) PRSubscription *preferableSubscription;

@end

#endif /* PRGrouppedIssuesCollection_h */
