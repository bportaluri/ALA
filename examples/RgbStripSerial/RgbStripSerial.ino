///////////////////////////////////////////////////////////////////////////////////////////
//
// ALA library example: RgbStripSerial
//
// Example to demonstrate how to control WS2812 RGB LED strip lighting and animations
// sending AT commands through the serial port.
//
// Web page: http://yaab-arduino.blogspot.com/p/ala-example-rgbstripserial.html
//
///////////////////////////////////////////////////////////////////////////////////////////

#include <AlaLedRgb.h>
#include <stdlib.h>

#define WS2811_PIN 6    // WS2811 control connected to pin 6
#define NUM_PIXELS 10   // number of leds in the LED strip
#define CMDBUFSIZE 16   // buffer size for receiving serial commands

AlaLedRgb rgbStrip;
char cmdBuffer[CMDBUFSIZE];

// global settings and initial values
int animation = ALA_OFF;
AlaColor color = 0xdddddd;
AlaPalette palette = alaPalNull;
int paletteId=0;
float brightness = 0.4;
long duration = 1000;


void setup()
{
  rgbStrip.initWS2812(NUM_PIXELS, WS2811_PIN);
  rgbStrip.setBrightness(color.scale(brightness));
  rgbStrip.setAnimation(animation, duration, color);
  
  Serial.begin(9600);

  Serial.println("Welcome to ALA RgbStripSerial example");
  Serial.println("A=[animation code] Set the animation. See https://github.com/bportaluri/ALA/blob/master/src/AlaLed.h");
  Serial.println("B=[brightness]     Set the brightness [0-100]");
  Serial.println("D=[duration]       Set the duration in milliseconds of the animation cycle");
  Serial.println("C=[color]          Set the color (hexadecimal RGB representation ex. 0xE8A240)");
  Serial.println("P=[palette]        Set the palette.");
}

void loop()
{

  if (Serial.available())
  {
    int charsRead;
    charsRead = Serial.readBytesUntil('\n', cmdBuffer, sizeof(cmdBuffer) - 1);  //read entire line
    cmdBuffer[charsRead] = '\0';       // Make it a C string
    Serial.print(">"); Serial.println(cmdBuffer);
    
    if(cmdBuffer[1] != '=' || strlen(cmdBuffer)<3)
    {
      Serial.println("KO");
    }
    else
    {
      switch(toupper(cmdBuffer[0]))
      {
      case 'A':
        animation = atoi(&cmdBuffer[2]);
        Serial.println("OK");
        break;
      case 'B':
        brightness = atoi(&cmdBuffer[2]);
        rgbStrip.setBrightness(color.scale((float)brightness / 100));
        Serial.println("OK");
        break;
      case 'C':
        color = strtol(&cmdBuffer[2], 0, 16);
        palette=alaPalNull;
        Serial.println("OK");
        break;
      case 'D':
        duration = atol(&cmdBuffer[2]);
        Serial.println("OK");
        break;
      case 'P':
        paletteId = atoi(&cmdBuffer[2]);
        switch(paletteId)
        {
        case 0:
          palette=alaPalNull;
          break;
        case 1:
          palette=alaPalRgb;
          break;
        case 2:
          palette=alaPalRainbow;
          break;
        case 3:
          palette=alaPalParty;
          break;
        case 4:
          palette=alaPalHeat;
          break;
        case 5:
          palette=alaPalFire;
          break;
        }
        break;
      
      default:
        Serial.println("KO");
      }
      
      if(palette==alaPalNull)
        rgbStrip.setAnimation(animation, duration, color);
      else
        rgbStrip.setAnimation(animation, duration, palette);
    }
  }

  rgbStrip.runAnimation();
}


