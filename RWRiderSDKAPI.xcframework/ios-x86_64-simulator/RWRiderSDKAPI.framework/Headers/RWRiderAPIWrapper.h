//
//  RWRiderAPI.h
//  RWRider
//
//  Created by Rahul Gera on 18/05/22.
//

#import <Foundation/Foundation.h>
#import "RAUserDataModel.h"
#import "RWRiderClient.h"
#import "RWRiderAPIWrapperInterface.h"
#import "RWRiderLoginAPIWrapper.h"
#import "RWRiderRegisterAPIWrapper.h"
#import "RWRiderForgotPasswordAPIWrapper.h"
#import "RAEnvironmentManager.h"
NS_ASSUME_NONNULL_BEGIN

@interface RWRiderAPIWrapper : NSObject

@property (strong, nonatomic, readonly) NSString* clientCode;
@property (strong, nonatomic) id<RWRiderLoginAPIDelegate> loginDelegate;
@property (strong, nonatomic) id<RWRiderRegisterAPIDelegate> registerDelegate;
@property (strong, nonatomic) id<RWRiderForgotPasswordAPIDelegate> forgotPasswordDelegate;
+(void)setupClient:(NSString*)clientCode;
+ (instancetype)sharedInstance;
-(void)setEnvironment: (RAEnvironment)environment;
@end

NS_ASSUME_NONNULL_END
