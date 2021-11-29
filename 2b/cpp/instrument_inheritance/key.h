#include <iostream>
using namespace std;
#include "instrument.h"

class Key : public Instrument{
    public:
        Key(string name, string soundDes, int note);
        ~Key();
        float lowHz;
        float highHz;
        void pitchRangeCheck();
};
