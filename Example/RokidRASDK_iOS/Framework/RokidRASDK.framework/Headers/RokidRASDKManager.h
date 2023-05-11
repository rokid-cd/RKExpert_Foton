//
//  RokidRASDKManager.h
//  RokidRASDK
//
//  Created by 杨朝  on 2021/9/13.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TurnType) {
    FTFormHomeIndex = 1,            //首页入口
    FTFromTechnicalSupport = 2,     //技术支持入口
    FTFromJPush = 3,                 //极光推送
    FTFromTaskList = 4               //只展示任务列表
};

typedef void(^getTurnlock)(NSInteger index);
typedef void(^RAOnSuccess)(void);
typedef void(^RAOnFailed)(NSInteger errCode,  NSString * _Nullable errMsg);

#pragma mark - APP配置协议
@protocol RARotationInterface <NSObject>

/// 横竖屏切换
/// @param interfaceOrientation 方向
- (void)setNewOrientationRA:(UIInterfaceOrientationMask)interfaceOrientation;

@end


@interface RokidRASDKManager : NSObject



+ (instancetype)sharedRokidRASDKManager;

/// 设置横竖屏代理
/// @param delegate @AppRotationInterface
//- (void)setRotationDelegate:(id <RARotationInterface>)delegate;
@property (nonatomic, weak) id <RARotationInterface> supportRotationDelegate;

/**
 * 初始化登录
 * @param name 登录用户名
 * @param block SDK初始化成功
 * @param errorBlock SDK初始化登录失败 (NSInteger errCode 失败状态 , NSString *errMsg 失败原因)
 */
- (void)initConfigRokidSDKWithUserName:(NSString *)name
                             onSuccess:(RAOnSuccess)block
                              onFailed:(RAOnFailed)errorBlock;
/**
 * 首页、技术支持入口
 * @param name 登录用户名
 * @param type 入口参数
 * @param block 成功回调
 * @param errorBlock 失败回调
 */
- (void)initWithUserName:(NSString *)name
            WithTurnType:(TurnType)type
                WithData:(NSDictionary *)data
               onSuccess:(RAOnSuccess)block
                onFailed:(RAOnFailed)errorBlock;

/**
 * 极光推送入口
 * @param name 登录用户名
 * @param type 入口参数
 * @param msg 极光参数
 */
- (void)initWithUserName:(NSString *)name
            WithTurnType:(TurnType)type
            WithPushData:(NSString *)msg;


/**
 * 退出登录
 */
- (void)loginOut;

#pragma  mark -----屏幕共享相关

/// 结束屏幕共享
- (void)endShareScreen;


///  传递视频流
/// @param sampleBuffer sampleBuffer
- (void)uploadSharePixelBuffer:(CVImageBufferRef )sampleBuffer;


/// 配置shareExtenId
/// @param shareExtenId 屏幕共享扩展的bundleID
- (void)configScreenShareExtenId:(NSString *)shareExtenId;




/// 选择已闭环列表 必须在SDK初始化成功后调用
- (void)enterClosedLoopList;

/// 判断SDK是否初始化成功
- (BOOL)loginSuccess;

@end

NS_ASSUME_NONNULL_END
