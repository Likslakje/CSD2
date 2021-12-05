#include <iostream>
using namespace std;
#include <array>
#include <sstream>
#include <string>
#include "sine.h"
#include "writeToFile.h"

class UserInput{
    public:
    UserInput();
    ~UserInput();
    bool terminate = false;
    bool choiceCheck = false;
    int makeWaveformTimes = 0;
    void waveformChoice();
    void waveformChoiceCheck();
    void waveformFreq();
    void makeObjectWaveform();
    protected:
        // string inputTerminate;
        string inputWaveform;  
        string inputFreq;
        float freq;
        array<string, 4> waveforms = {"sine", "triangle", "saw", "square"};
        // array<class, 4> waveformObjects = {Sine, Triangle, Saw, Square}; //something like Sine* array[2] = {&.., &..}; idk 
};
