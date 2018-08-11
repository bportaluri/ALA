#ifndef AlaLedRgb_h
#define AlaLedRgb_h

#include "Ala.h"

#include "ExtNeoPixel.h"

/**
 *  AlaLedRgb can be used to drive a single or multiple RGB leds to perform animations.
 *  Available drivers are PWM pin, TLC5940, WS2811.
 */
class AlaLedRgb
{

public:

    AlaLedRgb();

    void initPWM(byte pinsRed, byte pinGreen, byte pinBlue);
    void initPWM(int numLeds, byte *pins);
    void initTLC5940(int numLeds, byte *pins);

    /**
    * Initializes WS2812 LEDs. It be invoked in the setup() function of the main Arduino sketch.
    *
    * The type field can be used to set the RGB order and chipset frequency. Constants are Adafruit_NeoPixel.h file.
    * It is set by default to NEO_GRB + NEO_KHZ800.
    */
    void initWS2812(int numLeds, byte pin, byte type=0x01+0x02);

    /**
    * Sets the maximum brightness level.
    */
    void setBrightness(AlaColor maxOut);

    /**
    * Sets the maximum refresh rate in Hz (default value is 50 Hz).
    * May be useful to reduce flickering in some cases.
    */
    void setRefreshRate(int refreshRate);

    int getCurrentRefreshRate();


    void setAnimation(int animation, long speed, AlaColor color);
    void setAnimation(int animation, long speed, AlaPalette palette);
    void setAnimation(AlaSeq animSeq[]);
    int getAnimation();

    bool runAnimation();



private:

    void setAnimationFunc(int animation);
    void on();
    void off();
    void blink();
    void blinkAlt();
    void sparkle();
    void sparkle2();
    void strobo();
    void cycleColors();

    void pixelShiftRight();
    void pixelShiftLeft();
    void pixelBounce();
    void pixelSmoothShiftRight();
    void pixelSmoothShiftLeft();
    void comet();
    void cometCol();
    void pixelSmoothBounce();
    void larsonScanner();
    void larsonScanner2();

    void fadeIn();
    void fadeOut();
    void fadeInOut();
    void glow();
    void plasma();
    void fadeColors();
    void pixelsFadeColors();
    void fadeColorsLoop();

    void movingBars();
    void movingGradient();

    void fire();
    void bouncingBalls();
    void bubbles();


    byte driver;    // type of led driver: ALA_PWM, ALA_TLC5940
    byte *pins;     // pins where the leds are attached to
    AlaColor *leds; // array to store leds brightness values
    int numLeds;    // number of leds

    int animation;
    long speed;
    AlaPalette palette;
    AlaSeq *animSeq;
    int animSeqLen;
    long animSeqDuration;

    void (AlaLedRgb::*animFunc)();
    AlaColor maxOut;
    int refreshMillis;
    int refreshRate;   // current refresh rate
    unsigned long animStartTime;
    unsigned long animSeqStartTime;
    unsigned long lastRefreshTime;

    float *pxPos;
    float *pxSpeed;

    Adafruit_NeoPixel *neopixels;

};


#endif