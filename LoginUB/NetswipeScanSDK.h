//
//  NetswipeScanSDK.h
//  NetswipeScanSDK
//
//  Created by Jumio Inc. on 30.04.12.
//  Copyright (c) 2012 Jumio Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum {
    NetswipeCreditCardTypeAll               = 0,
    NetswipeCreditCardTypeVisa              = 1 << 0,
    NetswipeCreditCardTypeMasterCard        = 1 << 1,
    NetswipeCreditCardTypeAmericanExpress   = 1 << 2,
    NetswipeCreditCardTypeDiners            = 1 << 3,
    NetswipeCreditCardTypeDiscover          = 1 << 4,
} NetswipeCreditCardType;

typedef NSUInteger NetswipeCreditCardTypes;

@class NetswipeScanSDK, NetswipeCardInformation;

@protocol NetswipeScanSDKDelegate <NSObject>
- (void) netswipeScanSDKDidCancel: (NetswipeScanSDK*) netswipeScanSDK;
- (void) netswipeScanSDK: (NetswipeScanSDK*) netswipeScanSDK didFinishScanWithCardInformation: (NetswipeCardInformation*) cardInformation manuallyEnteredCardNumber: (BOOL) manualEntry;
@end

/**
 @class NetswipeScanSDK
 @brief Handle configuration and presentation of the Netswipe Scan SDK.
 */
@interface NetswipeScanSDK : NSObject

@property (nonatomic, assign) id<NetswipeScanSDKDelegate> delegate;

/** Creates an instance of the SDK.
 @param apiToken The API token of your Jumio merchant account
 @param apiSecret The corresponding API secret
 @param delegate A delegate implementing the NetswipeScanSDKDelegate protocol
 @param supportedCardTypes Specify which card types your App supports
 @return An initialized Netswipe Scan SDK instance */
+ (NetswipeScanSDK*) scanSDKWithMerchantApiToken: (NSString*) apiToken apiSecret: (NSString*) apiSecret delegate: (id<NetswipeScanSDKDelegate>) delegate supportedCardTypes: (NetswipeCreditCardTypes) cardTypes;

/** Present The Netswipe Scan SDK modally from your view controller.
 @param viewController Your view controller to present the SDK from
 @param lightOn YES to immediately turn on the camera's torch mode for better exposure
 */
- (void) presentNetswipeScanSDKFromViewController: (UIViewController*) viewController withLightOn:(BOOL)lightOn;

/** Dismiss the Netswipe Scan SDK from your view controller */
- (void) dismissNetswipeScanSDK;

/** Returns the release version of Netswipe Scan SDK */
- (NSString*) scanSDKVersion;

/** Customization */
- (void) setTintColorForNavigationBar: (UIColor*) tintColor;
- (void) setBackgroundImageForNavigationBar: (UIImage*) backgroundImage;

- (void) setSoundEffectFile: (NSString *) soundFileName;
- (void) setVibrationEffect: (BOOL) vibration;

@end
