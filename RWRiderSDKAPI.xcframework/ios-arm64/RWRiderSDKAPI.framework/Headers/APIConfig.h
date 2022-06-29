//
//  AppConfig.h
//  Ride
//
//  Created by Roberto Abreu on 2/6/18.
//  Copyright © 2018 RideAustin.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APIConfig : NSObject

+ (NSString *)apiKey;
+ (NSString *)productionServerURL;
+ (NSString *)qaServerURL;
+ (NSString *)stageServerURL;
+ (NSString *)devServerURL;
+ (NSString *)featureServerURL;
+ (NSString *)md5PasswordSalt;

@end
