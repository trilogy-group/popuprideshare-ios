//
//  RACityDropDown.h
//  RACityDropDown
//
//  Created by Carlos Alcala on 11/19/16.
//

#import <UIKit/UIKit.h>
#import "RADropDownModel.h"

@class RADropDown;
@protocol RADropDownDelegate
- (void) RADropDownDidSelect:(RADropDownModel *)selected;
@end

@interface RADropDown : UIView <UITableViewDelegate, UITableViewDataSource> {
    NSString *animationDirection;
    UIImageView *imgView;
}

@property (nonatomic, retain) id <RADropDownDelegate> delegate;
@property (nonatomic, retain) NSString *animationDirection;
@property (nonatomic, retain) NSArray<RADropDownModel*> *list;

-(void)hideDropDown:(CGRect)senderFrame;
- (id)showDropDown:(CGRect)senderFrame height:(CGFloat)height options:(NSArray *)options direction:(NSString *)direction;

@end
