//
//  PhoneStepViewController.h
//  RideAustin
//
//  Created by bpfullmetal on 3/8/22.
//  Copyright © 2022 RideAustin.com. All rights reserved.
//

#ifndef PhoneStepViewController_h
#define PhoneStepViewController_h

#import "BaseViewController.h"
#import "FlatButton.h"
#import "RWRiderSDKAPI/RWRiderSDKAPI.h"


@class PhoneStepViewController;
@protocol PhoneStepViewControllerDelegate

- (void)phoneStepViewControllerDidPhoneVerified:(NSString *)phone
                                          email:(NSString *)email
                                          token:(NSString *)token
                                    isLoginFlow:(Boolean)isLoginFlow;
-(void)showRootLogin;
                                        

@end

@class PaddedTextField;

@interface PhoneStepViewController : BaseViewController<UITextFieldDelegate>

@property (nonatomic, weak) id<PhoneStepViewControllerDelegate> delegate;

@property (strong, nonatomic) IBOutlet UIView *topStepProgressBar;
@property (weak, nonatomic) IBOutlet UIImageView *imgFlag;
@property(nonatomic) CAGradientLayer *mobileTextFieldGradientLayer;
@property(nonatomic, strong) IBOutlet PaddedTextField* mobileTextField;
@property (weak, nonatomic) IBOutlet UIButton *backBarBtn;
@property (weak, nonatomic) IBOutlet UIButton *cancelBarBtn;
@property (weak, nonatomic) IBOutlet FlatButton *nextButton;

@property (strong, nonatomic) IBOutlet UIView *viewCountryPicker;

@property (nonatomic) NSString *countryCode;

- (id)initWithEmail:(NSString*)email;
- (id)init;
- (IBAction)goBackScreen:(id)sender;
- (IBAction)goBackHomeScreen:(id)sender;
- (IBAction)submitNext:(UIButton *)sender;

@end

#endif /* PhoneStepViewController_h */
