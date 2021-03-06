//
//  ScoreBoardViewController.h
//  Chatty
//
//  Created by Eagle Du on 12/6/30.
//  Copyright (c) 2012年 GET. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LocalRoom.h"
#import "RoomDelegate.h"
#import "UIWaitForUserViewController.h"
#import "RoundRestTimeViewController.h"
#import "DDActionHeaderView.h"
#import "SoundsPlayer.h"
#import "KeyBoradEventInfo.h"
#import "ShowWinnerBox.h"
#import "UIFighterBox.h"

#define kWaitBoxForReset 1
#define kWaitBoxForReOrg 2
#define kUpdateTimeInterval 0.001

@class SelectWinnerBox;

@interface ScoreBoardViewController : UIViewController<RoomDelegate,UAModalPanelDelegate,UIFighterBoxDelegate>{
    LocalRoom* chatRoom;
    UILabel *lblGameName;
    UILabel *lblRedTotal;
    UILabel *lblBlueTotal;
    UITextView *txtHistory;
    UILabel *lblCoachName;
    NSTimer *timer;
    UIWaitForUserViewController *waitUserPanel;
    RoundRestTimeViewController *roundResetPanel;
    ShowWinnerBox *showWinnerBoxPanel;
    SelectWinnerBox *selectWinnerBoxPanel;
    DDActionHeaderView *actionHeaderView;
    NSTimer *gameLoopTimer;
    BOOL clientChange;
    NSMutableArray *cmdHis;
    NSMutableArray *marksFlags;
    NSMutableArray *marksGrayFlags;
    NSMutableArray *timeFlags;
    NSMutableArray *timeFlags2;
    NSMutableDictionary *scoreInfos;
    NSMutableArray *scoreReportIndicatorsBlue;
    NSMutableDictionary *scoreReportIndicatorTimersBlue;
    NSMutableArray *scoreReportIndicatorsRed;
    NSMutableDictionary *scoreReportIndicatorTimersRed;
    NSDictionary *scoreReportPointColors;
	NSTimer *calcTimer;
    //警告
    UIImage *imgWarning;
    //扣分
    UIImage *imgDecicade;
    NSTimer *pointGapTimer;
    NSTimer *warningMaxTimer;
    BOOL isAtMatchSetting;
    __strong SoundsPlayer *player;
}

@property (nonatomic, strong) IBOutlet UILabel *lblGameName;
@property (nonatomic, strong) IBOutlet UILabel *lblRedTotal;
@property (nonatomic, strong) IBOutlet UILabel *lblBlueTotal;
@property (nonatomic, strong) IBOutlet UILabel *lblCoachName;
@property (nonatomic, strong) IBOutlet UITextView *txtHistory;
@property(nonatomic,strong) LocalRoom* chatRoom;
@property (strong, nonatomic) IBOutlet UILabel *lblGameDesc;
@property (strong, nonatomic) IBOutlet UILabel *lblCortNo;
@property (strong, nonatomic) IBOutlet UILabel *lblArea;

@property (strong, nonatomic) IBOutlet UILabel *lblBluePlayerName;
@property (strong, nonatomic) IBOutlet UILabel *lblBluePlayerDesc;
@property (strong, nonatomic) IBOutlet UILabel *lblTime;
@property (strong, nonatomic) IBOutlet UILabel *lblRoundSeq;
@property (strong, nonatomic) IBOutlet UILabel *lblRedPlayerDesc;
@property (strong, nonatomic) IBOutlet UILabel *lblRedPlayerName;
@property(nonatomic, strong) DDActionHeaderView *actionHeaderView;
@property (strong, nonatomic) IBOutlet UILabel *lblScreening;
@property (strong, nonatomic) IBOutlet UIView *viewRedWarningBox;
@property (strong, nonatomic) IBOutlet UIView *viewBlueWarningBox;
@property (strong, nonatomic) IBOutlet UIView *viewBlueScore;
@property (strong, nonatomic) IBOutlet UIView *viewRedScore;
@property (strong, nonatomic) IBOutlet UIView *viewTime;
//十位数
@property (strong, nonatomic) IBOutlet UIImageView *imgBlueScoreDoubleTen;
//个位数
@property (strong, nonatomic) IBOutlet UIImageView *imgBlueScoreDoubleSin;

@property (strong, nonatomic) IBOutlet UIImageView *imgBlueScoreSingle;
@property (strong, nonatomic) IBOutlet UIImageView *imgRedScoreDoubleTen;
@property (strong, nonatomic) IBOutlet UIImageView *imgRedScoreDoubleSin;
@property (strong, nonatomic) IBOutlet UIImageView *imgRedScoreSingle;
@property (strong, nonatomic) IBOutlet UIImageView *imgRoundNum;
@property (strong, nonatomic) IBOutlet UIImageView *imgTimeMinus;
@property (strong, nonatomic) IBOutlet UIImageView *imgTimeSecTen;
@property (strong, nonatomic) IBOutlet UIImageView *imgTimeSecSin;
@property (strong, nonatomic) IBOutlet UIButton *btnShowSelectWinner;
@property (strong, nonatomic) IBOutlet UIImageView *imgScoreReportBlue1;
@property (strong, nonatomic) IBOutlet UIImageView *imgScoreReportBlue2;
@property (strong, nonatomic) IBOutlet UIImageView *imgScoreReportBlue3;
@property (strong, nonatomic) IBOutlet UIImageView *imgScoreReportBlue4;
@property (strong, nonatomic) IBOutlet UIImageView *imgScoreReportRed1;
@property (strong, nonatomic) IBOutlet UIImageView *imgScoreReportRed2;
@property (strong, nonatomic) IBOutlet UIImageView *imgScoreReportRed3;
@property (strong, nonatomic) IBOutlet UIImageView *imgScoreReportRed4;
@property (strong, nonatomic) IBOutlet UIFighterBox *fighterPanel;

// Exit back to the welcome screen
- (IBAction)exit;
- (void)exitWithSettingInfo:(NSArray *)nextProfileInfo;
- (void)exitProcess;

// View is active, start everything up
- (void)activate;

- (void)eraseText;

-(void)showWaitingUserBox;

-(void)goToNextMatch;
-(void)goToNextMatchWithProfileId:(NSString *)profileId startCourt:(int)courtSeq;

-(void)updateForGameSetting:(BOOL)hasChange;
-(void)duringSettingEndPress;

-(void)bluetoothKeyboardPressed:(KeyBoradEventInfo *)keyboardArgv;
- (IBAction)btnShowSelectWinnerPressed:(id)sender;

@end
