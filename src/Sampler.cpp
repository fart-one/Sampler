/*
 * Sampler, library or increasing sensor measuremets quality
 * Created by nouc <nouc23@gmail.com>
 */

#include "Arduino.h"
#include "Sampler.h"

Sampler::Sampler()
{
  _bufferSize     = 40;
  _bufferIterator = -1;
  _bufferFilled   = false;

  _buffer = new float[_bufferSize];
}

Sampler::Sampler(int bufferSize)
{
  _bufferSize     = bufferSize;
  _bufferIterator = -1;
  _bufferFilled   = false;

  _buffer = new float[_bufferSize];
}

Sampler::Sampler(int bufferSize, float min, float max)
{
  _bufferSize     = bufferSize;
  _bufferIterator = -1;
  _bufferFilled   = false;

  _min            = min;
  _max            = max;

  _buffer = new float[_bufferSize];
}

Sampler::~Sampler()
{
  delete[] _buffer;
}

bool Sampler::addSample(float sample)
{

  bool filtered = false;

  // check min range
  if (_min > 0.0 && sample <= _min) {
    sample = _min;
    filtered = true;
  }

  // check max range
  if (_max > 0.0 && sample >= _max) {
    sample = _max;
    filtered = true;
  }

  // calculate next buffer index
  _bufferIterator = (_bufferIterator + 1) % _bufferSize;

  // add to buffer
  _buffer[_bufferIterator] = sample;

  // check buffer filled flag
  if (!_bufferFilled &&  _bufferIterator == (_bufferSize - 1)) {
    _bufferFilled = true;
  }

  return filtered;

}

float Sampler::getMeasurement()
{
  float* sortedBuffer;
  float calculatedValue;

  // check buffer filled
  if (!_bufferFilled) {
    return 0.0;
  }

  sortedBuffer = new float[_bufferSize];

  // copy values
  for (int i = 0; i < _bufferSize; i++) {
    sortedBuffer[i] = _buffer[i];
  }

  _sort(sortedBuffer, _bufferSize);


  if (_bufferSize % 2 == 0)
    calculatedValue = (sortedBuffer[_bufferSize / 2] + sortedBuffer[_bufferSize / 2 - 1]) / 2.0;
  else
    calculatedValue = sortedBuffer[_bufferSize / 2];

  delete[] sortedBuffer;

  return calculatedValue;
}

void Sampler::_sort(float array[], int size)
{
  for(int i=0; i<(size-1); i++) {
    for(int o=0; o<(size-(i+1)); o++) {
      if(array[o] > array[o+1]) {
        float t = array[o];
        array[o] = array[o+1];
        array[o+1] = t;
      }
    }
  }
}

Sampler &Sampler::setBufferSize(int bufferSize)
{
  delete[] _buffer;

  _bufferSize     = bufferSize;
  _bufferIterator = -1;
  _bufferFilled   = false;

  _buffer = new float[_bufferSize];

  return *this;
}

Sampler &Sampler::setMin(float min)
{
  _min = min;
  return *this;
}

Sampler &Sampler::setMax(float max)
{
  _max = max;
  return *this;
}

int Sampler::getBufferSize()
{
  return _bufferSize;
}

float Sampler::getMin()
{
  return _min;
}

float Sampler::getMax()
{
  return _max;
}
