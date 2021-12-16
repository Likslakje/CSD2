//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include <iostream>
using namespace std;

class Oscillator{
    public:
        Oscillator();
        Oscillator(double frequency, double samplerate);
        virtual ~Oscillator();
        enum Waveform {
            Sine = 0, // ensure enum starts at 0
            Saw,
            Square,
            Size // 3
        };
        // setters and getters
        void setWaveform(Waveform type);

        // static method because this method does not depend on objects
        static string waveformTypeToString(Waveform type);
        //getters and setters
        void setFrequency(double frequency);
        double getFrequency();
        void setAmplitude(double newAmplitude);
        double getAmplitude();
        double getSample();
        void setSamplerate(double samplerate);
        void nextSample();
    protected:
        virtual void calculate();
        double frequency;
        double samplerate;
        double amplitude;
        double phase;
        double sample;
};

#endif