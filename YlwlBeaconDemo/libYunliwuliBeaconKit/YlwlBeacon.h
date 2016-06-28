//
//  YlwlBeacon.h
//  YlwlBeaconDemo
//
//  Created by Shengguo Gao on 15/9/27.
//  Copyright (c) 2015年 com.YLWL. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import "YlwlBeaconID.h"

@class YlwlBeacon;

@protocol YlwlBeaconDelegate <NSObject>

@optional

- (void)ylwlBeacon:(YlwlBeacon *)beacon didUpdateRSSI:(NSInteger)rssi;

@end

/**
 *  The YlwlBeacon class defines the interface of a beacon device. You can use instances of this class to get rssi, sensor data or configurate device settings. You do not create instances of this class directly. Use YlwlBeaconManager to get YlwlBeacon instances.
 *
 *  The identity of a beacon is defined by its beaconID properties.
 */
@interface YlwlBeacon : NSObject
{
    YlwlBeaconID *_beaconID;
    BOOL _inRange;
    NSInteger _rssi;
    CLProximity _proximity;
    CLLocationAccuracy _accuracy;
}

/**
 * The delegate of the app object.
 */
@property (nonatomic, weak) id <YlwlBeaconDelegate> delegate;

/**
 *  A YlwlBeaconID object identify the beacon. (read-only)
 */
@property (readonly, nonatomic, strong) YlwlBeaconID *beaconID;

/**
 *  Returns a Boolean value that indicates whether the beacon is in range. (read-only)
 */
@property (readonly, nonatomic, assign) BOOL inRange;

/**
 *  The received signal strength of the beacon, measured in decibels. (read-only)
 *
 *  @discussion If beacon is out of range, the value will be 0.
 */
@property (readonly, nonatomic, assign) NSInteger rssi;

/**
 *  The relative distance to the beacon. (read-only)
 *
 *  @discussion The value in this property gives a general sense of the relative distance to the beacon. Use it to quickly identify beacons that are nearer to the user rather than farther away.
 */
@property (readonly, nonatomic, assign) CLProximity proximity;

/**
 *  The accuracy of the proximity value, measured in meters from the beacon. (read-only)
 *
 *  @discussion Indicates the one sigma horizontal accuracy in meters. Use this property to differentiate between beacons with the same proximity value. Do not use it to identify a precise location for the beacon. Accuracy values may fluctuate due to RF interference. A negative value in this property signifies that the actual accuracy could not be determined.
 */
@property (readonly, nonatomic, assign) CLLocationAccuracy accuracy;

@end
