#include <iostream>
#include "sine.h"

class Oscillator : public Sine{
    public:
        Oscillator();
        ~Oscillator();
        void selectWaveform();
        void playWaveform();
};