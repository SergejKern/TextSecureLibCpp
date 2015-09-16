/* 
  Port of UIColor+OWS.h from Signal-iOS 

//  UIColor+UIColor_OWS.h
//  Signal
//
//  Created by Dylan Bourgeois on 25/11/14.
//  Copyright (c) 2014 Open Whisper Systems. All rights reserved.

  */

#ifndef UICOLOROWS_H_
#define UICOLOROWS_H_

// ??? #import <UIKit/UIKit.h>

//@interface UIColor (OWS)
class UIColor /* or may be struct? */
{
//+ (UIColor*) ows_materialBlueColor;
  static UIColor* OwsMaterialBlueColor;

//+ (UIColor *) ows_fadedBlueColor;
  static UIColor* OwsFadedBlueColor;

//+ (UIColor *) ows_darkBackgroundColor;
  static UIColor* OwsDarkBackgroundColor;

//+ (UIColor *) ows_darkGrayColor;
  static UIColor* OwsDarkGrayColor;

//+ (UIColor *) ows_yellowColor;
  static UIColor* OwsYellowColor;

//+ (UIColor *) ows_greenColor;
  static UIColor* OwsGreenColor;

//+ (UIColor *) ows_redColor;
  static UIColor* OwsRedColor;

//+ (UIColor*) ows_blackColor;
  static UIColor* OwsBlackColor;

//+ (UIColor*) backgroundColorForContact:(NSString*)contactIdentifier;
  static UIColor* GetBackgroundColorForContact(NSString* contactIdentifier);
}


#endif // UICOLOROWS_H_
