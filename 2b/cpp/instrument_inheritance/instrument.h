#ifndef _INSTRUMENT_H_
#define _INSTRUMENT_H_
#include <iostream>
using namespace std;

class Instrument{
    public:
        Instrument(string name, string soundDes, int note);
        ~Instrument();
        float noteToFreq(int note);
        void play(string message, string soundDes);
    protected:
        string name;
        string soundDes;
        int note;
        float freq;
};

#endif