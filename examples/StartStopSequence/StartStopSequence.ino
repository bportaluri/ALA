///////////////////////////////////////////////////////////////////////////////////////////
//
// ALA library example: StartStopSequence
//
// Example to demonstrate how to play an animation sequence, stop it, do something else
// start a new sequence and so on.
//
///////////////////////////////////////////////////////////////////////////////////////////

#include <AlaLedRgb.h>

AlaLedRgb rgbStrip;

int animPhase = 0;

// define the sequences to use

AlaSeq seq1[] =
{
  { ALA_ON,             2000, 2000, alaPalRgb },
  { ALA_SPARKLE,        2000, 2000, alaPalRgb },
  { ALA_CYCLECOLORS,    2000, 2000, alaPalRgb },
  { ALA_STOPSEQ,        1000, 1000, alaPalNull },
  { ALA_ENDSEQ }
};

AlaSeq seq2[]=
{
  { ALA_FADECOLORSLOOP, 3000, 4000, alaPalRgb },
  { ALA_COMETCOL,       3000, 4000, alaPalRgb },
  { ALA_SPARKLE2,       1000, 4000, alaPalRgb },
  { ALA_STOPSEQ,        1000, 1000, alaPalNull },
  { ALA_ENDSEQ }
};

AlaSeq seq3[]=
{
  { ALA_GLOW,           3000, 4000, alaPalRgb },
  { ALA_OFF,            1000, 1000, alaPalNull },
  { ALA_BOUNCINGBALLS,  1000, 4000, alaPalRgb },
  { ALA_STOPSEQ,        1000, 1000, alaPalNull },
  { ALA_ENDSEQ }
};


void setup()
{
  Serial.begin(9600);
  delay(100); // some arduinos need it
  
  Serial.println("\nAnimation sequences starting\n");

  // 24 leds driven by pin 11
  rgbStrip.initWS2812(10, 6);
  rgbStrip.setBrightness(0x444444);

  rgbStrip.setAnimation(seq1);
  animPhase = 1;
}

void loop()
{
  rgbStrip.runAnimation();

  if(animPhase==1 && rgbStrip.getAnimation()==ALA_STOPSEQ)
  {
    Serial.println("\nSequence 1 completed");
    // do something here
    for(int i=0;i<30;i++)
    {
      Serial.print("1");
      delay(100);
    }
    rgbStrip.setAnimation(seq2);
    animPhase = 2;
  }
  if(animPhase==2 && rgbStrip.getAnimation()==ALA_STOPSEQ)
  {
    Serial.println("\nSequence 2 completed");
    for(int i=0;i<30;i++)
    {
      Serial.print("2");
      delay(100);
    }
    rgbStrip.setAnimation(seq3);
    animPhase = 3;
  }
  if(animPhase==3 && rgbStrip.getAnimation()==ALA_STOPSEQ)
  {
    Serial.println("\nSequence 3 completed");
    animPhase = 4;
  }
}
