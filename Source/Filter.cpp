/*
  ==============================================================================

    Filter.cpp
    Created: 7 May 2015 8:57:23pm
    Author:  mobilestudio

  ==============================================================================
*/

#include "Filter.h"

//==============================================================================
//
//   Filter Class
//
//==============================================================================

Filter::Filter (double sampleRate, int blockSize)
{
  _sampleRate = sampleRate;
  _blockSize = blockSize;

  _outputBuffer = NULL;
  _outputBuffer = new AudioSampleBuffer (1, _blockSize);
}

Filter::~Filter ()
{
  delete _outputBuffer;
}

void Filter::calc_k (float f, float k)  //==============
{                                       //    Source:
  if (k > 4.) k = 4.;                   //    moog~.c
  if (k < 0.) k = 0.;                   //  
  if (f <= 3800) _k = k;                // f = frequency 
  else _k = k - 0.5*((f-3800)/4300);    // k = resonance 
}                                       //

AudioSampleBuffer* Filter::lowpass (AudioSampleBuffer& inputBuffer)
{
  _outputBuffer = &inputBuffer;
  return _outputBuffer;
}

AudioSampleBuffer* Filter::highpass (AudioSampleBuffer& inputBuffer)
{
  _outputBuffer = &inputBuffer;
  return _outputBuffer;
}

AudioSampleBuffer* Filter::bandpass (AudioSampleBuffer& inputBuffer)
{
  _outputBuffer = &inputBuffer;
  return _outputBuffer;
}