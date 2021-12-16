//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#ifndef _SYNTH_H_
#define _SYNTH_H_
#include <iostream>
#include <array>
#include "sine.h"
#include "saw.h"
#include "square.h"
using namespace std;

class Synth{
    public:
        Synth();
        Synth(float midiNumber, double samplerate);
        virtual ~Synth();
        // NOTE: needs to be same order as the waveFormOptions string array
        enum TypeSynth {
            AM = 0, // ensure enum starts at 0
            FM,
            Size // 2
        };
        // setters and getters
        void setTypeSynth(TypeSynth type);
        void setWaveformFreq(float midiNumber);
        void typeSynthNextSample();
        double getTypeSynthSample();
        // static method because this method does not depend on objects
        static string synthTypeToString(TypeSynth type);
    protected:
        double samplerate;
        float midiNumber;
        double sample;
        double synthTypeSample;
        int numWaveforms = 3;
        // Oscillator* waveforms[3] = {new Sine(0, 0), new Saw(0, 0), new Square(0, 0)};
        double midiToFreq(float midiNumber);
        virtual void typeSynthCalc();
};

#endif