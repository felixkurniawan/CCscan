//
//  NetswipeCardInformation.h
//  NetswipeScanSDK
//
//  Created by Jumio Inc. on 30/04/2012.
//  Copyright (c) 2012 Jumio Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 @class NetswipeCardInformation
 @brief Contains card details returned by a Netswipe Scan.
 */
@interface NetswipeCardInformation : NSObject {}

@property (nonatomic, readonly) NSString *cardNumber;		// The card number in the format 1234567812345678
@property (nonatomic, readonly) NSString *cardNumberGrouped; // The card number in grouped style (e.g. 1234 5678 1234 5678)

@property (nonatomic, readonly) NSString *expiryDate; 		// The expiry date of the card in the format mm/yy (e.g. 01/12)

@property (nonatomic, readonly) NSString *cvvCode;			// The CVV code of the card

@end
