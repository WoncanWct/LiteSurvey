# LiteSurvey SDK Demo for iOS

This demo project shows how to use the LiteSurvey SDK to connect to Woncan LiteSurvey devices.

LiteSurvey SDK for iOS can connect to LiteSurvey devices and

- Output device data (location, satellite, etc.) to the application
- Configure device settings
- Perform device firmware upgrade
- and more

By integrating this SDK, you can support LiteSurvey device's high-accuracy position in your own app.

This SDK is also used in Woncan's official iOS app, LiteGPS.

## iOS system requirement

iOS 13.0+

## How to use the SDK in your own app

### CocoaPods

[CocoaPods](http://cocoapods.org) is a dependency manager for Cocoa projects. You can install it with the following command:

```bash
$ gem install cocoapods
```

To integrate LiteSurvey into your Xcode project using CocoaPods, specify it in your `Podfile`:

```ruby
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '13.0'
use_frameworks!

target '<Your Target Name>' do
    pod 'LiteSurvey', '~> 0.0.1'
end
```

Then, run the following command:

```bash
$ pod install
```

### Manually

If you prefer not to use either of the aforementioned dependency managers, you can integrate LiteSurvey into your project manually.

添加LiteSurvey后需要在项目target->General->Frameworks,Libraries,and Embedded Content,修改引入的 LiteRTK.framework的Embed到Embed&Sign选项.

LiteSurvey目前是基于`Objective-C`开发，如果接入的项目也是OC环境可以直接引入`#import <LiteSurvey/LiteSurvey.h>`开始使用，<br>如果是`Swift`环境需要在桥接文件`bridging-header`里面引入`#import <LiteSurvey/LiteSurvey.h>`

---

### Scanning for devices

Use the `LiteSurveyDeviceInterface` object to start and stop scanning.

### Receive device data (e.g. location)

When connecting to a device, register a delegate implementing the `LiteSurveyDeviceDelegate` abstract class to receive device data.

### Code example

The following code snippet is a minimal code example in Swift that

1. 搜索或者直接使用已连接的LiteSurvey device.
2. Prints the location information reported by the device to Logcat.

```Swift
class ViewController: UIViewController,LiteSurveyDeviceDelegate {
  var liteSurveyInterface: LiteSurveyDeviceInterface?
  override func viewDidLoad() {
        super.viewDidLoad()
        liteSurveyInterface = LiteSurveyDeviceInterface(delegate: self)
  }

  //search device
    public func toSearch() {
        liteSurveyInterface?.startScan()
    }

  // Receive Location delegate
    func didReceiveLocation(_ location: LiteSurveyLocationModel!) {
        print(location!)
    }
}
```



## Location information reported by the SDK

Location information is reported as the `LiteSurveyLocationModel` class. This class inherits from the system Location class [ `CLLocation`](https://developer.apple.com/documentation/corelocation/cllocation?language=objc#). Please see `LiteSurveyLocationModel` class definition for details.

Table: LiteSurvey SDK support for system Location class parameters

|            Parameter            | Supported by LiteSurvey | Notes                         |
| :-----------------------------: | ----------------------- | ----------------------------- |
|            coordinate           | Yes                     |                               |
|            altitude             | Yes                     |                               |
|        horizontalAccuracy       | Yes                     |                               |
|         verticalAccuracy        | Yes                     |                               |
|             course              | No                      |                               |
|          courseAccuracy         | No                      |                               |
|             speed               | Yes                     |                               |
|          speedAccuracy          | No                      |                               |
|            timestamp            | Yes                     |                               |
|             floor               | No                      |                               |
|        sourceInformation        | Yes                     |                               |

## Contact email

For technical or business inquiries, please contact support@woncan.com.hk
