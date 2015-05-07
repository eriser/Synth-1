/*
  ==============================================================================

    Noise.cpp
    Created: 7 May 2015 8:53:54pm
    Author:  mobilestudio

  ==============================================================================
*/

#include "Noise.h"

//==============================================================================
//
//   Noise Class
//
//==============================================================================

Noise::Noise (double sampleRate, int blockSize)
{
  _sampleRate = sampleRate;
  _blockSize = blockSize;

  _outputBuffer = NULL;
  _outputBuffer = new AudioSampleBuffer (1, _blockSize);
}

Noise::~Noise ()
{
  delete _outputBuffer;
}

AudioSampleBuffer* Noise::processBlock (void)
{
  for (int i = 0; i < _blockSize; i++)
    {
      float value = (rand()% 1000) / 1000;
      if (value < -1) value = -1;
      if (value >  1) value =  1;
      _outputBuffer->setSample (0, i, value);
    }
}