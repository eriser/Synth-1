/*
  ==============================================================================

    Envelope.h
    Created: 7 May 2015 8:54:55pm
    Author:  mobilestudio

  ==============================================================================
*/

#ifndef ENVELOPE_H_INCLUDED
#define ENVELOPE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
//
//   Envelope Class
//
//==============================================================================

class Envelope
{
public:
  
  Envelope (double sampleRate, int blockSize);
  ~Envelope ();

  void setAttack (float attack);
  float getAttack (void);
  void setDecay (float decay);
  float getDecay (void);
  void setSustain (float sustain);
  float getSustain (void);
  void setRelease (float release);
  float getRelease (void);

  void triggerAttack (void);
  void triggerDecay (void);
  void triggerSustain (void);
  void triggerRelease (void);

  AudioSampleBuffer* processBlock (AudioSampleBuffer& inputBuffer);

private:
  
  double _sampleRate;
  int _blockSize;

  float _attack;
  float _decay;
  float _sustain;
  float _release;

  bool _loopReleaseAttack = false;

  // Buffer Pointer
  AudioSampleBuffer *_outputBuffer;
  
};

#endif  // ENVELOPE_H_INCLUDED
