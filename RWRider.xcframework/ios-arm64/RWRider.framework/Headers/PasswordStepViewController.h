//
//  PasswordStepViewController.h
//  Ride
//
//  Created by bpfullmetal on 3/14/22.
//  Copyright © 2022 RideAustin.com. All rights reserved.
//

#ifndef PasswordStepViewController_h
#define PasswordStepViewController_h

#import "BaseViewController.h"
#import "FlatButton.h"

@class PasswordStepViewController;
@class PaddedTextField;

@protocol PasswordStepViewControllerDelegate

- (void)passwordStepViewControllerDidComplete:(NSString *)password;

@end

@interface PasswordStepViewController : BaseViewController<UITextFieldDelegate>

@property (nonatomic, weak) id<PasswordStepViewControllerDelegate> delegate;

@property (strong, nonatomic) IBOutlet UIView *topStepProgressBar;
@property(nonatomic) CAGradientLayer *thePasswordGradientLayer;
@property(nonatomic) CAGradientLayer *confirmPasswordGradientLayer;
@property(nonatomic, strong) IBOutlet PaddedTextField* thePasswordTextField;
@property(nonatomic, strong) IBOutlet PaddedTextField* confirmPasswordTextField;
@property (weak, nonatomic) IBOutlet FlatButton *backBarBtn;
@property (weak, nonatomic) IBOutlet FlatButton *cancelBarBtn;
@property(weak, nonatomic) IBOutlet FlatButton *nextButton;
@property (strong, nonatomic) IBOutlet UIImageView *thePasswordVerifiedImage;
@property (strong, nonatomic) IBOutlet UIImageView *confirmPasswordVerifiedImage;

@property(nonatomic) Boolean isTheEmailVerified;
@property(nonatomic) Boolean isNextBtnEnabled;
@property(nonatomic) Boolean isValidateDisabled;

- (IBAction)goBackScreen:(id)sender;
- (IBAction)goBackHomeScreen:(id)sender;
- (IBAction)textFieldEditingChanged:(UITextField *)sender;
- (IBAction)submitNext:(id)sender;

@end

#endif /* PasswordStepViewController_h */
