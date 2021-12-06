//All credits for writeToFile, Sine and the structure for every type of oscillator 
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "subtractive.h"
using namespace std;

Subtractive::Subtractive(int numberOsc) : Synth(numberOsc){
    cout<< "constructor Subtractive" <<endl;
    // makeSubtractive();
}

Subtractive::~Subtractive(){
    cout<< "destructor Subtractive" <<endl;
}

void Subtractive::makeSubtractive(){
    Sine subtractiveOsc1(440, 44100);
}