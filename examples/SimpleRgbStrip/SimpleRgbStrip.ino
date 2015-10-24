///////////////////////////////////////////////////////////////////////////////////////////
//
// ALA library example: SimpleRgbStrip
//
// Example to demonstrate how to create display a color-fading animation for a
// WS2812 RGB LED strip.
//
// Web page: http://yaab-arduino.blogspot.com/p/ala-example-simplergbstrip.html
//
///////////////////////////////////////////////////////////////////////////////////////////

#include <AlaLedRgb.h>

AlaLedRgb rgbStrip;

void setup()
{
  // initialize the WS2812 strip with 30 leds on pin 6
  rgbStrip.initWS2812(30, 6);
  
  // set a color-fading animation with a duration of 5 seconds and an RGB palette
  rgbStrip.setAnimation(ALA_FADECOLORSLOOP, 5000, alaPalRgb);
}

void loop()
{
  // run the animation
  rgbStrip.runAnimation();
}

