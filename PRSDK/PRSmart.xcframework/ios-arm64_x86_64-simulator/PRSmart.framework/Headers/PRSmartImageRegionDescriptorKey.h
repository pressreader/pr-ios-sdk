//
//  PRSmartImageRegionDescriptorKey.h
//  PRiphone
//
//  Created by Serhii Myakinnikov on 19.12.2022.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

@import Foundation;

extern const struct PRSmartImageRegionDescriptorKeyReadable
{
    __unsafe_unretained NSString *caption;
    __unsafe_unretained NSString *byline;
    __unsafe_unretained NSString *rect;
    __unsafe_unretained NSString *targetWidth;
    __unsafe_unretained NSString *targetHeight;
    __unsafe_unretained NSString *loadFromWeb;
    __unsafe_unretained NSString *urlPath;
    __unsafe_unretained NSString *identifier;
} PRSmartImageRegionDescriptorKey;
