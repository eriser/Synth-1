/*
  ==============================================================================

    Noise.h
    Created: 7 May 2015 8:53:54pm
    Author:  mobilestudio

  ==============================================================================
*/

#ifndef NOISE_H_INCLUDED
#define NOISE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
//
//   Noise Class
//
//==============================================================================

class Noise
{
public:

  Noise (double sampleRate, int blockSize);
  ~Noise ();

  AudioSampleBuffer* processBlock (void);
  
private:

  double _sampleRate;
  int _blockSize;

  // Buffer Pointer
  AudioSampleBuffer *_outputBuffer;
  
};

#endif  // NOISE_H_INCLUDED
