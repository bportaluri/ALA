#include "Ala.h"


AlaColor alaPalNull_[] = { };
AlaPalette alaPalNull = { 0, alaPalNull_ };

// Red,Green,Blue sequence
AlaColor alaPalRgb_[] = { 0xFF0000, 0x00FF00, 0x0000FF };
AlaPalette alaPalRgb = { 3, alaPalRgb_ };

// Rainbow colors
AlaColor alaPalRainbow_[] =
{
    0xFF0000, 0xAB5500, 0xABAB00, 0x00FF00,
    0x00AB55, 0x0000FF, 0x5500AB, 0xAB0055
};
AlaPalette alaPalRainbow = { 8, alaPalRainbow_ };

// Rainbow colors with alternating stripes of black
AlaColor alaPalRainbowStripe_[] =
{
    0xFF0000, 0x000000, 0xAB5500, 0x000000, 0xABAB00, 0x000000, 0x00FF00, 0x000000,
    0x00AB55, 0x000000, 0x0000FF, 0x000000, 0x5500AB, 0x000000, 0xAB0055, 0x000000
};
AlaPalette alaPalRainbowStripe = { 16, alaPalRainbowStripe_ };


// Blue purple ping red orange yellow (and back)
// Basically, everything but the greens.
// This palette is good for lighting at a club or party.
AlaColor alaPalParty_[] =
{
    0x5500AB, 0x84007C, 0xB5004B, 0xE5001B,
    0xE81700, 0xB84700, 0xAB7700, 0xABAB00,
    0xAB5500, 0xDD2200, 0xF2000E, 0xC2003E,
    0x8F0071, 0x5F00A1, 0x2F00D0, 0x0007F9
};
AlaPalette alaPalParty = { 16, alaPalParty_ };


// Approximate "black body radiation" palette, akin to
// the FastLED 'HeatColor' function.
// Recommend that you use values 0-240 rather than
// the usual 0-255, as the last 15 colors will be
// 'wrapping around' from the hot end to the cold end,
// which looks wrong.
AlaColor alaPalHeat_[] =
{
    0x000000, 0xFF0000, 0xFFFF00, 0xFFFFCC
};
AlaPalette alaPalHeat = { 4, alaPalHeat_ };


AlaColor alaPalFire_[] =
{
    0x000000, 0x220000, 0x440000, 0x660000, 
    0x990000, 0xCC0000, 0xFF0000, 0xFF3300, 
    0xFF6600, 0xFF9900, 0xFFCC00, 0xFFFF00
};
AlaPalette alaPalFire = { 12, alaPalFire_ };




int getStep(long t0, long t, int v)
{
  return ((millis()-t0)%t)*v/t;
}

float getStepFloat(long t0, long t, float v)
{
  return ((millis()-t0)%t)*v/t;
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}




