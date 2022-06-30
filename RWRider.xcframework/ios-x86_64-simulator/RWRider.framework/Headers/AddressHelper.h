//
//  AddressHelper.h
//  RWRider
//
//  Created by Rahul Gera on 10/06/22.
//

#import <Foundation/Foundation.h>
#import <GoogleMaps/GMSAddress.h>
#import "RWRiderSDKAPI/RWRiderSDKAPI.h"

NS_ASSUME_NONNULL_BEGIN

@interface AddressHelper : NSObject

@end



@interface RAAddress (Helper)
- (instancetype)initWithGMSAddress:(GMSAddress*)gmsAddress;
@end

NS_ASSUME_NONNULL_END
