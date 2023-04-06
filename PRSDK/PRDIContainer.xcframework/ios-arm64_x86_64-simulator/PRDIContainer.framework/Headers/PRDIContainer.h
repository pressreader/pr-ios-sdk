//
//  PRDIContainer.h
//  PRDIContainer
//
//  This framework is intended for dependency injection's implementation. If you need to register a
//  dependency, you should do it in `PRModel+DIRegistator` extension, `registerDependencies` method.
//  In order to override dependencies with mocks for unit tests purpose, add your registration code
//  to `PRModel+DI` extension, `registerUnitTestsDependencies` method. In this way your dependencies
//  will be registered in `PRModel`'s `init` method, which happens even before app delegate methods call.
//
//  Created by Viacheslav Soroka on 2022-04-22.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for PRDIContainer.
FOUNDATION_EXPORT double PRDIContainerVersionNumber;

//! Project version string for PRDIContainer.
FOUNDATION_EXPORT const unsigned char PRDIContainerVersionString[];
