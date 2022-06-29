//
//  RideRequestInputParameters.h
//  RWRiderSDKAPI
//
//  Created by Rahul Gera on 23/05/22.
//

#import <Foundation/Foundation.h>
#import "RideConstants.h"
#import "RACarCategoryDataModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface RideRequestInputParameters : NSObject

@property (nonatomic, strong) NSNumber *startLocationLat;
@property (nonatomic, strong) NSNumber *startLocationLong;
@property (nonatomic, strong) NSString *startAddress;
@property (nonatomic, strong) NSString *startZipCode;
@property (nonatomic, assign) BOOL inSurgeArea;
@property (nonatomic, strong) RACarCategoryDataModel *carCategory;
@property (nonatomic, strong) NSString *applePayToken;
@property (readonly,nonatomic, strong) NSString *paymentProvider;
@property (nonatomic, strong) NSNumber *endLocationLat;
@property (nonatomic, strong) NSNumber *endLocationLong;
@property (nonatomic, strong) NSString *endAddress;
@property (nonatomic, strong) NSString *endZipCode;
@property (nonatomic, strong) NSString *driverType;
@property (nonatomic, strong) NSString *comment;
@property (nonatomic) PaymentMethod paymentMethod;

@end

NS_ASSUME_NONNULL_END
