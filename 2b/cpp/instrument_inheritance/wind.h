#include <iostream>
using namespace std;
#include "instrument.h"

class Wind : public Instrument{
    public: 
        Wind(string name, string soundDes, int note);
        ~Wind();
        float lowHz;
        float highHz;
        void pitchRangeCheck();
};