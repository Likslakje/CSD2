#include <iostream>
using namespace std;
#include "instrument.h"

class String : public Instrument{
    public:
        String(string name, string soundDes, float note);
        ~String();
        float lowHz;
        float highHz;
        void pitchRangeCheck();
};

