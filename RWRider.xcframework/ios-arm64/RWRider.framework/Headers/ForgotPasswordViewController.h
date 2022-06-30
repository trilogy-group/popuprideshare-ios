//
//  ForgotPasswordViewController.h
//  Ride
//
//  Created by Tyson Bunch on 5/19/16.
//  Updated by bpfullmetal on 3/8/22.
//  Copyright © 2016 RideAustin.com. All rights reserved.
//

#import "BaseViewController.h"
#import "FlatButton.h"

@class PaddedTextField;

@interface ForgotPasswordViewController : BaseViewController<UITextFieldDelegate>

@property(nonatomic) CAGradientLayer *emailGradientLayer;
@property(nonatomic, strong) IBOutlet PaddedTextField* emailTextField;
@property (weak, nonatomic) IBOutlet FlatButton *resetButton;

- (IBAction)goBackScreen:(id)sender;
- (IBAction)doForgotPassword:(id)sender;
- (IBAction)textFieldEditingChanged:(UITextField *)sender;

@end
