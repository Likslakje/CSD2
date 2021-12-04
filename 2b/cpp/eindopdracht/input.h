#include <iostream>
using namespace std;
#include <array>
#include <sstream>

class UserInput{
    public:
    UserInput();
    ~UserInput();
    bool terminate = false;
    bool choiceCheck = false;
    int makeWaveformTimes = 0;
    stringstream stream;
    string str;
    void waveformChoice();
    void waveformChoiceCheck();
    void makeObjectName();
    protected:
        // string inputTerminate;
        string inputWaveform;  
        array<string, 4> waveforms = {"sine", "triangle", "saw", "square"};
};
