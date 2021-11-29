#include <iostream>
using namespace std;
#include "instrument.h"

class Key : public Instrument{
    public:
        Key();
        ~Key();
        float lowHz;
        float highHz;
        void pitchRangeCheck();
};
