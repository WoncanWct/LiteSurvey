//
//  LiteSurveyLocation.h
//  LiteSurvey
//
//  Created by Woncan on 2024/10/15.
//  Location class as reported by LiteSurvey devices. Inherits from the system Location class.

#import <CoreLocation/CoreLocation.h>

/// Gnss fix status
/// status Integer representing the fix status as defined in NMEA GGA message
typedef NS_ENUM(NSUInteger,GnssFixStatus){
    GnssFixSingle = 1,// GNSS single solution, differential data not in use
    GnssFixDGNSS = 2,// DGNSS solution, differential GNSS based on pseudorange only
    GnssFixFixed = 4,// RTK fixed GNSS solution
    GnssFixFloat = 5,// RTK float GNSS solution
    GnssFixUnknown = 0 // GNSS fix status invalid or unknown
};

NS_ASSUME_NONNULL_BEGIN

@interface LiteSurveyLocationModel : CLLocation
/// GNSS fix status
@property (nonatomic,assign) GnssFixStatus fixStatus;

/// Number of satellites in view
@property (nonatomic,assign) int numSatsInView;

/// Number of satellites used in GNSS fix
@property (nonatomic,assign) int numSatsInUse;

/// Differential reference station ID, 0000-1023
@property (nonatomic,assign) int refStationId;

/// Age of Differential GNSS data in seconds
@property (nonatomic,assign) float diffDataDelaySeconds;

/// Horizontal dilution of precision
@property (nonatomic,assign) float hdop;

/// Vertical dilution of precision
@property (nonatomic,assign) float vdop;

/// Position dilution of precision
@property (nonatomic,assign) float pdop;


@end

NS_ASSUME_NONNULL_END
