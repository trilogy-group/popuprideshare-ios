//
//  RideCostDetailViewController.h
//  Ride
//
//  Created by Theodore Gonzalez on 2/3/17.
//  Copyright © 2017 RideAustin.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RWRiderSDKAPI/RWRiderSDKAPI.h"
#import "RAPopUpViewController.h"

@interface RideCostDetailViewController : RAPopUpViewController

+ (instancetype)controllerWithCarCategory:(RACarCategoryDataModel*)category andSpecialFees:(NSArray<RAFee *>*)specialFees;

@end
