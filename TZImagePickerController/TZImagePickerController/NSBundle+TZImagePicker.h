//
//  NSBundle+TZImagePicker.h
//  TZImagePickerController
//
//  Created by 谭真 on 16/08/18.
//  Copyright © 2016年 谭真. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSBundle (TZImagePicker)

+ (NSBundle *)tz_imagePickerBundle;

+ (NSString *)tz_localizedStringForKey:(NSString *)key value:(NSString *)value;
+ (NSString *)tz_localizedStringForKey:(NSString *)key;

@end

static inline void ShowAlert(NSString *message, UIViewController *sender) {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:nil message:message preferredStyle:UIAlertControllerStyleAlert];
    NSString *title = [NSBundle tz_localizedStringForKey:@"ZLPhotoBrowserOKText"];
    UIAlertAction *action = [UIAlertAction actionWithTitle: title style:UIAlertActionStyleDefault handler:nil];
    [alert addAction:action];
    [sender presentViewController:alert animated:YES completion:nil];
}
