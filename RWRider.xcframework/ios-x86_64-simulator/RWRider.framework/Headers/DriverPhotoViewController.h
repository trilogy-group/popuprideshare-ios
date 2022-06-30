//
//  DriverPhotoViewController.h
//  Ride
//
//  Created by Carlos Alcala on 9/16/16.
//  Copyright © 2016 RideAustin.com. All rights reserved.
//

#import "BaseRegistrationViewController.h"
#import "FlatButton.h"

@interface DriverPhotoViewController : BaseRegistrationViewController

@property (weak, nonatomic) IBOutlet UIImageView *imagePhoto;
@property (weak, nonatomic) UIImage *photo;
@property (weak, nonatomic) IBOutlet FlatButton *btTakePhoto;

- (IBAction)takePhotoAction:(id)sender;

@end
