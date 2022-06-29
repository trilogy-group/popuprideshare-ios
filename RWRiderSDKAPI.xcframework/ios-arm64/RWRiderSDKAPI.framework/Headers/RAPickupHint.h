#import <Foundation/Foundation.h>

#import "RABaseDataModel.h"
#import "RACoordinate.h"
#import "RADesignatedPickup.h"

@interface RAPickupHint : RABaseDataModel

@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) NSArray<RACoordinate*> *areaPolygon;
@property (nonatomic, readonly) NSArray<RADesignatedPickup*> *designatedPickups;

- (Path *)path;
- (BOOL)containsCoordinate:(CLLocationCoordinate2D)coordinate;

@end
