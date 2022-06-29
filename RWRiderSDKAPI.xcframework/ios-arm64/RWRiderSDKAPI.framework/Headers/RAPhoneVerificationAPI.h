//
//  RAPhoneVerificationAPI.h
//  Ride
//
//  Created by Theodore Gonzalez on 6/13/17.
//  Copyright © 2017 RideAustin.com. All rights reserved.
//

#import "RABaseAPI.h"
#import "RASessionAPI.h"
#import "RASessionManager.h"
#import <Foundation/Foundation.h>

@interface RAPhoneVerificationAPI : RABaseAPI

#pragma mark - Phone Verification
+ (void)postVerifyPhoneNumber:(NSString *)phoneNumber clientCode:(NSString *)clientCode withCompletion:(void(^)(NSString *token, NSError *error))completion;
+ (void)postVerifyCode:(NSString *)code token:(NSString *)token clientCode:(NSString *)clientCode withCompletion:(void(^)(BOOL success, NSError *error))completion;
+ (void)sendOTPAtPhone:(NSString *)phoneNumber clientCode:(NSString *)clientCode withCompletion:(void(^)(NSString *token, NSError *error))completion ;
+ (void)verifyOTP:(NSString *)code phoneNumber:(NSString *)phoneNumber clientCode:(NSString *)clientCode token:(NSString *)token withCompletion:(RALoginCompletionBlock)completion;
@end
