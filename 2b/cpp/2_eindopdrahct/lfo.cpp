//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "lfo.h"
using namespace std;

Lfo::Lfo(float midiNumber, double samplerate) : Synth(midiNumber, samplerate){
    cout<< "constructor Lfo" <<endl;
}

Lfo::~Lfo(){
    cout<< "destructor Lfo" <<endl;
}

void Lfo::typeSynthCalc(){
    //imagine every waveforms starts at 0...
    //we need to get the first sample so...nextsample() voor each waveform
    waveforms[0]->nextSample();
    waveforms[2]->nextSample();
    // get amp of sine and change amp sine to freq square
    double modulator = waveforms[2]->getSample();
    modulator = (modulator * 0.5) + 0.5;
    waveforms[0]->setAmplitude(modulator);
    synthTypeSample = waveforms[0]->getSample();
}