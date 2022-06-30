//
//  ConfirmStepViewController.h
//  RideAustin
//
//  Created by bpfullmetal on 3/9/22.
//  Copyright © 2022 RideAustin.com. All rights reserved.
//

#ifndef ConfirmStepViewController_h
#define ConfirmStepViewController_h

#import "BaseViewController.h"
#import "FlatButton.h"
#import "RWRiderSDKAPI/RWRiderSDKAPI.h"

@class ConfirmStepViewController;
@protocol ConfirmStepViewControllerDelegate

- (void)confirmStepViewControllerDidPhoneConfirmed;
- (void)confirmStepViewControllerDidPhoneConfirmedForLogin;

@end

@class PaddedTextField;

@interface ConfirmStepViewController : BaseViewController<UITextFieldDelegate>

@property (nonatomic, weak) id<ConfirmStepViewControllerDelegate> delegate;

@property (strong, nonatomic) IBOutlet UIView *topStepProgressBar;
@property(nonatomic) CAGradientLayer *codeTextFieldGradientLayer;
@property(nonatomic, strong) IBOutlet PaddedTextField* codeTextField;
@property (weak, nonatomic) IBOutlet FlatButton *nextButton;
@property (weak, nonatomic) IBOutlet FlatButton *resendButton;

- (id)initWithPhone:(NSString*)phone token:(NSString*)token isLogin:(BOOL)isLoginFlow;
- (IBAction)goBackScreen:(id)sender;
- (IBAction)goBackHomeScreen:(id)sender;
- (IBAction)textFieldEditingChanged:(UITextField *)sender;
- (IBAction)resendCode:(id)sender;
- (IBAction)submitNext:(UIButton *)sender;

@end


#endif /* ConfirmStepViewController_h */
