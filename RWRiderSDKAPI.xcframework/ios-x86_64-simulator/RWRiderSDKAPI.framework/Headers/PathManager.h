//
//  PathManager.h
//  RWRiderSDKAPI
//
//  Created by Rahul Gera on 09/06/22.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


NS_ASSUME_NONNULL_BEGIN

@interface Path : NSObject

-(instancetype)init;
-(BOOL)contains:(CLLocationCoordinate2D)coordinate;
@property(nonatomic, strong)NSArray<CLLocation *> *allLocations;
@end

@interface MutablePath : Path

@property(nonatomic, strong)NSMutableArray *allCoordinates;
/** Adds |coord| at the end of the path. */
- (void)addCoordinate:(CLLocationCoordinate2D)coord;

/** Adds a new CLLocationCoordinate2D instance with the given lat/lng. */
- (void)addLatitude:(CLLocationDegrees)latitude longitude:(CLLocationDegrees)longitude;

@end

@interface PathManager : NSObject

+(Path*)pathWithLocations:(NSArray<CLLocation *> *)locations;
+ (BOOL)coordinate:(CLLocationCoordinate2D)coordinate isInsidePathFromLocations:(NSArray<CLLocation *> *)locations;
@end








@interface Bounds: NSObject

@end

NS_ASSUME_NONNULL_END
