// Generated by Apple Swift version 2.3 (swiftlang-800.10.12 clang-800.0.38)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
@import Foundation;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class ActionCameraListener;
@protocol DispatchQueue;
@class NSURLSession;
@class NSURLSessionDownloadTask;
@class NSURL;
@class NSURLSessionTask;
@class NSError;


/// Present an YI action camera.
///
/// This class presents an YI action camera. App can invoke its functions to control the camera.
/// Like start recording, stop recording, take picture, read settings, set settings, etc. Before
/// operating an camera, App need invoke <code>ActionCamera.connect(connectionString:)
/// </code> to connect to the camera.
/// After connect success (<code>ActionCameraListener.onConnected()
/// </code> will be invoked), app can invoke other functions.
/// Whenever app wants to disconnect from the camera, app can invoke <code>ActionCamera.disconnect()
/// </code>.
///
/// Any <code>success
/// </code> or <code>fail
/// </code> callback in commands are optional parameter. If you don't care command
/// execution result, you can pass <code>nil
/// </code>.
SWIFT_CLASS("_TtC11YICameraSDK12ActionCamera")
@interface ActionCamera : NSObject <NSURLSessionDownloadDelegate, NSURLSessionDelegate, NSURLSessionTaskDelegate>

/// Constructor of ActionCamera.
///
/// When app creates an ActionCamera object, app need specify a listener which will receive the
/// camera notifications and a message queue which will be used to dispatch the notification.
/// Recommend app uses the same message queue as UI thread using. So that all notifications will
/// be passed in UI thread and app can update UI directly in the callback of notifications.
///
/// \param listener The listener will be used to receive notification from the camera.
///
/// \param workThreadQueue The message queue will be used to dispatch camera notifications.
- (nonnull instancetype)initWithListener:(ActionCameraListener * _Nonnull)listener dispatchQueue:(id <DispatchQueue> _Nonnull)dispatchQueue OBJC_DESIGNATED_INITIALIZER;

/// Connect to a YI action camera.
///
/// Invoke this function to connect to a YI action camera. Param <code>connectionString
/// </code> represents
/// the address of the remote camera. Format is:
///
/// <code>tcp:<ip address>:<port>
/// 
/// </code>
/// If the camera has been connected or the previous connect operation hasn't been finished.
/// Nothing will happen. Otherwise connect operation will be executed asynchronously. If success,
/// <code>ActionCameraListener.onConnected()
/// </code> callback will be invoked. If fail,
/// <code>ActionCameraListener.onClosed(error:)
/// </code> callback will be invoked and parameter <code>error
/// </code>
/// will be set.
- (void)connectWithConnectionString:(NSString * _Nonnull)connectionString;

/// Cancel current download task.
- (ActionCamera * _Nonnull)cancelDownlad;
- (void)URLSession:(NSURLSession * _Nonnull)session downloadTask:(NSURLSessionDownloadTask * _Nonnull)downloadTask didFinishDownloadingToURL:(NSURL * _Nonnull)location;
- (void)URLSession:(NSURLSession * _Nonnull)session downloadTask:(NSURLSessionDownloadTask * _Nonnull)downloadTask didWriteData:(int64_t)bytesWritten totalBytesWritten:(int64_t)totalBytesWritten totalBytesExpectedToWrite:(int64_t)totalBytesExpectedToWrite;
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task didCompleteWithError:(NSError * _Nullable)error;

/// Disconnect from YI action camera.
///
/// Invoke this function to disconnect from a YI action camera. This function will return
/// immediately and the disconnect operation will be executed asynchronously. All pending
/// commands will be cancelled (the <code>fail
/// </code> callback of the command will be invoked and the
/// code of <code>error
/// </code> parameter will be set to <code>ErrorCode.Cancelled
/// </code>). At the end,
/// <code>ActionCameraListener.onClosed(error:)
/// </code> callback will be invoked and <code>error
/// </code> parameter
/// will be set to <code>nil
/// </code>.
- (void)disconnect;
@end

@class Error;

@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))

/// Delete file from camera.
///
/// \param fileName Filename you want to delete from camera.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)deleteFileWithFileName:(NSString * _Nonnull)fileName success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;
@end

@class NSDate;

@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))

/// Set datetime to camera.
///
/// \param datetime The datetime you want to set to camera.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setDateTimeWithDatetime:(NSDate * _Nonnull)datetime success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;
@end

enum VideoResolution : NSInteger;

@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))

/// Get current video resolution.
///
/// \param success If command executes success, this callback will be invoked and parameter is
/// current video resolution.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getVideoResolutionWithSuccess:(void (^ _Nullable)(enum VideoResolution))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;
@end


@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))

/// Get current video resolution.
///
/// \param success If command executes success, this callback will be invoked and parameter is
/// current video resolution.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setVideoResolutionWithResolution:(enum VideoResolution)resolution success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;
@end


@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))

/// Take a picture on camera.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)takeCaptureWithSuccess:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;
@end


@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))
@end

@class ActionCameraSettings;

@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))

/// Get camera settings.
///
/// \param success If command executes success, this callback will be invoked and parameter is
/// the settings of camera.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getSettingsWithSuccess:(void (^ _Nullable)(ActionCameraSettings * _Nonnull))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;
@end


@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))

/// Stop recording on camera.
///
/// \param success If command executes success, this callback wil be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)stopRecordingWithSuccess:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;
@end

enum SystemMode : NSInteger;

@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))

/// Set camera system mode.
///
/// \param mode System mode supported by YI action camera.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setSystemModeWithMode:(enum SystemMode)mode success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;
@end

enum PhotoSize : NSInteger;

@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))

/// Get current photo size.
///
/// \param success If command executes success, this callback will be invoked and parameter is
/// current photo size.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getPhotoSizeWithSuccess:(void (^ _Nullable)(enum PhotoSize))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;
@end

enum Status : NSInteger;

@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))

/// Get camera current status.
///
/// \param success If command executes success, this callback will be invoked and parameter is
/// current status of camera.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getStatusWithSuccess:(void (^ _Nullable)(enum Status))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;
@end


@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))

/// Get current video resolution.
///
/// \param success If command executes success, this callback will be invoked and parameter is
/// current video resolution.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setPhotoSizeWithPhotoSize:(enum PhotoSize)photoSize success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;
@end


@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))

/// Start recording immediately.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)startRecordingWithSuccess:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Start recording at specific time.
///
/// \param hour Start recording at this hour.
///
/// \param minute Start recording at this minute.
///
/// \param second Start recording at this second.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)startRecordingWithHour:(NSInteger)hour minute:(NSInteger)minute second:(NSInteger)second success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;
@end


@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))
@end

enum WhiteBalance : NSInteger;
enum ISO : NSInteger;
enum ExposureValue : NSInteger;
enum ShutterTime : NSInteger;
enum FieldOfView : NSInteger;
enum MeteringMode : NSInteger;
enum Quality : NSInteger;
enum ColorMode : NSInteger;
enum Sharpness : NSInteger;
enum Enabled : NSInteger;
enum Timestamp : NSInteger;

@interface ActionCamera (SWIFT_EXTENSION(YICameraSDK))

/// Get photo white balance.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getPhotoWhiteBalanceWithSuccess:(void (^ _Nullable)(enum WhiteBalance))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Set photo white balance.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setPhotoWhiteBalanceWithWhiteBalance:(enum WhiteBalance)whiteBalance success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Get video white balance.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getVideoWhiteBalanceWithSuccess:(void (^ _Nullable)(enum WhiteBalance))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Set video white balance.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setVideoWhiteBalanceWithWhiteBalance:(enum WhiteBalance)whiteBalance success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Get photo iso.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getPhotoISOWithSuccess:(void (^ _Nullable)(enum ISO))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Set photo iso.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setPhotoISOWithIso:(enum ISO)iso success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Get video iso.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getVideoISOWithSuccess:(void (^ _Nullable)(enum ISO))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Set video iso.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setVideoISOWithIso:(enum ISO)iso success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Get photo exposure value.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getPhotoExposureValueWithSuccess:(void (^ _Nullable)(enum ExposureValue))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Set photo exposure value.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setPhotoExposureValueWithEv:(enum ExposureValue)ev success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Get video exposure value.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getVideoExposureValueWithSuccess:(void (^ _Nullable)(enum ExposureValue))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Set video exposure value.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setVideoExposureValueWithEv:(enum ExposureValue)ev success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Get photo shutter time.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getPhotoShutterTimeWithSuccess:(void (^ _Nullable)(enum ShutterTime))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Set photo shutter time.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setPhotoShutterTimeWithShutterTime:(enum ShutterTime)shutterTime success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Get video field of view.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getVideoFieldOfViewWithSuccess:(void (^ _Nullable)(enum FieldOfView))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Set video field of view.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setVideoFieldOfViewWithFieldOfView:(enum FieldOfView)fieldOfView success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Get metering mode.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getMeteringModeWithSuccess:(void (^ _Nullable)(enum MeteringMode))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Set metering mode.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setMeteringModeWithMeteringMode:(enum MeteringMode)meteringMode success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Get video quality.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getVideoQualityWithSuccess:(void (^ _Nullable)(enum Quality))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Set video quality.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setVideoQualityWithQuality:(enum Quality)quality success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Get video color mode.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getVideoColorModeWithSuccess:(void (^ _Nullable)(enum ColorMode))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Set video quality.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setVideoColorModeWithColorMode:(enum ColorMode)colorMode success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Get photo color mode.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getPhotoColorModeWithSuccess:(void (^ _Nullable)(enum ColorMode))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Set photo color mode.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setPhotoColorModeWithColorMode:(enum ColorMode)colorMode success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Get video sharpness.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getVideoSharpnessWithSuccess:(void (^ _Nullable)(enum Sharpness))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Set video sharpness.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setVideoSharpnessWithSharpness:(enum Sharpness)sharpness success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Get photo sharpness.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getPhotoSharpnessWithSuccess:(void (^ _Nullable)(enum Sharpness))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Set photo sharpness.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setPhotoSharpnessWithSharpness:(enum Sharpness)sharpness success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Get electron image stabilization enabled status.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getElectronImageStabilizationEnabledWithSuccess:(void (^ _Nullable)(enum Enabled))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Set electron image stabilization enabled status.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setElectronImageStabilizationEnabledWithEnabled:(enum Enabled)enabled success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Get video timestamp setting.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getVideoTimestampWithSuccess:(void (^ _Nullable)(enum Timestamp))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Set video timestamp setting.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setVideoTimestampWithTimestamp:(enum Timestamp)timestamp success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Get photo timestamp setting.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)getPhotoTimestampWithSuccess:(void (^ _Nullable)(enum Timestamp))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;

/// Set photo timestamp setting.
///
/// \param success If command executes success, this callback will be invoked.
///
/// \param fail If command executes fail, this callback will be invoked.
- (ActionCamera * _Nonnull)setPhotoTimestampWithTimestamp:(enum Timestamp)timestamp success:(void (^ _Nullable)(void))success fail:(void (^ _Nullable)(Error * _Nonnull))fail;
@end



/// Define the callback to receive camera notifications.
SWIFT_CLASS("_TtC11YICameraSDK20ActionCameraListener")
@interface ActionCameraListener : NSObject

/// When ActionCamera.connect() success, this callback will be invoked.
- (void)onConnected;

/// When the connection to camera is closed, this callback will be invoked.
///
/// \param error If the connection is closed due to any error, this parameter will be set.
/// If it is <code>nil
/// </code>, means the connection is closed by app.
- (void)onClosedWithError:(Error * _Nullable)error;

/// When recording is started on camera, this callback will be invoked.
- (void)onRecordStarted;

/// When recording is stopped on camera, this callback will be invoked.
- (void)onRecordStopped;

/// When capture is started on camera, this callback will be invoked.
- (void)onCaptureStarted;

/// When capture is stopped on camera, this callback will be invoked.
- (void)onCaptureStopped;

/// When video finder started, this callback will be invoked. After received this event, you can start play video stream vi rtsp protocol.
- (void)onVideoFinderStarted;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

enum VideoStandard : NSInteger;


/// Define the camera settings.
SWIFT_CLASS("_TtC11YICameraSDK20ActionCameraSettings")
@interface ActionCameraSettings : NSObject

/// Current status.
@property (nonatomic) enum Status status;

/// Current datetime of camera.
@property (nonatomic, strong) NSDate * _Nullable clock;

/// Current software version.
@property (nonatomic, copy) NSString * _Nullable softwareVersion;

/// Current hardware version.
@property (nonatomic, copy) NSString * _Nullable hardwareVersion;

/// Serial number of camera.
@property (nonatomic, copy) NSString * _Nullable serialNumber;

/// Product name of camera.
@property (nonatomic, copy) NSString * _Nullable productName;

/// Current mode of camera.
@property (nonatomic) enum SystemMode systemMode;

/// Current video standard.
@property (nonatomic) enum VideoStandard videoStandard;

/// Current video resolution.
@property (nonatomic) enum VideoResolution videoResolution;

/// Current video quality.
@property (nonatomic) enum Quality videoQuality;

/// Current picture resolution.
@property (nonatomic) enum PhotoSize photoSize;

/// Current photo white balance.
@property (nonatomic) enum WhiteBalance photoWhiteBalance;

/// Current video white balance.
@property (nonatomic) enum WhiteBalance videoWhiteBalance;

/// Current photo iso.
@property (nonatomic) enum ISO photoISO;

/// Current video iso.
@property (nonatomic) enum ISO videoISO;

/// Current photo exposure value.
@property (nonatomic) enum ExposureValue photoExposureValue;

/// Current video exposure value.
@property (nonatomic) enum ExposureValue videoExposureValue;

/// Current photo shutter time.
@property (nonatomic) enum ShutterTime photoShutterTime;

/// Current video field of view.
@property (nonatomic) enum FieldOfView videoFieldOfView;

/// Current metering mode.
@property (nonatomic) enum MeteringMode meteringMode;

/// Current video color mode.
@property (nonatomic) enum ColorMode videoColorMode;

/// Current photo color mode.
@property (nonatomic) enum ColorMode photoColorMode;

/// Current video sharpness.
@property (nonatomic) enum Sharpness videoSharpness;

/// Current photo sharpness.
@property (nonatomic) enum Sharpness photoSharpness;

/// Is electronic image stabilization enabled.
@property (nonatomic) enum Enabled electronicImageStabilizationEnabled;

/// Current video timestamp.
@property (nonatomic) enum Timestamp videoTimestamp;

/// Current photo timestamp.
@property (nonatomic) enum Timestamp photoTimestamp;
@end


/// Color mode supported by YI action camera.
typedef SWIFT_ENUM(NSInteger, ColorMode) {

/// Unknown
  ColorModeUnknown = 0,

/// YI Color
  ColorModeYIColor = 1,

/// Flat
  ColorModeFlat = 2,
};



/// Define the interface of message loop.
///
/// App need implement this interface and runs a message loop to process the message/task one by one.
/// All callback will be invoked from this queue.
SWIFT_PROTOCOL("_TtP11YICameraSDK13DispatchQueue_")
@protocol DispatchQueue

/// Put a task to the queue.
///
/// <em>Note: This method must be thread safe and <code>task
/// </code> must be executed out of current call stack.</em>
///
/// \param task The task will be executed from the message loop.
- (void)dispatchWithTask:(void (^ _Nonnull)(void))task;
@end


/// Color mode supported by YI action camera.
typedef SWIFT_ENUM(NSInteger, Enabled) {

/// Unknown
  EnabledUnknown = 0,

/// Enabled
  EnabledOn = 1,

/// Disabled
  EnabledOff = 2,
};



/// Represent the error.
SWIFT_CLASS("_TtC11YICameraSDK5Error")
@interface Error : NSObject

/// Get the error code.
- (uint32_t)getCode;

/// Get the sub error.
- (Error * _Nullable)getSubError;

/// Get the detail information of error.
- (NSString * _Nullable)getDetail;
@end



/// Define the error code of an error object.
SWIFT_CLASS("_TtC11YICameraSDK9ErrorCode")
@interface ErrorCode : NSObject

/// Success, not an error.
+ (uint32_t)Success;

/// Operation has been cancelled by the user.
+ (uint32_t)Cancelled;

/// State is invalid.
+ (uint32_t)InvalidState;

/// An IOException is raised.
+ (uint32_t)IOException;

/// Parameter is invalid.
+ (uint32_t)InvalidParameter;

/// Operation is not supported.
+ (uint32_t)NotSupported;

/// The response format of the camera is invalid.
+ (uint32_t)InvalidResponse;

/// Command executes failed.
+ (uint32_t)CommandFailed;

/// The format is invalid.
+ (uint32_t)InvalidFormat;

/// Requirements are not meet.
+ (uint32_t)PreConditionFailed;

/// Timeout.
+ (uint32_t)Timeout;

/// Camera is busy.
+ (uint32_t)CameraIsBusy;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


/// Exposure value supported by YI action camera.
typedef SWIFT_ENUM(NSInteger, ExposureValue) {

/// Unknown
  ExposureValueUnknown = 0,

/// -2.0
  ExposureValueev_negative_2 = 1,

/// -1.5
  ExposureValueev_negative_1_point_5 = 2,

/// -1.0
  ExposureValueev_negative_1 = 3,

/// -0.5
  ExposureValueev_negative_0_point_5 = 4,

/// 0
  ExposureValueev_0 = 5,

/// +0.5
  ExposureValueev_positive_0_point_5 = 6,

/// +1.0
  ExposureValueev_positive_1 = 7,

/// +1.5
  ExposureValueev_positive_1_point_5 = 8,

/// +2.0
  ExposureValueev_positive_2 = 9,
};


/// Field of view supported by YI action camera.
typedef SWIFT_ENUM(NSInteger, FieldOfView) {

/// Unknown
  FieldOfViewUnknown = 0,

/// Wide
  FieldOfViewWide = 1,

/// Medium
  FieldOfViewMedium = 2,

/// Narrow
  FieldOfViewNarrow = 3,
};


/// ISO supported by YI action camera.
typedef SWIFT_ENUM(NSInteger, ISO) {

/// Unknown
  ISOUnknown = 0,

/// Auto
  ISOiso_Auto = 1,

/// 100 (only used for photo)
  ISOiso_100 = 2,

/// 200 (only used for photo)
  ISOiso_200 = 3,

/// 400
  ISOiso_400 = 4,

/// 800 (only used for photo)
  ISOiso_800 = 5,

/// 1600 (only used for video)
  ISOiso_1600 = 6,

/// 6400 (only used for video)
  ISOiso_6400 = 7,
};



/// Define the log interface.
///
/// App can write a subclass inherited from this class to supply log functionality.
SWIFT_CLASS("_TtC11YICameraSDK6Logger")
@interface Logger : NSObject

/// Output verbose level log.
///
/// \param message The message will be outputted at verbose level.
- (void)verboseWithMessage:(NSString * _Nonnull)message;

/// Output info level log.
///
/// \param message The message will be outputted at info level.
- (void)infoWithMessage:(NSString * _Nonnull)message;

/// Output warning level log.
///
/// \param message The message will be outputted at warning level.
- (void)warningWithMessage:(NSString * _Nonnull)message;

/// Output error level log.
///
/// \param message The message will be outputted at error level.
- (void)errorWithMessage:(NSString * _Nonnull)message;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


/// Metering mode supported by YI action camera.
typedef SWIFT_ENUM(NSInteger, MeteringMode) {

/// Unknown
  MeteringModeUnknown = 0,

/// Center
  MeteringModeCenter = 1,

/// Average
  MeteringModeAverage = 2,

/// Spot
  MeteringModeSpot = 3,
};


/// Picture resolution supported by YI action camera.
typedef SWIFT_ENUM(NSInteger, PhotoSize) {

/// Unknown
  PhotoSizeUnknown = 0,

/// Photo size is 12MP (4000x3000 4:3) fov:w
  PhotoSizep_12MP_4000x3000_4x3_w = 1,

/// Photo size is 7MP (3008x2256 4:3) fov:w
  PhotoSizep_7MP_3008x2256_4x3_w = 2,

/// Photo size is 7MP (3008x2256 4:3) fov:m
  PhotoSizep_7MP_3008x2256_4x3_m = 3,

/// Photo size is 5MP (2560x1920 4:3) fov:m
  PhotoSizep_5MP_2560x1920_4x3_m = 4,

/// Photo size is 8MP (3840x2160 16:9) fov:w
  PhotoSizep_8MP_3840x2160_16x9_w = 5,
};



/// This class will be used to initialize/uninitialize the whole SDK platform.
SWIFT_CLASS("_TtC11YICameraSDK8Platform")
@interface Platform : NSObject

/// Initialize SDK platform.
///
/// This function should only be invoked once at the app startup. App shouldn't invoke any
/// functions before invoking this function.
///
/// \param logger The log interface (app need implements this interface) used by the whole
/// SDK platform. Pass <code>nil
/// </code> will turn off the log.
+ (void)initializeWithLogger:(Logger * _Nullable)logger;

/// Uninitialize SDK platform.
///
/// This function should only be invoked once at the app ended. App shouldn't invoke any
/// functions after invoking this function.
+ (void)uninitialize;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


/// Quality supported by YI action camera.
typedef SWIFT_ENUM(NSInteger, Quality) {

/// Unknown.
  QualityUnknown = 0,

/// Low quality.
  QualityLow = 1,

/// Middle quality.
  QualityMiddle = 2,

/// High quality.
  QualityHigh = 3,
};


/// Sharpness supported by YI action camera.
typedef SWIFT_ENUM(NSInteger, Sharpness) {

/// Unknown
  SharpnessUnknown = 0,

/// High
  SharpnessHigh = 1,

/// Medium
  SharpnessMedium = 2,

/// Low
  SharpnessLow = 3,
};


/// Shutter time supported by YI action camera.
typedef SWIFT_ENUM(NSInteger, ShutterTime) {

/// Unknown
  ShutterTimeUnknown = 0,

/// Auto
  ShutterTimest_Auto = 1,

/// 2 seconds
  ShutterTimest_2s = 2,

/// 5 seconds
  ShutterTimest_5s = 3,

/// 10 seconds
  ShutterTimest_10s = 4,

/// 20 seconds
  ShutterTimest_20s = 5,

/// 30 seconds
  ShutterTimest_30s = 6,
};


/// Camera status.
typedef SWIFT_ENUM(NSInteger, Status) {

/// Unknown.
  StatusUnknown = 0,

/// Camera is idle.
  StatusIdle = 1,

/// Camera is recording.
  StatusRecording = 2,

/// RTSP service is started.
  StatusVideoFinderStarted = 3,
};


/// Camera mode supported by YI action camera.
typedef SWIFT_ENUM(NSInteger, SystemMode) {

/// Unknown.
  SystemModeUnknown = 0,

/// Video mode.
  SystemModeRecord = 1,

/// Picture mode.
  SystemModeCapture = 2,
};


/// Timestamp supported by YI action camera.
typedef SWIFT_ENUM(NSInteger, Timestamp) {

/// Unknown
  TimestampUnknown = 0,

/// Off
  TimestampOff = 1,

/// Time
  TimestampTime = 2,

/// Date
  TimestampDate = 3,

/// Date and time;
  TimestampDateAndTime = 4,
};


/// Video resolution supported by YICamera.
typedef SWIFT_ENUM(NSInteger, VideoResolution) {

/// Unknown
  VideoResolutionUnknown = 0,

/// Resolution is 3840x1260 30P 16:9.
  VideoResolutionv_3840x2160_30p_16x9 = 1,

/// Resolution is 3840x2160 30P 16:9 super.
  VideoResolutionv_3840x2160_30p_16x9_super = 2,

/// Resolution is 2560x1920 30P 4:3.
  VideoResolutionv_2560x1920_30p_4x3 = 3,

/// Resolution is 1920x1440 60P 4:3.
  VideoResolutionv_1920x1440_60p_4x3 = 4,

/// Resolution is 1920x1440 30P 4:3.
  VideoResolutionv_1920x1440_30p_4x3 = 5,

/// Resolution is 1920x1080 120P 16:9.
  VideoResolutionv_1920x1080_120p_16x9 = 6,

/// Resolution is 1920x1080 120P 16:9 super.
  VideoResolutionv_1920x1080_120p_16x9_super = 7,

/// Resolution is 1920x1080 60P 16:9.
  VideoResolutionv_1920x1080_60p_16x9 = 8,

/// Resolution is 1920x1080 60P 16:9 super.
  VideoResolutionv_1920x1080_60p_16x9_super = 9,

/// Resolution is 1920x1080 30P 16:9.
  VideoResolutionv_1920x1080_30p_16x9 = 10,

/// Resolution is 1920x1080 30P 16:9 super.
  VideoResolutionv_1920x1080_30p_16x9_super = 11,

/// Resolution is 1280x960 120P 4:3.
  VideoResolutionv_1280x960_120p_4x3 = 12,

/// Resolution is 1280x960 60P 4:3.
  VideoResolutionv_1280x960_60P_4x3 = 13,

/// Resolution is 1280x720 240P 16:9.
  VideoResolutionv_1280x720_240p_16x9 = 14,

/// Resolution is 1280x720 120P 16:9 super.
  VideoResolutionv_1280x720_120p_16x9_super = 15,

/// Resolution is 1280x720 60P 16:9 super.
  VideoResolutionv_1280x720_60p_16x9_super = 16,

/// Resolution is 840x480 240P 16:9.
  VideoResolutionv_840x480_120p_16x9 = 17,
};


/// Video standard supported by YICamera.
typedef SWIFT_ENUM(NSInteger, VideoStandard) {

/// Unknown
  VideoStandardUnknown = 0,

/// PAL standard
  VideoStandardPAL = 1,

/// NTSC standard
  VideoStandardNTSC = 2,
};


/// White balance supported by YI action camera.
typedef SWIFT_ENUM(NSInteger, WhiteBalance) {

/// Unknown
  WhiteBalanceUnknown = 0,

/// Auto
  WhiteBalancewb_Auto = 1,

/// Native
  WhiteBalancewb_Native = 2,

/// 3000k
  WhiteBalancewb_3000k = 3,

/// 5500k
  WhiteBalancewb_5500k = 4,

/// 6500k
  WhiteBalancewb_6500k = 5,
};

#pragma clang diagnostic pop
