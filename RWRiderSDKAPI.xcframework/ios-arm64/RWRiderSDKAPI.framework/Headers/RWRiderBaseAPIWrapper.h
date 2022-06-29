//
//  RWRiderBaseAPIWrapper.h
//  RWRider
//
//  Created by Rahul Gera on 18/05/22.
//

#import <Foundation/Foundation.h>
#import "RWRiderAPIWrapperInterface.h"
NS_ASSUME_NONNULL_BEGIN
typedef void(^LocationResult)(CLLocation* _Nullable location,NSError* _Nullable error);
@interface RWRiderBaseAPIWrapper : NSObject
@property (strong, nonatomic) NSString* clientCode;

- (instancetype)initWithClientCode:(NSString*)clientCode;
-(void)getGlobalConfig:(void (^)(ConfigGlobal *, NSError *))handler;
@end

NS_ASSUME_NONNULL_END
