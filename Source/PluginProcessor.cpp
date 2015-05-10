#include "config.h"

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
  OSC1 = NULL;
}

NewProjectAudioProcessor::~NewProjectAudioProcessor()
{
  delete OSC1;
}

//==============================================================================
const String NewProjectAudioProcessor::getName() const
{
  return JucePlugin_Name;
}

int NewProjectAudioProcessor::getNumParameters()
{
  return 1;
}

float NewProjectAudioProcessor::getParameter (int index)
{
  return 0.0f;
}

void NewProjectAudioProcessor::setParameter (int index, float newValue)
{
}

const String NewProjectAudioProcessor::getParameterName (int index)
{
  return String("empty");
}

const String NewProjectAudioProcessor::getParameterText (int index)
{
  return String("empty");
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

  OSC1 = new YAO (sampleRate, samplesPerBlock);
}

void NewProjectAudioProcessor::releaseResources()
{
  OSC1 = NULL;
}

//==============================================================================

//================================
//   AUDIO PROCESS CALLBACK FUCTION                                 
//================================

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

  connector = OSC1->processBlock ();
  
  for (int i = 0; i < 2; i++)
    {
    buffer.copyFrom (i, 0, connector[0], 0, 0, _blockSize);
    }
  
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
  #ifdef HASNOEDITOR
  return false;
  #define HASEDITOR
  return true;
  #endif
}
 
//============================================================================== 
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
