//
//  RAEstimatedFareDataModel.h
//  Ride
//
//  Created by Roberto Abreu on 1/3/18.
//  Copyright © 2018 RideAustin.com. All rights reserved.
//

#import <Foundation/Foundation.h>
@class RAEstimate;
NS_ASSUME_NONNULL_BEGIN
@interface RAEstimatedFareViewModel : NSObject

@property (nonatomic, nonnull, readonly) NSString *title;
@property (nonatomic, nonnull, readonly) NSString *startAddress;
@property (nonatomic, nonnull, readonly) NSString *endAddress;
@property (nonatomic, nonnull, readonly) NSString *displayFareEstimate;
@property (nonatomic, nonnull, readonly) NSString *displayTotalFare;
@property (nonatomic, readonly) NSURL *campaignBannerIcon;

- (instancetype)initWithStartAddress:(NSString * _Nonnull)startAddress endAddress:(NSString * _Nonnull)endAddress estimate:(RAEstimate * _Nonnull)estimate;

@end
NS_ASSUME_NONNULL_END
