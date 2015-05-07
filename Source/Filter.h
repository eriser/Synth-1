/*
  ==============================================================================

    Filter.h
    Created: 7 May 2015 8:57:23pm
    Author:  mobilestudio

  ==============================================================================
*/

#ifndef FILTER_H_INCLUDED
#define FILTER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
//
//   Filter Class
//
//==============================================================================

class Filter
{
public:
  
  Filter (double sampleRate, int blockSize);
  ~Filter ();

  void calc_k (float f, float k);
  AudioSampleBuffer* lowpass (AudioSampleBuffer& inputBuffer);
  AudioSampleBuffer* highpass (AudioSampleBuffer& inputBuffer);
  AudioSampleBuffer* bandpass (AudioSampleBuffer& inputBuffer);
  
private:
  
  double _sampleRate;
  int _blockSize;
  float _k;

  // Buffer Pointer
  AudioSampleBuffer *_outputBuffer;
  
};

#endif  // FILTER_H_INCLUDED
