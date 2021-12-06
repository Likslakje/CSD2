//All credits for writeToFile, Sine and the structure for every type of oscillator 
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "synth.h"
using namespace std;

Synth::Synth(int numberOsc){
    cout<< "constructor Synth" <<endl;
    this-> numberOsc = numberOsc;
    cout<< numberOsc <<endl;
}

Synth::~Synth(){
    cout<< "destructor Synth" <<endl;
}

void Synth::setOsc(){
    //everything it needs to make a number of oscillators, like 3x freq -> userinput
}