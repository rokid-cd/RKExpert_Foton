//
//  XYBaseCell.h
//
//
//  Created by Binbin on 16/7/13.
//  Copyright © 2016年
//

#import <UIKit/UIKit.h>
@interface XYCellData : NSObject
//cell队列的String
@property (nonatomic, copy  ) NSString       * cellId;
//需要给Cell填充的数据字典
@property (nonatomic, strong) NSMutableDictionary   * cellData;
@property (nonatomic, assign) CGFloat          cellHeight;
@property (nonatomic,assign) NSInteger actionId;

+ (instancetype)createWithCellId:(NSString *)cellId cellData:(NSDictionary *)cellData;
+ (instancetype)createWithCellId:(NSString *)cellId cellData:(NSDictionary *)cellData actionId:(NSInteger)actionId;
+ (instancetype)createWithCellId:(NSString *)cellId cellData:(NSDictionary *)cellData height:(CGFloat)height;
+ (instancetype)createWithCellId:(NSString *)cellId cellData:(NSDictionary *)cellData actionId:(NSInteger)actionId height:(CGFloat)height;
@end

@interface UITableViewCell (XYBaseCell)
@property (nonatomic,strong) NSIndexPath *indexPath;
+ (NSString *)clsName;
+ (CGFloat   )cellHeight;
+ (BOOL)isEqualCellId:(NSString *)cellId;
+ (BOOL)isEqualCellData:(XYCellData *)cellData;
- (CGFloat   )cellHeight;
- (CGSize    )calcLblSize:(UILabel *)lbl normalFont:(UIFont *)normalFont;
- (void      )fill:(XYCellData *)rowObj;
- (void      )fill:(XYCellData *)rowObj indexPath:(NSIndexPath *)indexPath;
- (void)fillDefaultValue;
- (void)fillCompleted;

@end


@interface UITableView (XYBaseCell)
@property (nonatomic,strong) NSMutableDictionary * cellHeightCache;
@property (nonatomic,strong) NSMutableDictionary * calcCellCach;
- (CGFloat)cellHeightAtIndexPath:(NSIndexPath *)indexPath cellData:(XYCellData *)cellData;
- (CGFloat)cellHeightAtIndexPath:(NSIndexPath *)indexPath cellData:(XYCellData *)cellData needCache:(BOOL)cache;
- (void   )regCellClsNames:(NSArray *)cellNames;
- (void)regNibWithNibNames:(NSArray *)nibNames bundle:(NSBundle *)bundle;
- (void)regNibWithNibNames:(NSArray *)nibNames clsNames:(NSArray *)clsNames bundle:(NSBundle *)bundle;
@end


@interface UICollectionViewCell (XYBaseCell)
@property (nonatomic,strong) NSIndexPath *indexPath;
+ (NSString *)clsName;
+ (CGFloat   )cellHeight;
+ (BOOL)isEqualCellId:(NSString *)cellId;
+ (BOOL)isEqualCellData:(XYCellData *)cellData;
- (CGFloat   )cellHeight;
- (CGSize    )calcLblSize:(UILabel *)lbl normalFont:(UIFont *)normalFont;
- (void      )fill:(XYCellData *)rowObj;
- (void      )fill:(XYCellData *)rowObj indexPath:(NSIndexPath *)indexPath;
- (void)fillDefaultValue;
- (void)fillCompleted;

@end


@interface UICollectionView (XYBaseCell)
@property (nonatomic,strong) NSMutableDictionary * cellHeightCache;
@property (nonatomic,strong) NSMutableDictionary * calcCellCach;
- (CGFloat)cellHeightAtIndexPath:(NSIndexPath *)indexPath cellData:(XYCellData *)cellData;
- (CGFloat)cellHeightAtIndexPath:(NSIndexPath *)indexPath cellData:(XYCellData *)cellData needCache:(BOOL)cache;
- (void   )regCellClsNames:(NSArray *)cellNames;
- (void)regNibWithNibNames:(NSArray *)nibNames bundle:(NSBundle *)bundle;
- (void)regNibWithNibNames:(NSArray *)nibNames clsNames:(NSArray *)clsNames bundle:(NSBundle *)bundle;

@end
