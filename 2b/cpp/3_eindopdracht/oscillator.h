//All credits for Oscillator go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/taylorSwift/csd2b/theorie/session_2/oscillator

#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include <iostream>

// 1 = regular flow, 2 = mid_level, 3 = low_level, 0 = off
#define DEBUG 1

class Oscillator
{
public:
  Oscillator();
  Oscillator(double frequency, double samplerate);
  virtual ~Oscillator();

  //getters and setters
  void setFrequency(double frequency);
  void setAmplitude(double newAmplitude);
  double getSample();
  void setSamplerate(double samplerate);
  void nextSample();
protected:
  virtual void calculate() = 0;
  double frequency;
  double samplerate;
  double amplitude;
  double phase;
  double sample;
};

#endif
