//
//  EstimatedFareViewController.h
//  Ride
//
//  Created by Abdul Rehman on 21/05/2016.
//  Copyright © 2016 RideAustin.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RAEstimatedFareViewModel.h"

@class EstimatedFareViewController;

@protocol EstimatedFareViewDelegate

//- (void)estimatedViewChangedDestinationPressed;

@end

@interface EstimatedFareViewController : UIViewController

//Properties
@property (weak) id <EstimatedFareViewDelegate> delegate;
@property (strong, nonatomic) RAEstimatedFareViewModel *viewModel;

- (instancetype)initWithDelegate:(id<EstimatedFareViewDelegate>)delegate viewModel:(RAEstimatedFareViewModel *)viewModel;

@end
