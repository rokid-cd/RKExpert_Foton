//
//  JCMessageWrapper.h
//  JCCloudWrapper
//
//  Created by maikireton on 2019/11/15.
//  Copyright © 2019 ireton. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^MessageOperationBlock)(bool, int, NSObject* __nullable);

@interface JCMessageWrapper : NSObject

/**
 *  @brief  发送文本消息
 *  @param  type    消息所属会话类型
 *  @param  serverUid    会话服务器 id，一对一必须先获得对方 userId 的 serverUid，群聊必须先获得群的 serverUid
 *  @param  contentType    消息类型
 *  @param  content    消息内容
 *  @param  extra    额外信息
 *  @param  atAll       是否@群体成员，针对群消息
 *  @param  atServerUidList   @成员的serverUid列表 针对群消息
 */
+(void)sendText:(JCMessageChannelType)type serverUid:(NSString*)serverUid contentType:(NSString*)contentType content:(NSString*)content extraParams:(NSDictionary<NSString*, NSObject*>* _Nullable)extraParams atAll:(bool)atAll atServerUidList:(NSArray<NSString*>* __nullable)atServerUidList;

/**
 *  @brief  发送文件消息
 *  @param  type    消息所属会话类型
 *  @param  serverUid    会话服务器 id，一对一必须先获得对方 userId 的 serverUid，群聊必须先获得群的 serverUid
 *  @param  contentType    消息类型
 *  @param  filePath    文件本地路径
 *  @param  thumbPath    缩略图本地路径
 *  @param  size    文件大小
 *  @param  duration    时长
 *  @param  extraParams    额外信息
 *  @param expiredSeconds 过期秒数，-1表示永久
 *  @param  atAll       是否@群体成员，针对群消息
 *  @param  atServerUidList   @成员的serverUid列表 针对群消息
 */
+(void)sendFile:(JCMessageChannelType)type serverUid:(NSString*)serverUid contentType:(NSString*)contentType filePath:(NSString*)filePath thumbPath:(NSString* _Nullable)thumbPath size:(int)size duration:(int)duration extraParams:(NSDictionary<NSString*, NSObject*>* _Nullable)extraParams expiredSeconds:(int)expiredSeconds atAll:(bool)atAll atServerUidList:(NSArray<NSString*>* __nullable)atServerUidList;

/**
 *  @brief 停止文件传输，目前只有取消上传可以
 *  @param   messageId   数据库消息 id
 */
+(void)stopFile:(long)messageId;

/**
 *  @brief  续发送文件消息
 *  @param  messageId   数据库消息 id
 */
+(void)resumSendFile:(long)messageId;

/**
 * @brief   重发消息，只针对发送失败消息，会删除原先消息并重新生成一条
 * @param   messageId   数据库消息 id
 */
+(void)resendMessage:(long)messageId;

/**
 * @brief   转发消息，有文件url和文本消息都可以转发
 * @param   messageIds   数据库消息 id 列表
 * @param   serverUids 会话 serverUid 列表
 */
+(void)forwordMessage:(NSArray<NSNumber*>*)messageIds serverUids:(NSArray*)serverUids;

/**
 *  @brief  合并转发消息，有文件url和文本消息都可以转发
 *  @param  messageIds   数据库消息 id 列表
 *  @param  serverUids 会话 serverUid 列表
 *  @param  title 标题
 */
+(void)mergeForwordMessage:(NSArray<NSNumber*>*)messageIds serverUids:(NSArray*)serverUids title:(NSString*)title;

/**
 *  @brief  回复消息，必须有服务器消息id
 *  @param  messageId   本地数据库消息id
 *  @param  content 回复内容
 */
+(void)replyMessage:(long)messageId content:(NSString*)content;

/**
 *  @brief  下载文件
 *  @param  messageId   数据库消息 id
 *  @param  fileUrl    文件 url
 *  @param  savePath 保存路径
 */
+(void)downloadFile:(long)messageId fileUrl:(NSString*)fileUrl savePath:(NSString*)savePath;

/**
 *  @brief  下载文件，只会更新消息进度，不会更新消息状态，用于离线发送文件下载
 *  @param  messageId   数据库消息 id
 *  @param  fileUrl    文件 url
 *  @param  savePath 保存路径
 */
+(void)downloadFileOnly:(long)messageId fileUrl:(NSString*)fileUrl savePath:(NSString*)savePath;

/**
 *  @brief  下载文件，通过block上报状态
 *  @param  messageId   数据库消息 id
 *  @param  fileUrl    文件 url
 *  @param  savePath 保存路径
 *  @param  block 结果函数，obj 为 JCStorageItem 对象，JCStorageItem 不为空根据 JCStorageItem 中状态来处理
 */
+(void)downloadFileWithBlock:(NSString *)fileUrl savePath:(NSString *)savePath usingBlock:(MessageOperationBlock)block;

/**
 *  @brief  下载缩略图
 *  @param  messageId   数据库消息 id
 *  @param  thumbUrl    文件 url
 *  @param  savePath 保存路径
 */
+(void)downloadThumbFile:(long)messageId thumbUrl:(NSString *)thumbUrl savePath:(NSString *)savePath;

/**
 *  @brief  设置文件进度
 *  @param  messageId    数据库消息 id
 *  @param  transferSize    传输长度
 */
+(void)setFileProgress:(long)messageId transferSize:(int)transferSize;

/**
 *  @brief  设置文件上传结果
 *  @param  messageId    数据库消息 id
 *  @param  result    上传结果
 *  @param  fileUrl 文件url
 */
+(void)setFileUrl:(long)messageId result:(bool)result fileUrl:(NSString* _Nullable)fileUrl thumbUrl:(NSString*)thumbUrl;

/**
 *  @brief  设置处理完的文件
 *  @param  messageId 数据库消息 id
 *  @param  result 处理结果
 *  @param  dealedFilePath  处理后的文件路径
 *  @param  dealedFileSize 处理后的文件大小
 */
+(void)setPreDealFile:(long)messageId result:(bool)result dealedFilePath:(NSString* _Nullable)dealedFilePath dealedFileSize:(int)dealedFileSize;

/**
 *  @brief  将该会话所有消息置为已读，并按照内部逻辑设置服务器已读
 *  @param  conversationId 数据库会话 id
 */
+(void)markRead:(long)conversationId;

/**
 *  @brief 获取服务器会话列表
 *  @param beginTime   在此时间以后的活跃会话，单位毫秒，JCCloudDatabase 中 getServerConversationQueryTime 获得最后一次拉取的服务器时间
 *  @param block 结果函数，成功则 block 的 obj 为 JCServerConversationData 列表
 */
+(void)refreshConversations:(long)beginTime usingBlock:(MessageOperationBlock)block;

/**
 *  @brief 获取消息消息(数据库没有则从服务器拉取，拉取过被删的消息不会再拉取),该接口表示从 dbMessageId 开始往更早的取，总共取 count 条消息
 *  @param serverUid 会话服务器id
 *  @param dbMessageId 起始本地数据库消息id, -1 表示从最新一条开始取
 *  @param count 消息条数不包括(dbMessageId)
 *  @param block 结果函数，obj 无数据返回
 */
+(void)fetchMessages:(nonnull NSString*)serverUid dbMessageId:(long)dbMessageId count:(int)count usingBlock:(MessageOperationBlock)block;

/**
 *  @brief 撤回消息，针对自己发送成功的消息
 *  @param  type    消息所属会话类型
 *  @param  serverUid    会话服务器 id
 *  @param  dbMessageId    数据库消息id
 *  @param  block 结果函数，obj 无数据返回
 */
+(void)withdrawalMessage:(JCMessageChannelType)type serverUid:(nonnull NSString*)serverUid dbMessageId:(long)dbMessageId usingBlock:(MessageOperationBlock)block;

@end

NS_ASSUME_NONNULL_END
