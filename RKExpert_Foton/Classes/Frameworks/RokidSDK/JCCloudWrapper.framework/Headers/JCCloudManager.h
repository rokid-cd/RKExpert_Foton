//
//  JCCloudManager.h
//  JCCloudWrapper
//
//  Created by maikireton on 2019/11/14.
//  Copyright © 2019 ireton. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^CloudOperationBlock)(bool, int, NSObject* __nullable);

@protocol JCCloudManagerDelegate <JCClientCallback>

/**
 *  @brief 当使用用户自己的文件存储在调用发送文件接口后会触发此回调，用户将文件上传至文件存储获得 url
 *  @param messageId 消息在数据库中 id
 *  @param filePath 调用发送文件接口传入的文件路径
 */
//- (void)onUploadOrDownloadFile:(id<JCFileDealCallback>)callback;

/**
 *  @brief 预处理文件发送
 *  @param message 消息对象
 *  @return true 表示上层要要对该文件进行处理，处理完需要调用 JCMessageWrapper.setPreDealFile，false 则内部继续处理
 */
-(bool)onPreDealFileTransfer:(JCConversationMessageData* __nonnull)message;

/**
 * @param messageId 消息id
 * 当使用用户自己的文件存储在调用停止文件传输接口后会触发此回调，用户在上层自己去停止文件传输
 */
//- (void)onStopFile:(long)messageId;

/**
 *  @brief 新增会话
 *  @param conversationId 会话数据库 id
 */
-(void)onConversationAdd:(long)conversationId;

/**
 *  @brief 会话更新，例如会话中的消息新增，消息状态更新，删除等都会触发
 *  @param conversationId 会话数据库 id
 */
-(void)onConversationUpdate:(long)conversationId;

/**
 *  @brief 会话删除
 *  @param conversationId 会话数据库 id，-1 表示全部会话
*/
-(void)onConversationDelete:(long)conversationId;

/**
 *  @brief  新增消息
 *  @param  conversationId 会话数据库 id
 *  @param  message 消息数据库对象
 */
-(void)onConversationMessageAdd:(long)conversationId message:(JCConversationMessageData* __nonnull)message;

/**
 *  @brief  消息更新
 *  @param  conversationId 会话数据库 id
 *  @param  message 消息数据库对象
 */
-(void)onConversationMessageUpdate:(long)conversationId message:(JCConversationMessageData* __nonnull)message;

/**
 *  @brief  消息删除，会话删除导致的消息删除不上报
 *  @param  conversationId 会话数据库 id
 *  @param  message 消息数据库对象
 */
-(void)onConversationMessageDelete:(long)conversationId message:(JCConversationMessageData* __nonnull)message;

/**
 *  @brief 新增群
 *  @param group JCGroupData 对象
 */
-(void)onGroupAdd:(JCGroupData*)group;

/**
 *  @brief 群更新
 *  @param group JCGroupData 对象
 */
-(void)onGroupUpdate:(JCGroupData*)group;

/**
 *  @brief 会话删除
 *  @param group JCGroupData 对象
 */
-(void)onGroupDelete:(JCGroupData*)group;

/**
 *  @brief 新增群
 *  @param member JCGroupMemberData 对象
 */
-(void)onGroupMemberAdd:(JCGroupMemberData*)member;

/**
 *  @brief 群更新
 *  @param member JCGroupMemberData 对象
 */
-(void)onGroupMemberUpdate:(JCGroupMemberData*)member;

/**
 *  @brief 会话删除
 *  @param member JCGroupMemberData 对象
 */
-(void)onGroupMemberDelete:(JCGroupMemberData*)member;

/**
 * @brief 在线消息发送结果
 *
 * @param operationId 操作id, 由 @ref JCClient#sendOnlineMessage "sendOnlineMessage" 返回
 * @param result 消息发送是否成功
 */

-(void)onOnlineMessageSend:(int)operationId result:(bool)result;

/**
 * @brief 收到在线消息
 *
 * @param userId 消息发送方用户标识
 * @param content 消息内容
 */
-(void)onOnlineMessageReceive:(NSString *)userId content:(NSString *)content;

@end

@interface JCCloudManager : NSObject

/// JCClient 对象
@property (nonatomic, readonly) JCClient* client;
/// JCMessageChannel 对象
@property (nonatomic, readonly) JCMessageChannel* message;
/// JCStorage 对象
@property (nonatomic, readonly) JCStorage* storge;
/// JCAccount 对象
@property (nonatomic, readonly) JCAccount* account;
/// JCGroup 对象
@property (nonatomic, readonly) JCGroup* group;
/// JCCloudManagerDelegate 回调对象
@property (nonatomic, weak, nullable) id<JCCloudManagerDelegate> delegate;
/// 文件保存路径
@property (nonatomic, strong) NSString* fileSaveDir;
/// 缩略图保存路径
@property (nonatomic, strong) NSString* thumbSaveDir;
/// 当有服务器会话新增的情况自动创建会话，默认为 false
@property (nonatomic) bool autoCreateConversation;
/// JCAccountCallback 回调对象
@property (nonatomic, weak) id<JCAccountCallback> accountCallback;

/**
 *  @biref 单例获取
 */
+(JCCloudManager*)shared;

/**
 *  @brief  初始化
 *  @param  appKey appKey
 *  @return 是否成功
 */
-(bool)initialize:(NSString*)appKey createParam:(JCClientCreateParam* __nullable)createParam;

/**
 *   @brief 反初始化
 */
-(void)uninitialize;

/**
 *  @brief 异步调用，数据库操作要在同一线程中
 */
-(void)dispatchIm:(void(^)(void))block;

/**
 *  @brief 异步调用，数据库操作要在同一线程中
 */
-(void)dispatchImDelay:(void(^)(void))block delay:(int)millisecond;

/**
 *  @brief 设置会话置顶
 *  @param isPriority   是否置顶
 *  @param block 结果函数
 */
-(void)setConversationPriority:(long)conversationId isPriority:(bool)isPriority usingBlock:(CloudOperationBlock)block;

/**
 *  @brief 设置会话免打扰
 *  @param dnd   是否免打扰
 *  @param block 结果函数
 */
-(void)setConversationDnd:(long)conversationId dnd:(bool)dnd usingBlock:(CloudOperationBlock)block;

/**
 *  @brief 刷新服务器联系人
 *  @param block 结果函数
 */
-(void)refreshContacts:(CloudOperationBlock)block;

/**
 * @brief 查询 serverUid
 * @param userIdArray 查询的账号
 */
-(void)queryServerUid:(NSArray<NSString*>*)userIdArray usingBlock:(CloudOperationBlock)block;

@end

NS_ASSUME_NONNULL_END
