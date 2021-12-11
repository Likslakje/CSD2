//All credits for writeToFile, Sine and the structure for every type of oscillator 
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "additive.h"
#include "oscillator.h"
#include "sine.h"
using namespace std;

Additive::Additive(int numberOsc) : Synth(numberOsc){
    cout<< "constructor Additive" <<endl;
    
    makeAdditive();
}

Additive::~Additive(){
    cout<< "destructor Additive" <<endl;
}

void Additive::makeAdditive(){
   Sine AdditiveOsc1(440, 44100);
}