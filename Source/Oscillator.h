/*
  ==============================================================================

    Oscillator.h
    Created: 7 May 2015 8:59:13pm
    Author:  mobilestudio

  ==============================================================================
*/

#ifndef OSCILLATOR_H_INCLUDED
#define OSCILLATOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
//
//   Oscillator Class
//
//==============================================================================

class Oscillator
{
 public:
  
  Oscillator (double sampleRate, int blockSize);
  ~Oscillator ();
  
  void setFreq (float freq);
  float getFreq (void);
  void calcIncrement (void);
  void setPhase (float phase);
  float getPhase (void);
  AudioSampleBuffer* processBlock ();
  
 private:
  
  double _sampleRate;
  int _blockSize;
  float _phase;
  float _freq;
  float _increment;
  bool _recalcInc = true;
  
  // Buffer Pointer
  AudioSampleBuffer *_outputBuffer;
  
};

#endif  // OSCILLATOR_H_INCLUDED
