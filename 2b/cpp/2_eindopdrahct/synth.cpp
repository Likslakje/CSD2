//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
//Credits for MIDI to frequency formula go to https://www.music.mcgill.ca/~gary/307/week1/node28.html
#include <iostream>
#include "synth.h"
using namespace std;

Synth::Synth(float midiNumber, double samplerate) : midiNumber(midiNumber), sample(0){
    cout<< "constructor Synth" << midiNumber <<endl;
    waveforms[0]->setSamplerate(samplerate);
    setWaveformFreq(midiNumber);
}

Synth::~Synth(){
    cout<< "destructor Synth" <<endl;
}

double Synth::midiToFreq(float midiNumber){
    return 440 * pow(2.0, (midiNumber - 69.0) / 12.0);
}

void Synth::nextSample(){
    typeSynthCalc();
    cout<< "Synth nextSmaple " << sample <<endl;
}

double Synth::getSample(){
    return sample;
}

void Synth::setWaveformFreq(float midiNumber){
    double frequency = midiToFreq(midiNumber);
    waveforms[0]->setFrequency(frequency);
}