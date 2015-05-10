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
#endif

//==============================================================================
//
//   YAO Class
//
//==============================================================================

class YAO
{
 public:
  YAO ();
  YAO (double sampleRate, int blockSize);
  
  ~YAO ();
  
  AudioSampleBuffer* processBlock (void);
  AudioSampleBuffer* processBlock (AudioSampleBuffer& inputBuffer); 

  void updateFrequency (void);
  void updateFrequency (float _freq);
  void updateIncrement (void);
  
 private:
  double pvt_sampleRate;
  int pvt_blockSize;

  float pvt_Frequency = 110;
  
  float pvt_Increment = 0;
  float pvt_Phase = 0;
    
  AudioSampleBuffer *outputBuffer;
  void initOutputBuffer (void);
  void zeroOutputBuffer (void);
};
