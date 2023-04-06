//
//  PRSocialSignInCell.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 3/10/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PRSignInOption;
@class PRSocialSignInCell;

@protocol PRSocialSignInCellDelegate <NSObject>

- (void)cell:(PRSocialSignInCell *)cell didReceiveNetworkTap:(PRSignInOption *)network;

@end

@interface PRSocialSignInCell : UITableViewCell
@property (nonatomic, weak) id<PRSocialSignInCellDelegate> delegate;

- (void)fillWithNetworks:(NSArray<PRSignInOption *> *)networks;

@end
