//
//  PRConcurrentOperation.h
//  PRiphone
//
//  Created by Jackie Cane on 1/27/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

@import Foundation;

@interface PRConcurrentOperation : NSOperation {

// In concurrent operations, we have to manage the operation's state
BOOL      executing_;
BOOL      finished_;

}

- (void)done;

@property (nonatomic, assign, getter=isOperationStarted) BOOL operationStarted;

@end
