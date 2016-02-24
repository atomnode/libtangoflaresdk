//
//  TangoFlareSDK.h
//  TangoFlareSDK
//
//  Created by How Tah Lun on 30/12/2015.
//  Copyright © 2015 How Tah Lun. All rights reserved.
//

//
//  TangoFlareSDK.h
//  TangoFlare
//
//  Created by How Tah Lun on 30/11/2015.
//  Copyright © 2015 How Tah Lun. All rights reserved.
//

/** This class provides access to the various services provided by TangoFlare
 
To use this class initialize the SDK in the AppDelegate as follows:

    [TangoFlareSDK initializeSDK];
 
 */

#import <Foundation/Foundation.h>

#import "TangoFlareMessageQueueController.h"
#import "TangoFlareNavigationController.h"

@class Contact;

@interface TangoFlareSDK : NSObject


/**---------------------------------------------------------------------------------------
 * @name TangoFlare initialization methods
 *  ---------------------------------------------------------------------------------------
 */

/** Registers the device with TangoFlare
 
 Should be called in application:application didFinishLaunchingWithOptions:
 */
+(void)initializeSDK;

/** Handles the incoming remote notification
 
 Should be called in application:didReceiveRemoteNotification:
 
 @param userInfo The userInfo dictionary returned from application:didReceiveRemoteNotification:
 @param completionHandler The completionHandler returned from application:didReceiveRemoteNotification:
*/
+(void)didReceiveRemoteNotification:(NSDictionary *)userInfo
             fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;

/** Handles the incoming remote notification. Used in place of didReceiveRemoteNotification:fetchCompletionHandler:  if required to check whether the notification is handled by TangoFlare
 
 Should be called in application:didReceiveRemoteNotification:
 
 @param userInfo The userInfo dictionary returned from application:didReceiveRemoteNotification:
 @param completionHandler The completionHandler returned from application:didReceiveRemoteNotification:
 
 @return Returns whether the incoming remote notification is handled by TangoFlare
 */
+(BOOL)isReceiveRemoteNotification:(NSDictionary *)userInfo;

/** Handles the incoming local notification
 
 Should be called in application:didReceiveLocalNotification:
 
 @param application The application object returned from application:didReceiveLocalNotification:
 @param notification The notification object returned from application:didReceiveLocalNotification:
 */
+(void)application:(UIApplication*)application didReceiveLocalNotification:(UILocalNotification *)notification;


/**---------------------------------------------------------------------------------------
 * @name TangoFlare location methods
 *  ---------------------------------------------------------------------------------------
 */

/** Starts sending user's location to TangoFlare
 
 Requires location services permission from user
 */
+(void)startUpdatingLocation;

/** Stops sending user's location to TangoFlare
 
 Use appropriate to control battery consumption
 */
+(void)stopUpdatingLocation;


/**---------------------------------------------------------------------------------------
 * @name TangoFlare registration methods
 *  ---------------------------------------------------------------------------------------
 */

/** Sends device's push notification token to TangoFlare
 
 @param deviceToken The push notification token obtained from the device
 */
+(void)setDeviceToken:(NSData*)deviceToken;

/** Registers a custom contact with TangoFlare
 
 @param ucidString The contact string as defined by the developer
 */
+(void)registerContact:(NSString*)ucidString;

/** Unregisters a custom contact with TangoFlare
*/
+(void)unregisterContact;

/** Unregisters a custom contact with TangoFlare
 
@return The contact details currently registered with the device
 */
+(Contact*)getCurrentContact;


/**---------------------------------------------------------------------------------------
 * @name TangoFlare tag methods
 *  ---------------------------------------------------------------------------------------
 */

/** Registers with TangoFlare if the device has currently opted in to receiving Notifications
 
 @param opt_in YES indicates the the device has opted in : NO indicates the the device hasn't opted in
 */
+(void)setOptInNotification:(BOOL)opt_in;

/** Registers with TangoFlare if the device has currently opted in to updating its Location
 
 @param opt_in YES indicates the the device has opted in : NO indicates the the device hasn't opted in
 */
+(void)setOptInLocation:(BOOL)opt_in;

/** Registers with TangoFlare if the device has currently opted in to a permission defined by the developer
 
 @param opt_in YES indicates the the device has opted in : NO indicates the the device hasn't opted in
 @param nameString The permission defined by the developer
 */
+(void)setOptIn:(BOOL)opt_in ForName:(NSString*)nameString;

/** Registers with TangoFlare if the device is currently connected with Facebook
 
 @param opt_in YES indicates the the device is connected : NO indicates the the device isn't connected
 */
+(void)setConnectWithFacebook:(BOOL)opt_in;

/** Registers with TangoFlare if the device is currently connected with Google
 
 @param opt_in YES indicates the the device is connected : NO indicates the the device isn't connected
 */
+(void)setConnectWithGoogle:(BOOL)opt_in;

/** Registers with TangoFlare if the device is currently connected with Twitter
 
 @param opt_in YES indicates the the device is connected : NO indicates the the device isn't connected
 */
+(void)setConnectWithTwitter:(BOOL)opt_in;

/** Registers with TangoFlare if the device is currently connected with a social network defined by the developer
 
 @param opt_in YES indicates the the device is connected : NO indicates the the device isn't connected
 @param nameString The social network defined by the developer
 */
+(void)setConnectWith:(BOOL)opt_in ForName:(NSString*)nameString;

/** Registers an event with TangoFlare
 
 @param eventString The name of the event
 */
+(void)setEvent:(NSString*)eventString;

/** Registers a category with TangoFlare
 
 @param categoryString The name of the category
 */
+(void)setCategory:(NSString*)categoryString;

/** Registers that the device has viewed an item with TangoFlare
 
 @param viewItemString The name of the item
 */
+(void)setViewItem:(NSString*)viewItemString;

/** Registers that the device has liked an item with TangoFlare
 
 @param likeItemString The name of the item
 */
+(void)setViewLike:(NSString*)likeItemString;


/**---------------------------------------------------------------------------------------
 * @name TangoFlare message methods
 *  ---------------------------------------------------------------------------------------
 */

/** Starts retrieving the messages from TangoFlare
 
 @param completionHandler The completion handler returned from application:performFetchWithCompletionHandler:
 */
+(void)startMessageQueueControllerWithFetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;

/** Gets the current instance of TangoFlareMessageQueueController
 
 @return Instance of TangoFlareMessageQueueController
 */
+(TangoFlareMessageQueueController*)getMessageQueueController;


/**---------------------------------------------------------------------------------------
 * @name TangoFlare app inbox methods
 *  ---------------------------------------------------------------------------------------
 */

/** Gets an instance of the TangoFlareNavigationController that is used to display the app inbox.
 
 @return Instance of TangoFlareNavigationController
 */

+(TangoFlareNavigationController*)getAppInbox;


@end

