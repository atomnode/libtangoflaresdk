//
//  TFContact.h
//  TangoFlareSDK
//
//  Created by How Tah Lun on 12/01/2017.
//  Copyright © 2017 How Tah Lun. All rights reserved.
//

/** 
 This class defines the contact details that can be registered with TangoFlare.
 */

#import <Foundation/Foundation.h>

@interface TFContact : NSObject

/**
The time at which the intially user signed up.
 */
@property NSDate *signUpAt;
/**
 The user's first name.
 */
@property NSString *firstName;
/**
 The user's last name.
 */
@property NSString *lastName;
/**
 The user's nickname.
 */
@property NSString *nickname;
/**
 The user's email address.
 */
@property NSString *emailAddress;
/**
 The user's mobile phone number.
 */
@property NSString *mobilePhone;
/**
 The user's gender.
 */
@property NSString *gender;
/**
 The user's birthday.
 */
@property NSDate *birthday;
/**
 The user's age group.
 */
@property NSString *ageGroup;
/**
 The user's current country.
 */
@property NSString *country;
/**
 The user's primary language.
 */
@property NSString *language;
/**
A dictionary used to send any additional contact details not defined by the SDK.
 */
@property NSDictionary *customAttrs;

-(NSDictionary*)getAsDictionary;

@end
