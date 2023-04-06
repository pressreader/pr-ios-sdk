//
//  PRViewLayoutProtocol.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 10.05.17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PRViewLayout) {
    PRViewLayoutUnspecified = 0,
    PRViewLayoutRegular     = 1,
    PRViewLayoutCompact     = 2,
};

@protocol PRViewLayoutProtocol <NSObject>

- (void)viewLayoutWillChange:(BOOL)animated;
- (void)viewLayoutDidChange:(BOOL)animated;

@property (nonatomic) PRViewLayout viewLayout;

@end
