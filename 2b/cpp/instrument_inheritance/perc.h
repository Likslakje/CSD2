# include <iostream>
using namespace std;
#include "instrument.h"

class Percussion : public Instrument{
    public:
        Percussion();
        ~Percussion();
        float lowHz;
        float highHz;
        void pitchRangeCheck();
};