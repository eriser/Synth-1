/*
  ==============================================================================

    Oscillator.cpp
    Created: 7 May 2015 8:59:13pm
    Author:  mobilestudio

  ==============================================================================
*/

#include "Oscillator.h"

//==============================================================================
//
//   Oscillator Class
//
//==============================================================================

Oscillator::Oscillator (double sampleRate, int blockSize)
{
  _sampleRate = sampleRate;
  _blockSize = blockSize;
  _phase = 0;

  _outputBuffer = NULL;
  _outputBuffer = new AudioSampleBuffer (1, _blockSize);
}

Oscillator::~Oscillator ()
{
      delete _outputBuffer;
}

void Oscillator::setFreq (float freq)
{
  _recalcInc = true;
  _freq = freq;
}

float Oscillator::getFreq (void)
{
  return _freq;
}

void Oscillator::calcIncrement (void)
{
  float temp = (float)_sampleRate / _freq;
  _increment = 1 / temp;
  _recalcInc = false;
}

void Oscillator::setPhase (float phase)
{
  _phase = phase;
}

float Oscillator::getPhase (void)
{
  return _phase;
}

AudioSampleBuffer* Oscillator::processBlock (void)
{
  for (int i = 0; i < _blockSize; i++)
      {
	if (_recalcInc) calcIncrement ();
        if (_phase >= 1) _phase = 0;
	_phase = _phase + _increment;
	_outputBuffer->setSample (0, i, (_phase - 0.5) * 2);
      }  
  return _outputBuffer;
}