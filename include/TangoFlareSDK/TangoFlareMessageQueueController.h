//
//  TangoFlareMessageQueueController.h
//  TangoFlare
//
//  Created by How Tah Lun on 07/12/2015.
//  Copyright © 2015 How Tah Lun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/** The TangoFlareMessageQueueControllerDelegate allows the developer to define custom behaviour when a notification is received
 */
@protocol TangoFlareMessageQueueControllerDelegate <NSObject>

/** Is called when the device has received a notification
 
 @param notification The contents of the notification in the form of a NSDictionary
 */
- (void)receivedNotification:(NSDictionary *)notification;

@end

@interface TangoFlareMessageQueueController : NSObject

@property(nonatomic, weak) id <TangoFlareMessageQueueControllerDelegate> delegate;

+(TangoFlareMessageQueueController*)sharedInstance;
+(void)createQueue;
-(void)startMessageQueueControllerWithFetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;

@end
