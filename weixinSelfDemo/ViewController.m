//
//  ViewController.m
//  weixinSelfDemo
//
//  Created by 孙云 on 15/12/23.
//  Copyright © 2015年 haidai. All rights reserved.
//

#import "ViewController.h"
#import "WXApiRequestHandler.h"
#import "WXApiManager.h"
@interface ViewController ()
- (IBAction)click:(id)sender;

- (IBAction)clickTZ:(id)sender;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
#warning ---
- (void)bizPay {
    NSString *res = [WXApiRequestHandler jumpToBizPay];
    if( ![@"" isEqual:res] ){
        UIAlertView *alter = [[UIAlertView alloc] initWithTitle:@"支付失败" message:res delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
        
        [alter show];
    }
    
}
- (IBAction)click:(id)sender {
    [self bizPay];
}
//微信跳转
- (IBAction)clickTZ:(id)sender {
    NSString *urlStr = [NSString stringWithFormat:@"weixin://dl/officialaccounts"];
    UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];
    pasteboard.string = @"洋礼物";
    [[UIApplication sharedApplication]openURL:[NSURL URLWithString:urlStr]];
}
@end
