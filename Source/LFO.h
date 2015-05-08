/*
  ==============================================================================

    LFO.h
    Created: 8 May 2015 3:21:13am
    Author:  mobilestudio

  ==============================================================================
*/

#ifndef LFO_H_INCLUDED
#define LFO_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
//
//   LFO Class
//
//==============================================================================

class LFO
{
public:
    
    LFO (double sampleRate, int blockSize);
    ~LFO ();

    void setFreq (float freq);

private:

  double _sampleRate;
  int _blockSize;
  float _freq;

};

#endif  // LFO_H_INCLUDED
