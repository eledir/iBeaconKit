//
//  YlwlBeaconManager.h
//  YlwlBeaconDemo
//
//  Created by Shengguo Gao on 15/9/27.
//  Copyright (c) 2015年 com.YLWL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "YlwlConstants.h"


@class YlwlBeaconManager, YlwlBeacon, YlwlBeaconID;

@protocol YlwlBeaconManagerDelegate;

/**
 *  The YlwlBeaconManager class defines the interface for configuring the delivery of beacon-related events to your application. You use an instance of this class to get YlwlBeacon objects, and establish the parameters that determine which beacon's events should be delivered.
 *
 *  You should always use the shared instance. Creating own instance is not allowed.
 */
@interface YlwlBeaconManager : NSObject

/**
 * The delegate of the app object.
 */
@property (nonatomic, weak) id<YlwlBeaconManagerDelegate> delegate;

/**
 *  Returns the shared instance of the YlwlBeaconManager class. Users are not allowed to create own instance.
 */
+ (YlwlBeaconManager *)sharedInstance;

/**
 *  Requests permission to use location services whenever the app is running.
 */
- (void)requestAlwaysAuthorization;

/**
 *  Requests permission to use location services while the app is in the foreground.
 */
- (void)requestWhenInUseAuthorization;

/**
 *  Starts the delivery of notifications for beacons with specified id.
 *
 *  @param beaconID          Using YlwlBeaconID object to identify the beacons.
 *  @param wakeUpApplication Wake up your application in background when those beacons being ranged.
 */
- (void)startRangingBeaconsWithID:(YlwlBeaconID *)beaconID wakeUpApplication:(BOOL) wakeUpApplication;

/**
 *  Stops the delivery of notifications for beacons with specified id.
 *
 *  @param beaconID Using YlwlBeaconID object to identify the beacons.
 */
- (void)stopRangingBeaconsWithID:(YlwlBeaconID *)beaconID;

/**
 *  Stops the delivery of notifications for all beacons.
 */
- (void)stopRangingAllBeacons;

/**
 *  The set of YlwlBeaconID currently being ranged.
 *
 *  @return The objects in the set are instances of the YlwlBeaconID class
 */
- (NSSet *)rangedBeaconIDs;

/**
 *  Get the beacon instance with YlwlBeaconID object.
 *
 *  @param beaconID Using YlwlBeaconID object to identify the beacon you want.
 *
 *  @return Beacon instance.
 *
 *  @discussion This mehtod will always return a beacon instance even if the beacon has not been ranged. The beacon with same ID will only have one instance.
 *
 *  @warning The YlwlBeaconID object must have major and minor properties.
 */
- (YlwlBeacon *)beaconWithID:(YlwlBeaconID *)beaconID;

/**
 *  Get the beacon instances in range now.
 *
 *  @return Beacon instances in array, sorted by accuracy.
 */
- (NSArray *)beaconsInRange;

/**
 *  Get all the beacon instances.
 *
 *  @return Beacon instances in array.
 */
- (NSArray *)allBeacons;

@end


@protocol YlwlBeaconManagerDelegate <NSObject>

@optional

/**
 *  Tells the delegate that ranged a new beacon.
 *
 *  @param beaconManager The beacon manager object reporting the event.
 *  @param beacon        The beacon instance just be ranged.
 */
- (void)beaconManager:(YlwlBeaconManager *)beaconManager didRangeNewBeacon:(YlwlBeacon *)beacon;

/**
 *  Tells the delegate that a beacon has been out of range.
 *
 *  @param beaconManager The beacon manager object reporting the event.
 *  @param beacon        The beacon instance just be out of range.
 */
- (void)beaconManager:(YlwlBeaconManager *)beaconManager beaconDidGone:(YlwlBeacon *)beacon;

/**
 *  Tells the delegate that if one or more beacons are in range. This method will be called approximate every one second, even there is not beacon around.
 *
 *  @param beaconManager The beacon manager object reporting the event.
 *  @param beacons       An array of YlwlBeacon objects representing the beacons currently in range. You can use the information in these objects to determine the range of each beacon and its identifying information.
 */
- (void)beaconManager:(YlwlBeaconManager *)beaconManager scanDidFinishWithBeacons:(NSArray *)beacons;

/**
 *  Tells the delegate that the authorization status for the application changed.
 *
 *  @param beaconManager The beacon manager object reporting the event.
 *  @param status        The new authorization status for the application.
 *  @discussion This method is called whenever the application’s ability to use location services changes. Changes can occur because the user allowed or denied the use of location services for your application or for the system as a whole.
 */
- (void)beaconManager:(YlwlBeaconManager *)beaconManager didChangeAuthorizationStatus:(CLAuthorizationStatus)status;

/**
 * It is same with locationManager:didDetermineState:forRegion: of CLLocationManagerDelegate
 * Tells the delegate about the state of the specified region.
 *
 *  @param beaconManager The beacon manager object reporting the event.
 *  @param state The state of the specified region. For a list of possible values, see the YlwlRegionState type.
 *  @param region The region whose state was determined.
 *
 *  @discussion see locationManager:didDetermineState:forRegion: of CLLocationManagerDelegate, When a app waked up by a region,
 *  The system will call SDK, SDK will call this delegate method.
 */
- (void)beaconManager:(YlwlBeaconManager *)beaconManager didDetermineState:(YlwlRegionState) state forRegion:(YlwlBeaconID*) region;

@end
