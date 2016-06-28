//
//  ViewController.m
//  YlwlBeaconDemo
//
//  Created by Shengguo Gao on 15/9/27.
//  Copyright (c) 2015年 com.YLWL. All rights reserved.
//

#import "ViewController.h"
#import "YlwlBeacon.h"
#import "YlwlBeaconID.h"
#import "YlwlBeaconManager.h"


@interface ViewController () <YlwlBeaconManagerDelegate, YlwlBeaconDelegate>

- (IBAction)startRange:(UIButton *)sender;

- (IBAction)stopRange:(UIButton *)sender;

- (IBAction)allBeacons:(UIButton *)sender;

@property (nonatomic, strong) YlwlBeaconID *beaconID;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    [YlwlBeaconManager sharedInstance].delegate = self;
   
}


- (IBAction)startRange:(UIButton *)sender
{
    [[YlwlBeaconManager sharedInstance] requestAlwaysAuthorization];
//    [[YlwlBeaconManager sharedInstance] requestWhenInUseAuthorization];
    
    [self createBeaconID];
    
    [[YlwlBeaconManager sharedInstance] startRangingBeaconsWithID:self.beaconID wakeUpApplication:YES];
}

- (void)createBeaconID
{
    //FDA50693-A4E2-4FB1-AFCF-C6EB07647825
    
    //74278BDA-B644-4520-8F0C-720EAF059935
    
    //E2C56DB5-DFFB-48D2-B060-D0F5A71096E0
    
    //B9407F30-F5F8-466E-AFF9-25556B57FE6D
    
    NSUUID *proximityUUID = [[NSUUID alloc] initWithUUIDString:@"FDA50693-A4E2-4FB1-AFCF-C6EB07647825"];
    
    self.beaconID = [YlwlBeaconID beaconIDWithProximityUUID:proximityUUID];
}

- (IBAction)stopRange:(UIButton *)sender
{
    [[YlwlBeaconManager sharedInstance] stopRangingBeaconsWithID:self.beaconID];
}

- (IBAction)allBeacons:(UIButton *)sender
{
    NSLog(@"allBeacons : %@", [[YlwlBeaconManager sharedInstance] allBeacons]);
}

#pragma mark -- delegate

- (void)beaconManager:(YlwlBeaconManager *)beaconManager scanDidFinishWithBeacons:(NSArray *)beacons
{
    for (YlwlBeacon *b in beacons)
    {
        NSLog(@"UUID：%@；major:%@；minor:%@\n inRange:%d, accuracy：%lf；RSSI:%ld,距离：%.2fm；proximity：%ld，%@", [b.beaconID.proximityUUID UUIDString], b.beaconID.major, b.beaconID.minor, b.inRange, b.accuracy, b.rssi, [self calcDistByRSSI:(int)b.rssi], b.proximity, [self nameForProximity:b.proximity]);
        
        
        
        b.delegate = self;
    }
    
//    NSLog(@"-------\n\n");
}

- (void)ylwlBeacon:(YlwlBeacon *)beacon didUpdateRSSI:(NSInteger)rssi
{
    NSLog(@"%@ -- %ld", beacon, (long)beacon.rssi);
}

- (float)calcDistByRSSI:(int)rssi
{
    if (rssi == 0)
    {
        return -1.0;
    }
    
    int txPower = -55;
    
    double ratio = rssi * 1.0 / txPower;
    
    if (ratio < 1.0)
    {
        return (double)(pow(ratio, 10));
    }else
    {
        double accuracy = (0.89976) * pow(ratio, 7.7095) + 0.111;
        return accuracy;
    }
}

- (NSString *)nameForProximity:(CLProximity)proximity {
    switch (proximity) {
        case CLProximityUnknown:
            return @"未知, Unknown";
            break;
        case CLProximityImmediate:
            return @"最接近的, Immediate";
            break;
        case CLProximityNear:
            return @"附近, Near";
            break;
        case CLProximityFar:
            return @"远, Far";
            break;
    }
}

@end
