# include <iostream>
using namespace std;
#include "instrument.h"

class String : public Instrument{
    public:
        String(string name);
        ~String();
};

