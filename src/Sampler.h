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
    Sampler(int bufferSize, int min, int max);
    bool addSample(int sample);
    float getMeasurement();
  private:
    int _bufferSize;
    int _min;
    int _max;

    int _bufferIterator;
    int _buffer[];
};

#endif