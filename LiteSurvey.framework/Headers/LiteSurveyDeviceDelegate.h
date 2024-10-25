//
//  LiteSurveyDeviceDelegate.h
//  LiteSurvey
//
//  Created by Woncan on 2024/10/15.
//  Delegate for monitoring data and connection status of LiteSurvey devices

#ifndef LiteSurveyDeviceDelegate_h
#define LiteSurveyDeviceDelegate_h
#import <LiteSurvey/LiteSurveyDeviceInfoModel.h>
#import <LiteSurvey/LiteSurveyLocationModel.h>
#import <LiteSurvey/SatelliteInfoModel.h>
#import <LiteSurvey/BatteryInfoModel.h>
#import <LiteSurvey/ImuInfoModel.h>

typedef NS_ENUM(NSUInteger, NmeaType) {
    NmeaTypeGGA = 1,
    NmeaTypeGSA,
    NmeaTypeGSV,
    NmeaTypeRMC,
    NmeaTypeVTG,
    NmeaTypeGST,
    NmeaTypeZDA
};

typedef NS_ENUM(NSUInteger, GnssOutputRate) {
    GnssRate200Ms = 200,
    GnssRate500Ms = 500,
    GnssRate1Sec = 1000,
    GnssRate2Sec = 2000,
    GnssRate5Sec = 5000
};

@protocol LiteSurveyDeviceDelegate <NSObject>

@optional


/// Called when a LiteSurvey device has connected.
- (void)deviceDidConnect;


/// Called when a LiteSurvey device has disconnected.
- (void)deviceDidDisconnect;


/// Called when general information about the device was received from a LiteSurvey device.
/// - Parameter deviceInfo: General device information of the LiteSurvey device
- (void)didReceiveDeviceInfo:(LiteSurveyDeviceInfoModel *)deviceInfo;


/// Called when LiteSurvey device updates is location
/// - Parameter location: Location of the LiteSurvey device
- (void)didReceiveLocation:(LiteSurveyLocationModel *)location;


/// Called when LiteSurvey device updates satellite information
/// - Parameter satelliteInfoList: List of satellite information
- (void)didReceiveSatelliteInfo:(NSArray<SatelliteInfoModel*> *)satelliteInfoList;


/// Called when an NMEA message is received from LiteSurvey device
/// - Parameter nmeaMessage: NMEA message
- (void)didReceiveNmeaMessage:(NSString *)nmeaMessage;

/// Called when a RTCM message is received from LiteSurvey device
/// - Parameter rtcmMessage: RTCM message
- (void)didReceiveRtcmMessage:(NSData *)rtcmMessage;

/// Called when LiteSurvey device updates its battery information
/// - Parameter batteryInfo: Battery information of LiteSurvey device
- (void)didReceiveBatteryInfo:(BatteryInfoModel *)batteryInfo;

/// Called when the laser on LiteSurvey device was toggled
/// - Parameter laserState: true if laser was turned on, false if laser was turned off
- (void)laserStateDidChange:(BOOL)laserState;

/// Called when IMU data was received from LiteSurvey device
/// - Parameter imuInfo: IMU data
- (void)didReceiveImuData:(ImuInfoModel *)imuInfo;

/// Called when Woncan server reports whether a firmware upgrade for this LiteSurvey device is available
/// - Parameter newFirmwareAvailable: true if firmware upgrade is available, false otherwise
- (void)didReceiveFirmwareUpgradeAvailability:(BOOL)newFirmwareAvailable;

/// Called when firmware upgrade of LiteSurvey device has progressed
/// - Parameter progressPercentage: Progress percentage
- (void)firmwareUpgradeDidProgress:(int)progressPercentage;

/// Called when firmware update (query or the update itself) encounters an error
/// - Parameter errorMessage: Error message
- (void)firmwareUpgradeDidFailWithError:(NSString *)errorMessage;

/// called when ntrip mountpoint query failed
/// - Parameter errorMessage: error message
- (void)ntripMountpointQueryDidFailWithError:(NSString *)errorMessage;

/// Called when mountpoint list was retrieved from ntrip server
/// - Parameter mountpointList: List of ntrip mountpoints
- (void)ntripMountpointQueryDidFinishWithResult:(NSArray<NSString *> *)mountpointList;


@end
#endif /* LiteSurveyDeviceDelegate_h */
