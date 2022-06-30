//
//  NameStepViewController.h
//  Ride
//
//  Created by bpfullmetal on 3/8/22.
//  Copyright © 2022 RideAustin.com. All rights reserved.
//

#ifndef NameStepViewController_h
#define NameStepViewController_h

#import "BaseViewController.h"
#import "FlatButton.h"

@class NameStepViewController;
@class PaddedTextField;

@protocol NameStepViewControllerDelegate

- (void)nameStepViewControllerDidComplete:(NSString *)firstName
                                 lastName:(NSString *)lastName;

@end

@interface NameStepViewController : BaseViewController<UITextFieldDelegate>

@property (nonatomic, weak) id<NameStepViewControllerDelegate> delegate;

@property (strong, nonatomic) IBOutlet UIView *topStepProgressBar;
@property(nonatomic) CAGradientLayer *firstNameGradientLayer;
@property(nonatomic) CAGradientLayer *lastNameGradientLayer;
@property(nonatomic, strong) IBOutlet PaddedTextField* firstNameTextField;
@property(nonatomic, strong) IBOutlet PaddedTextField* lastNameTextField;
@property (weak, nonatomic) IBOutlet UIButton *backBarBtn;
@property (weak, nonatomic) IBOutlet UIButton *cancelBarBtn;
@property(weak, nonatomic) IBOutlet FlatButton *nextButton;

- (IBAction)goBackScreen:(id)sender;
- (IBAction)goBackHomeScreen:(id)sender;
- (IBAction)textFieldEditingChanged:(UITextField *)sender;
- (IBAction)submitNext:(UIButton *)sender;

@end


#endif /* NameStepViewController_h */
