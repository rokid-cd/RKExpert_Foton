//
//  JCCloudDatabase.h
//  JCCloudWrapper
//
//  Created by maikireton on 2019/11/14.
//  Copyright © 2019 ireton. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark JCConversationData
/// 数据库会话对象
@interface JCConversationData : NSObject
/// 会话id
@property (nonatomic) long _id;
/// 会话类型，一对一和群组
@property (nonatomic) int type;
/// 会话对端 UserId，只针对一对一会话
@property (nonatomic, strong) NSString* recipient;
/// 会话名字
@property (nonatomic, strong) NSString* name;
/// 会话头像
@property (nonatomic, strong) NSString* icon;
/// 创建会话时间
@property (nonatomic) long create_timestamp;
/// 最后一条消息数据库id
@property (nonatomic) long latest_message_id;
/// 最后一条文本内容
@property (nonatomic, strong) NSString* snippet_text;
/// 最后一条消息类型
@property (nonatomic, strong) NSString* content_type;
/// 最后一条文件路径
@property (nonatomic, strong) NSString* preview_path;
/// 草稿文本
@property (nonatomic, strong) NSString* draft_snippet_text;
/// 草稿文件
@property (nonatomic, strong) NSString* draft_preview_path;
/// 草稿消息类型
@property (nonatomic, strong) NSString* draft_content_type;
/// 草稿生成的时间
@property (nonatomic) long draft_timestamp;
/// 最后一条消息时间
@property (nonatomic) long sort_timestamp;
/// 未读消息书
@property (nonatomic) int unread;
/// 会话优先级，用于置顶
@property (nonatomic) bool priority;
/// 免打扰
@property (nonatomic) bool dnd;
/// 会话服务器id
@property (nonatomic, strong) NSString* server_uid;
/// 发送者服务器id
@property (nonatomic, strong) NSString* server_sender_uid;
/// 发送者昵称（目前只有群聊）
@property (nonatomic, strong) NSString* sender_displayname;
/// 未读 at 消息
@property (nonatomic) int at_unread;
/// 转化为 string
-(NSString*)toString;

/// 是否相等
/// @param other JCConversationData 对象
-(bool)isEqual:(id)other;

@end

#pragma mark JCConversationMessageData

@class JCMergeForwardData;
@class JCReplyMessageData;

/// 数据库消息对象
@interface JCConversationMessageData : NSObject
/// 消息id
@property (nonatomic) long _id;
/// 会话id
@property (nonatomic) long conversation_id;
/// 消息发送还是接收类型
@property (nonatomic) JCMessageChannelItemDirection direction;
/// 发送该消息 UserId，自己发送的消息则为 “”
@property (nonatomic, strong) NSString* user_id;
/// 发送者昵称（针对接收的消息）
@property (nonatomic, strong) NSString* display_name;
/// 是否群组
@property (nonatomic) bool is_group;
/// 消息时间
@property (nonatomic) long timestamp;
/// 状态
@property (nonatomic) int state;
/// 消息内容
@property (nonatomic, strong) NSString* content;
/// 消息类型
@property (nonatomic, strong) NSString* content_type;
/// 是否已读
@property (nonatomic) int read;
/// 消息唯一id（终端生成）
@property (nonatomic, strong) NSString* unique_id;
/// 错误码
@property (nonatomic) int error_code;
/// 缩略图路径
@property (nonatomic, strong) NSString* thumb_path;
/// 缩略图url
@property (nonatomic, strong) NSString* thumb_url;
/// 文件路径
@property (nonatomic, strong) NSString* file_path;
/// 文件url
@property (nonatomic, strong) NSString* file_url;
/// 文件过期，用于发送
@property (nonatomic) int file_expire;
/// 文件大小
@property (nonatomic) int total_size;
/// 传输大小
@property (nonatomic) int tranfer_size;
/// 文件时长（语音，视频等）
@property (nonatomic) int duration;
/// 额外数据（用户自定义）
@property (nonatomic, strong) NSString* extra;
/// 服务器消息时间
@property (nonatomic) long server_timestamp;
/// 服务器消息id
@property (nonatomic) long server_message_id;
/// 会话服务器id
@property (nonatomic, strong) NSString* server_uid;
/// 发送者 ServerUid
@property (nonatomic, strong) NSString* server_sender_uid;
/// 本地额外数据1（用户自定义）
@property (nonatomic, strong) NSString* local_extra1;
/// 本地额外数据2（用户自定义）
@property (nonatomic, strong) NSString* local_extra2;
/// 回复消息服务器id
@property (nonatomic) long orig_server_message_id;
/// 此消息被回复数
@property (nonatomic) int reply_count;
/// 是否是 @ 我的消息
@property (nonatomic) bool at_me;
/// 是否是 @All 的消息
@property (nonatomic) bool at_all;
/// 是否是 @ 我的消息
@property (nonatomic, strong) NSArray<NSString*>* at_server_uid_list;

/// 非数据库字段，用于合并转发解析后的数据对象
@property (nonatomic, strong) JCMergeForwardData* merge_forward_data;
/// 非数据库字段，用于回复消息解析后的数据对象
@property (nonatomic, strong) JCReplyMessageData* reply_message_data;

@end

#pragma mark JCMergeForwardData

/// 合并转发消息数据
@interface JCMergeForwardData : NSObject
/// 标题
@property (nonatomic, strong) NSString* title;
/// 消息队列
@property (nonatomic, strong) NSArray<JCConversationMessageData*>* messages;
/// 转化为json
/// @param title 标题
/// @param messages 消息队列
+(NSString*)toMergeForwardJson:(NSString*)title messages:(NSArray<JCConversationMessageData*>*)messages;
/// json转化为合并转发消息对象
/// @param json 合并转发消息 json
+(JCMergeForwardData*)parseMergeForwardJson:(NSString*)json;

@end

#pragma mark JCReplyMessageData
/// 回复消息
@interface JCReplyMessageData : NSObject
/// 被回复的消息服务器id
@property (nonatomic) long orig_server_message_id;
/// 昵称
@property (nonatomic, strong) NSString* display_name;
/// 内容
@property (nonatomic, strong) NSString* content;
/// 消息类型
@property (nonatomic, strong) NSString* content_type;
/// 将回复消息对象转换为 NSDictionary 对象
/// @param message 消息对象
/// @param origServerMessageId 消息服务器id
+(NSDictionary<NSString*, NSObject*>*)toReplyDic:(JCConversationMessageData*)message origServerMessageId:(long)origServerMessageId;
/// json转化为回复消息对象
/// @param json 回复消息 json
+(JCReplyMessageData*)parseReplyJson:(NSString*)json;

@end

#pragma mark JCServerConversationData
/// 服务器会话
@interface JCServerConversationData : NSObject
/// 服务器会话id
@property (nonatomic, strong) NSString* server_uid;
/// 本地已接收的消息最小的服务器id
@property (nonatomic) long local_recv_min_id;
/// 本地已读消息服务器id
@property (nonatomic) long local_read_id;
/// 本地已收消息服务器id
@property (nonatomic) long local_recv_id;
/// 对端已读消息服务器id（服务器记录）（一对一）
@property (nonatomic) long other_read_id;
/// 对端已读消息服务器id（服务器记录）（一对一）
@property (nonatomic) long other_recv_id;
/// 自己已读消息服务器id（服务器记录）
@property (nonatomic) long self_read_id;
/// 会话总消息数（服务器记录）
@property (nonatomic) long server_total;
/// 上次与服务器同步信息时间
@property (nonatomic) long update_time;
/// 最后一条消息时间戳
@property (nonatomic) long last_message_time;
/// 最后一条消息概述
@property (nonatomic, strong) NSString* last_message_brief;

-(NSString*)toString;

@end

#pragma mark JCMessageSearchData
/// 索索结果数据
@interface JCMessageSearchData : NSObject
/// 会话信息
@property (nonatomic, strong) JCConversationData* conversation;
/// 最后一条匹配消息信息
@property (nonatomic, strong) JCConversationMessageData* lastMessageData;
/// 消息条数
@property (nonatomic) long count;

@end

#pragma mark JCGroupData
/// 群数据
@interface JCGroupData : NSObject
/// id
@property (nonatomic) long _id;
/// 群服务器 uid
@property (nonatomic, strong) NSString* server_uid;
/// 群名称
@property (nonatomic, strong) NSString* name;
/// 群别名
@property (nonatomic, strong) NSString* nick_name;
/// 群头像
@property (nonatomic, strong) NSString* icon;
/// 群类型
@property (nonatomic) int type;
/// 群自定义属性集
@property (nonatomic, strong) NSDictionary* custom_properties;
/// 群本端设置的 tag
@property (nonatomic, strong) NSString* tag;
/// 免打扰
@property (nonatomic) bool dnd;
/// 群详情更新时间
@property (nonatomic) long update_time;
/// 群最后活跃时间
@property (nonatomic) long active_time;
@end

#pragma mark JCGroupMemberData
/// 群成员数据
@interface JCGroupMemberData : NSObject
/// id
@property (nonatomic) long _id;
/// 用户服务器 uid
@property (nonatomic, strong) NSString* member_server_uid;
/// 用户 userId
@property (nonatomic, strong) NSString* user_id;
/// 用户头像
@property (nonatomic, strong) NSString* icon;
/// 用户群昵称
@property (nonatomic, strong) NSString* display_name;
/// 用户角色
@property (nonatomic) int role;
/// 用户状态
@property (nonatomic) int status;
/// 群服务器 uid
@property (nonatomic, strong) NSString* group_server_uid;

@end

#pragma mark JCGroupNotificationData
/// 群通知数据
@interface JCGroupNotificationData : NSObject
/// id
@property (nonatomic) long _id;
/// 通知类型
@property (nonatomic) int type;
/// 服务器通知 id
@property (nonatomic) int apply_id;
/// 群服务器 uid
@property (nonatomic, strong) NSString* group_server_uid;
/// 群名称
@property (nonatomic, strong) NSString* group_name;
/// 用户对象服务器 uid
@property (nonatomic, strong) NSString* member_server_uid;
/// 用户对象昵称
@property (nonatomic, strong) NSString* member_name;
/// 信息
@property (nonatomic, strong) NSString* info;
/// 时间
@property (nonatomic) long timestamp;
/// 状态
@property (nonatomic) int state;

@end

#pragma mark JCGroupSearchData
/// 群搜索数据
@interface JCGroupSearchData : NSObject
/// 群
@property (nonatomic, strong) JCGroupData* group;
/// 成员列表
@property (nonatomic, strong) JCGroupMemberData* member;

@end

#pragma mark JCServerContactData
/// 服务器联系人数据
@interface JCServerContactData : NSObject
/// server uid
@property (nonatomic, strong) NSString* server_uid;
/// 类型
@property (nonatomic) JCAccountContactType type;
/// 昵称
@property (nonatomic, strong) NSString* display_name;
/// tag
@property (nonatomic, strong) NSDictionary* tag;
/// 免打扰
@property (nonatomic) bool dnd;
/// user_id
@property (nonatomic, strong) NSString* user_id;

@end

#pragma mark JCReplySearchData
/// 回复消息搜索数据
@interface JCReplySearchData : NSObject
/// 原始消息，可能为空
@property (nonatomic, strong) JCConversationMessageData* orig_message;
/// 回复消息列表
@property (nonatomic, strong) NSArray<JCConversationMessageData*>* replyMessages;

@end

#pragma mark JCCloudDatabase

@interface JCCloudDatabase : NSObject

/**
 *  @brief  打开数据库
 *  @return
 */
+(bool)open:(NSString*)name;

/**
 *  @brief  关闭数据库
 */
+(void)close;

#pragma mark conversation

/**
 *  @brief  获得会话本地 id
 *  @param  serverUid 服务器会话 uid，一对一实际是对方的个人 uid，群组 id 要创建成功才能获得
 *  @return 会话id，没有返回 -1
 */
+(long)getConversation:(NSString* __nonnull)serverUid;

/**
 *  @brief  获得会话本地id，没有则创建
 *  @param  type 会话类型，一对一和群聊
 *  @param  serverUid 服务器会话 uid，一对一实际是对方的个人 uid，群组 id 要创建成功才能获得
 *  @param  name    会话名字，只针对一对一会话有效
 *  @return 会话id，失败返回 -1
 */
+(long)getOrCreateConversation:(JCConversationType)type serverUid:(NSString* __nonnull)serverUid name:(NSString* __nullable)name;

/**
 *  @brief  获得会话本地id，没有则创建
 *  @param  type 会话类型，一对一和群聊
 *  @param  serverUid 服务器会话 uid，一对一实际是对方的个人 uid，群组 id 要创建成功才能获得
 *  @param  name    会话名字，只针对一对一会话有效
 *  @param  lastActiveTime  最后活跃时间,  <=0 则按当前时间
 *  @return 会话id，失败返回 -1
 */
+(long)getOrCreateConversation:(JCConversationType)type serverUid:(NSString* __nonnull)serverUid name:(NSString* __nullable)name lastActiveTime:(long)lastActiveTime;

/**
 *  @brief  删除会话
 *  @param  conversationId 本地会话 id
 */
+(void)deleteConversation:(long)conversationId;

/**
 *  @brief 删除所有会话
 */
+(void)deleteAllConversations;

/**
 *  @brief  更新会话信息
 *  @param  conversationId 本地会话 id
 */
+(void)updateConversation:(JCConversationData*)oldConversationData;

/**
 *  @brief  更新会话名字
 *  @param  serverUid 会话服务器id
 *  @param  name    会话名字
 */
+(void)updateConversationNameIfNeed:(NSString*)serverUid name:(NSString*)name;

/**
 *  @brief  设置会话所有消息本地已读
 *  @param  conversationId 本地会话 id
 */
+(void)markConversationRead:(long)conversationId;

/**
 *  @brief  查询所有会话
 */
+(NSArray<JCConversationData*>*)queryConversations;

/**
 *  @brief  查询单个会话
 */
+(JCConversationData*)queryConversation:(long)conversationId;

/**
 *  @brief  通过 ServerUid 查询会话
 */
+(JCConversationData*)queryConversationByServerUid:(NSString*)serverUid;

/**
 *  @brief  设置会话置顶
 *  @param  serverUid 服务器会话id
 *  @param  priority 置顶值，置顶会话按照这个排序
 *  @param  dnd 是否免打扰
 */
+(void)updateConversationPriorityAndDndIfNeed:(NSString*)serverUid priority:(long)priority dnd:(bool)dnd;

/**
 *  @brief  保存草稿
 *  @param  conversationId 会话数据库id
 *  @param  content 文本内容
 *  @param  contentType 类型
 *  @param  filePath 文件路径
 */
+(void)saveDraft:(long)conversationId content:(NSString*)content contentType:(NSString*)contentType filePath:(NSString*)filePath;

/**
 *  @brief  清除草稿
 *  @param  conversationId 会话数据库id
 */
+(void)clearDraft:(long)conversationId;

/**
 *  @brief  获得所有的未读消息数
 *  @param  conversationId 会话数据库id
 *  @param  includeDndConversation 是否包含免打扰会话
 */
+(long)getToltalUnreadMessageCount:(bool)includeDndConversation;

/**
 *  @brief  更新会话图标
 *  @param  serverUid 服务器会话 uid
 *  @param  icon    会话图标
 */
+(void)updateConversationIconIfNeed:(NSString * __nonnull)serverUid icon:(NSString *)icon;

#pragma mark message

/**
 *  @brief  将通话消息插入数据库
 *  @param  serverUid 会话服务器id
 *  @param  senderUid 发送者服务器id
 *  @param  item 通话对象
 *  @return 消息id，失败返回 -1
 */
+(long)addCallMessage:(NSString* __nonnull)serverUid senderUid:(NSString* __nonnull)senderUid contentType:(NSString *)contentType item:(JCCallItem*)item;

/**
 *  @brief  用于将发送文本消息插入数据库
 *  @param  type 会话类型
 *  @param  serverUid 会话服务器id
 *  @param  senderUid 发送者服务器id
 *  @param  contentType 文本消息类型
 *  @param  content 文本内容
 *  @param  extraParams 额外参数
 *  @param  atAll       是否@群体成员，针对群消息
 *  @param  atServerUidList   @成员的serverUid列表 针对群消息
 *  @return 消息id，失败返回 -1
 */
+(long)addMessage:(JCMessageChannelType)type serverUid:(NSString* __nonnull)serverUid senderUid:(NSString* __nonnull)senderUid contentType:(NSString* __nonnull)contentType content:(NSString* __nonnull)content extra:(NSDictionary* __nullable)extraParams atAll:(bool)atAll atServerUidList:(NSArray<NSString*>* __nullable)atServerUidList;

/**
*  @brief 用于将发送文件消息插入数据库
*  @return 消息id，失败返回 -1
*/
+(long)addMessage:(JCMessageChannelType)type serverUid:(NSString* __nonnull)serverUid senderUid:(NSString* __nonnull)senderUid contentType:(NSString* __nonnull)contentType filePath:(NSString* __nonnull)filePath thumbPath:(NSString* __nullable)thumbPath size:(int)size duration:(int)duration extraParams:(NSDictionary* __nullable)extraParams expiredSeconds:(int)expiredSeconds atAll:(bool)atAll atServerUidList:(NSArray<NSString*>* __nullable)atServerUidList;

/**
 *  @brief  用于将接收的消息插入数据库，
 *  @param  item 消息对象
 *  @param  notify 是否触发上层通知
 *  @return 消息id，失败返回 -1
 */
+(long)addMessage:(JCMessageChannelItem* __nonnull)item notify:(bool)notify;

/**
 *  @brief  更新消息状态
 *  @param  messageId 消息数据库id
 */
+(void)updateMessageState:(long)messageId state:(JCMessageChannelItemState)state;

/**
 *  @brief  更新消息发送结果
 *  @param  item 消息对象
 */
+(void)updateMessage:(JCMessageChannelItem* __nonnull)item;

/**
 *  @brief  更新文件传输进度
 *  @param  messageId 消息数据库id
 *  @param  transferSize 传输大小，字节数
 */
+(void)updateMessageProgress:(long)messageId transferSize:(int)transferSize totalSize:(int)totalSize;

/**
 *  @brief  更新文件路径
 *  @param  messageId 消息数据库id
 *  @param  filePath 文件路径
 */
+(void)updateMessageFilePath:(long)messageId filePath:(NSString* __nonnull)filePath;

/**
 *  @brief  更新文件缩略图路径
 *  @param  messageId 消息数据库id
 *  @param  filePath 文件路径
 */
+(void)updateMessageThumbPath:(long)messageId thumbPath:(NSString* __nonnull)thumbPath;

/**
 *  @brief  更新文件路径和大小
 *  @param  messageId 消息数据库id
 *  @param  filePath 文件路径
 *  @param  size 文件大小
 */
+(void)updateMessageFilePathSize:(long)messageId filePath:(NSString* __nonnull)filePath size:(int)size;

/**
 *  @brief  更新消息错误码
 *  @param  messageId 消息数据库id
 *  @param  errorCode 错误码
 */
+(void)updateMessageErrorCode:(long)messageId errorCode:(int)errorCode;

/**
 *  @brief  删除消息
 *  @param  messageId 消息数据库id
 */
+(void)deleteMessage:(long)messageId;

/**
 *  @brief  删除消息
 *  @param  messageId 消息数据库id
 */
+(void)deleteMessages:(NSArray<NSNumber*>*)messageIds;

/**
 *  @brief  删除会话所有消息
 *  @param  conversationId 会话数据库id
 */
+(void)deleteMessagesByConversationId:(long)conversationId;

/**
 *  @brief  查询本地数据库消息
 *  @param  conversationId 会话数据库id
 *  @param  count 消息条数,  -1 表示符合条件的所有消息
 *  @param  timestamp 时间位置，-1 表示从最新开始查之前的
 *  @param  beforeTimestamp timestamp 不为 -1 才有意义， true 表示在 timestamp 值之前的消息，不包含该时间消息
 *  @return 消息列表
 */
+(NSArray<JCConversationMessageData*>*)queryMessages:(long)conversationId count:(int)count timestamp:(long)lastTimestamp beforeTimestamp:(bool)beforeTimestamp;

/**
 *  @brief  查询一条消息
 *  @param  messageId 消息数据库id
 *  @return 消息对象, 没有则返回 nil
 */
+(JCConversationMessageData*)queryMessage:(long)messageId;

/**
 *  @brief  查询最后一条消息本地数据库 id
 *  @param  conversationId 会话数据库 id
 *  @return 本地数据库消息id
 */
+(long)getLastMessageId:(long)conversationId;

/**
 *  @brief  查询最后一条有服务器标识的消息服务器id
 *  @param  conversationId 会话数据库id
 *  @return 服务器消息id
 */
+(long)getLastServerMessageId:(long)conversationId;

/**
 *  @brief  搜索本地文本消息
 *  @param  key 搜索关键字
 *  @param  conversationId 会话id，-1表示所有会话
 */
+(NSArray<JCConversationMessageData*>*)searchMessage:(NSString* __nonnull)key contentTypes:(NSArray<NSString*>* __nonnull)contentTypes conversationId:(long)conversationId;

/**
 *  @brief  搜索包含搜索关键字的会话信息
 *  @param  key 搜索关键字
 *  @return JCMessageSearchData 列表
 */
+(NSArray<JCMessageSearchData*>*)searchMessageConversationInfo:(NSString* __nonnull)key contentTypes:(NSArray<NSString*>* __nonnull)contentTypes;

/**
 *  @brief  根据消息类型搜索本地消息，一般用于搜索文件消息
 *  @param  contentType 消息类型
 *  @param  conversationId 会话id，-1表示所有会话
 */
+(NSArray<JCConversationMessageData*>*)searchMessageByContentType:(NSArray<NSString*>* __nonnull)contentTypes conversationId:(long)conversationId;

/**
 *  @brief  更新本地额外数据1
 *  @param  messageId 消息数据库id
 *  @param  extra 额外数据
 */
+(void)updateMessageLocalExtra1:(long)messageId extra:(NSString*)extra1;

/**
 *  @brief  更新本地额外数据2
 *  @param  messageId 消息数据库id
 *  @param  extra 额外数据
*/
+(void)updateMessageLocalExtra2:(long)messageId extra:(NSString*)extra2;

/**
 *  @brief 查询回复的消息
 *  @param serverMessageId 消息数据库id
 */
+(JCReplySearchData*)searchReplyData:(long)serverMessageId;

#pragma mark uid

/**
 *  @brief  保存 userId 和 serverUid
 *  @param  userId 登录用户id
 *  @param  serverUid 服务器用户uid
 */
+(void)saveUserServerUid:(NSString* __nonnull)userId serverUid:(NSString* __nonnull)serverUid;

/**
 *  @brief  根据 userId 查询 serverUid
 *  @param  userId 登录用户id
 */
+(NSString*)getServerUidByUserId:(NSString* __nonnull)userId;

/**
 *  @brief  根据 serverUid 查询 userId
 *  @param  serverUid 服务器用户uid
 */
+(NSString*)getUserIdByServerUid:(NSString* __nonnull)serverUid;

/**
 *  @brief  设置最后一次服务器更新时间
 *  @param updateTime 最后一次服务器更新时间
 */
+(void)setServerContactsQueryTime:(long)updateTime;

/**
 *  @brief  获得最后一次服务器更新时间
 *  @return 最后一次服务器更新时间
 */
+(long)getServerContactsQueryTime;

/**
 *  @brief 保存服务器联系人
 *  @param contact JCAccountContact 对象
 */
+(void)dealServerContact:(JCAccountContact*)contact;

/**
 *  @brief 查询本地保存的服务器联系人
 *  @param serverUid 服务器的会话 id
 *  @return JCServerContactData 对象
 */
+(JCServerContactData*)queryServerContact:(NSString*)serverUid;

/**
 *  @brief 查询本地保存的服务器联系人列表
 *  @return JCServerContactData 对象列表
 */
+(NSArray<JCServerContactData*>*)queryServerContacts;

#pragma mark ServerConversation

/**
 *  @brief  保存服务器的会话信息
 *  @param  conversation 服务器的会话信息
 */
+(void)saveServerConversation:(JCMessageChannelConversation* __nonnull)conversation;

/**
 *  @brief  如果存在该 serverUid 则不插入，不存在则插入一条初始数据
 *  @param  serverUid 服务器的会话 id
 */
+(void)saveServerConversationByServerUidIfNeed:(NSString* __nonnull)serverUid;

/**
 *  @brief  更新本地已读最新服务器消息 id
 *  @param  serverUid 服务器的会话 id
 *  @param  serverMessageId 服务器的消息 id
 */
+(void)updataServerConversationLocalRead:(NSString* __nonnull)serverUid serverMessageId:(long)serverMessageId;

/**
 *  @brief  更新本地已收最新服务器消息 id
 *  @param  serverUid 服务器的会话 id
 *  @param  serverMessageId 服务器的消息 id
*/
+(void)updataServerConversationLocalRecv:(NSString* __nonnull)serverUid serverMessageId:(long)serverMessageId;

/**
 *  @brief  更新对端已读最新服务器消息 id
 *  @param  serverUid 服务器的会话 id
 *  @param  serverMessageId 服务器的消息 id
*/
+(void)updataServerConversationOtherRead:(NSString* __nonnull)serverUid serverMessageId:(long)serverMessageId;

/**
 *  @brief  更新对端已收最新服务器消息 id
 *  @param  serverUid 服务器的会话 id
 *  @param  serverMessageId 服务器的消息 id
*/
+(void)updataServerConversationOtherRecv:(NSString* __nonnull)serverUid serverMessageId:(long)serverMessageId;

/**
 *  @brief  更新自己已读最新服务器消息 id
 *  @param  serverUid 服务器的会话 id
 *  @param  serverMessageId 服务器的消息 id
*/
+(void)updataServerConversationSelfRead:(NSString* __nonnull)serverUid serverMessageId:(long)serverMessageId;

/**
 *  @brief  查询所有服务会话
 *  @return 服务器会话列表
 */
+(NSArray<JCServerConversationData*>*)queryServerConversations;

/**
 *  @brief  查询服务会话
 *  @param serverUid 服务器会话uid
 *  @return 服务器会话列表
 */
+(JCServerConversationData*)queryServerConversation:(NSString*)serverUid;

/**
 *  @brief  设置整体最后一次服务器更新时间
 *  @param time 整体最后一次服务器更新时间
 */
+(void)setServerConversationQueryTime:(long)updateTime;

/**
 *  @brief  获得整体最后一次服务器更新时间
 *  @return 整体最后一次服务器更新时间
 */
+(long)getServerConversationQueryTime;

/**
 *  @brief   获得所有没有 userId 的一对一会话
 *  @return serverUid 列表
 */
+(NSArray<NSString*>*)queryNoUserId1To1Conversations;

#pragma mark Group

/**
 *  @brief   查询所有群组
 *  @return 群组列表
 */
+(NSArray<JCGroupData*>*)queryGroups;

/**
 *  @brief   查询群
 *  @param  serverUid 群服务器 uid
 *  @return 群组对象
 */
+(JCGroupData*)queryGroup:(NSString* __nonnull)serverUid;

/**
 *  @brief   查询群成员列表
 *  @param  serverUid 群服务器 uid
 *  @return 成员列表
 */
+(NSArray<JCGroupMemberData*>*)queryGroupMembers:(NSString* __nonnull)groupServerUid;

/**
 *  @brief   查询单个成员
 *  @param  serverUid 群服务器 uid
 *  @param  memberServerUid 成员ServerUid
 *  @return 成员对象
 */
+(JCGroupMemberData*)queryGroupMember:(NSString* __nonnull)serverUid memberServerUid:(NSString* __nonnull)memberServerUid;

/**
 *  @brief  查询创建的群
 *  @param  memberSeverUid 创建者 serverUid
 *  @return 群列表
 */
+(NSArray<JCGroupData*>*)queryOwnedGroups:(NSString* __nonnull)memberSeverUid;

/**
 *  @brief  查询加入的群
 *  @param  memberSeverUid 创建者 serverUid
 *  @return 群列表
 */
+(NSArray<JCGroupData*>*)queryJoinedGroups:(NSString* __nonnull)memberSeverUid;

/**
 * @brief 搜索包括关键字的群（群名，群别名，群成员），没有匹配成员则 JCGroupSearchData 的 member 为空
 * @param key 搜索关键字
 * @param includNickName 是否包含搜索群的 nickName
 */
+(NSArray<JCGroupSearchData*>*)searchGroup:(NSString* __nonnull)key includNickName:(bool)includNickName;

#pragma mark GroupNotification

+(void)addInvite:(int)applyId groupId:(NSString*)groupId groupName:(NSString*)groupName memberServerUid:(NSString*)memberServerUid memberName:(NSString*)memberName info:(NSString*)info send:(bool)send;

+(NSArray<JCGroupNotificationData*>*)queryGroupNotifications;

+(JCGroupNotificationData*)queryGroupNotification:(int)applyId;

@end

NS_ASSUME_NONNULL_END
