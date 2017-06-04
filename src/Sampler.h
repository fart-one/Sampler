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
    Sampler();
    Sampler(int bufferSize);
    Sampler(int bufferSize, float min, float max);
    ~Sampler();
    bool addSample(float sample);
    float getMeasurement();
    Sampler &setBufferSize(int bufferSize);
    Sampler &setMin(float min);
    Sampler &setMax(float max);
    int getBufferSize();
    float getMin();
    float getMax();
  private:
    int _bufferSize;
    int _bufferIterator;
    float* _buffer;
    bool _bufferFilled;
    float _min;
    float _max;
    void _sort(float array[], int size);
};

#endif