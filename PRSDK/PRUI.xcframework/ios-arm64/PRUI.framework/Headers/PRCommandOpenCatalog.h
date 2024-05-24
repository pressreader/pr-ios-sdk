//
//  PRCommandOpenCatalog.h
//  PRiphone
//
//  Created by Jackie Cane on 8/21/13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import "PRCommandOpenSources.h"

@import PRAPI.PRCatalogSection;

extern NSString *const PRCommandOpenCatalogHomeConfigurationSchemeKey;
extern NSString *const PRCommandOpenCatalogSectionKey;

@interface PRCommandOpenCatalog : PRCommandOpenSources

+ (void)executeWithSection:(PRCatalogSectionType)sectionType;

@end
