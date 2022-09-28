//
//  RASessionAPI.h
//  RideAustin
//
//  Created by Kitos on 3/9/16.
//  Copyright © 2016 Crossover Markets Inc. All rights reserved.
//

#import "RABaseAPI.h"
#import "RASessionDataModel.h"

@interface RASessionAPI : RABaseAPI

@end

typedef void(^RASessionCompletionBlock)(RASessionDataModel *session, NSError *error);
typedef void(^RAPartialSessionCompletionBlock)(NSError *error);

@interface RASessionAPI (SignIn)

+ (void)loginWithUsername:(NSString*)username password:(NSString*)password encrypt:(BOOL)encrypt andCompletion:(RASessionCompletionBlock) handler;
+ (void)loginWithFacebook:(NSString*)facebookToken andCompletion:(RAPartialSessionCompletionBlock)handler;
+ (void)verifyOTP:(NSString *)code phoneNumber:(NSString *)phoneNumber clientCode:(NSString *)clientCode token:(NSString *)token andCompletion:(RASessionCompletionBlock)handler;
+ (void)createUser:(RAUserDataModel *)user andCompletion:(RASessionCompletionBlock)handler;
@end

@interface RASessionAPI (SignOut)

+ (void)logoutWithCompletion:(APIResponseBlock)handler;

@end

@interface RASessionAPI (ForgotPassword)

+ (void)recoverPasswordFromEmail:(NSString*)email withCompletion:(APIResponseBlock)handler;

@end

@interface RASessionAPI (ChangePassword)

+ (void)updatePassword:(NSString *)password withCompletion:(APIResponseBlock)handler;

@end
@interface RASessionAPI (DeleteAccount)

+ (void)deleteAccountForUser:(NSString*)userId WithCompletion:(APIResponseBlock)handler;

@end


