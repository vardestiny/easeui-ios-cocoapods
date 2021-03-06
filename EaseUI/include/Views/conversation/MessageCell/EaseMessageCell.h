//
//  EaseMessageCell.h
//  ChatDemo-UI3.0
//
//  Created by dhc on 15/6/26.
//  Copyright (c) 2015年 easemob.com. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "IModelChatCell.h"
#import "IMessageModel.h"

#import "EaseBubbleView.h"

#define kEMMessageImageSizeWidth 120
#define kEMMessageImageSizeHeight 120
#define kEMMessageLocationHeight 95
#define kEMMessageVoiceHeight 23

extern CGFloat const EaseMessageCellPadding;

typedef enum{
    EaseMessageCellEvenVideoBubbleTap,
    EaseMessageCellEventLocationBubbleTap,
    EaseMessageCellEventImageBubbleTap,
    EaseMessageCellEventAudioBubbleTap,
    EaseMessageCellEventFileBubbleTap,
    EaseMessageCellEventCustomBubbleTap,
}EaseMessageCellTapEventType;

@protocol EaseMessageCellDelegate;
@interface EaseMessageCell : UITableViewCell<IModelChatCell>
{
    UIButton *_statusButton;
    UILabel *_hasRead;
    EaseBubbleView *_bubbleView;
    UIActivityIndicatorView *_activity;

    
    NSLayoutConstraint *_statusWidthConstraint;
}

@property (weak, nonatomic) id<EaseMessageCellDelegate> delegate;

@property (nonatomic, strong) UIActivityIndicatorView *activity;

@property (strong, nonatomic) UIImageView *avatarView;

@property (strong, nonatomic) UILabel *nameLabel;

@property (strong, nonatomic) UIButton *statusButton;

@property (strong, nonatomic) UILabel *hasRead;

@property (strong, nonatomic) EaseBubbleView *bubbleView;

@property (strong, nonatomic) id<IMessageModel> model;

/*!
 @property
 @brief 状态尺寸
 */
@property (nonatomic) CGFloat statusSize UI_APPEARANCE_SELECTOR; //default 20;

/*!
 @property
 @brief 状态尺寸
 */
@property (nonatomic) CGFloat activitySize UI_APPEARANCE_SELECTOR; //default 20;

/*!
 @property
 @brief 气泡最大宽度
 */
@property (nonatomic) CGFloat bubbleMaxWidth UI_APPEARANCE_SELECTOR; //default 200;

/*!
 @property
 @brief 气泡偏移
 */
@property (nonatomic) UIEdgeInsets bubbleMargin UI_APPEARANCE_SELECTOR; //default UIEdgeInsetsMake(8, 0, 8, 0);

/*!
 @property
 @brief 接收消息气泡偏移
 */
@property (nonatomic) UIEdgeInsets leftBubbleMargin UI_APPEARANCE_SELECTOR; //default UIEdgeInsetsMake(8, 15, 8, 10);

/*!
 @property
 @brief 发送消息气泡偏移
 */
@property (nonatomic) UIEdgeInsets rightBubbleMargin UI_APPEARANCE_SELECTOR; //default UIEdgeInsetsMake(8, 10, 8, 15);

/*!
 @property
 @brief 接收消息气泡图片
 */
@property (strong, nonatomic) UIImage *sendBubbleBackgroundImage UI_APPEARANCE_SELECTOR;

/*!
 @property
 @brief 发送消息气泡图片
 */
@property (strong, nonatomic) UIImage *recvBubbleBackgroundImage UI_APPEARANCE_SELECTOR;

/*!
 @property
 @brief 消息字体
 */
@property (nonatomic) UIFont *messageTextFont UI_APPEARANCE_SELECTOR; //default [UIFont systemFontOfSize:15];

/*!
 @property
 @brief 消息字体颜色
 */
@property (nonatomic) UIColor *messageTextColor UI_APPEARANCE_SELECTOR; //default [UIColor blackColor];

/*!
 @property
 @brief 位置消息字体
 */
@property (nonatomic) UIFont *messageLocationFont UI_APPEARANCE_SELECTOR; //default [UIFont systemFontOfSize:12];

/*!
 @property
 @brief 位置消息字体颜色
 */
@property (nonatomic) UIColor *messageLocationColor UI_APPEARANCE_SELECTOR; //default [UIColor whiteColor];

/*!
 @property
 @brief 发送语音消息播放图片数组
 */
@property (nonatomic) NSArray *sendMessageVoiceAnimationImages UI_APPEARANCE_SELECTOR;

/*!
 @property
 @brief 接收语音消息播放图片数组
 */
@property (nonatomic) NSArray *recvMessageVoiceAnimationImages UI_APPEARANCE_SELECTOR;

/*!
 @property
 @brief 语音消息字体颜色
 */
@property (nonatomic) UIColor *messageVoiceDurationColor UI_APPEARANCE_SELECTOR; //default [UIColor grayColor];

/*!
 @property
 @brief 语音消息字体
 */
@property (nonatomic) UIFont *messageVoiceDurationFont UI_APPEARANCE_SELECTOR; //default [UIFont systemFontOfSize:12];

/*!
 @property
 @brief 文件消息字体
 */
@property (nonatomic) UIFont *messageFileNameFont UI_APPEARANCE_SELECTOR; //default [UIFont systemFontOfSize:13];

/*!
 @property
 @brief 文件消息字体颜色
 */
@property (nonatomic) UIColor *messageFileNameColor UI_APPEARANCE_SELECTOR; //default [UIColor blackColor];

/*!
 @property
 @brief 文件消息字体
 */
@property (nonatomic) UIFont *messageFileSizeFont UI_APPEARANCE_SELECTOR; //default [UIFont systemFontOfSize:11];

/*!
 @property
 @brief 文件消息字体颜色
 */
@property (nonatomic) UIColor *messageFileSizeColor UI_APPEARANCE_SELECTOR; //default [UIColor grayColor];

- (instancetype)initWithStyle:(UITableViewCellStyle)style
              reuseIdentifier:(NSString *)reuseIdentifier
                        model:(id<IMessageModel>)model;

+ (NSString *)cellIdentifierWithModel:(id<IMessageModel>)model;

+ (CGFloat)cellHeightWithModel:(id<IMessageModel>)model;

@end

@protocol EaseMessageCellDelegate <NSObject>

@optional

- (void)messageCellSelected:(id<IMessageModel>)model;

- (void)statusButtonSelcted:(id<IMessageModel>)model withMessageCell:(EaseMessageCell*)messageCell;

- (void)avatarViewSelcted:(id<IMessageModel>)model;

@end

