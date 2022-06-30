//
//  TermsStepViewController.h
//  RideAustin
//
//  Created by bpfullmetal on 3/9/22.
//  Copyright © 2022 RideAustin.com. All rights reserved.
//

#ifndef TermsStepViewController_h
#define TermsStepViewController_h

#import "BaseViewController.h"
#import "FlatButton.h"
#import <WebKit/WebKit.h>

@class TermsStepViewController;
@protocol TermsStepViewControllerDelegate

- (void)accceptTerms;
- (void)termsStepViewControllerDidTermsAccepted;

@end
@class PaddedTextField;

@interface TermsStepViewController : BaseViewController

@property (nonatomic, weak) id<TermsStepViewControllerDelegate> delegate;

@property (strong, nonatomic) IBOutlet UIView *topStepProgressBar;
@property (strong, nonatomic) IBOutlet WKWebView *termsWebView;
@property (weak, nonatomic) IBOutlet FlatButton *acceptButton;
@property (weak, nonatomic) IBOutlet FlatButton *viewTermsButton;
@property (weak, nonatomic) IBOutlet FlatButton *agreeCheckButton;
@property (weak, nonatomic) IBOutlet FlatButton *backButton;
@property (weak, nonatomic) IBOutlet FlatButton *cancelButton;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *acceptBtnBottomConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *termsWebViewHeightConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *viewTermsBtnCenterYConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *agreeCheckBtnCenterYConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *viewTermsSpaceVerticalConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *agreeCheckSpaceVerticalConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *headerHeightConstraint;

- (IBAction)goBackScreen:(id)sender;
- (IBAction)goBackHomeScreen:(id)sender;
- (IBAction)viewTermsWebView:(id)sender;
- (IBAction)checkAgreeTerms:(id)sender;
- (IBAction)submitAccept:(id)sender;

- (void)setUserIdAndProtocalTerms:(NSString*)userId;

@end

#endif /* TermsStepViewController_h */
