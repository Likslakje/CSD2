#include <iostream>
using namespace std;
#include "instrument.h"

class Wind : public Instrument{
    public: 
        Wind();
        ~Wind();
        float lowHz;
        float highHz;
        void pitchRangeCheck();
};