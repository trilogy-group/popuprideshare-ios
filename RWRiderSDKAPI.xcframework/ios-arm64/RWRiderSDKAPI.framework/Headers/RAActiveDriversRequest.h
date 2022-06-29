//
//  RAActiveDriversRequest.h
//  Ride
//
//  Created by Kitos on 16/11/16.
//  Copyright © 2016 RideAustin.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "RACarCategoryDataModel.h"

@interface RAActiveDriversRequest : NSObject <NSCopying>
- (instancetype)initWithStartLocation:(CLLocationCoordinate2D)startLocation andSelectedCategory:(RACarCategoryDataModel*)category womanOnlyMode:(BOOL)womanOnlyMode isFingerPrintedDriverOnlyMode:(BOOL)isFingerPrint;
@property (nonatomic) CLLocationCoordinate2D location;
@property (nonatomic, strong) RACarCategoryDataModel *carCategory;
@property (nonatomic, getter=isWomanOnlyMode) BOOL womanOnlyMode;
@property (nonatomic) BOOL isFingerPrintedDriverOnlyMode;

@end
