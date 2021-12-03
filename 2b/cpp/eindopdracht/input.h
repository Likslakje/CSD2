#include <iostream>
using namespace std;

class UserInput{
    public:
    UserInput();
    ~UserInput();
    void waveformChoice();
    string inputWaveform;  
    string waveforms[4] = {"sine", "triangle", "saw", "square"};
};
