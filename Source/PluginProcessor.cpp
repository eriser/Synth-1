//==============================================================================
//
//   Linux VST Synth PluginProcessor.cpp
//
//==============================================================================

#include "PluginProcessor.h"
#include "GUI.h"

//==============================================================================
//
//   NewProjectAudioProcessor Class
//
//==============================================================================

NewProjectAudioProcessor::NewProjectAudioProcessor()
{
  _juceIn = NULL;
  _juceOut = NULL;

  _mixer1 = NULL;
  _mixer2 = NULL;
  _mixer3 = NULL;
  _mixer4 = NULL;
  
  OSC1 = NULL;
  OSC2 = NULL;
  OSC3 = NULL;
  OSC4 = NULL;

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

  NOISE1 = NULL;
}

NewProjectAudioProcessor::~NewProjectAudioProcessor()
{
  if (_juceIn)
    {
      for (int i = 0; i < getNumInputChannels(); ++i)
	delete _juceIn[i];
      delete _juceIn;

      for (int i = 0; i < getNumOutputChannels(); ++i)
	delete _juceOut[i];
      delete _juceOut;
    }

  delete OSC1;
  delete OSC2;
  delete OSC3;
  delete OSC4;

  delete NOISE1;

  delete FILTER1;
  delete FILTER2;
  delete FILTER3;
  delete FILTER4;

  delete ENV1;
  delete ENV2;
  delete ENV3;
  delete ENV4;

  delete DLL1;
  delete DLL2;
  delete DLL3;
  delete DLL4;

  delete _mixer1;
  delete _mixer2;
  delete _mixer3;
  delete _mixer4;

  delete bufferRevolver;
}

//==============================================================================
const String NewProjectAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int NewProjectAudioProcessor::getNumParameters()
{
    return 33;
}

float NewProjectAudioProcessor::getParameter (int index)
{
    return 0.0f;
}

void NewProjectAudioProcessor::setParameter (int index, float newValue)
{
  //=MASTER=====================================
  //
  // Master Volume
  if (index == 0) _masterVolume = newValue;

  //=OSC1=======================================
  //
  // OSC1 Pitch Coarse
  if (index == 1) OSC1->setFreq (newValue*127);
  // OSC1 Pitch Fine
  if (index == 2) ;
  // OSC1 N.C.
  if (index == 3) ;
  // OSC1 N.C.
  if (index == 4) ;

  //=OSC2=======================================
  //
  // OSC2 Pitch Coarse
  if (index == 5) OSC2->setFreq (newValue*127);
  // OSC2 Pitch Fine
  if (index == 6) ;
  // OSC2 N.C.
  if (index == 7) ;
  // OSC2 N.C.
  if (index == 8) ;

  //=OSC3=======================================
  //
  // OSC3 Pitch Coarse
  if (index == 9) OSC3->setFreq (newValue*127);
  // OSC3 Pitch Fine
  if (index == 10) ;
  // OSC3 N.C.
  if (index == 11) ;
  // OSC3 N.C.
  if (index == 12) ;

  //=OSC4=======================================
  //
  // OSC4 Pitch Coarse
  if (index == 13) OSC4->setFreq (newValue*127);
  // OSC4 Pitch Fine
  if (index == 14) ;
  // OSC4 N.C.
  if (index == 15) ;
  // OSC4 N.C.
  if (index == 16) ;

  //=ENV1=======================================
  //
  // ENV1 Attack
  if (index == 17) ENV1->setAttack (newValue*512);
  // ENV1 Decay
  if (index == 18) ENV1->setDecay (newValue*512);
  // ENV1 Sustain
  if (index == 19) ENV1->setSustain (newValue);
  // ENV1 Release
  if (index == 20) ENV1->setRelease (newValue*512);

  //=ENV2=======================================
  //
  // ENV2 Attack
  if (index == 21) ENV2->setAttack (newValue*512);
  // ENV2 Decay
  if (index == 22) ENV2->setDecay (newValue*512);
  // ENV2 Sustain
  if (index == 23) ENV2->setSustain (newValue);
  // ENV2 Release
  if (index == 24) ENV2->setRelease (newValue*512);  

  //=ENV3=======================================
  //
  // ENV3 Attack
  if (index == 25) ENV3->setAttack (newValue*512);
  // ENV3 Decay
  if (index == 26) ENV3->setDecay (newValue*512);
  // ENV3 Sustain
  if (index == 27) ENV3->setSustain (newValue);
  // ENV3 Release
  if (index == 28) ENV3->setRelease (newValue*512);

  //=ENV4=======================================
  //
  // ENV4 Attack
  if (index == 29) ENV4->setAttack (newValue*512);
  // ENV4 Decay
  if (index == 30) ENV4->setDecay (newValue*512);
  // ENV4 Sustain
  if (index == 31) ENV4->setSustain (newValue);
  // ENV4 Release
  if (index == 32) ENV4->setRelease (newValue*512);  
  
}

const String NewProjectAudioProcessor::getParameterName (int index)
{
  if(index == 0) return "Master Volume";

  if(index == 1)  return "OSC1 Pitch Coarse";
  if(index == 2)  return "OSC1 Pitch Fine";
  if(index == 3)  return "OSC1 N.C.";
  if(index == 4)  return "OSC1 N.C.";

  if(index == 5)  return "OSC2 Pitch Coarse";
  if(index == 6)  return "OSC2 Pitch Fine";
  if(index == 7)  return "OSC2 N.C.";
  if(index == 8)  return "OSC2 N.C.";

  if(index == 9)  return "OSC3 Pitch Coarse";
  if(index == 10) return "OSC3 Pitch Fine";
  if(index == 11) return "OSC3 N.C.";
  if(index == 12) return "OSC3 N.C.";

  if(index == 13) return "OSC4 Pitch Coarse";
  if(index == 14) return "OSC4 Pitch Fine";
  if(index == 15) return "OSC4 N.C.";
  if(index == 16) return "OSC4 N.C.";

  if(index == 17) return "ENV1 Attack";
  if(index == 18) return "ENV1 Decay";
  if(index == 19) return "ENV1 Sustain";
  if(index == 20) return "ENV1 Release";

  if(index == 21) return "ENV2 Attack";
  if(index == 22) return "ENV2 Decay";
  if(index == 23) return "ENV2 Sustain";
  if(index == 24) return "ENV2 Release";

  if(index == 25) return "ENV3 Attack";
  if(index == 26) return "ENV3 Decay";
  if(index == 27) return "ENV3 Sustain";
  if(index == 28) return "ENV3 Release";

  if(index == 29) return "ENV4 Attack";
  if(index == 30) return "ENV4 Decay";
  if(index == 31) return "ENV4 Sustain";
  if(index == 32) return "ENV4 Release";
  
  return String();
}

const String NewProjectAudioProcessor::getParameterText (int index)
{
  if(index == 0)  return "Master Volume";

  if(index == 1)  return "OSC1 Pitch Coarse";
  if(index == 2)  return "OSC1 Pitch Fine";
  if(index == 3)  return "OSC1 N.C.";
  if(index == 4)  return "OSC1 N.C.";

  if(index == 5)  return "OSC2 Pitch Coarse";
  if(index == 6)  return "OSC2 Pitch Fine";
  if(index == 7)  return "OSC2 N.C.";
  if(index == 8)  return "OSC2 N.C.";

  if(index == 9)  return "OSC3 Pitch Coarse";
  if(index == 10) return "OSC3 Pitch Fine";
  if(index == 11) return "OSC3 N.C.";
  if(index == 12) return "OSC3 N.C.";

  if(index == 13) return "OSC4 Pitch Coarse";
  if(index == 14) return "OSC4 Pitch Fine";
  if(index == 15) return "OSC4 N.C.";
  if(index == 16) return "OSC4 N.C.";

  if(index == 17) return "ENV1 Attack";
  if(index == 18) return "ENV1 Decay";
  if(index == 19) return "ENV1 Sustain";
  if(index == 20) return "ENV1 Release";

  if(index == 21) return "ENV2 Attack";
  if(index == 22) return "ENV2 Decay";
  if(index == 23) return "ENV2 Sustain";
  if(index == 24) return "ENV2 Release";

  if(index == 25) return "ENV3 Attack";
  if(index == 26) return "ENV3 Decay";
  if(index == 27) return "ENV3 Sustain";
  if(index == 28) return "ENV3 Release";

  if(index == 29) return "ENV4 Attack";
  if(index == 30) return "ENV4 Decay";
  if(index == 31) return "ENV4 Sustain";
  if(index == 32) return "ENV4 Release";
  
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
  
  _juceIn = new float*[getNumInputChannels()];
  for (int i = 0; i < getNumInputChannels(); ++i)
    _juceIn[i] = new float[samplesPerBlock];

  _juceOut = new float*[getNumOutputChannels()];
  for (int i = 0; i < getNumOutputChannels(); ++i)
    _juceOut[i] = new float[samplesPerBlock];

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
}

void NewProjectAudioProcessor::releaseResources()
{
  if (_juceIn)
    {
      for (int i = 0; i < getNumInputChannels(); ++i)
	delete _juceIn[i];
      delete _juceIn;

      for (int i = 0; i < getNumOutputChannels(); ++i)
	delete _juceOut[i];
      delete _juceOut;
    }

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
}

//==============================================================================
//
//  AUDIO PROCESS CALLBACK FUCTION
//
//==============================================================================

void NewProjectAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
//==============================================================================
// MIDI ->

MidiBuffer processedMidi;
int time;
MidiMessage m;
 
    for (MidiBuffer::Iterator i (midiMessages); i.getNextEvent (m, time);)
    {
        if (m.isNoteOn())
        {
	  
        }
        else if (m.isNoteOff())
        {
        }
        else if (m.isAftertouch())
        {
        }
        else if (m.isPitchWheel())
        {
        }
    }
 
//==============================================================================
// AUDIO ->
    
  timeOfFirstEvent = midiMessages.getFirstEventTime ();
  timeOfLastEvent = midiMessages.getLastEventTime ();
  numEvents = midiMessages.getNumEvents (); 
  
  buffer.clear ();

  _mixer1 = OSC1->processBlock ();
  _mixer2 = FILTER1->lowpass (*_mixer1);

  //_mixer2 = NOISE1->processBlock ();

  _mixer3 = ENV1->processBlock (*_mixer2);

  for (int i = 0; i < getNumOutputChannels (); i++)
    {
      buffer.copyFrom (i, 0, _mixer2[0], 0, 0, _blockSize);
    }
}

//==============================================================================
bool NewProjectAudioProcessor::hasEditor() const
{
  //return true; // (change this to false if you choose to not supply an editor)
    return false; // (change this to false if you choose to not supply an editor)
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
