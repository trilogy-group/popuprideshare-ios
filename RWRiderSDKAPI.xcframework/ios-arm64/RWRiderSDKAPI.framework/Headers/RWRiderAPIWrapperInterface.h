//
//  RWRiderAPIInterface.h
//  RWRider
//
//  Created by Rahul Gera on 18/05/22.
//

#import <Foundation/Foundation.h>
#import "RWRiderClient.h"
#import "RAPhoneVerificationAPI.h"
#import "RASessionManager.h"
#import "RAUserAPI.h"
#import "RASessionManager.h"
NS_ASSUME_NONNULL_BEGIN

typedef void(^RWLoginCompletionBlock)(RWRiderClient * _Nullable client, NSError * _Nullable error);
typedef void(^RWSendOTPCompletionBlock)(NSString * _Nullable token, NSError * _Nullable error);
typedef void(^RWVerifyOTPCompletionBlock)(BOOL success, NSError * _Nullable error);
typedef void (^RWCheckResponseBlock)(BOOL success, NSError* error);
typedef void (^RWAPIResponseBlock)(id responseObject, NSError* error);
typedef void(^RWRecoverPasswordCompletionBlock)(NSError * _Nullable error);

@protocol RWRiderLoginAPIDelegate

-(void)sendOTPInPhone:(NSString *)phoneNumber withCompletion:(RWSendOTPCompletionBlock)handler;
- (void)verifyOTPWithCode:(nonnull NSString *)code phoneNumber:(nonnull NSString *)phoneNumber token:(nonnull NSString *)token withCompletion:(nonnull RWLoginCompletionBlock)handler;
- (void)loginWithUsername:(nonnull NSString *)username password:(nonnull NSString *)password andCompletion:(nonnull RWLoginCompletionBlock)handler;

@end


@protocol RWRiderRegisterAPIDelegate <NSObject>

-(void)checkAvailabilityOfEmail:(NSString*)email andPhone:(NSString*)phoneNumber withCompletion:(RWCheckResponseBlock)handler;
-(void)sendOTPInPhone:(NSString *)phoneNumber withCompletion:(RWSendOTPCompletionBlock)handler;
-(void)verifyOTPWithCode:(NSString *)code token:(NSString *)token withCompletion:(RWVerifyOTPCompletionBlock)handler;
-(void)registerWithFirstName:(NSString *)firstName lastName:(NSString*)lastName email:(NSString*)email password:(NSString*)password phone:(NSString*)phone andCompletion:(RWLoginCompletionBlock)handler;
@end

@protocol RWRiderForgotPasswordAPIDelegate
-(void)recoverPasswordFromEmail:(NSString *)email withCompletion:(RWRecoverPasswordCompletionBlock)handler;
@end

NS_ASSUME_NONNULL_END
