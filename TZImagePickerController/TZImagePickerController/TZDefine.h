//
//  TZDefine.h
//  多选相册照片
//
//  Created by long on 15/11/26.
//  Copyright © 2015年 long. All rights reserved.
//

#ifndef TZDefine_h
#define TZDefine_h

#import <UIKit/UIKit.h>
#import "TZImagePickerController.h"

#if DEBUG
#define ZLLoggerDebug(format, ...) NSLog(format, ##__VA_ARGS__)
#else
#define ZLLoggerDebug(format, ...)
#endif

#define kRGB(r, g, b)   [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1]


#ifndef zl_weakify
    #if DEBUG
        #if __has_feature(objc_arc)
        #define zl_weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
        #else
        #define zl_weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
        #endif
    #else
        #if __has_feature(objc_arc)
        #define zl_weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
        #else
        #define zl_weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
        #endif
    #endif
#endif

#ifndef zl_strongify
    #if DEBUG
        #if __has_feature(objc_arc)
        #define zl_strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
        #else
        #define zl_strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
        #endif
    #else
        #if __has_feature(objc_arc)
        #define zl_strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
        #else
        #define zl_strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
        #endif
    #endif
#endif



//#define kZLPhotoBrowserBundle [NSBundle bundleForClass:[self class]]

// 图片路径
//#define kZLPhotoBrowserSrcName(file) [@"TZImagePickerController.bundle" stringByAppendingPathComponent:file]
//#define kZLPhotoBrowserFrameworkSrcName(file) [@"TZImagePickerController/TZImagePickerController.framework/TZImagePickerController.bundle" stringByAppendingPathComponent:file]

#define kViewWidth      [[UIScreen mainScreen] bounds].size.width
#define kViewHeight     [[UIScreen mainScreen] bounds].size.height

//app名字
#define kZL_LOCALIZED_APP_NAME [[NSBundle mainBundle].localizedInfoDictionary objectForKey:@"CFBundleDisplayName"]
#define kAPPName kZL_LOCALIZED_APP_NAME ?: [[NSBundle mainBundle].infoDictionary objectForKey:@"CFBundleDisplayName"] ?: [[NSBundle mainBundle].infoDictionary objectForKey:@"CFBundleName"]

//自定义图片名称存于plist中的key
#define TZCustomImageNames @"TZCustomImageNames"
//设置框架语言的key
#define TZLanguageTypeKey @"TZLanguageTypeKey"
//自定义多语言key value存于plist中的key
#define TZCustomLanguageKeyValue @"TZCustomLanguageKeyValue"

////////ZLShowBigImgViewController
#define kItemMargin 40

///////ZLBigImageCell 不建议设置太大，太大的话会导致图片加载过慢
#define kMaxImageWidth 500

#define ClippingRatioValue1 @"value1"
#define ClippingRatioValue2 @"value2"
#define ClippingRatioTitleFormat @"titleFormat"

#define TZPreviewPhotoObj @"TZPreviewPhotoObj"
#define TZPreviewPhotoTyp @"TZPreviewPhotoTyp"



typedef NS_ENUM(NSUInteger, ZLLanguageType) {
    //跟随系统语言，默认
    ZLLanguageSystem,
    //中文简体
    ZLLanguageChineseSimplified,
    //中文繁体
    ZLLanguageChineseTraditional,
    //英文
    ZLLanguageEnglish,
    //日文
    ZLLanguageJapanese,
};



//导出视频类型
typedef NS_ENUM(NSUInteger, TZExportVideoType) {
    //default
    TZExportVideoTypeMov,
    TZExportVideoTypeMp4,
};

//导出视频水印位置
typedef NS_ENUM(NSUInteger, TZWatermarkLocation) {
    TZWatermarkLocationTopLeft,
    TZWatermarkLocationTopRight,
    TZWatermarkLocationCenter,
    TZWatermarkLocationBottomLeft,
    TZWatermarkLocationBottomRight,
};

//混合预览图片时，图片类型
typedef NS_ENUM(NSUInteger, TZPreviewPhotoType) {
    TZPreviewPhotoTypePHAsset,
    TZPreviewPhotoTypeUIImage,
    TZPreviewPhotoTypeURLImage,
    TZPreviewPhotoTypeURLVideo,
};

static inline BOOL ZL_DeviceIsiPhone() {
    return UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone;
}

static inline CGFloat ZL_SafeAreaBottom() {
    CGFloat temp = 0;
    
    if (@available(iOS 11.0, *)) {
        temp = UIApplication.sharedApplication.keyWindow.safeAreaInsets.bottom;
    }
    
    return temp;
}

static inline NSDictionary * GetDictForPreviewPhoto(id obj, TZPreviewPhotoType type) {
    if (nil == obj) {
        @throw [NSException exceptionWithName:@"error" reason:@"预览对象不能为空" userInfo:nil];
    }
    return @{TZPreviewPhotoObj: obj, TZPreviewPhotoTyp: @(type)};
}

static inline void SetViewWidth(UIView *view, CGFloat width) {
    CGRect frame = view.frame;
    frame.size.width = width;
    view.frame = frame;
}

static inline CGFloat GetViewWidth(UIView *view) {
    return view.frame.size.width;
}

static inline void SetViewHeight(UIView *view, CGFloat height) {
    CGRect frame = view.frame;
    frame.size.height = height;
    view.frame = frame;
}

static inline CGFloat GetViewHeight(UIView *view) {
    return view.frame.size.height;
}

//static inline NSString *  GetLocalLanguageTextValue (NSString *key) {
//    NSDictionary *dic = [[NSUserDefaults standardUserDefaults] valueForKey:ZLCustomLanguageKeyValue];
//    if ([dic.allKeys containsObject:key]) {
//        return dic[key];
//    }
//    return [NSBundle zlLocalizedStringForKey:key];
//}

//static inline UIImage * GetImageWithName(NSString *name) {
//    NSArray *names = [[NSUserDefaults standardUserDefaults] valueForKey:ZLCustomImageNames];
//    if ([names containsObject:name]) {
//        return [UIImage imageNamed:name];
//    }
//    return [UIImage imageNamed:kZLPhotoBrowserSrcName(name)]?:[UIImage imageNamed:kZLPhotoBrowserFrameworkSrcName(name)];
//}

static inline CGFloat GetMatchValue(NSString *text, CGFloat fontSize, BOOL isHeightFixed, CGFloat fixedValue) {
    CGSize size;
    if (isHeightFixed) {
        size = CGSizeMake(MAXFLOAT, fixedValue);
    } else {
        size = CGSizeMake(fixedValue, MAXFLOAT);
    }
    
    CGSize resultSize;
    if ([[[UIDevice currentDevice] systemVersion] doubleValue] >= 7.0) {
        //返回计算出的size
        resultSize = [text boundingRectWithSize:size options:NSStringDrawingTruncatesLastVisibleLine | NSStringDrawingUsesFontLeading | NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName: [UIFont systemFontOfSize:fontSize]} context:nil].size;
    }
    if (isHeightFixed) {
        return resultSize.width;
    } else {
        return resultSize.height;
    }
}

//static inline void ShowAlert(NSString *message, UIViewController *sender) {
//    UIAlertController *alert = [UIAlertController alertControllerWithTitle:nil message:message preferredStyle:UIAlertControllerStyleAlert];
//    NSString *title = [NSBundle tz_localizedStringForKey:@"ZLPhotoBrowserOKText"];
//    UIAlertAction *action = [UIAlertAction actionWithTitle: title style:UIAlertActionStyleDefault handler:nil];
//    [alert addAction:action];
//    [sender presentViewController:alert animated:YES completion:nil];
//}

static inline CABasicAnimation * GetPositionAnimation(id fromValue, id toValue, CFTimeInterval duration, NSString *keyPath) {
    CABasicAnimation *animation = [CABasicAnimation animationWithKeyPath:keyPath];
    animation.fromValue = fromValue;
    animation.toValue   = toValue;
    animation.duration = duration;
    animation.repeatCount = 0;
    animation.autoreverses = NO;
    //以下两个设置，保证了动画结束后，layer不会回到初始位置
    animation.removedOnCompletion = NO;
    animation.fillMode = kCAFillModeForwards;
    return animation;
}

static inline CAKeyframeAnimation * GetBtnStatusChangedAnimation() {
    CAKeyframeAnimation *animate = [CAKeyframeAnimation animationWithKeyPath:@"transform"];
    
    animate.duration = 0.3;
    animate.removedOnCompletion = YES;
    animate.fillMode = kCAFillModeForwards;
    
    animate.values = @[[NSValue valueWithCATransform3D:CATransform3DMakeScale(0.7, 0.7, 1.0)],
                       [NSValue valueWithCATransform3D:CATransform3DMakeScale(1.2, 1.2, 1.0)],
                       [NSValue valueWithCATransform3D:CATransform3DMakeScale(0.8, 0.8, 1.0)],
                       [NSValue valueWithCATransform3D:CATransform3DMakeScale(1.0, 1.0, 1.0)]];
    return animate;
}

static inline NSInteger GetDuration (NSString *duration) {
    NSArray *arr = [duration componentsSeparatedByString:@":"];
    
    NSInteger d = 0;
    for (int i = 0; i < arr.count; i++) {
        d += [arr[i] integerValue] * pow(60, (arr.count-1-i));
    }
    return d;
}


static inline NSDictionary * GetCustomClipRatio() {
    return @{ClippingRatioValue1: @(0), ClippingRatioValue2: @(0), ClippingRatioTitleFormat: @"Custom"};
}

static inline NSDictionary * GetClipRatio(NSInteger value1, NSInteger value2) {
    return @{ClippingRatioValue1: @(value1), ClippingRatioValue2: @(value2), ClippingRatioTitleFormat: @"%g : %g"};
}

#endif /* TZDefine_h */
