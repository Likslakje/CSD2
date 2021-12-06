//All credits for writeToFile, Sine and the structure for every type of oscillator 
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "oscillator.h"
#include "sine.h"
#include "tri.h"
#include "saw.h"
#include "square.h"
#ifndef _SYNTH_H_
#define _SYNTH_H_

class Synth{
    public:
        Synth(int numberOsc);
        ~Synth();
        void setOsc();
    // protected:
        int numberOsc;

};

#endif