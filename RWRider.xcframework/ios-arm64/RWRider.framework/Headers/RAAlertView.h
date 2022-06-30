//
//  RAAlertView.h
//  Ride
//
//  Created by Kitos on 17/8/16.
//  Copyright © 2016 RideAustin.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RAPopUpViewController.h"

@interface RAAlertView : RAPopUpViewController

typedef void (^RAAlertViewActiondBlock) (BOOL yesPressed);

+ (instancetype)alertViewWithTitle:(NSString*)title line1:(NSString*)line1 line2:(NSString*)line2 line3:(NSString*)line3 completion:(RAAlertViewActiondBlock)handler;

- (void)dismissAlert;

@property (nonatomic, readonly, getter=isVisible) BOOL visible;

- (void)updateLine1:(NSString*)line1;

@end
