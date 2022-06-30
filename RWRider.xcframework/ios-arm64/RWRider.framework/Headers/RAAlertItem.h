//
//  RAAlertItem.h
//  Ride
//
//  Created by Roberto Abreu on 15/11/16.
//  Copyright © 2016 RideAustin.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol RAAlertItem <NSObject>

- (NSString*)messageAlert;
- (NSInteger)statusCodeAlert;

@end

@interface NSString (RAAlertItem) <RAAlertItem>

@end


@interface NSError (RAAlertItem) <RAAlertItem>

@end

