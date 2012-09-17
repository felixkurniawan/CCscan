//
//  jumioViewController.m
//  LoginUB
//
//  Created by Felix Kurniawan on 9/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "jumioViewController.h"
#import "NetswipeCardInformation.h"


@implementation jumioViewController
@synthesize scanSDK;


- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

/*
// Implement loadView to create a view hierarchy programmatically, without using a nib.
- (void)loadView
{
}
*/


// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad
{
    [super viewDidLoad];
    
    NSString *merchantApiToken = nil;
    merchantApiToken = @"merchantApiToken";
    
    NSString *merchantApiSecret = nil;
    merchantApiSecret =  @"merchantApiSecret";

    //self.scanSDK = [NetswipeScanSDK scanSDKWithMerchantApiToken: merchantApiToken apiSecret: merchantApiSecret delegate:self supportedCardTypes: NetswipeCreditCardTypeAll];

}

- (void)startScanSDK {
    [scanSDK presentNetswipeScanSDKFromViewController: self withLightOn:NO];
}

- (void) netswipeScanSDKDidCancel: (NetswipeScanSDK*) netswipeScanSDK {
    NSLog(@"NetswipeScanSDK did cancel");
    
    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"NetswipeScanSDK cancelled" message:@"" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alertView show];
}

- (void) netswipeScanSDK: (NetswipeScanSDK*) netswipeScanSDK didFinishScanWithCardInformation: (NetswipeCardInformation*) cardInformation manuallyEnteredCardNumber: (BOOL) manualEntry {
    
    NSString *netswipeScanSDKResult = [NSString stringWithFormat:@"Card Number: %@, expiry date: %@, CVV code: %@\nmanually entered = %@", cardInformation.cardNumber, cardInformation.expiryDate, cardInformation.cvvCode, manualEntry ? @"YES" : @"NO"];
    NSLog(@"NetswipeScanSDK did finish with result: %@", netswipeScanSDKResult);
    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"NetswipeScanSDK finished" message:netswipeScanSDKResult delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alertView show];
}


- (void)viewDidAppear:(BOOL)animated {
    //[self startScanSDK];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

@end
