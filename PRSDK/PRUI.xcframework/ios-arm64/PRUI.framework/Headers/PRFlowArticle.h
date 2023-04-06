//
//  PRFlowArticle.h
//  PRUI
//
//  Created by berec on 08/05/2021.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

@import PRAPI.NTFArticle;

@protocol NTFActionConfig <NSObject>
- (NSDictionary *)generalActionConfig;
- (NSDictionary *)articleActionConfig;
@end

/// Basically PRAPI.NTFArticle extended with PRUI's protocols
@protocol PRFlowArticle <NTFArticle, NTFActionConfig>
@end
