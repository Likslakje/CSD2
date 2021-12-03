#include <iostream>
using namespace std;
#include <array>

class UserInput{
    public:
    UserInput();
    ~UserInput();
    bool choiceCheck = false;
    void waveformChoice();
    void waveformChoiceCheck();
    protected:
        string inputWaveform;  
        array<string, 4> waveforms = {"sine", "triangle", "saw", "square"};
};
