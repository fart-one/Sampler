/*
 * Sampler, library or increasing sensor measuremets quality
 * Created by nouc <nouc23@gmail.com>
 */

#include "Arduino.h"
#include "Sampler.h"

Sampler::Sampler(int bufferSize)
{
  _bufferSize     = bufferSize;
  _bufferIterator = -1;
}

Sampler::Sampler(int bufferSize, int min, int max)
{
  _bufferSize     = bufferSize;
  _min            = min;
  _max            = max;
  _bufferIterator = -1;
}

bool Sampler::addSample(int sample)
{

  // check min range
  if (_min > 0 && sample <= _min) {
    return false;
  }


  // check max range
  if (_max > 0 && sample >= _max) {
    return false;
  }

  // calculate next buffer index
  _bufferIterator = (_bufferIterator + 1) % _bufferSize;

  // add to buffer
  _buffer[_bufferIterator] = sample;

  return true;

}

float Sampler::getMeasurement()
{
  return 123.23;
}

