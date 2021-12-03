#include <iostream>
using namespace std;

class UserInput{
    public:
    UserInput();
    ~UserInput();
    void waveformChoice();
    protected:
        string inputWaveform;  
        string waveforms[4] = {"sine", "triangle", "saw", "square"};
};
