//
//  YlwlBeaconID.h
//  YlwlBeaconDemo
//
//  Created by Shengguo Gao on 15/9/27.
//  Copyright (c) 2015年 com.YLWL. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

/**
 *  YlwlBeaconID instance is an obejct to specify a beacon’s identity. The proximityUUID property will never be nil, major and minor are optional.
 */
@interface YlwlBeaconID : NSObject

/**
 *  Initializes and returns a YlwlBeaconID object that targets a beacon with the specified proximity ID
 *
 *  @param proximityUUID The unique ID of the beacons being targeted. This value must not be nil.
 *
 *  @return An initialized YlwlBeaconID object.
 */
+ (instancetype)beaconIDWithProximityUUID:(NSUUID *)proximityUUID;

/**
 *  Initializes and returns a YlwlBeaconID object that targets a beacon with the specified proximity ID
 *
 *  @param proximityUUID The unique ID of the beacons being targeted. This value must not be nil.
 *  @param major The major value that you use to identify one or more beacons.
 *
 *  @return An initialized YlwlBeaconID object.
 */
+ (instancetype)beaconIDWithProximityUUID:(NSUUID *)proximityUUID major:(NSNumber *)major;

/**
 *  Initializes and returns a YlwlBeaconID object that targets a beacon with the specified proximity ID
 *
 *  @param proximityUUID The unique ID of the beacons being targeted. This value must not be nil.
 *  @param major The major value that you use to identify one or more beacons.
 *  @param minor The minor value that you use to identify a specific beacon.
 *
 *  @return An initialized YlwlBeaconID object.
 */
+ (instancetype)beaconIDWithProximityUUID:(NSUUID *)proximityUUID major:(NSNumber *)major minor:(NSNumber *)minor;

/**
 *  Returns a Boolean value that indicates whether the receiver and a given beacon id are equal.
 *
 *  @param aBeaconID The beacon id with which to compare the receiver.
 *
 *  @return YES if the receiver and aBeaconID are equal, otherwise NO.
 */
- (BOOL)isEqualToBeaconID:(YlwlBeaconID *)aBeaconID;

/**
 *  The unique ID of the beacons being targeted. (read-only)
 */
@property (readonly, nonatomic, strong) NSUUID *proximityUUID;

/**
 *  The value identifying a group of beacons. (read-only)
 */
@property (readonly, nonatomic, strong) NSNumber *major;

/**
 *  The value identifying a specific beacon within a group. (read-only)
 */
@property (readonly, nonatomic, strong) NSNumber *minor;

/**
 *  Convert a YlwlBeaconID object to a CLBeaconRegion object.
 *
 *  @return A CLBeaconRegion object.
 */
- (CLBeaconRegion *)CLBeaconRegion;

/**
 *  Convert a CLBeaconRegion object to a YlwlBeaconID object.
 *
 *  @param region A CLBeaconRegion object.
 *
 *  @return A YlwlBeaconID object.
 */
+ (instancetype)beaconIDFromCLBeaconRegion:(CLBeaconRegion *)region;

@end
