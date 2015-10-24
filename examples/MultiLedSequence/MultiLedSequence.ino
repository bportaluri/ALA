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

// pins where the leds are connected
byte pins[] = { 5, 6, 9, 10, 11 };

// declare the animation sequence
// each row has three values:
// 1 - a numeric code identifying the desired animation, valid codes are listed in the Ala.h
// 2 - the duration of the loop animationin milliseconds
// 3 - the total duration of the animation in milliseconds

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
  // initialize the 5 leds attached to PWM pins
  leds.initPWM(5, pins);

  // set the animation sequence
  leds.setAnimation(seq);
}

void loop()
{
  // run the animation
  leds.runAnimation();
}
