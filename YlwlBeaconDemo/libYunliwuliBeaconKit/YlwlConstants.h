//
//  YlwlConstants.h
//  YlwlBeaconDemo
//
//  Created by Shengguo Gao on 16/4/7.
//  Copyright © 2016年 com.YLWL. All rights reserved.
//

/**
 *    Report the state for region.
 */
typedef NS_ENUM(int, YlwlRegionState) {
    /**
     *  the state was unknown.
     */
    YlwlRegionStateUnknown,
    /**
     *  enter a region.
     */
    YlwlRegionStateEnter,
    /**
     *  leave a region.
     */
    YlwlRegionStateLeave
};

