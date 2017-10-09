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

    [[TangoFlareSDK sharedInstance] initializeSDK];
 
 */

#import <Foundation/Foundation.h>

#import "TangoFlareNavigationController.h"

#import "TFContact.h"

@interface TangoFlareSDK : NSObject


/**---------------------------------------------------------------------------------------
 * @name TangoFlare initialization methods
 *  ---------------------------------------------------------------------------------------
 */

/*
 * Returns the TangoFlareSDK singleton
 */
+ (instancetype)sharedInstance;

/** Registers the device with TangoFlare
 
 Should be called in application:application didFinishLaunchingWithOptions:
 */
-(void)initializeSDK;

/** Registers the device with TangoFlare
 
 Should be called in application:application didFinishLaunchingWithOptions:
 
 @param completionBlock The block to execute when the initialization operation is complete
 <table>
 <tr>
    <td><tt>success</tt></td>
    <td>A boolean indicating whether the initialization operation was successful</td>
 </tr>
 <tr>
    <td><tt>contactInfo</tt></td>
    <td>A dictionary that contains information related to the initialization, including the unique contact id and the unique device id.</td>
 </tr>
 </table>
 */
-(void)initializeSDKWithCompletionBlock:(void (^)(BOOL success, NSDictionary *contactInfo))completionBlock;

/** Handles the incoming remote notification
 
 Should be called in application:didReceiveRemoteNotification:
 
 @param application The application object returned from application:didReceiveRemoteNotification:
 @param userInfo The userInfo dictionary returned from application:didReceiveRemoteNotification:
 @param completionHandler The completionHandler returned from application:didReceiveRemoteNotification:
*/
-(void)application:(UIApplication*)application didReceiveRemoteNotification:(NSDictionary *)userInfo
fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;

/** Handles the incoming remote notification. Used in place of didReceiveRemoteNotification:fetchCompletionHandler:  if required to check whether the notification is handled by TangoFlare
 
 Should be called in application:didReceiveRemoteNotification:
 
 @param application The application object returned from application:didReceiveRemoteNotification:
 @param userInfo The userInfo dictionary returned from application:didReceiveRemoteNotification:
 @param completionHandler The completionHandler returned from application:didReceiveRemoteNotification:
 
 @return Returns whether the incoming remote notification is handled by TangoFlare
 */
-(BOOL)application:(UIApplication*)application isReceiveRemoteNotification:(NSDictionary *)userInfo;

/** Handles the incoming local notification
 
 Should be called in application:didReceiveLocalNotification:
 
 @param application The application object returned from application:didReceiveLocalNotification:
 @param notification The notification object returned from application:didReceiveLocalNotification:
 */
-(void)application:(UIApplication*)application didReceiveLocalNotification:(UILocalNotification *)notification;

/**---------------------------------------------------------------------------------------
 * @name TangoFlare registration methods
 *  ---------------------------------------------------------------------------------------
 */

/** Sends device's push notification token to TangoFlare
 
 @param deviceToken The push notification token obtained from the device
 */
-(void)setDeviceToken:(NSData*)deviceToken;

/** Registers a custom contact with TangoFlare
 
 @param ucidString The contact string as defined by the developer.The string must have a minimum length of 6 and a maximum length of 128.
 */
-(void)registerContact:(NSString*)ucidString;

/** Update the contact details registered with this device. Only the values that have been set will be updated.
 
 @param ucidString The contact details to be registered with Tango Flare.
 */
-(void)updateContactDetails:(TFContact*)contact;

/** Unregisters a custom contact with TangoFlare
*/
-(void)unregisterContact;

/** Returns the devices' unique contact id value
 
 @return String with the value of the unique contact id. Will return nil if the SDK has not been initialized.
 */
-(NSString*)getUniqueContactId;

/** Returns the devices' unique device id value
 
 @return String with the value of the unique device id. Will return nil if the SDK has not been initialized.
 */
-(NSString*)getUniqueDeviceId;

/**---------------------------------------------------------------------------------------
 * @name TangoFlare tag methods
 *  ---------------------------------------------------------------------------------------
 */

/** Registers with TangoFlare if the device has currently opted in to receiving Notifications
 
 @param opt_in YES indicates the the device has opted in : NO indicates the the device hasn't opted in
 */
-(void)setOptInNotification:(BOOL)opt_in;

/** Registers with TangoFlare if the device has currently opted in to updating its Location
 
 @param opt_in YES indicates the the device has opted in : NO indicates the the device hasn't opted in
 */
-(void)setOptInLocation:(BOOL)opt_in;

/** Registers with TangoFlare if the device has currently opted in to a permission defined by the developer
 
 @param opt_in YES indicates the the device has opted in : NO indicates the the device hasn't opted in
 @param nameString The permission defined by the developer
 
 @return a boolean indicating whether or not the name used for the tag is valid
 */
-(BOOL)setOptIn:(BOOL)opt_in ForName:(NSString*)nameString;

/** Registers with TangoFlare if the device is currently connected with Facebook
 
 @param opt_in YES indicates the the device is connected : NO indicates the the device isn't connected
 */
-(void)setConnectWithFacebook:(BOOL)opt_in;

/** Registers with TangoFlare if the device is currently connected with Google
 
 @param opt_in YES indicates the the device is connected : NO indicates the the device isn't connected
 */
-(void)setConnectWithGoogle:(BOOL)opt_in;

/** Registers with TangoFlare if the device is currently connected with Twitter
 
 @param opt_in YES indicates the the device is connected : NO indicates the the device isn't connected
 */
-(void)setConnectWithTwitter:(BOOL)opt_in;

/** Registers with TangoFlare if the device is currently connected with a social network defined by the developer
 
 @param opt_in YES indicates the the device is connected : NO indicates the the device isn't connected
 @param nameString The social network defined by the developer
 
 
 @return a boolean indicating whether or not the name used for the tag is valid
 */
-(BOOL)setConnectWith:(BOOL)opt_in ForName:(NSString*)nameString;

/** Registers an event with TangoFlare
 
 @param eventString The name of the event
 
 
 @return a boolean indicating whether or not the name used for the tag is valid
 */
-(BOOL)addEvent:(NSString*)eventString;

/* Unregisters an event with TangoFlare
 
 @param eventString The name of the event
 
 
 @return a boolean indicating whether or not the name used for the tag is valid
 */
-(BOOL)removeEvent:(NSString*)eventString;

/** Registers an event and its value with TangoFlare
 
 The value stored is an accumulation of all values returned for a particular event
 
 @param eventString The name of the event
 @param value The value of the event
 
 
 @return a boolean indicating whether or not the name used for the tag is valid
 */
-(BOOL)addEvent:(NSString*)eventString WithValue:(NSNumber*)value;

/** Registers a category with TangoFlare
 
 @param categoryString The name of the category
 
 
 @return a boolean indicating whether or not the name used for the tag is valid
 */
-(BOOL)addCategory:(NSString*)categoryString;
   
/** Unregisters a category with TangoFlare
 
 @param categoryString The name of the category

 @return a boolean indicating whether or not the name used for the tag is valid
 */
-(BOOL)removeCategory:(NSString*)categoryString;

/** Registers that the device has viewed an item with TangoFlare
 
 @param viewItemString The name of the item
 
 
 @return a boolean indicating whether or not the name used for the tag is valid
 */
-(BOOL)addViewItem:(NSString*)viewItemString;

/** Registers that the device has liked an item with TangoFlare
 
 @param likeItemString The name of the item
 
 
 @return a boolean indicating whether or not the name used for the tag is valid
 */
-(BOOL)addLikeItem:(NSString*)likeItemString;
    
/** Unregisters that the device has liked an item with TangoFlare
 
 @param likeItemString The name of the item
 
 
 @return a boolean indicating whether or not the name used for the tag is valid
*/
-(BOOL)removeLikeItem:(NSString*)likeItemString;

/** Registers that the device has searched for an item with TangoFlare
 
 @param likeItemString The name of the item
 
 
 @return a boolean indicating whether or not the name used for the tag is valid
 */
-(BOOL)addSearchItem:(NSString*)searchItemString;

/**---------------------------------------------------------------------------------------
 * @name TangoFlare location methods
 *  ---------------------------------------------------------------------------------------
 */

/** SDK will request WhenInUse authorization on your behalf
 
 Must be called if location collection is enable
 */
- (void)requestWhenInUseLocationPermission;

/** SDK will request Always authorization on your behalf
 
 Must be called if Geo Fences are used
 */
- (void)requestAlwaysPermission;

/**---------------------------------------------------------------------------------------
 * @name TangoFlare app inbox methods
 *  ---------------------------------------------------------------------------------------
 */

/** Gets an instance of the TangoFlareNavigationController that is used to display the app inbox.
 
 @return Instance of TangoFlareNavigationController
 */

-(TangoFlareNavigationController*)getAppInbox;


@end

