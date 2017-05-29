/*
 * Sampler, library or increasing sensor measuremets quality
 * Created by nouc <nouc23@gmail.com>
 */
 
#ifndef Sampler_h
#define Sampler_h

#include "Arduino.h"

class Sampler
{
  public:
    Sampler(int bufferSize);
    void addSample();
    float getMeasurement();
  private:
    int _bufferSize;
};

#endif