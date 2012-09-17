//
//  jumioViewController.h
//  LoginUB
//
//  Created by Felix Kurniawan on 9/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NetswipeScanSDK.h"


@interface jumioViewController : UIViewController <NetswipeScanSDKDelegate>
@property (nonatomic, retain) NetswipeScanSDK* scanSDK;



@end
