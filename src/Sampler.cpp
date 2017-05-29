/*
 * Sampler, library or increasing sensor measuremets quality
 * Created by nouc <nouc23@gmail.com>
 */

#include "Arduino.h"
#include "Sampler.h"

Sampler::Sampler(int bufferSize)
{
  _bufferSize = bufferSize;
}

void Sampler::addSample()
{
 Serial.println("addSample");
}

void Sampler::getMeasurement()
{
  return 123.23;
}

