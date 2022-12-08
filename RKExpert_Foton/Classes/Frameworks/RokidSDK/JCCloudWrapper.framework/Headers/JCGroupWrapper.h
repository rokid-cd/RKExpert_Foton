//
//  JCGroupWrapper.h
//  JCCloudWrapper
//
//  Created by maikireton on 2019/11/27.
//  Copyright © 2019 ireton. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// NSObject 为群 ServerUid
typedef void (^GroupOperationBlock)(bool, int, NSObject* __nullable);

@interface JCGroupWrapper : NSObject

/**
 * @brief 创建群
 * @param members 成员列表，uid, memberType 和 displayname 需要赋值
 * @param groupName 群名字
 * @param type 群类型
 * @param block 结果函数
 */
+(void)createGroup:(NSArray<JCGroupMember*>* __nonnull)members groupName:(NSString* __nonnull)groupName type:(JCGroupType)type customProperties:(NSDictionary<NSString*, NSObject*>* __nullable)customProperties usingBlock:(GroupOperationBlock)block;

/**
 * @brief 添加人员
 * @param groupServerUid 群 ServerUid
 * @param members 成员列表，uid 和 displayname 需要赋值
 * @param block 结果函数
 */
+(void)addMembers:(NSString* __nonnull)groupServerUid members:(NSArray<JCGroupMember*>* __nonnull)members usingBlock:(GroupOperationBlock)block;

/**
 * @brief 踢掉人员
 * @param groupServerUid 群 ServerUid
 * @param memberServerUids 成员列表
 * @param block 结果函数
 */
+(void)kickMembers:(NSString* __nonnull)groupServerUid memberServerUids:(NSArray<NSString*>* __nonnull)memberServerUids usingBlock:(GroupOperationBlock)block;

/**
 * @brief 离开，群主必须转移群主后才能离开
 * @param groupServerUid 群 ServerUid
 * @param block 结果函数
 */
+(void)leave:(NSString* __nonnull)groupServerUid usingBlock:(GroupOperationBlock)block;

/**
 * @brief 解散群
 * @param groupServerUid 群 ServerUid
 * @param block 结果函数
 */
+(void)dissolve:(NSString* __nonnull)groupServerUid usingBlock:(GroupOperationBlock)block;

/**
 * @brief 更改群名称
 * @param groupServerUid 群 ServerUid
 * @param groupName 群名字
 * @param block 结果函数
 */
+(void)changeGroupName:(NSString* __nonnull)groupServerUid groupName:(NSString* __nonnull)groupName usingBlock:(GroupOperationBlock)block;

/**
 * @brief 设置群自定义属性
 * @param groupServerUid 群 ServerUid
 * @param customProperties 属性集
 * @param block 结果函数
 */
+(void)setGroupCustomProperties:(NSString* __nonnull)groupServerUid customProperties:(NSDictionary<NSString*, NSObject*>* __nonnull)customProperties usingBlock:(GroupOperationBlock)block;

/**
 * @brief 设置群主，只有当前群主可以操作
 * @param groupServerUid 群 ServerUid
 * @param memberServerUid 成员 serverUid
 * @param block 结果函数
 */
+(void)modifyToOwner:(NSString* __nonnull)groupServerUid memberServerUid:(NSString* __nonnull)memberServerUid usingBlock:(GroupOperationBlock)block;

/**
 * @brief 设置管理员，只有当前群主可以操作
 * @param groupServerUid 群 ServerUid
 * @param memberServerUid 成员 serverUid
 * @param block 结果函数
 */
+(void)modifyToManager:(NSString* __nonnull)groupServerUid memberServerUid:(NSString * __nonnull)memberServerUid usingBlock:(GroupOperationBlock)block;

/**
 * @brief 设置普通成员，只有当前群主可以操作
 * @param groupServerUid 群 ServerUid
 * @param memberServerUid 成员 serverUid
 * @param block 结果函数
 */
+(void)modifyToMember:(NSString* __nonnull)groupServerUid memberServerUid:(NSString* __nonnull)memberServerUid usingBlock:(GroupOperationBlock)block;

/**
 * @brief 修改自己的群昵称
 * @param groupServerUid 群 ServerUid
 * @param displayName 昵称
 * @param block 结果函数
 */
+(void)changeDisplayName:(NSString* __nonnull)groupServerUid displayName:(NSString* __nonnull)displayName usingBlock:(GroupOperationBlock)block;

/**
 * @brief 群备注更新
 * @param groupServerUid 群 ServerUid
 * @param nickName 群备注名
 * @param tag 标签，内部会将该 NSDictionary 转为 json
 * @param block 结果函数
 */
+(void)updateComment:(NSString* __nonnull)groupServerUid nickName:(NSString* __nullable)nickName tag:(NSDictionary<NSString*, NSObject*>* __nullable)tag usingBlock:(GroupOperationBlock)block;

/**
 * @brief 上传群头像，最终是群的 customProperties 会增加 "Icon"（JCGroupIconPropertyKey 在 JCCloudConstants.h 中） 字段，存的是服务器文件链接
 * @param path 头像文件路径
 * @param block 结果函数，block 的 obj 为 groupServerUid
 */
+(void)updateGroupIcon:(NSString* __nonnull)groupServerUid path:(NSString*)path usingBlock:(GroupOperationBlock)block;

//+(void)inviteMember:(NSString *)groupServerUid receiverServerUid:(NSString*)receiverServerUid receiverName:(NSString*)receiverName info:(NSString*)info usingBlock:(GroupOperationBlock)block;
//
//+(void)rejectInvite:(int)inviteId description:(NSString*)description  usingBlock:(GroupOperationBlock)block;

/**
 *  @brief 拉取服务器更新
 *  @param block 结果函数
 */
+(void)refreshGroups:(GroupOperationBlock)block;

/**
 *  @brief 更新群信息
 *  @param block 结果函数
 */
+(void)refreshGroupInfo:(NSString* __nonnull)groupServerId usingBlock:(GroupOperationBlock)block;

@end

NS_ASSUME_NONNULL_END
