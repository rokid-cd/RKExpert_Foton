//
//  RKDrawView.h

#import <UIKit/UIKit.h>

@class RKDoodle;

@protocol DrawViewDelegate<NSObject>
///  添加点位标注
/// @param point 标注信息
- (void)touchPointAction:(RKDoodle *)point;
/// 添加曲线标注
/// @param doodle 标注信息
- (void)addWireDoodleAction:(RKDoodle *)doodle;

@end

@interface RKDrawView : UIView
@property (nonatomic, weak) id<DrawViewDelegate> delegate;
// 画笔宽度
@property(nonatomic, assign) CGFloat lineWidth;
// 画笔颜色
@property(nonatomic, strong) UIColor *lineColor;

// 添加笔画
- (void)add:(NSArray <RKDoodle *> *)doodles;
// 清除画板
- (void)clean;
// 撤销
- (void)undo:(RKDoodle *)doodle;
// 保存到相册
- (void)save;
// 截屏
- (UIImage *)snip;

@end
