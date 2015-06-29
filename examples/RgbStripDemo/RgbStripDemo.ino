///////////////////////////////////////////////////////////////////////////////////////////
//
// ALA library example: RgbStripDemo
//
// Example to demonstrate how to create an animation sequence for a
// WS2812 RGB LED strip.
//
// Web page: http://yaab-arduino.blogspot.com/p/ala-example-rgbstripdemo.html
//
///////////////////////////////////////////////////////////////////////////////////////////

#include "AlaLedRgb.h"

AlaLedRgb rgbStrip;


AlaSeq seq[] =
{
  { ALA_OFF, 1000, alaPalNull, 2000 },
  { ALA_ON, 1000, alaPalRgb, 2000 },
  { ALA_SPARKLE, 1000, alaPalRgb, 9000 },
  { ALA_CYCLECOLORS, 3000, alaPalRgb, 6000 },
  { ALA_OFF, 1000, alaPalNull, 1000 },
  { ALA_FADECOLORSLOOP, 3000, alaPalRgb, 6000 },
  { ALA_SPARKLE2, 1000, alaPalRgb, 6000 },
  { ALA_OFF, 1000, alaPalNull, 1000 },
  { ALA_SPARKLE2, 1000, alaPalFire, 6000 },
  { ALA_PIXELSMOOTHSHIFTRIGHT, 2000, alaPalRgb, 6000 },
  { ALA_OFF, 1000, alaPalNull, 1000 },
  { ALA_MOVINGBARS, 3000, alaPalRgb, 6000 },
  { ALA_COMET, 3000, alaPalRgb, 6000 },
  { ALA_COMETCOL, 3000, alaPalRgb, 6000 },
  { ALA_OFF, 1000, alaPalNull, 1000 },
  { ALA_GLOW, 3000, alaPalRgb, 6000 },
  { ALA_OFF, 1000, alaPalNull, 1000 },
  { ALA_FIRE, 1000, alaPalFire, 6000 },
  { ALA_OFF, 1000, alaPalNull, 1000 },
  { ALA_BOUNCINGBALLS, 1000, alaPalRgb, 6000 },
  { ALA_OFF, 1000, alaPalNull, 1000 },
  { ALA_BUBBLES, 1000, alaPalRainbow, 6000 },
  { ALA_ENDSEQ, 0, NULL, 0 }
};
/*
AlaPalette paletteList[3] = {
    alaPalRgb,
    alaPalRainbow,
    alaPalFire
};
*/
void setup()
{
  delay(1000);
  
  rgbStrip.initWS2812(60, 6);
  
  rgbStrip.setBrightness(0x444444);

  rgbStrip.setAnimation(seq);
}

void loop()
{
  rgbStrip.runAnimation();
}

