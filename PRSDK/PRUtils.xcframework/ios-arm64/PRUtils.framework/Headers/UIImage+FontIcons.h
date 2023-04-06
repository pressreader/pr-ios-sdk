//
//  UIImage (Icons).h
//  test1
//
//  Created by Oleg Stepanenko on 27.04.16.
//  Copyright © 2016 StephanWhite. All rights reserved.
//

#import <UIKit/UIKit.h>

extern unichar PRUIIcons_About;
extern unichar PRUIIcons_Accounts;
extern unichar PRUIIcons_Back;
extern unichar PRUIIcons_Blog;
extern unichar PRUIIcons_Bookmarks;
extern unichar PRUIIcons_Calendar;
extern unichar PRUIIcons_Downloaded;
extern unichar PRUIIcons_Favorite;
extern unichar PRUIIcons_HelpCenter;
extern unichar PRUIIcons_HotSpot;
extern unichar PRUIIcons_Menu;
extern unichar PRUIIcons_MyTopics;
extern unichar PRUIIcons_Opinions;
extern unichar PRUIIcons_Publications;
extern unichar PRUIIcons_NewsFeed;
extern unichar PRUIIcons_Settings;
extern unichar PRUIIcons_ThreeDots;
extern unichar PRUIIcons_Checkmark;

@interface UIImage (FontIcons)
+ (NSString*)fontIconName:(unichar)character;
+ (UIImage*)fontIconNamed:(NSString *)iconName;
+ (UIImage*)fontIconNamed:(NSString *)iconName height:(CGFloat)height;
+ (UIImage*)fontIconFromChar:(unichar)character;
+ (UIImage*)fontIconFromChar:(unichar)character fontName:(NSString *)fontName height:(CGFloat)height;
@end
