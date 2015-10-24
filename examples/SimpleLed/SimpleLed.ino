///////////////////////////////////////////////////////////////////////////////////////////
//
// ALA library example: SimpleLed
//
// A very simple example about how to fade one LED.
//
// Web page: http://yaab-arduino.blogspot.com/p/ala-example-simpleled.html
//
///////////////////////////////////////////////////////////////////////////////////////////

#include <AlaLed.h>

AlaLed alaLed;

void setup()
{
  // initialize the led attached to pin 11 with PWM driver
  alaLed.initPWM(11);
  
  // set a fading animation with a duration of 2 seconds
  alaLed.setAnimation(ALA_FADEIN, 2000);
}

void loop()
{
  // run the animation
  alaLed.runAnimation();
}

