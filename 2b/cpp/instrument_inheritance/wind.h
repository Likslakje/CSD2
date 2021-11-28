#include <iostream>
using namespace std;
#include "instrument.h"

class Wind : public Instrument{
    public: 
        Wind(string name);
        ~Wind();
};