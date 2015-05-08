//==============================================================================
//
//   Linux VST Synth PluginProcessor.cpp
//
//==============================================================================

#include "PluginProcessor.h"
#include "GUI.h"

//=============================================================================
//
//   TimeStampMessage Class
//
//=============================================================================

TimeStampMessage::TimeStampMessage ()
{
}

TimeStampMessage::~TimeStampMessage ()
{
}

//==============================================================================
//
//   NewProjectAudioProcessor Class
//
//==============================================================================

NewProjectAudioProcessor::NewProjectAudioProcessor()
{
  _mixer1 = NULL;
  _mixer2 = NULL;
  _mixer3 = NULL;
  _mixer4 = NULL;
  
  OSC1 = NULL;
  OSC2 = NULL;
  OSC3 = NULL;
  OSC4 = NULL;

  NOISE1 = NULL;
  NOISE2 = NULL;
  NOISE3 = NULL;
  NOISE4 = NULL;
  
  FILTER1 = NULL;
  FILTER2 = NULL;
  FILTER3 = NULL;
  FILTER4 = NULL;

  ENV1 = NULL;
  ENV2 = NULL;
  ENV3 = NULL;
  ENV4 = NULL;

  DLL1 = NULL;
  DLL2 = NULL;
  DLL3 = NULL;
  DLL4 = NULL;
}

NewProjectAudioProcessor::~NewProjectAudioProcessor()
{
  delete DLL1;
  delete DLL2;
  delete DLL3;
  delete DLL4;

  delete ENV1;
  delete ENV2;
  delete ENV3;
  delete ENV4;

  delete FILTER1;
  delete FILTER2;
  delete FILTER3;
  delete FILTER4;

  delete OSC1;
  delete OSC2;
  delete OSC3;
  delete OSC4;

  delete NOISE1;
  delete NOISE2;
  delete NOISE3;
  delete NOISE4;
  
  delete _mixer1;
  delete _mixer2;
  delete _mixer3;
  delete _mixer4;
}

//==============================================================================
const String NewProjectAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int NewProjectAudioProcessor::getNumParameters()
{
    return 18;
}

float NewProjectAudioProcessor::getParameter (int index)
{
    return 0.0f;
}

void NewProjectAudioProcessor::setParameter (int index, float newValue)
{
  //=MASTER=
  if (index == 0) _masterVolume = newValue;

  //=OSC1=
  if (index == 1) OSC1->setFreq (mtof[(int)(newValue*127)]);
  if (index == 2) OSC1->setPW ((newValue * 0.9)+ 0.05);
  if (index == 3) OSC1->setShape (newValue*4);
  if (index == 4) OSC1->setGain (newValue);

  //=OSC2=
  if (index == 5) OSC2->setFreq (mtof[(int)(newValue*127)]);
  if (index == 6) OSC2->setPW ((newValue * 0.9)+ 0.05);
  if (index == 7) OSC2->setShape (newValue*4);
  if (index == 8) OSC2->setGain (newValue);

  //=OSC3=
  if (index == 9) OSC3->setFreq (mtof[(int)(newValue*127)]);
  if (index == 10) OSC3->setPW ((newValue * 0.9)+ 0.05);
  if (index == 11) OSC3->setShape (newValue*4);
  if (index == 12) OSC3->setGain (newValue);

  //=OSC4=
  if (index == 13) OSC4->setFreq (mtof[(int)(newValue*127)]);
  if (index == 14) OSC4->setPW ((newValue * 0.9)+ 0.05);
  if (index == 15) OSC4->setShape (newValue*4);
  if (index == 16) OSC4->setGain (newValue);  
}

const String NewProjectAudioProcessor::getParameterName (int index)
{
  if(index == 0) return "Master Volume";

  if(index == 1)  return "OSC1 Pitch Coarse";
  if(index == 2)  return "OSC1 PulseWidth";
  if(index == 3)  return "OSC1 Shape";
  if(index == 4)  return "OSC1 Gain";

  if(index == 5)  return "OSC2 Pitch Coarse";
  if(index == 6)  return "OSC2 PulseWidth";
  if(index == 7)  return "OSC2 Shape";
  if(index == 8)  return "OSC2 Gain";

  if(index == 9)  return "OSC3 Pitch Coarse";
  if(index == 10) return "OSC3 PulseWidth";
  if(index == 11) return "OSC3 Shape";
  if(index == 12) return "OSC3 Gain";

  if(index == 13) return "OSC4 Pitch Coarse";
  if(index == 14) return "OSC4 PulseWidth";
  if(index == 15) return "OSC4 Shape";
  if(index == 16) return "OSC4 Gain";

  if(index == 17) return "DELAY";

  return String();
}

const String NewProjectAudioProcessor::getParameterText (int index)
{
  if(index == 0)   return "xxx";

  if(index == 1)   return OSC1->getFreq ();
  if(index == 2)   return OSC1->getPW ();
  if(index == 3)   return OSC1->getShape ();
  if(index == 4)   return OSC1->getGain ();

  if(index == 5)   return OSC2->getFreq ();
  if(index == 6)   return OSC2->getPW ();
  if(index == 7)   return OSC2->getShape ();
  if(index == 8)   return OSC2->getGain ();

  if(index == 9)   return OSC3->getFreq ();
  if(index == 10)  return OSC3->getPW ();
  if(index == 11)  return OSC3->getShape ();
  if(index == 12)  return OSC3->getGain ();

  if(index == 13)  return OSC4->getFreq ();
  if(index == 14)  return OSC4->getPW ();
  if(index == 15)  return OSC4->getShape ();
  if(index == 16)  return OSC4->getGain ();

  if(index == 17) return "DELAY";

  return String();
}

const String NewProjectAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String NewProjectAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool NewProjectAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool NewProjectAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool NewProjectAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool NewProjectAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool NewProjectAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double NewProjectAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int NewProjectAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int NewProjectAudioProcessor::getCurrentProgram()
{
    return 0;
}

void NewProjectAudioProcessor::setCurrentProgram (int index)
{
}

const String NewProjectAudioProcessor::getProgramName (int index)
{
    return String();
}

void NewProjectAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void NewProjectAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
  _blockSize = samplesPerBlock;
  
  _mixer1 = new AudioSampleBuffer (1, _blockSize);
  _mixer2 = new AudioSampleBuffer (1, _blockSize);
  _mixer3 = new AudioSampleBuffer (1, _blockSize);
  _mixer4 = new AudioSampleBuffer (1, _blockSize);

  OSC1 = new Oscillator (sampleRate, samplesPerBlock);
  OSC2 = new Oscillator (sampleRate, samplesPerBlock);
  OSC3 = new Oscillator (sampleRate, samplesPerBlock);
  OSC4 = new Oscillator (sampleRate, samplesPerBlock);

  FILTER1 = new Filter (sampleRate, samplesPerBlock);
  FILTER2 = new Filter (sampleRate, samplesPerBlock);
  FILTER3 = new Filter (sampleRate, samplesPerBlock);
  FILTER4 = new Filter (sampleRate, samplesPerBlock);

  ENV1 = new Envelope (sampleRate,samplesPerBlock);
  ENV2 = new Envelope (sampleRate,samplesPerBlock);
  ENV3 = new Envelope (sampleRate,samplesPerBlock);
  ENV4 = new Envelope (sampleRate,samplesPerBlock);

  DLL1 = new Delay (sampleRate,samplesPerBlock);
  DLL2 = new Delay (sampleRate,samplesPerBlock);
  DLL3 = new Delay (sampleRate,samplesPerBlock);
  DLL4 = new Delay (sampleRate,samplesPerBlock);

  NOISE1 = new Noise (sampleRate,samplesPerBlock);
  NOISE2 = new Noise (sampleRate,samplesPerBlock);
  NOISE3 = new Noise (sampleRate,samplesPerBlock);
  NOISE4 = new Noise (sampleRate,samplesPerBlock);
}

void NewProjectAudioProcessor::releaseResources()
{
  OSC1 = NULL;
  OSC2 = NULL;
  OSC3 = NULL;
  OSC3 = NULL;

  FILTER1 = NULL;
  FILTER2 = NULL;
  FILTER3 = NULL;
  FILTER4 = NULL;

  ENV1 = NULL;
  ENV2 = NULL;
  ENV3 = NULL;
  ENV4 = NULL;

  DLL1 = NULL;
  DLL2 = NULL;
  DLL3 = NULL;
  DLL4 = NULL;

  _mixer1 = NULL;
  _mixer2 = NULL;
  _mixer3 = NULL;
  _mixer4 = NULL;

  NOISE1 = NULL;
  NOISE2 = NULL;
  NOISE3 = NULL;
  NOISE4 = NULL;
}

void NewProjectAudioProcessor::guiToOSC (int index, float value)
{
  if      (index == 0)  _masterVolume = value;
  
  else if (index == 1)   OSC1->setFreq (value);
  else if (index == 2)   OSC1->setPW (value);
  else if (index == 3)   OSC1->setShape (value);
  else if (index == 4)   OSC1->setGain (value);

  else if (index == 5)   OSC2->setFreq (value);
  else if (index == 6)   OSC2->setPW (value);
  else if (index == 7)   OSC2->setShape (value);
  else if (index == 8)   OSC2->setGain (value);

  else if (index == 9)   OSC3->setFreq (value);
  else if (index == 10)  OSC3->setPW (value);
  else if (index == 11)  OSC3->setShape (value);
  else if (index == 12)  OSC3->setGain (value);

  else if (index == 13)  OSC4->setFreq (value);
  else if (index == 14)  OSC4->setPW (value);
  else if (index == 15)  OSC4->setShape (value);
  else if (index == 16)  OSC4->setGain (value);

  else if (index == 17)  _delay = (int)value * _blockSize;
}

//==============================================================================

  //   //    //==================================//    //    //
 //   //    //                                  //    //    //
/////////////  AUDIO PROCESS CALLBACK FUCTION  //////////////
    //    //                                  //    //    //
   //    //==================================//    //    //

void NewProjectAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
  
//==============================================================================
//  
// MIDI -> ProcessBlock
//  
//==============================================================================

MidiBuffer processedMidi;
int time;
MidiMessage m;

int Position = 0;
  
 for (MidiBuffer::Iterator i (midiMessages); i.getNextEvent (m, time);)
   {
     if (m.isNoteOn())
       {
       }     
   }

 midiMessages.clear ();
   
//==============================================================================
//
// AUDIO -> ProcessBlock
//
//==============================================================================    
  
  buffer.clear ();

  _mixer1 = OSC1->processBlock ();
  _mixer2 = OSC2->processBlock ();
  _mixer3 = OSC3->processBlock ();
  _mixer4 = OSC4->processBlock ();

  _mixer1->applyGain (0.25);
  _mixer2->applyGain (0.25);
  _mixer3->applyGain (0.25);
  _mixer4->applyGain (0.25);
  
  _mixer1->addFrom (0,0,_mixer2[0],0,0,_blockSize);
  _mixer1->addFrom (0,0,_mixer3[0],0,0,_blockSize);
  _mixer1->addFrom (0,0,_mixer4[0],0,0,_blockSize);  
  
  for (int i = 0; i < 2; i++)
    {
      buffer.copyFrom (i, 0, _mixer1[0], 0, 0, _blockSize);
    }
  
  buffer.applyGain (_masterVolume);

  for (int channel = 0; channel < 2; channel++)
    {
      for (int i = 0; i < _blockSize; i++)
	{
	  if (buffer.getSample (channel, i) <= -0.97) buffer.setSample (channel,i, -0.97);
	  if (buffer.getSample (channel, i) >= 0.97) buffer.setSample (channel,i, 0.97);
	}
    }  
}

//==============================================================================
bool NewProjectAudioProcessor::hasEditor() const
{
  return true; // (change this to false if you choose to not supply an editor)
  //return false; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* NewProjectAudioProcessor::createEditor()
{
    return new GUI (*this);
}

//==============================================================================
void NewProjectAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void NewProjectAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new NewProjectAudioProcessor();
}
