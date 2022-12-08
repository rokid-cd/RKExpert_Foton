//
//  DotEnginePixelBuffer.h
//
//  Created by xiang on 15/01/2017.
//  Copyright © 2017 dotEngine. All rights reserved.
//  

#import <UIKit/UIKit.h>

@interface RKPixelBufferConvert : NSObject

+ (void)pixelBufferYUV_NV12From:(UIImage *)image complete:(void(^)(CVPixelBufferRef pixelBuffer))complete;

@end

