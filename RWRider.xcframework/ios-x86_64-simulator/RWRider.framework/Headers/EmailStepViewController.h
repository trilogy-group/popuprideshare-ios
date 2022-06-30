//
//  EmailStepViewController.h
//  Ride
//
//  Created by bpfullmetal on 3/8/22.
//  Copyright © 2022 RideAustin.com. All rights reserved.
//

#ifndef EmailStepViewController_h
#define EmailStepViewController_h

#import "BaseViewController.h"
#import "FlatButton.h"

@class EmailStepViewController;
@class PaddedTextField;

@protocol EmailStepViewControllerDelegate

- (void)emailStepViewControllerDidComplete:(NSString *)email;

@end

@interface EmailStepViewController : BaseViewController<UITextFieldDelegate>

@property (nonatomic, weak) id<EmailStepViewControllerDelegate> delegate;

@property (strong, nonatomic) IBOutlet UIView *topStepProgressBar;
@property(nonatomic) CAGradientLayer *theEmailGradientLayer;
@property(nonatomic) CAGradientLayer *confirmEmailGradientLayer;
@property(nonatomic, strong) IBOutlet PaddedTextField* theEmailTextField;
@property(nonatomic, strong) IBOutlet PaddedTextField* confirmEmailTextField;
@property (weak, nonatomic) IBOutlet UIButton *backBarBtn;
@property (weak, nonatomic) IBOutlet UIButton *cancelBarBtn;
@property(weak, nonatomic) IBOutlet FlatButton *nextButton;
@property (strong, nonatomic) IBOutlet UIImageView *theEmailVerifiedImage;
@property (strong, nonatomic) IBOutlet UIImageView *confirmEmailVerifiedImage;

@property(nonatomic) Boolean isTheEmailVerified;
@property(nonatomic) Boolean isNextBtnEnabled;
@property(nonatomic) Boolean isValidateDisabled;

- (IBAction)goBackScreen:(id)sender;
- (IBAction)goBackHomeScreen:(id)sender;
- (IBAction)textFieldEditingChanged:(UITextField *)sender;
- (IBAction)submitNext:(UIButton *)sender;

@end


#endif /* EmailStepViewController_h */
