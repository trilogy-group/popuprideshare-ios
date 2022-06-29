//
//  RWRiderClient.h
//  RWRider
//
//  Created by Rahul Gera on 18/05/22.
//

#import <Foundation/Foundation.h>
#import "RAUserDataModel.h"
#import "RARideManager.h"
#import "RARideRequestManager.h"
#import "RASessionManager.h"
#import "RARideAPI.h"
#import "RARiderAPI.h"
#import "CarCategoriesManager.h"
#import "RAActiveDriversRequest.h"
#import "NSNotificationCenterConstants.h"
#import "RAActiveDriversManager.h"
#import "ConfigurationManager.h"
#import "TripHistoryAPI.h"
#import "RAUserAPI.h"
#import "RATokensAPI.h"
#import "SupportTopicAPI.h"
#import "RAActiveDriversAPI.h"

@protocol RWRiderClientDelegate <NSObject>
-(void)changeRideStatus:(RARideStatus)status;
-(void)updateEstimationCompletion:(NSDate*_Nullable)date;
-(void)updatePrecedingMarker:(CLLocationCoordinate2D)coordinate;
-(void)activeDriverLocationChange:(CLLocation*_Nullable)newLocation;
-(void)updateCarTitle:(NSString*_Nullable)title;
-(void)rideUpgradeRequest:(RARideUpgradeRequestDataModel*_Nullable)requestData;
-(void)pollingError:(NSError*_Nullable)error;
-(void)destinationLocationChange:(CLLocation*_Nullable)newLocation;
@end

NS_ASSUME_NONNULL_BEGIN

@interface RWRiderClient : NSObject
@property(weak, nonatomic) id <RWRiderClientDelegate> delegate;
@property (weak, nonatomic) RARiderDataModel *rider;
@property (nonatomic, readonly, getter=isDriverComing) BOOL driverComing;
@property (nonatomic, readonly, getter=isDriverArrived) BOOL driverArrived;
@property (nonatomic, readonly, getter=isOnTrip) BOOL onTrip;
@property (nonatomic, readonly, getter=isRiding) BOOL riding;
@property (nonatomic, readonly, getter=isStartLocationSelected) BOOL startLocationSelected;
@property (nonatomic, readonly, getter=isDestinationLocationSelected) BOOL destinationLocationSelected;

- (instancetype)initWithRider:(RARiderDataModel * _Nullable)dataModel;
-(BOOL)hasUnpaidBalance;
- (BOOL)isRiding;

- (void)startPollingForActiveDrivers;
- (void)stopPollingForActiveDrivers;
- (void)getNearestDriversWithStartLocation:(CLLocationCoordinate2D)startLocation andSelectedCategory:(RACarCategoryDataModel*)category withCompletion:(RAActiveDriversAPICompletionlock)handler;

- (void)reloadCurrentRiderWithCompletion:(void (^)(RARiderDataModel *rider, NSError *error))completion;
-(void)requestRide:(RARideRequest *)rideRequest withCompletion:(RARideStatusCodeCompletionBlock)handler;
-(void)postRidesQueue:(NSString * _Nonnull)token withCompletion:(RARideCompletionBlock)completion;
-(void)cancelRideById:(NSString*)rideID withCompletion:(APIErrorResponseBlock)handler;
-(void)getRide:(NSString *)rideID andCompletion:(RARideCompletionBlock)handler;
-(void)getRide:(NSString*)rideID withRiderLocation:(nullable CLLocation *)riderLocation andCompletion:(RARideCompletionBlock)handler;
-(void)restoreRide:(RARideDataModel *)ride;
-(void)updateDestination:(RARideLocationDataModel*)destination forRide:(NSString*)rideID completion:(APIErrorResponseBlock)handler;
-(void)updateComment:(NSString*)comment forRide:(NSString*)rideID completion:(APIErrorResponseBlock)handler;

@end



@interface RWRiderClient (UpgradeRideRequest)

-(void)declineUpgradingCurrentRideWithCompletion:(APIErrorResponseBlock)handler;
-(void)confirmUpgradingCurrentRideWithCompletion:(APIErrorResponseBlock)handler;
NS_ASSUME_NONNULL_END
@end

#import "CFReasonDataModel.h"
NS_ASSUME_NONNULL_BEGIN
@interface RWRiderClient (CancellationFeedback)

-(void)getReasonsWithCompletion:(void(^)(NSArray<CFReasonDataModel *> * _Nullable reasons, NSError * _Nullable error))completion;
-(void)postReason:(NSString *)reasonCode forRide:(NSNumber *)rideID withComment:(NSString *)comment andCompletion:(void (^)(NSError * _Nullable))completion;

@end
NS_ASSUME_NONNULL_END
#import "RAEstimate.h"
NS_ASSUME_NONNULL_BEGIN
@interface RWRiderClient (Costs)

-(void)getSpecialFeesAtCoordinate:(CLLocationCoordinate2D)coordinate
                           cityID:(NSNumber *)cityID
                   forCarCategory:(NSString *)carCategory
                   withCompletion:(void(^)(NSArray<RAFee *> * _Nullable specialFees, NSError * _Nullable error))completion;

-(void)getRideEstimateFromStartLocation:(CLLocationCoordinate2D)startLocation
                          toEndLocation:(CLLocationCoordinate2D)endLocation
                             inCategory:(RACarCategoryDataModel*)category
                         withCompletion:(void (^)(RAEstimate * _Nullable estimate, NSError * _Nullable))completion;

@end

@interface RWRiderClient (CompletedRides)

-(void)getMapForRide:(NSString *)rideID withCompletion:(void (^)(NSURL *mapURL, NSError *error))completion;

/**
 @param paymentProvider if specified as CREDIT_CARD, server will not wait for paymentDelays and immediately charge the primary credit card
 */
-(void)rateRide:(NSString *)rideID
     withRating:(NSString *)rating
            tip:(NSString *)tip
     andComment:(NSString *)comment
paymentProvider:(NSString *)paymentProvider
 withCompletion:(RARideCompletionBlock)completion;
@end

@interface RWRiderClient (RealTimeTracking)
-(void)getRealTimeTrackingTokenByID:(NSString *)rideID completion:(void(^)(NSString * _Nullable token, NSError * _Nullable error))completion;
NS_ASSUME_NONNULL_END
@end


@interface RWRiderClient (Ride)

-(void)getCurrentRiderWithCompletion:(RARiderCompletionBlock _Nonnull)handler;
-(void)updateRider:(RARiderDataModel* _Nonnull)rider completion:(NetworkCompletionBlock _Nonnull)handler;

@end

@interface RWRiderClient (Charity)

-(void)updateCurrentRiderCharity:(RACharityDataModel* _Nullable)charity withCompletion:(NetworkCompletionBlock _Nonnull)handler;

@end

@interface RWRiderClient (Cards)

-(void)addCardForRider:(NSString* _Nonnull)riderId token:(NSString* _Nonnull)cardToken withCompletion:(CardCreatedBlock _Nonnull)handler;
-(void)setPrimaryCard:(RACardDataModel* _Nonnull)card toRider:(NSString* _Nonnull)riderId withCompletion:(PrimaryCardBlock _Nonnull)handler;
-(void)deleteCard:(RACardDataModel* _Nonnull)card fromRider:(NSString* _Nonnull)riderId withCompletion:(DeleteCardBlock _Nonnull)handler;
-(void)updateCard:(RACardDataModel *_Nonnull)card forRideWithId:(NSString * _Nonnull)riderId expMonth:(NSString *_Nullable)month expYear:(NSString *_Nullable)year withCompletion:(APIErrorResponseBlock _Nonnull)handler;

@end

@interface RWRiderClient (UnpaidBalance)

-(void)payUnpaidBalanceForRiderWithId:(NSString* _Nonnull)riderId rideId:(NSString* _Nonnull)rideId applePayToken:(NSString* _Nullable)applePayToken completion:(APIErrorResponseBlock _Nonnull)handler;

@end

@interface RWRiderClient (CreditBalance)

-(void)redemptionsRemainderForRiderWithId:(NSString* _Nonnull)riderId completion:(APIResponseBlock _Nonnull)completion;
-(void)redemptionsForRiderWithId:(NSString* _Nonnull)riderId completion:(RedemptionsBlock _Nonnull)completion;

@end

NS_ASSUME_NONNULL_BEGIN

@interface RWRiderClient (TripHistory)

-(void)getTripHistoryWithRiderId:(NSString *)riderId limit:(NSNumber *)pageSize offset:(NSNumber *)page completion:(TripHistoryCompletion)handler;

@end

NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN

@interface RWRiderClient (UserProfile)

- (void)updateUserEmail:(NSString *)email firstname:(NSString *)firstname lastname:(NSString *)lastname phoneNumber:(NSString *)phoneNumber withCompletion:(RAUpdateUserCompletionBlock)handler;
-(void)checkAvailabilityOfPhone:(NSString*)newPhone;
-(void)updateUserPhoto:(UIImage*)photo withCompletion:(RAUpdateUserCompletionBlock)handler;
-(void)registerPushNotificationsToken:(NSString*)token withCompletion:(void(^)(NSError *error))completion;

@end


@interface RWRiderClient (Support)

- (void)getSupportTopicListWithCompletion:(SupportTopicBlock _Nonnull )handler;
- (void)getTopicsWithParentId:(NSNumber*_Nonnull)parentTopicId withCompletion:(SupportTopicBlock _Nonnull )handler;
- (void)getFormForTopic:(SupportTopic *_Nonnull)topic
         withCompletion:(void(^_Nonnull)(LIOptionDataModel *_Nullable, NSError *_Nullable))completion;
- (void)postSupportMessage:(NSString*_Nonnull)comment supportTopic:(SupportTopic*_Nonnull)supportTopic rideId:(NSNumber*_Nonnull)rideId withCompletion:(SupportTopicPostMessageBlock _Nonnull )handler;
- (void)postSupportMessage:(NSString*_Nonnull)message rideID:(NSString *_Nullable)rideID cityID:(NSNumber *_Nullable)cityID withCompletion:(void(^_Nonnull)(NSError * _Nullable error))completion;
- (void)postLostAndFoundLostParameters:(NSDictionary *_Nonnull)params
                        withCompletion:(LostAndFoundBlock _Nonnull )completion;
- (void)postLostAndFoundContactParameters:(NSDictionary *_Nonnull)params
                           withCompletion:(LostAndFoundBlock _Nonnull)completion;
- (void)postLostAndFoundFoundParameters:(NSDictionary *_Nonnull)params
                              andImages:(NSDictionary<NSString *, NSData *> *_Nullable)images
                         withCompletion:(LostAndFoundBlock _Nonnull)completion;

@end

NS_ASSUME_NONNULL_END
