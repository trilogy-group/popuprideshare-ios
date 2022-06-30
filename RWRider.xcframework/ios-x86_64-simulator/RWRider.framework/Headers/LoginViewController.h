//
//  LoginViewController.h
//  RideAustin.com
//
//  Created by Tyson Bunch on 9/19/12.
//  Copyright (c) 2012 FuelMe, Inc. All rights reserved.
//

#import "BaseViewController.h"
#import "FlatButton.h"


@class LoginViewController;
@protocol LoginViewControllerDelegate
- (void)loginViewControllerDidLoginSuccessfully:(LoginViewController *)loginViewController;
- (void)loginViewControllerDidTapForgotPassword:(LoginViewController *)loginViewController;
- (void)loginViewControllerDidTapOTPLogin:(LoginViewController *)loginViewController;
@end

@class PaddedTextField;

@interface LoginViewController : BaseViewController<UITextFieldDelegate>

@property (nonatomic, weak) id<LoginViewControllerDelegate> delegate;
@property(nonatomic) CAGradientLayer *emailGradientLayer;
@property(nonatomic) CAGradientLayer *passwordGradientLayer;
@property(nonatomic, strong) IBOutlet PaddedTextField* emailTextField;
@property(nonatomic, strong) IBOutlet PaddedTextField* passwordTextField;
@property (weak, nonatomic) IBOutlet FlatButton *backBarBtn;
@property (weak, nonatomic) IBOutlet FlatButton *cancelBarBtn;
@property (weak, nonatomic) IBOutlet UIButton *forgotButton;
@property(weak, nonatomic) IBOutlet FlatButton *loginButton;
@property (weak, nonatomic) IBOutlet FlatButton *signinWithOTPButton;


- (IBAction)doForgotPassword:(id)sender;
- (IBAction)goBackScreen:(id)sender;
- (IBAction)goBackHomeScreen:(id)sender;
- (IBAction)textFieldEditingChanged:(UITextField *)sender;
- (IBAction)submitLogin:(UIButton *)sender;

@end
