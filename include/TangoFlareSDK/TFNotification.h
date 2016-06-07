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

@property NSString *notification_id;
@property NSString *message_type;
@property NSString *appearance;
@property NSString *recipient_type;
@property NSString *segment_id;
@property NSString *device_id;
@property NSString *contact_id;
@property NSString *content_type;
@property NSString *content_title;
@property NSString *content_text;
@property NSString *content_image;
@property NSString *content_html;
@property NSString *action_tap_perform;
@property NSString *action_tap_url;
@property NSString *action_tap_tracker_tag;
@property NSString *action_button_one_perform;
@property NSString *action_button_one_url;
@property NSString *action_button_one_tracker_tag;
@property NSString *action_button_two_perform;
@property NSString *action_button_two_url;
@property NSString *action_button_two_tracker_tag;
@property NSDate *deliver_at;
@property NSNumber *is_read;

/**---------------------------------------------------------------------------------------
 * @name Managing Push Notifications
 *  ---------------------------------------------------------------------------------------
 */

/** Removes the notification from the local database
 */
- (void)remove;

@end
