//==============================================================================
//
//   Linux VST Synth PluginProcessor.cpp
//
//==============================================================================

#include "PluginProcessor.h"
#include "GUI.h"

//==============================================================================
//
//   Envelope Class
//
//==============================================================================

Envelope::Envelope ()
{
}

Envelope::~Envelope ()
{
}

void Envelope::init (double sampleRate, int blockSize)
{
  _sampleRate = sampleRate;
  _blockSize = blockSize;
}

//==============================================================================
//
//   Filter Class
//
//==============================================================================

Filter::Filter ()
{
}

Filter::~Filter ()
{
}

void Filter::init (double sampleRate, int blockSize)
{
  _sampleRate = sampleRate;
  _blockSize = blockSize;
}

float Filter::lowpass (void)
{
  return 0;
}

float Filter::highpass (void)
{
  return 0;
}

float Filter::bandpass (void)
{
  return 0;
}

//==============================================================================
//
//   Oscillator Class
//
//==============================================================================

Oscillator::Oscillator ()
{
}

Oscillator::~Oscillator ()
{
}

void Oscillator::init (double sampleRate, int blockSize)
{
  _sampleRate = sampleRate;
  _blockSize = blockSize;
  _phase = 0;
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

void Oscillator::calcInc (void)
{
  // _sampleRate / _freq = numSteps
  // 1 / numSteps = _increment
  float temp = (float)_sampleRate / _freq;
  _increment = 1 / temp;

  _recalcInc = false;
}

void Oscillator::calcPhase (void)
{
  if (_phase >= 1) _phase = 0;
  _phase = _phase + _increment;
}

void Oscillator::setPhase (float phase)
{
  _phase = phase;
}

float Oscillator::getPhase (void)
{
  return _phase;
}

float Oscillator::getNewPhase (void)
{
  if (_recalcInc) calcInc ();
    
  calcPhase ();
  return _phase;
}

//==============================================================================
//
//   NewProjectAudioProcessor Class
//
//==============================================================================

NewProjectAudioProcessor::NewProjectAudioProcessor()
{
  _juceIn = NULL;
  _juceOut = NULL;
  
  OSC1 = NULL;
  OSC2 = NULL;
  OSC3 = NULL;
  OSC4 = NULL;

  FILTER1 = NULL;
  FILTER2 = NULL;
  FILTER3 = NULL;
  FILTER4 = NULL;
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

  delete FILTER1;
  delete FILTER2;
  delete FILTER3;
  delete FILTER4;
}

//==============================================================================
const String NewProjectAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int NewProjectAudioProcessor::getNumParameters()
{
    return 9;
}

float NewProjectAudioProcessor::getParameter (int index)
{
    return 0.0f;
}

void NewProjectAudioProcessor::setParameter (int index, float newValue)
{
  if (index == 0)
    {
      _masterVolume = newValue;
    }

  if (index == 1)
    {
      float temp = newValue * 127;
      OSC1->setFreq (temp);
    }

  if (index == 2)
    {
      float temp = newValue * 127;
      OSC2->setFreq (temp);
    }

  if (index == 3)
    {
      float temp = newValue * 127;
      OSC3->setFreq (temp);
    }

  if (index == 4)
    {
      float temp = newValue * 127;
      OSC4->setFreq (temp);
    }
}

const String NewProjectAudioProcessor::getParameterName (int index)
{
  if(index == 0) return "Master Volume";

  if(index == 1) return "OSC1 Pitch";
  if(index == 2) return "OSC2 Pitch";
  if(index == 3) return "OSC3 Pitch";
  if(index == 4) return "OSC4 Pitch";

  if(index == 5) return "N.C.";
  if(index == 6) return "N.C.";
  if(index == 7) return "N.C.";
  if(index == 8) return "N.C.";
    return String();
}

const String NewProjectAudioProcessor::getParameterText (int index)
{
  if(index == 0) return "Master Volume";

  if(index == 1) return "OSC1 Pitch";
  if(index == 2) return "OSC2 Pitch";
  if(index == 3) return "OSC3 Pitch";
  if(index == 4) return "OSC4 Pitch";

  if(index == 5) return "N.C.";
  if(index == 6) return "N.C.";
  if(index == 7) return "N.C.";
  if(index == 8) return "N.C.";
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

  OSC1 = new Oscillator;
  OSC1->init (sampleRate, samplesPerBlock);

  OSC2 = new Oscillator;
  OSC2->init (sampleRate, samplesPerBlock);

  OSC3 = new Oscillator;
  OSC3->init (sampleRate, samplesPerBlock);

  OSC4 = new Oscillator;
  OSC4->init (sampleRate, samplesPerBlock);

  FILTER1 = new Filter;
  FILTER1->init (sampleRate, samplesPerBlock);

  FILTER2 = new Filter;
  FILTER2->init (sampleRate, samplesPerBlock);

  FILTER3 = new Filter;
  FILTER3->init (sampleRate, samplesPerBlock);

  FILTER4 = new Filter;
  FILTER4->init (sampleRate, samplesPerBlock);
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
}

void NewProjectAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
  //for (int i = 0; i < _blockSize; i++)
  //  {
  //    if (lastValue > 1) lastValue = 0;
      
  //    lastValue = lastValue + (increment);
      
  //    _juceOut[0][i] = lastValue;
  //    _juceOut[1][i] = lastValue;
  //  }
  
  //    buffer.copyFrom (0, 0, _juceOut[0], _blockSize);
  //    buffer.copyFrom (1, 0, _juceOut[1], _blockSize);

  float currentValueOSC1;
  float currentValueOSC2;
  float currentValueOSC3;
  float currentValueOSC4;

  float outputValue;
  
  for (int i = 0; i < _blockSize; i++)
    {
      currentValueOSC1 = OSC1->getNewPhase ();
      currentValueOSC2 = OSC2->getNewPhase ();
      currentValueOSC3 = OSC3->getNewPhase ();
      currentValueOSC4 = OSC4->getNewPhase ();

      _juceOut[0][i] = currentValueOSC1 * _masterVolume;
      _juceOut[1][i] = currentValueOSC1 * _masterVolume;
    }

  buffer.copyFrom (0, 0, _juceOut[0], _blockSize);
  buffer.copyFrom (1, 0, _juceOut[1], _blockSize);
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
