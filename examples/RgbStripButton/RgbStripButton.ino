///////////////////////////////////////////////////////////////////////////////////////////
//
// ALA library example: RgbStripButton
//
// Example to demonstrate how to switch animations using three buttons.
// The first button change the animation.
// The second button the color palette.
// The third button change the animation speed.
//
// Button library is required: http://playground.arduino.cc/Code/Button
//
// Web page: http://yaab-arduino.blogspot.com/p/ala-example-rgbstripbutton.html
//
///////////////////////////////////////////////////////////////////////////////////////////

#include <AlaLedRgb.h>
#include <Button.h>


AlaLedRgb rgbStrip;
Button button1 = Button(2, PULLDOWN);
Button button2 = Button(3, PULLDOWN);
Button button3 = Button(4, PULLDOWN);

int animation = 0;
int duration = 0;
int palette = 0;

int animList[14] = {
    ALA_ON,
    ALA_SPARKLE,
    ALA_SPARKLE2,
    ALA_PIXELSHIFTRIGHT,
    ALA_PIXELSMOOTHSHIFTRIGHT,
    ALA_MOVINGBARS,
    ALA_COMET,
    ALA_COMETCOL,
    ALA_GLOW,
    ALA_CYCLECOLORS,
    ALA_FADECOLORS,
    ALA_FIRE,
    ALA_BOUNCINGBALLS,
    ALA_BUBBLES
};

AlaPalette paletteList[3] = {
    alaPalRgb,
    alaPalRainbow,
    alaPalFire
};

int durationList[3] = {
    1000,
    2000,
    5000
};


void setup()
{
  delay(4000);
  
  rgbStrip.initWS2812(60, 6);

  updateAnimation();
}

void loop()
{
  // button 1 changes the animation
  if (button1.uniquePress())
  {
    animation++;
    updateAnimation();
  }
  
  // button 2 changes the color palette
  if (button2.uniquePress())
  {
    palette++;
    updateAnimation();
  }
  
  // button 3 changes the animation speed
  if (button3.uniquePress())
  {
    duration++;
    updateAnimation();
  }
  
  rgbStrip.runAnimation();

}

void updateAnimation()
{
    rgbStrip.setAnimation(animList[animation%14], durationList[duration%3], paletteList[palette%3]);
}

