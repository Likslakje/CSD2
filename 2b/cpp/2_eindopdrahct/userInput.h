#ifndef _USERINPUT_H_
#define _USERINPUT_H_
#include <iostream>
using namespace std;

class UserInput{
    public:
        UserInput();
        ~UserInput();
                bool terminate = false;
        void commands();
        void make();
        bool validateSelection(string selection, string selectionOptions[],
            int numOptions);
        string retrieveUserInput(string subject, string selectionOptions[], 
            int numOptions);
        string retrieveUserSelection(string subject, string selectionOptions[], 
            int numOptions);
        float retrieveValueInRange(float min, float max);
    protected:
        int numCommands = 2;
        string commandOptions[2] = {"make", "exit"};
        int numSynthTypes = 2;
        string synthTypesOptions[2] = {"AM", "FM"};
        int numWaveFormOptions = 4;
        string waveFormOptions[4] = {"sine", "saw", "square", "triangle"};



};

#endif