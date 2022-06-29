//
//  DirectionAPI.h
//  RideAustin
//
//  Created by Rahul Gera on 16/12/21.
//  Copyright © 2021 RideAustin.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RABaseAPI.h"
//typedef void(^TripHistoryCompletion)(NSArray<TripHistoryDataModel*> *tripHistories, NSInteger numberOfElements,NSError *error);
typedef void(^DirectionCompletion)(id response,NSError *error);

@interface DirectionAPI : RABaseAPI

+ (void)getDirections:(float)fromLat fromLong:(float)fromLong toLat:(float)toLat toLong:(float)toLong completion:(DirectionCompletion)handler;

@end

