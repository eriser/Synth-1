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
  _freq = freq;
}

String Oscillator::getFreq (void)
{
  char temp[10];
  sprintf (temp,"%f",_freq);
  String text = temp;
  return text;
}

float Oscillator::getFreqRaw (void)
{
  return _freq;
}

void Oscillator::setPhase (float phase)
{
  _phase = phase;
}

float Oscillator::getPhase (void)
{
  return _phase;
}

void Oscillator::setGain (float gain)
{
  _gain = gain;
}

String Oscillator::getGain (void)
{
  char temp[10];
  sprintf (temp,"%f",_gain);
  String text = temp;
  return text;
}

void Oscillator::setShape (int shape)
{
  _waveshape = shape;
}

String Oscillator::getShape (void)
{
  if (_waveshape == 0) return "PHASE";
  else if (_waveshape == 1) return "SINUSOID";
  else if (_waveshape == 2) return "TRIANGLE";
  else if (_waveshape == 3) return "SAWTOOTH";
  else if (_waveshape == 4) return "PWM-SQUARE";
}

void Oscillator::setPW (float width)
{
  _pwmThreshold = width;
}

String Oscillator::getPW (void)
{
  char temp[10];
  sprintf (temp,"%f",_pwmThreshold);
  String text = temp;
  return text;
}

float Oscillator::calcIncrement (float freq)
{
  float temp = (float)_sampleRate / freq;
  return 1 / temp;
}

void Oscillator::phasor (float freq)
{
  _increment = calcIncrement (freq);
  if (_phase >= 1) _phase = 0;
  _phase = _phase + _increment;
}

//================================================================================
// WAVESHAPES:      0=PHASESIGNAL  2=           4=PWM
//                  1=SINUSOID     3=SAWTOOTH
//
float Oscillator::waveshaper (float signal)
{
  //=PHASE=PHASE=PHASE=PHASE=PHASE=PHASE=PHASE
  if (_waveshape == 0) return signal * _gain;

  //=SINE=SINE=SINE=SINE=SINE=SINE=SINE=SINE=SINE
  else if (_waveshape == 1)
    {
      return (sin (signal * 43)) *_gain;
    }
  
  //=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X    <=  TRIANGEL
  else if (_waveshape == 2)
    {
      return signal * _gain;
    }
  
  //=SAW=SAW=SAW=SAW=SAW=SAW=SAW=SAW=SAW=SAW=SAW
  else if (_waveshape == 3)
    {
      return ((signal - 0.5) * 2) *_gain;
    }

  //=PWM=PWM=PWM=PWM=PWM=PWM=PWM=PWM=PWM=PWM=PWM
  else if (_waveshape == 4)
    {
      if (signal < _pwmThreshold) signal = -1;
      else signal = 1;
      
      return signal * _gain;
    }

  //=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X    <=  Wavetable
  else if (_waveshape == 5)
    {
      return signal * _gain;
    }
  
  return signal * _gain;
}

AudioSampleBuffer* Oscillator::processBlock (void)
{
  for (int i = 0; i < _blockSize; i++)
      {
	phasor (_freq);
	_outputBuffer->setSample (0, i, waveshaper (_phase));
      }  
  return _outputBuffer;
}
