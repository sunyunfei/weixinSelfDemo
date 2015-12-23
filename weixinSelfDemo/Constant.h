//
//  Constant.h
//  SDKSample
//
//  Created by Jeason on 15/7/14.
//
//

#ifndef SDKSample_Constant_h
#define SDKSample_Constant_h

#define RGBCOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]

#define TIPSLABEL_TAG 10086
#define SCREEN_WIDTH [[UIScreen mainScreen] bounds].size.width
#define SCREEN_HEIGHT [[UIScreen mainScreen] bounds].size.height
#define BUFFER_SIZE 1024 * 100

static const int kHeadViewHeight = 135;
static const int kSceneViewHeight = 100;

static NSString *kAuthScope = @"snsapi_message,snsapi_userinfo,snsapi_friend,snsapi_contact";
static NSString *kAuthOpenID = @"0c806938e2413ce73eef92cc3";
static NSString *kFileTitle = @"iphone4.pdf";
static const NSInteger kRecvGetMessageReqAlertTag = 1000;
static const NSInteger kProfileAppIdAlertTag = 2000;
static const NSInteger kProfileUserNameAlertTag = 3000;
static const NSInteger kBizWebviewAppIdAlerttag = 4000;
static const NSInteger kBizWebviewTousernameAlertTag = 6000;

static NSString *kProfileExtMsg = @"http://we.qq.com/d/AQCIc9a3EqRfb19z8WnLB6iFNCxX5bO2S3lHwMQL";
static NSString *kBizWebviewExtMsg = @"KOoCKdavezBjdj2wJZsq67N2j_g3XEQ5JP_pkLhBYS4";

#endif
