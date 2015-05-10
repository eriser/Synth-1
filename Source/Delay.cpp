/*
  ==============================================================================

  Delay.cpp
  Created: 7 May 2015 8:51:22pm
  Author:  mobilestudio

  ==============================================================================
*/

#include "Delay.h"

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
//
//   Delay Class
//
//==============================================================================

Delay::Delay (double sampleRate, int blockSize)
{
  _sampleRate = sampleRate;
  _blockSize = blockSize;

  _outputBuffer = NULL;
  _outputBuffer = new AudioSampleBuffer (1, _blockSize);

}

Delay::~Delay ()
{
  delete _outputBuffer;
}
