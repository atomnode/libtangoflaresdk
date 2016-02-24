//
//  TangoFlareNotificationsController.h
//  TangoFlareSDK
//
//  Created by How Tah Lun on 12/02/2016.
//  Copyright © 2016 How Tah Lun. All rights reserved.
//

/** This class provides access to the functions that can be used to create an app inbox 
 */

#import <Foundation/Foundation.h>

@interface TangoFlareNotificationsController : NSObject

/**---------------------------------------------------------------------------------------
 * @name Querying Push Notifications
 *  ---------------------------------------------------------------------------------------
 */

/** Gets an array of all received notifications

@return An array containing all available notifications
*/
+(NSMutableArray*)getNotifications;

/** Gets the total of unread notifications
 
 @return The total unread notifications from all received
 */
+(int)getUnreadNotificationsCount;

@end
