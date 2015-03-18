///////////////////////////////////////////////////////////////////////////////////////////
//
// ALA library example: RgbLedSequence
//
// Example to demonstrate how to create an animation sequence for one RGB LED.
// The example also shows how to create and use a custom color palette.
//
// Web page: http://yaab-arduino.blogspot.com/p/ala-example-rgbledsequence.html
//
///////////////////////////////////////////////////////////////////////////////////////////

#include "AlaLedRgb.h"

#define REDPIN 11
#define GREENPIN 9
#define BLUEPIN 10

AlaLedRgb rgbLed;

// custom palette :     black   , white   , black   , red     , green   , blue
AlaColor mycolors_[6] = { 0x000000, 0xFFFFFF, 0x000000, 0xFF0000, 0x00FF00, 0x0000FF };
AlaPalette mycolors = { 6, colors_ };


AlaSeq seq[] =
{
  { ALA_CYCLECOLORS, 3000, 3000, alaPalRgb },
  { ALA_OFF, 1000, 1000, NULL },
  { ALA_FADECOLORSLOOP, 4000, 8000, alaPalRgb },
  { ALA_FADECOLORSLOOP, 500, 4000, mycolors },
  { ALA_OFF, 1000, 1000, NULL },
  { ALA_FADECOLORS, 5000, 5000, mycolors },
  { ALA_OFF, 1000, 1000, NULL },
  { ALA_ENDSEQ, 0, 0, NULL }
};


void setup()
{
  rgbLed.initPWM(REDPIN, GREENPIN, BLUEPIN);
  rgbLed.setBrightness(0x33FF22);
  rgbLed.setAnimation(seq);
}

void loop()
{
  rgbLed.runAnimation();
}
