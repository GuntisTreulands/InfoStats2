//
//  IS2System.h
//  InfoStats2
//
//  Created by Matt Clarke on 14/07/2015.
//
//

#import <Foundation/Foundation.h>

/** IS2System is used to access various system related data and functions, such as the RAM and battery data found in the original InfoStats, and functions such as launching applications.
 */

@interface IS2System : NSObject

/** @name Device Data */

/** Gives the current percentage of the battery remaining. This value is equal to that shown in the status bar.
@return The currrent battery remaining percentage
*/
+(int)batteryPercent;

/** Gives the current state of the battery as a string, which is pre-translated for you.
 @return The currrent battery state
 */
+(NSString*)batteryState;

/** Gives the current state of the battery as an integer, which may be used if you wish to supply your own strings for each state.
 @return The currrent battery state as an integer
 */
+(int)batteryStateAsInteger;

/** Gives the current amount of free RAM in megabytes (MB). This is calculated by adding the free RAM to the inactive RAM, since it appears iOS also treats inactive as free.
 @return The currrent amount of free RAM
 */
+(int)ramFree;

/** Gives the current amount of used RAM in megabytes (MB).
 @return The currrent amount of used RAM
 */
+(int)ramUsed;

/** Gives the amount of RAM available on the device in megabytes (MB).
 @return The amount of available RAM
 */
+(int)ramAvailable;

/** Gives the current CPU usage in percent (across all available cores)
 @return Current CPU usage (combined for system processes and user processes)
 */
+(double)cpuUsage;

/** Gives the current free space left on the device. 
 @param format Adjusts the output of the function to be in bytes, kb, MB or GB:<br/>0 - Bytes<br/>1 - kb<br/>2 - MB<br/>3 - GB
 */
+(double)freeDiskSpaceInFormat:(int)format;

/** Gives the current up speed of the user's network connection.<br/><i>Please note this is currently non-functional.</i>
 @return Up speed in kb/s
 */
+(double)networkSpeedUp;

/** Gives the current down speed of the user's network connection.<br/><i>Please note this is currently non-functional.</i>
 @return Down speed in kb/s
 */
+(double)networkSpeedDown;

/** Gives the device type, eg iPhone, iPad or iPod
 @return Device type
 */
+(NSString*)deviceType;

/** Gives the exact model of the current device, eg iPhone7,2
 @return Device model
 */
+(NSString*)deviceModel;

/** Gives the height of the device's display in points. This does not change if the device is rotated.
 @return The height of the display
 */
+(int)deviceDisplayHeight;

/** Gives the width of the device's display in points. This does not change if the device is rotated.
 @return The width of the display
 */
+(int)deviceDisplayWidth;

/** Gives whether the user is using their device in 24hr time, or in 12hr time
 @return Whether device is in 24hr time or not
 */
+(BOOL)isDeviceIn24Time;

/** @name System functions 
 */

/** Takes a screenshot of the current screen, and saves it in the user's photos.
 */
+(void)takeScreenshot;

/** Locks the device. Doesn't need much more explanation really.
 */
+(void)lockDevice;

/** Opens the app switcher.
 */
+(void)openSwitcher;

/** Launches a given application to the foreground.
 @param bundleIdentifier The bundle identifier of the application to launch
 */
+(void)openApplication:(NSString*)bundleIdentifier;

/** Opens the Siri interface.
 */
+(void)openSiri;

/** Relaunches SpringBoard immediately after calling.
 */
+(void)respring;

/** Reboots the device immediately after calling.
 */
+(void)reboot;

/** Vibrates the device (triggers an audible alert instead if vibration is not available) for 0.2 seconds. This respects the user setting "Vibrate on Silent" found under Sounds; no vibration will occur when this is turned off.
 */
+(void)vibrateDevice;

/** Vibrates the device (audible alert if vibration is unavailable) for a custom period of time. This respects the user setting "Vibrate on Silent" found under Sounds; no vibration will occur when this is turned off.
 @param timeLength Length of time in seconds to vibrate the device for
 */
+(void)vibrateDeviceForTimeLength:(CGFloat)timeLength;

/** @name Toggles, and other data setting
 */

/** Gives the current backlight level, which will be between 0.0 and 1.0.
 @return Current backlight level
 */
+(CGFloat)getBrightness;

/** Sets the current backlight level, and expects values between 0.0 and 1.0
 @param The new backlight level
 */
+(void)setBrightness:(CGFloat)level;

/** Gives the current state of the Low Power mode.<br/><br/>This will return NO for versions of iOS less than iOS 9.
 @return Current Low Power mode state
 */
+(BOOL)getLowPowerMode;

/** Sets the current Low Power mode state.<br/><br/>This will do nothing for versions of iOS less than iOS 9.
 @param The new mode; YES for on, NO for off.
 */
+(void)setLowPowerMode:(BOOL)mode;

@end
