//==============================================================================
//
//   Linux VST Synth PluginProcessor.cpp
//
//==============================================================================

#include "PluginProcessor.h"
#include "GUI.h"

//==============================================================================
//
//   Delay Class
//
//==============================================================================

Delay::Delay ()
{
}

Delay::Delay (double sampleRate, int blockSize)
{
  _sampleRate = sampleRate;
  _blockSize = blockSize;

  delayLine01 = NULL;
  delayLine02 = NULL;
}

Delay::~Delay ()
{
  delete delayLine01;
  delete delayLine02;
}

//==============================================================================
//
//   Envelope Class
//
//==============================================================================

Envelope::Envelope ()
{
}

Envelope::Envelope (double sampleRate, int blockSize)
{
  _sampleRate = sampleRate;
  _blockSize = blockSize;
}

Envelope::~Envelope ()
{
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

//=======================================================
//
//  Example Code from moog~.c Pd
//
//  static t_float calc_k(t_float f,t_float k) {
//  if (k>4.) k =4.;
//  if (k < 0.) k = 0.;
//  if (f <= 3800) return k;
//  k = k - 0.5*((f-3800)/4300);
//  return k;
//
//  t_int *moog_perform(t_int *w)
//  {
//    t_moog* x = (t_moog*) (w[1]); 
//    t_float *in1 = (t_float *)(w[2]);
//    t_float *p = (t_float *)(w[3]);
//    t_float *k = (t_float *)(w[4]);
//
//    t_float *out = (t_float *)(w[5]);
//    int n = (int)(w[6]);
//    float in;
//    float pt,pt1;
//    
//    float x1 = x->x_1;
//    float x2 = x->x_2;
//    float x3 = x->x_3;
//    float x4 = x->x_4;
//    float ys1 = x->y_1;
//    float ys2 = x->y_2;
//    float ys3 = x->y_3;
//    float ys4 = x->y_4;
//
//
//   while (n--) {
//     if (*p > 8140) *p = 8140.;
//     *k = calc_k(*p,*k);
//     pt =*p;
//     pt1=(pt+1)*0.76923077;
//     in = *in1++ - *k*ys4;
//     ys1 = (pt1)*in + 0.3*x1 - pt*ys1;
//     x1 = in;
//     ys2 = (pt1)*ys1 + 0.3*x2 - pt*ys2;
//     x2 = ys1;
//     ys3 = (pt1)*ys2 + 0.3 *x3 - pt*ys3;
//     x3 = ys2;
//     ys4 = (pt1)*ys3 + 0.3*x4 - pt*ys4;
//     x4 = ys3;
//     *out++ = ys4;
//   }
//
//   
//    x->y_1 = ys1;
//    x->y_2 = ys2;
//    x->y_3 = ys3;
//    x->y_4 = ys4;
//    x->x_1 = x1;
//    x->x_2 = x2;
//    x->x_3 = x3;
//    x->x_4 = x4;
//
//    return (w+7);
//}

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

  delete ENV1;
  delete ENV2;
  delete ENV3;
  delete ENV4;

  delete DLL1;
  delete DLL2;
  delete DLL3;
  delete DLL4;
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

  ENV1 = new Envelope (sampleRate,samplesPerBlock);
  ENV2 = new Envelope (sampleRate,samplesPerBlock);
  ENV3 = new Envelope (sampleRate,samplesPerBlock);
  ENV4 = new Envelope (sampleRate,samplesPerBlock);

  DLL1 = new Delay (sampleRate,samplesPerBlock);
  DLL2 = new Delay (sampleRate,samplesPerBlock);
  DLL3 = new Delay (sampleRate,samplesPerBlock);
  DLL4 = new Delay (sampleRate,samplesPerBlock);
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
