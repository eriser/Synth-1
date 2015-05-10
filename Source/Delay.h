/*
  ==============================================================================

  Delay.h
  Created: 7 May 2015 8:51:22pm
  Author:  mobilestudio

  ==============================================================================
*/

#ifndef DELAY_H_INCLUDED
#define DELAY_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
//
//   Delay Class
//
//==============================================================================

class Delay
{
 public:
  
  Delay (double sampleRate, int blockSize);
  ~Delay ();
  
 private:
  
  double _sampleRate;
  int _blockSize;

  // Buffer Pointer
  AudioSampleBuffer *_outputBuffer;
  
};

#endif  // DELAY_H_INCLUDED
