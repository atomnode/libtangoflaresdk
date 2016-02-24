//
//  TFNotification.h
//  TangoFlareSDK
//
//  Created by How Tah Lun on 12/02/2016.
//  Copyright © 2016 How Tah Lun. All rights reserved.
//

/** This class defines a push notification received from TangoFlare.
*/

#import <Foundation/Foundation.h>

@interface TFNotification : NSObject

@property NSString *content_text;
@property NSString *content_title;
@property NSString *content_type;
@property NSString *content_url;
@property NSDate *created_at;
@property NSNumber *deliver_as_inbox;
@property NSNumber *deliver_as_push;
@property NSNumber *is_read;
@property NSDate *deliver_at;
@property NSString *engage_type;
@property NSString *engage_url;
@property NSDate *expires_at;
@property NSNumber *notification_id;
@property NSNumber *project_id;

/**---------------------------------------------------------------------------------------
 * @name Managing Push Notifications
 *  ---------------------------------------------------------------------------------------
 */

/** Removes the notification from the local database
 */
- (void)remove;

@end
