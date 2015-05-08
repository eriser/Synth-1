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

#define PI 3.14159265

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
  String getFreq (void);
  float getFreqRaw (void);

  void setPhase (float phase);
  float getPhase (void);
  
  void setGain (float gain);
  String getGain (void);

  void setShape (int shape);
  String getShape (void);

  void setPW (float width);
  String getPW (void);

  float calcIncrement (float freq);

  void phasor (float freq);

  float waveshaper (float signal);

  AudioSampleBuffer* processBlock (void);
  
 private:
  
  double _sampleRate;
  int _blockSize;
  float _phase;
  float _freq;
  float _increment;
  float _gain;
  int _waveshape = 1;
  float _pwmThreshold = 0.5;
  
  // Buffer Pointer
  AudioSampleBuffer *_outputBuffer;
  
};

#endif  // OSCILLATOR_H_INCLUDED
