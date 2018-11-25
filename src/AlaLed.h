#ifndef AlaLed_h
#define AlaLed_h

#include "Ala.h"


/**
 *  AlaLed can be used to drive a single or multiple output channels to perform animations.
 *  Single leds can be attached to each channel or MOSFETS/relays can be used to drive
 *  heavier loads such as lamps or monochrome led strips.
 */
class AlaLed
{

public:

    AlaLed();


    /**
    * Initializes a LED driven by Arduino PWM pin. It be invoked in the setup() function of the main Arduino sketch.
    */
    void initPWM(byte pin);

    /**
    * Initializes LEDs driven by Arduino PWM pins. It be invoked in the setup() function of the main Arduino sketch.
    */
    void initPWM(int numLeds, byte *pins);

    /**
    * Initializes LEDs driven by a TLC5940 chip. It be invoked in the setup() function of the main Arduino sketch.
    * The TLC5940 must be wired as follows (http://XYXYXYXY)
    * pin  2 > GND
    * pin  3 > Arduino 11
    * pin  4 > Arduino 13
    * pin  5 > Arduino 9
    * pin  6 > Arduino 10 + XXX resistor to +5V
    * pin  7 > GND
    * pin  8 > +5V
    * pin  9 > xxx resistor to GND
    * pin 10 > +5V
    * pin 11 > Arduino 3
    *
    * It can be used also to drive a single led.
    */
    void initTLC5940(int numLeds, byte *pins);


    /**
    * Sets the maximum brightness level (0-255).
    */
    void setBrightness(byte maxOut);

    /**
    * Sets the maximum refresh rate in Hz (default value is 50 Hz).
    * May be useful to reduce flickering in some cases.
    */
    void setRefreshRate(int refreshRate);

    int getRefreshRate();

    void setAnimation(int animation, long speed, bool isSeq=false);
    void setAnimation(AlaSeq animSeq[]);
	void setSpeed(long speed);
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

    void pixelShiftRight();
    void pixelShiftLeft();
    void pixelBounce();
    void pixelSmoothShiftRight();
    void pixelSmoothShiftLeft();
    void pixelSmoothBounce();
    void comet();
    void barShiftRight();
    void barShiftLeft();
    void larsonScanner();
    void larsonScanner2();

    void fadeIn();
    void fadeOut();
    void fadeInOut();
    void glow();
    void flame();


    byte driver; // type of led driver: ALA_PWM, ALA_TLC5940
    byte *pins;  // pins where the leds are attached to
    byte *leds;  // array to store leds brightness values
    int numLeds; // number of leds

    int maxOut;
    int refreshMillis;
    int refreshRate;   // current refresh rate

    int animation;
    long speed;
    AlaSeq *animSeq;
    int animSeqLen;
    long animSeqDuration;

    void (AlaLed::*animFunc)();
    unsigned long animStartTime;
    unsigned long animSeqStartTime;
    unsigned long lastRefreshTime;

};

#endif