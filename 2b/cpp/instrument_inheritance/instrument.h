#ifndef _INSTRUMENT_H_
#define _INSTRUMENT_H_
#include <iostream>
using namespace std;

class Instrument{
    public:
        Instrument(string name, string soundDes, float note);
        ~Instrument();
        void play(string message);
    protected:
        string name;
        string soundDes;
        float note;
};

#endif