//
//  CompleteStepViewController.h
//  RideAustin
//
//  Created by bpfullmetal on 3/10/22.
//  Copyright © 2022 RideAustin.com. All rights reserved.
//

#ifndef CompleteStepViewController_h
#define CompleteStepViewController_h

#import "BaseViewController.h"
#import "FlatButton.h"

@class CompleteStepViewController;
@protocol CompleteStepViewControllerDelegate

- (void)completeStepViewControllerDidRegisterSuccessfully:(NSString *)userId;

@end

@interface CompleteStepViewController : BaseViewController

@property (nonatomic, weak) id<CompleteStepViewControllerDelegate> delegate;

@property (weak, nonatomic) IBOutlet FlatButton *completeButton;

- (id)initWithEmail:(NSString*)email
          firstName:(NSString*)firstName
           lastName:(NSString*)lastName
             mobile:(NSString*)mobile
           password:(NSString*)password;
- (IBAction)submitComplete:(id)sender;

@end


#endif /* CompleteStepViewController_h */
