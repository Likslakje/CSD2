#include <iostream>
using namespace std;
#include "instrument.h"

class String : public Instrument{
    public:
        String();
        ~String();
        float lowHz;
        float highHz;
        void pitchRangeCheck();
};

