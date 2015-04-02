#include "Ala.h"

#include "Arduino.h"


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




