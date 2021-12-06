//All credits for writeToFile, Sine and the structure for every type of oscillator 
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "fm.h"
using namespace std;

Fm::Fm(int numberOsc) : Synth(numberOsc){
    cout<< "constructor Fm" <<endl;
    // makeFm();
}

Fm::~Fm(){
    cout<< "destructor Fm" <<endl;
}

void Fm::makeFm(){
    Sine fmOsc1(440, 44100);
}