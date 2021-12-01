#include <iostream>
#include "woofer.h"
#include "tweeter.h"

class Speaker
{
public:
    Speaker();
    ~Speaker();
    void make_sound(float freq);
    float filter_freq;
    
    Tweeter tweeter;
    Woofer woofer_big;
    Woofer woofer_normal;
};
