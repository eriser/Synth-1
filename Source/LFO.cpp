/*
  ==============================================================================

    LFO.cpp
    Created: 8 May 2015 3:21:13am
    Author:  mobilestudio

  ==============================================================================
*/

#include "LFO.h"

//==============================================================================
//
//   LFO Class
//
//==============================================================================

LFO::LFO (double sampleRate, int blockSize)
{
  _sampleRate = sampleRate;
  _blockSize = blockSize;
}

LFO::~LFO ()
{
}

void LFO::setFreq (float freq)
{
  _freq = freq;
}
