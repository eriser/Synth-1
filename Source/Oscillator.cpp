/*
  ==============================================================================

  Oscillator.cpp
  Created: 7 May 2015 8:59:13pm
  Author:  mobilestudio

  ==============================================================================
*/

#include "Oscillator.h"

//==============================================================================
//
//   YAO Class
//
//==============================================================================

YAO::YAO ()
{
}

YAO::YAO (double sampleRate, int blockSize)
{
  pvt_sampleRate = sampleRate;
  pvt_blockSize = blockSize;

  initOutputBuffer ();
  zeroOutputBuffer ();
}
  
YAO::~YAO ()
{
}

void YAO::updateFrequency (float _freq)
{
  pvt_Frequency = _freq;
}

AudioSampleBuffer* YAO::processBlock (void)
{  
  for (int i = 0; i < pvt_blockSize; i++)
    {
      pvt_Phase = pvt_Phase + pvt_Increment;
      outputBuffer->setSample (0, i, pvt_Phase);
    }
  
  return outputBuffer;
}

AudioSampleBuffer* YAO::processBlock (AudioSampleBuffer& inputBuffer)
{
  for (int i = 0; i < pvt_blockSize; i++)
    {
      pvt_Phase = pvt_Phase + pvt_Increment;
      outputBuffer->setSample (0, i, pvt_Phase);
    }
  
  return outputBuffer;
}

void YAO::updateIncrement (void)
{
  float temp_f_IncrementCount = pvt_Frequency / pvt_sampleRate;

  pvt_Increment = 1 / temp_f_IncrementCount;
}

void YAO::initOutputBuffer (void)
{
  outputBuffer = new AudioSampleBuffer (1, pvt_blockSize);
}

void YAO::zeroOutputBuffer (void)
{
  for (int i = 0; i < pvt_blockSize; i++) outputBuffer->setSample (0, i, 0);
}
