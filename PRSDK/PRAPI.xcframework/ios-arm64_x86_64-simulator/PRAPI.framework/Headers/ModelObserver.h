//
//  ModelObserver.h
//  PR-API
//
//  Created by Viacheslav Soroka on 12/3/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@protocol ModelObserver <NSObject>

@optional
- (void)modelDidUnload:(id<ModelProtocol>)model;
- (void)modelDidStartLoading:(id<ModelProtocol>)model;
- (void)modelDidLoad:(id<ModelProtocol>)model;
- (void)modelDidFailLoading:(id<ModelProtocol>)model;
- (void)modelDidUpdate:(id<ModelProtocol>)model;
- (void)model:(id<ModelProtocol>)model didFailWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
