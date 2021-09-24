//
//  XMMenuPopover.h
//  MMMenuPopover
//
//  Created by gyh on 2021/4/23.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "XMMenuItem.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    ///XM自定义   △ Size (10 * 5) 最多支持五个菜单项
    XMMenuStyleDefault  = 0,
    ///仿系统样式   △ Size(18.5 * 9) 最多支持五个菜单项
    XMMenuStyleSystem   = 1,
    ///仿微信样式   △ Size(12 * 5)
    XMMenuStyleWechat   = 2,
    ///仿手Q样式    △ Size(19 * 9)
    XMMenuStyleQQ       = 3,
    ///仿钉钉样式   △ Size(22 * 10)
    XMMenuStyleDingTalk = 4,
    ///自定义样式  △ Size(10 * 5)
    XMMenuStyleCustom   = 5,
} XMMenuStyle;

@interface XMMenuPopover : NSObject

@property(class, nonatomic, readonly) XMMenuPopover *sharedMenuPopover;

@property(nonatomic,getter=isMenuVisible) BOOL menuVisible;        // default is NO

///default is XMMenuStyleDefault
@property(nonatomic,assign) XMMenuStyle style;
@property(nullable,nonatomic,copy) NSArray<XMMenuItem *> *menuItems;

//圆角，default is 5
@property(nonatomic,assign) CGFloat cornerRadius;
///气泡距离屏幕左右的最小间距，default is 15
@property(nonatomic,assign) CGFloat padding;
///颜色，default is black(alpha = 0.9)
@property(nonatomic,strong) UIColor *color;
@property(nonatomic,strong) UIColor *highLightColor;
///文本颜色，default is white
@property(nonatomic,strong) UIColor *textColor;
///竖线颜色，default is white
@property(nonatomic,strong) UIColor *lineColor;

//!!!!: 自定义View，如果设置了自定义View，其他属性无效， 自定义View必须设置size
@property(nonatomic,strong) UIView *customView;

@property(nonatomic,readonly) CGRect menuFrame;
///是否避开导航条，default is YES
@property(nonatomic,assign) BOOL avoidNavigationBar;

///展示菜单项控件
- (void)showMenuFromView:(UIView *)targetView
                    rect:(CGRect)targetRect;
///展示菜单项控件
- (void)showMenuFromView:(UIView *)targetView
                    rect:(CGRect)targetRect
                animated:(BOOL)animated;
///隐藏菜单项控件
- (void)hideMenu;


- (CGFloat)width;
- (CGFloat)height;
- (CGFloat)triangleWidth;
- (CGFloat)triangleHeight;

@end

UIKIT_EXTERN NSNotificationName const XMMenuPopoverWillShowMenuNotification;
UIKIT_EXTERN NSNotificationName const XMMenuPopoverDidShowMenuNotification;
UIKIT_EXTERN NSNotificationName const XMMenuPopoverWillHideMenuNotification;
UIKIT_EXTERN NSNotificationName const XMMenuPopoverDidHideMenuNotification;
UIKIT_EXTERN NSNotificationName const XMMenuPopoverMenuFrameDidChangeNotification;



NS_ASSUME_NONNULL_END