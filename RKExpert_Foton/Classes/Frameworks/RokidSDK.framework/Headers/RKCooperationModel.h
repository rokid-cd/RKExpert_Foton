//
//  RKCooperationModel.h
//  iOSRokid
//
//  Created by 张小饼 on 2021/4/19.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@class RKRemoteRecordParams;

@interface RKSDKInfo: NSObject
/// 商户服务器地址 （默认使用标准产品host）
@property(nonatomic, copy, nullable) NSString *apiHost;
/// 用户token
@property(nonatomic, copy) NSString *token;
/// appKey
@property(nonatomic, copy) NSString *appKey;
/// 录制参数
@property(nonatomic, strong, nullable) RKRemoteRecordParams *recordParams;

@end


@interface RKContactInfo: NSObject
/// 用户id
@property(nonatomic, copy) NSString *userId;
/// JC授权码
@property(nonatomic, copy) NSString *licenseCode;
/// 真实名字
@property(nonatomic, copy) NSString *realName;
/// 头像
@property(nonatomic, copy, nullable) NSString *headUrl;
/// 0-离线 1-在线
@property (nonatomic, assign) NSInteger status;

@end


@interface RKRemoteRecordParams: NSObject
@property (nonatomic, copy) NSString *secretKey;
@property (nonatomic, copy) NSString *accessKey;
@property (nonatomic, copy) NSString *bucketName;
@property (nonatomic, copy) NSString *directory;
@property (nonatomic, copy, nullable) NSString *uploadEndPoint;
@end

@interface RKFileInfo : NSObject
@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *fileName;
@end

/**
 IM数据
 */

//用户信息
@interface RKChatMember : NSObject

@property (nonatomic, copy) NSString *licenseCode;
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *displayName;

@end

//群聊信息
@interface RKChatInfo : NSObject
//群聊ID
@property (nonatomic, copy) NSString *serverId;
//群聊名称
@property (nonatomic, copy) NSString *chatName;
//群聊成员
@property (nonatomic, strong) NSArray<RKChatMember *> *chatMembers;

//群聊任务主题名称
@property (nonatomic, copy) NSString *subjectName;
//群聊任务主题内容
@property (nonatomic, copy) NSString *subjectContent;

@end


NS_ASSUME_NONNULL_END

