///////////////////////////////////////////////////////////////////////////////////////////
//
// ALA library example: SimpleTlc5940
//
// Example to demonstrate how to animate few LEDs using a TLC5940 chip.
//
// Web page: http://yaab-arduino.blogspot.com/p/ala-example-tlc5940.html
//
///////////////////////////////////////////////////////////////////////////////////////////

#include <AlaLed.h>

AlaLed alaLed;

byte pins[] = { 4, 5, 6, 7, 8 };

void setup()
{
  alaLed.initTLC5940(5, pins);
  alaLed.setAnimation(ALA_GLOW, 2000);
}

void loop()
{
  alaLed.runAnimation();
}
