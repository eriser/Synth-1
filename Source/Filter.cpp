/*
  ==============================================================================

  Filter.cpp
  Created: 7 May 2015 8:57:23pm
  Author:  mobilestudio

  ==============================================================================
*/

#include "Filter.h"

//==============================================================================
//
//   Filter Class
//
//==============================================================================

Filter::Filter (double sampleRate, int blockSize)
{
  _sampleRate = sampleRate;
  _blockSize = blockSize;

  _outputBuffer = NULL;
  _outputBuffer = new AudioSampleBuffer (1, _blockSize);

  x_1 = x_2 = x_3 = x_4 = 0.0;
  y_1 = y_2 = y_3 = y_4 = 0.0;
}

Filter::~Filter ()
{
  delete _outputBuffer;
}

void Filter::setCutoff (float cutoff)
{
  _cutoff = cutoff;
}

void Filter::setReso (float resonance)
{
  _resonance = resonance;
}

void Filter::calc_k (float f, float k)  //==============
{                                       //    Source:
  if (k > 4.) k = 4.;                   //    moog~.c
  if (k < 0.) k = 0.;                   //==============  
  if (f <= 3800) _k = k;                //  
  else _k = k - 0.5*((f-3800)/4300);    //  
}                                       //



AudioSampleBuffer* Filter::processBlock (AudioSampleBuffer& inputBuffer)
{                                                                     
  int n = _blockSize;                                                     
                                                                          
  float in;                                                               
  float pt,pt1;                                                           
                                                                          
  float x1 = x_1;                                                         
  float x2 = x_2;                                                         
  float x3 = x_3;                                                         
  float x4 = x_4;                                                         
  float ys1 = y_1;                                                        
  float ys2 = y_2;                                                        
  float ys3 = y_3;                                                         
  float ys4 = y_4;                                                        
                                                                          
  /*                                                                          
									      while (n--)                                                             
									      {                                                                     
									      if (_cutoff > 8140) _cutoff = 8140.;
									      _resonance = calc_k(_cutoff, _resonance);
     
									      pt =*p;
									      pt1=(pt+1)*0.76923077;
									      in = *in1++ - *k*ys4;
									      ys1 = (pt1)*in + 0.3*x1 - pt*ys1;
									      x1 = in;
									      ys2 = (pt1)*ys1 + 0.3*x2 - pt*ys2;
									      x2 = ys1;
									      ys3 = (pt1)*ys2 + 0.3 *x3 - pt*ys3;
									      x3 = ys2;
									      ys4 = (pt1)*ys3 + 0.3*x4 - pt*ys4;
									      x4 = ys3;
									      *out++ = ys4;
									      }
  */

  y_1 = ys1;
  y_2 = ys2;
  y_3 = ys3;
  y_4 = ys4;
  x_1 = x1;
  x_2 = x2;
  x_3 = x3;
  x_4 = x4;


  _outputBuffer = &inputBuffer;
  
  return _outputBuffer;
}
