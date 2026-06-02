//
//  NSDate+Presentation.h
//  PR-UI
//
//  Created by berec on 27/06/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(uint8_t, PRDatePresentationStyle) {
    PRDatePresentationStyleHide = -1,
    PRDatePresentationStyleAuto = 0,
    PRDatePresentationStyleDMY,
    PRDatePresentationStyleDM
};

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (Presentation)

- (NSString *)recentDatePresentationWithStyle:(PRDatePresentationStyle)style;
- (NSString *)presentationWithStyle:(PRDatePresentationStyle)style;

@property (nonatomic, readonly) NSString *recentDatePresentation;

@end

NS_ASSUME_NONNULL_END
