//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
//Credits for MIDI to frequency formula go to https://www.music.mcgill.ca/~gary/307/week1/node28.html
#include <iostream>
#include "synth.h"
using namespace std;

Synth::Synth(int midiNumber, double samplerate) : midiNumber(midiNumber), samplerate(samplerate){
    cout<< "constructor Synth" << midiNumber <<endl;
    setMidiToFreq();
}

Synth::~Synth(){
    cout<< "destructor Synth" <<endl;
}

void Synth::setMidiNumber(int midiNumber){
    this->midiNumber = midiNumber;
}

int Synth::getMidiNumber(){
    return midiNumber;
}

void Synth::setMidiToFreq(){
    int midiNumber = getMidiNumber();
    cout<< "Synth::midiToFreq" << midiNumber << endl;
    if(midiNumber > 1 && midiNumber < 128){
        this->midiToFreq = 440 * pow(2.0, (midiNumber - 69.0) / 12.0);
    }else{
        cout<< "ask for new frequency" <<endl;
    }
}

float Synth::getMidiToFreq(){
    return midiToFreq;
}

void Synth::setFrequency(){
    this->frequency = getMidiToFreq();
}

float Synth::getFrequency(){
    return frequency;
}

void Synth::setSamplerate(double samplerate){
    this->samplerate = samplerate;
}

double Synth::getSamplerate(){
    return samplerate;
}
