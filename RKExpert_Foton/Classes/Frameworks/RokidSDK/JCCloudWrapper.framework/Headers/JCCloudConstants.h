//
//  JCCloudConstants.h
//  JCCloudWrapper
//
//  Created by maikireton on 2019/11/15.
//  Copyright © 2019 ireton. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark 消息类型
/// 群头像key
extern NSString* const JCGroupIconPropertyKey;
/// 合并转发类型
extern NSString* const JCMessageContentTypeMergeForward;
/// 回复类型
extern NSString* const JCMessageContentTypeReplyMessage;

#pragma mark 会话类型

/// 会话类型
typedef NS_ENUM(NSInteger, JCConversationType) {
    /// 一对一
    JCConversationType1To1 = JCMessageChannelType1To1,
    /// 群组
    JCConversationTypeGroup = JCMessageChannelTypeGroup,
};

/// 群通知类型
typedef NS_ENUM(NSInteger, JCGroupNotificationType) {
    /// 发出的邀请
    JCGroupNotificationTypeSendInvite,
    /// 收到的邀请
    JCGroupNotificationTypeRecvInvite,
};

/// 群通知状态
typedef NS_ENUM(NSInteger, JCGroupNotificationState) {
    /// 未处理
    JCGroupNotificationStateNotDeal,
    /// 接受
    JCGroupNotificationStateAccept,
    /// 拒绝
    JCGroupNotificationStateReject,
};
