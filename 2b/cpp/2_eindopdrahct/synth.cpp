//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
//Credits for MIDI to frequency formula go to https://www.music.mcgill.ca/~gary/307/week1/node28.html
#include <iostream>
#include "synth.h"
#include "math.h"
using namespace std;

Synth::Synth(){
    cout<< "constructor Synth" << midiNumber <<endl;
}

Synth::Synth(float midiNumber, double samplerate) : midiNumber(midiNumber), sample(0){
    cout<< "constructor Synth" << midiNumber <<endl;
    // waveforms[0]->setSamplerate(samplerate);
    // waveforms[2]->setSamplerate(samplerate);
    // setWaveformFreq(midiNumber);
}

Synth::~Synth(){
    cout<< "destructor Synth" <<endl;
    // //I've got no frikkin clu if this is "tha wäy"?
    // for (int i = 0; i < numWaveforms; i++){
    //     //delete frees the memory address
    //     delete waveforms[i];
    //     //nulptr is an address which is set to 0
    //     waveforms[i] = nullptr;
    //     /*possible question: How do memory addresses work?
    //      *How are they build up?
    //     */
    // }
}

void Synth::setTypeSynth(TypeSynth type)
{
  cout<< "\n• Synth::setWaveform" <<endl;

  cout<< "\n - using " << synthTypeToString(type) << " as synth"
    <<endl;
  switch (type) {
  case TypeSynth::AM:
    // set sine
    cout << "\n--- selecting am";
    break;
  case TypeSynth::FM:
    // set saw
    cout << "\n--- selecting fm";
    break;
  default:
    break;
  }
}

string Synth::synthTypeToString(TypeSynth type)
{
  switch(type) {
    case TypeSynth::AM:
      return "am";
    case TypeSynth::FM:
      return "fm";
    default:
      return "Invalid synth type";
  }
}

double Synth::midiToFreq(float midiNumber){
    //Just a midi to freq formula (we need math.h)
    return 440 * pow(2.0, (midiNumber - 69.0) / 12.0);
}

void Synth::typeSynthCalc(){
    //could't be pure virtual void because the Synth base class is
    //called by th euserIput in main -> Synth synth

}
void Synth::typeSynthNextSample(){
    typeSynthCalc();
}

double Synth::getTypeSynthSample(){
    return synthTypeSample;
}

void Synth::setWaveformFreq(float midiNumber){
    double frequency = midiToFreq(midiNumber);
    // waveforms[0]->setFrequency(frequency);
    // waveforms[2]->setFrequency(frequency/50);
}