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

  void setCutoff (float cutoff);
  void setReso (float resonance);

  void calc_k (float f, float k);
  
  AudioSampleBuffer* lowpass (AudioSampleBuffer& inputBuffer);
  AudioSampleBuffer* highpass (AudioSampleBuffer& inputBuffer);
  AudioSampleBuffer* bandpass (AudioSampleBuffer& inputBuffer);

  AudioSampleBuffer* processBlock (AudioSampleBuffer& inputBuffer);
  
 private:
  
  double _sampleRate;
  int _blockSize;
  float _k;

  float x_1, x_2, x_3, x_4;
  float y_1, y_2, y_3, y_4;

  float _cutoff;
  float _resonance;

  // Buffer Pointer
  AudioSampleBuffer *_outputBuffer;
  
};

#endif  // FILTER_H_INCLUDED
