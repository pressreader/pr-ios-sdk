//
//  PRFeedbackController.h
//  PRiphone
//
//  Created by Jackie Cane on 3/13/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <MessageUI/MessageUI.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const kFeedbackMailAttachmentMimeType;
extern NSString * const kFeedbackMailAttachmentFilePath;
extern NSString * const kFeedbackMailAttachmentData;

@interface PRFeedbackController : MFMailComposeViewController<MFMailComposeViewControllerDelegate>

+ (void)presentFeedbackComposerForParent:(nullable UIViewController *)parent NS_SWIFT_NAME(presentFeedbackComposer(for:));
+ (void)presentFeedbackComposerWithLogsAttachedForParent:(nullable UIViewController *)parent NS_SWIFT_NAME(presentFeedbackComposerWithLogsAttached(for:));

/// attachments is array of dictionaries with mime type and file path or NSData
+ (void)presentFeedbackComposerForParent:(nullable UIViewController *)parent
                                 subject:(nullable NSString *)subject
                                    body:(nullable NSString *)body
                             attachments:(nullable NSArray *)attachments;
/// PRFeedbackController static method to customize ToRecipients
+ (void)presentFeedbackComposerForParent:(nullable UIViewController *)parent
                                 subject:(nullable NSString *)subject
                                    body:(nullable NSString *)body
                              recipients:(nullable NSArray<NSString *> *)recipients
                             attachments:(nullable NSArray *)attachments;

- (nullable instancetype)initWithParent:(nullable UIViewController *)parent;
- (nullable instancetype)initWithParent:(nullable UIViewController *)parent
                                subject:(nullable NSString *)subject
                                   body:(nullable NSString *)body
                            attachments:(nullable NSArray *)attachments;
- (nullable instancetype)initWithParent:(nullable UIViewController *)parent
                                subject:(nullable NSString *)subject
                                   body:(nullable NSString *)body
                             recipients:(nullable NSArray<NSString *> *)recipients
                            attachments:(nullable NSArray *)attachments;

@property (nullable, nonatomic, strong) NSArray *attachments;

@end

NS_ASSUME_NONNULL_END
