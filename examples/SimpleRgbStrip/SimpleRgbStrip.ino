///////////////////////////////////////////////////////////////////////////////////////////
//
// ALA library example: RgbStrip
//
// Example to demonstrate how to create display a color-fading animation for a
// WS2812 RGB LED strip.
//
// Web page: http://yaab-arduino.blogspot.com/p/ala-example-rgbstrip.html
//
///////////////////////////////////////////////////////////////////////////////////////////

#include "AlaLedRgb.h"

AlaLedRgb rgbStrip;

void setup()
{
  rgbStrip.initWS2812(30, 6);
  
  rgbStrip.setAnimation(ALA_FADECOLORSLOOP, 5000, alaPalRgb);
}

void loop()
{
  rgbStrip.runAnimation();
}
