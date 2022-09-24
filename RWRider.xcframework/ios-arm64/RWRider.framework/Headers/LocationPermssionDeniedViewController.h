//
//  LocationPermssionDeniedViewController.h
//  RWRider
//
//  Created by Rahul Gera on 17/09/22.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface LocationPermssionDeniedViewController : UIViewController
@property (weak, nonatomic) IBOutlet UIButton *buttonDismiss;
@property (weak, nonatomic) IBOutlet UIButton *buttonSettings;
@property (weak, nonatomic) IBOutlet UIView *mapIconView;


@end

NS_ASSUME_NONNULL_END
