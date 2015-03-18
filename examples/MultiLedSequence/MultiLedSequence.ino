///////////////////////////////////////////////////////////////////////////////////////////
//
// ALA library example: MultiLedSequence
//
// Example to demonstrate the use of animation sequences.
//
// Web page: http://yaab-arduino.blogspot.com/p/ala-example-multiledseq.html
//
///////////////////////////////////////////////////////////////////////////////////////////

#include <AlaLed.h>

AlaLed leds;
byte pins[] = { 5, 6, 9, 10, 11 };

AlaSeq seq[] =
{
  { ALA_FADEIN, 1000, 1000 },
  { ALA_ON, 1000, 1000 },
  { ALA_FADEOUT, 1000, 1000 },
  { ALA_BARSHIFTRIGHT, 1000, 1000 },
  { ALA_BARSHIFTLEFT, 1000, 1000 },
  { ALA_OFF, 1000, 1000 },
  { ALA_PIXELSHIFTRIGHT, 700, 1400 },
  { ALA_PIXELSHIFTLEFT, 700, 1400 },
  { ALA_BLINKALT, 500, 3000 },
  { ALA_PIXELSMOOTHSHIFTRIGHT, 1000, 4000 },
  { ALA_PIXELSMOOTHSHIFTLEFT, 1000, 4000 },
  { ALA_FADEINOUT, 1000, 4000 },
  { ALA_COMET, 1000, 4000 },
  { ALA_GLOW, 1000, 4000 },
  { ALA_STROBO, 200, 4000 },
  { ALA_ENDSEQ, 0, 0 }
};


void setup()
{
  leds.initPWM(3, pins);
  leds.setAnimation(seq);
}

void loop()
{
  leds.runAnimation();
}
