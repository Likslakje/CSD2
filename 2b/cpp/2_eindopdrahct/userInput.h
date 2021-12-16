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
        static string retrieveUserSelection(string subject, string selectionOptions[], 
            int numOptions);
        static int retrieveSelectionIndex(string subject, 
            string selectionOptions[], int numOptions);
        static float retrieveValueInRange(float min, float max);
        float getCarrier();
        float getModulator();
    protected:

        static bool validateSelection(string selection, string selectionOptions[],
            int numOptions);
        static string retrieveUserInput(string subject, string selectionOptions[], 
            int numOptions);
        int numCommands = 2;
        string commandOptions[2] = {"make", "exit"};
        int numSynthTypes = 2;
        string synthTypesOptions[2] = {"AM", "FM"};
        int numWaveFormOptions = 4;
        string waveFormOptions[4] = {"sine", "saw", "square", "triangle"};

        string synthTypeSelection;
        string carrierWaveSelection;
        string modulatorWaveSelection;
        float carrierFrequency;
        float modulatorFrequency;
};

#endif