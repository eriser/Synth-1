/*
  ==============================================================================

    Envelope.cpp
    Created: 7 May 2015 8:54:55pm
    Author:  mobilestudio

  ==============================================================================
*/

#include "Envelope.h"

//==============================================================================
//
//   Envelope Class
//
//==============================================================================

Envelope::Envelope (double sampleRate, int blockSize)
{
  _sampleRate = sampleRate;
  _blockSize = blockSize;

  _outputBuffer = NULL;
  _outputBuffer = new AudioSampleBuffer (1, _blockSize);
  
}

Envelope::~Envelope ()
{
  delete _outputBuffer;
}

void Envelope::setAttack (float attack)
{
  _attack = attack;
}

float Envelope::getAttack (void)
{
  return _attack;
}

void Envelope::setDecay (float decay)
{
  _decay = decay;
}

float Envelope::getDecay (void)
{
  return _decay;
}

void Envelope::setSustain (float sustain)
{
  _sustain = sustain;
}

float Envelope::getSustain (void)
{
  return _sustain;
}

void Envelope::setRelease (float release)
{
  _release = release;
}

float Envelope::getRelease (void)
{
  return _release;
}

void Envelope::triggerAttack (void)
{
  triggerDecay ();
}

void Envelope::triggerDecay (void)
{
  triggerSustain ();
}

void Envelope::triggerSustain (void)
{
  triggerRelease ();
}

void Envelope::triggerRelease (void)
{
  if (_loopReleaseAttack) triggerAttack ();
}

AudioSampleBuffer* Envelope::processBlock (AudioSampleBuffer& inputBuffer)
{ 
  inputBuffer.applyGainRamp (0, 0, _blockSize, 0, _sustain);

  _outputBuffer = &inputBuffer;

  return _outputBuffer;
}
