//
//  APIBundle.h
//  RWRiderSDKAPI
//
//  Created by Rahul Gera on 28/05/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface APIBundle : NSObject
+ (instancetype)sharedInstance;
+ (NSString*)bundleIdentifier;
+ (NSBundle*)bundle;
+(BOOL)isRideShareApp;
@end

NS_ASSUME_NONNULL_END
