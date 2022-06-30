//
//  FareEstimateViewController.h
//  Ride
//
//  Created by bpfullmetal on 4/3/22.
//

#import <UIKit/UIKit.h>

#import "RAEstimatedFareViewModel.h"

@class FareEstimateViewController;

@protocol FareEstimateDelegate

- (void)fareEstimateViewController:(FareEstimateViewController *)fareEstimateViewController didBackNavigate:(BOOL)backPressed;
- (void)fareEstimateViewController:(FareEstimateViewController *)fareEstimateViewController didTapAddPromoCode:(id)sender;
- (void)fareEstimateViewController:(FareEstimateViewController *)fareEstimateViewController didTapViewCostDetail:(id)sender;
- (void)fareEstimateViewController:(FareEstimateViewController *)fareEstimateViewController didTapContinue:(NSString *)estimatedCost;

@end

@interface FareEstimateViewController : UIViewController

//Properties
@property (weak, nonatomic) id<FareEstimateDelegate> delegate;
@property (strong, nonatomic) RAEstimatedFareViewModel *viewModel;

- (instancetype)initWithDelegate:(id<FareEstimateDelegate>)delegate viewModel:(RAEstimatedFareViewModel *)viewModel;

@end
