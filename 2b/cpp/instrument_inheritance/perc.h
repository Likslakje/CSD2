# include <iostream>
using namespace std;
#include "instrument.h"

class Percussion : public Instrument{
    public:
        Percussion(string name, string soundDes, int note);
        ~Percussion();
        float lowHz;
        float highHz;
        void pitchRangeCheck();
};