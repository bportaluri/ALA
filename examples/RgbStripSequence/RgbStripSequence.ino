///////////////////////////////////////////////////////////////////////////////////////////
//
// ALA library example: RgbStripSequence
//
// Example to demonstrate how to create an animation sequence for a
// WS2812 RGB LED strip.
//
// Web page: http://yaab-arduino.blogspot.com/p/ala-example-rgbstripseq.html
//
///////////////////////////////////////////////////////////////////////////////////////////

#include <AlaLedRgb.h>

AlaLedRgb rgbStrip;


AlaSeq seq[] =
{
  { ALA_OFF,            1000, 2000, alaPalNull },
  { ALA_ON,             1000, 2000, alaPalRgb },
  { ALA_SPARKLE,        1000, 9000, alaPalRgb },
  { ALA_CYCLECOLORS,    3000, 6000, alaPalRgb },
  { ALA_OFF,            1000, 1000, alaPalNull },
  { ALA_FADECOLORSLOOP, 3000, 6000, alaPalRgb },
  { ALA_SPARKLE2,       1000, 6000, alaPalRgb },
  { ALA_OFF,            1000, 1000, alaPalNull },
  { ALA_SPARKLE2,       1000, 6000, alaPalFire },
  { ALA_PIXELSMOOTHSHIFTRIGHT, 6000, 2000, alaPalRgb },
  { ALA_OFF,            1000, 1000, alaPalNull },
  { ALA_MOVINGBARS,     3000, 6000, alaPalRgb },
  { ALA_COMET,          3000, 6000, alaPalRgb },
  { ALA_COMETCOL,       3000, 6000, alaPalRgb },
  { ALA_OFF,            1000, 1000, alaPalNull },
  { ALA_GLOW,           3000, 6000, alaPalRgb },
  { ALA_OFF,            1000, 1000, alaPalNull },
  { ALA_FIRE,           1000, 6000, alaPalFire },
  { ALA_OFF,            1000, 1000, alaPalNull },
  { ALA_BOUNCINGBALLS,  1000, 6000, alaPalRgb },
  { ALA_OFF,            1000, 1000, alaPalNull },
  { ALA_BUBBLES,        1000, 6000, alaPalRainbow },
  { ALA_ENDSEQ }
};


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

