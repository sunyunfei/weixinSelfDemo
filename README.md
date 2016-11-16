# 微信支付与微信跳转
***
# 2016.11.16 跳转微信公众号现在好像不行了，跳转过去是失败界面。正在找办法处理。
***
***
## 前言
这是一个微信支付与微信跳转的demo，只是作为demo作为参考。

这是在2015年12月23号，根据微信官方文档做出的支付demo。
***
## 微信支付
和官方文档里面的read.text描述的一样，需要两步操作。
### 微信支付请求
	+(NSString *)jumpToBizPay {

    //============================================================
    // V3&V4支付流程实现
    // 注意:参数配置请查看服务器端Demo
    // 更新时间：2015年11月20日
    //============================================================
    NSString *urlString   = @"http://wxpay.weixin.qq.com/pub_v2/app/app_pay.php?plat=ios";
        //解析服务端返回json数据
        NSError *error;
        //加载一个NSURL对象
        NSURLRequest *request = [NSURLRequest requestWithURL:[NSURL URLWithString:urlString]];
        //将请求的url数据放到NSData对象中
        NSData *response = [NSURLConnection sendSynchronousRequest:request returningResponse:nil error:nil];
        if ( response != nil) {
            NSMutableDictionary *dict = NULL;
            //IOS5自带解析类NSJSONSerialization从response中解析出数据放到字典中
            dict = [NSJSONSerialization JSONObjectWithData:response options:NSJSONReadingMutableLeaves error:&error];
            
            NSLog(@"url:%@",urlString);
            if(dict != nil){
                NSMutableString *retcode = [dict objectForKey:@"retcode"];
                if (retcode.intValue == 0){
                    NSMutableString *stamp  = [dict objectForKey:@"timestamp"];
                    
                    //调起微信支付
                    PayReq* req             = [[PayReq alloc] init];
                    req.partnerId           = [dict objectForKey:@"partnerid"];
                    req.prepayId            = [dict objectForKey:@"prepayid"];
                    req.nonceStr            = [dict objectForKey:@"noncestr"];
                    req.timeStamp           = stamp.intValue;
                    req.package             = [dict objectForKey:@"package"];
                    req.sign                = [dict objectForKey:@"sign"];
                    [WXApi sendReq:req];
                    //日志输出
                    NSLog(@"appid=%@\npartid=%@\nprepayid=%@\nnoncestr=%@\ntimestamp=%ld\npackage=%@\nsign=%@",[dict objectForKey:@"appid"],req.partnerId,req.prepayId,req.nonceStr,(long)req.timeStamp,req.package,req.sign );
                    return @"";
                }else{
                    return [dict objectForKey:@"retmsg"];
                }
            }else{
                return @"服务器返回错误，未获取到json对象";
            }
        }else{
            return @"服务器返回错误";
        }}

### 微信支付结果返回调用
	- (void)onResp:(BaseResp *)resp {
if([resp isKindOfClass:[PayResp class]]){
        //支付返回结果，实际支付结果需要去微信服务器端查询
        NSString *strMsg,*strTitle = [NSString stringWithFormat:@"支付结果"];
        
        switch (resp.errCode) {
            case WXSuccess:
                strMsg = @"我的支付结果：成功！";
                NSLog(@"支付－PaySuccess，retcode = %d", resp.errCode);
                break;
                
            default:
                strMsg = [NSString stringWithFormat:@"支付结果：失败！retcode = %d, retstr = %@", resp.errCode,resp.errStr];
                NSLog(@"错误，retcode = %d, retstr = %@", resp.errCode,resp.errStr);
                break;
        }
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:strTitle message:strMsg delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
        [alert show];
    }}
    
### 然后再你需要调用的时候调用
	- (void)bizPay {
    NSString *res = [WXApiRequestHandler jumpToBizPay];
    if( ![@"" isEqual:res] ){
        UIAlertView *alter = [[UIAlertView alloc] initWithTitle:@"支付失败" message:res delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
        
        [alter show];
    }}
    

到此，微信支付结束。主要注意的是在appdelegate调用支付结果回调，这一版里面所有的设置参数都放在了后台操作。
***
## 微信跳转
平时我们的app有时候需要跳转到微信，下面是跳转微信公众号的demo。如果你对下面的代码感到陌生，请百度：ios应用间跳转。

	NSString *urlStr = [NSString stringWithFormat:@"weixin://dl/officialaccounts"];
    //复制字符串到剪切板
    UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];
    pasteboard.string = @"孙云飞";
    [[UIApplication sharedApplication]openURL:[NSURL URLWithString:urlStr]];
    
#### 微信相关转相关的scheme：
![微信scheme](http://ww1.sinaimg.cn/bmiddle/005yPfcfjw1ez9lln8zboj30oi0q4aer.jpg)
***
# 后记
至此，关于此demo的文档结束。有问题可以联系。
QQ:1035044809
