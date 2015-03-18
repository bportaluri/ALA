///////////////////////////////////////////////////////////////////////////////////////////
//
// ALA library example: ALA Example - ComplexMultitasking
//
// Example to demonstrate how to drive different set of LEDs independently
// using Arduino PWM output pins a TLC5940 chip and an WS2812 strip.
//
// Web page: http://yaab-arduino.blogspot.com/p/ala-example-multianimations.html
//
///////////////////////////////////////////////////////////////////////////////////////////

#include "AlaLed.h"
#include "AlaLedRgb.h"

byte tlcPins1[] = { 1, 2, 3 };
byte tlcPins2[] = { 6,7,8, 9,10,11, 12,13,14 };

AlaLed led1;
AlaLed led2;
AlaLed someLeds;
AlaLedRgb rgbLeds;
AlaLedRgb rgbStrip;


void setup()
{
  led1.initPWM(5);
  led2.initPWM(6);
  someLeds.initTLC5940(3, tlcPins1);
  rgbLeds.initTLC5940(3, tlcPins2);
  rgbStrip.initWS2812(8, 2);

  led1.setAnimation(ALA_STROBO, 1000);
  led2.setAnimation(ALA_GLOW, 5000);
  someLeds.setAnimation(ALA_PIXELSMOOTHSHIFTLEFT, 2400);
  rgbLeds.setAnimation(ALA_FADECOLORSLOOP, 12000, alaPalRgb);
  rgbStrip.setAnimation(ALA_COMETCOL, 5000, alaPalRgb);
}

void loop()
{
  led1.runAnimation();
  led2.runAnimation();
  someLeds.runAnimation();
  rgbLeds.runAnimation();
  rgbStrip.runAnimation();
}
