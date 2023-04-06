//
//  PRPubHubVC+HotSpot.h
//  PR-UI
//
//  Created by berec on 03/04/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PREmbedablePubHubVC.h"

NS_ASSUME_NONNULL_BEGIN

@interface PREmbedablePubHubVC (HotSpot) <PRHotspotStatusViewPresenterProtocol>

- (void)refreshHotspotStatusView;

@end

NS_ASSUME_NONNULL_END
