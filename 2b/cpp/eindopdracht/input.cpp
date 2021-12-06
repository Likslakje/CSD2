//All credits for writeToFile, Sine and the structure for every type of oscillator 
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include <array>
#include <sstream>
#include <string>
#include "sine.h"
using namespace std;

bool terminateBool = false;
// bool choiceCheck = false;
// int makeWaveformTimes = 0;
string inputExecute;
// string inputWaveform;  
// string inputFreq;
// float freq;
// array<string, 4> waveforms = {"sine", "triangle", "saw", "square"};
// array<class, 4> waveformObjects = {Sine, Triangle, Saw, Square}; //something like Sine* array[2] = {&.., &..}; idk 

// void waveformChoice(){
//     cout<< "Choose waveform: ";
//     //print everything inside the array
//     for(int i = 0; i < waveforms.size(); i++){
//         cout<< waveforms[i] << " ";
//     }
//     cout<< endl;
//     cin>> inputWaveform;
//     int i = 0; //the index for the waveform array inside the while loop
//     do{
//         if(inputWaveform == waveforms[i]){
//             //check if the input exists inside the array
//             //else keep going until choiceCheck is true -> see waveformChoiceCheck()
//                 choiceCheck = true;
//                 i = 0;
//                 break;
//         }else{
//             i++;
//             // cout<< inputWaveform << " does not exist" <<endl;
//         }
//     }
//     while(i < waveforms.size());
// }

// void waveformChoiceCheck(){
//     do{
//         //keep executing wavefromChoice until choiceCheck is true
//         waveformChoice();
//         // cout<< inputWaveform << " does not exist" <<endl;
//     }
//     while(!choiceCheck);
// }

// void waveformFreq(){
//     cout<< "Set frequency: ";
//     cin>> inputFreq;
//     freq = stof(inputFreq); //convert str to float
//     if (freq >= 20 && freq <= 20000){
//         // return freq;
//     }else{
//         cout<< "Frequency out of range (20 - 20k Hz)" <<endl;
//         waveformFreq();
//     }
// }


bool validateSelection(string selection, string selectionOptions[],
    int numOptions)
{
    // check if the selection occurs inside the options, if so, return true
    for (int i = 0; i < numOptions; ++i) {
        if(selection == selectionOptions[i]) {
            return true;
        }
    }
    // selection does not occur in options --> return false
    return false;
}


string retrieveUserInput(string selectionOptions[], int numOptions)
{
    // show user the allowed options
    cout << "Please enter your selection. You can choice between: ";
    for(int i = 0; i < numOptions - 1; i++) {
        cout << selectionOptions[i] << ", ";
    }
    // print last option outside forloop to end with an .
    cout << selectionOptions[numOptions - 1] << "." << std::endl;
    // retrieve and return choice
    string selection = "";
    cin >> selection;
    return selection;
}

string retrieveUserSelection(string selectionOptions[], int numOptions)
{
    bool noCorrectSelection = true;
    string userSelection = "";
    while(noCorrectSelection) {
        // let user choice between the allowed options
        userSelection = retrieveUserInput(selectionOptions,
            numOptions);
        // check if the selection is correct
        noCorrectSelection = !validateSelection(userSelection, selectionOptions,
            numOptions);
        // if selection is not correct, log message to user to try again
        if(noCorrectSelection) {
            cout << "Incorrect selection, please try again";
        }
    }
    return userSelection;
}

void execute(){
    do{ 
        cin>> inputExecute;
        if(inputExecute == "make"){
            // waveformChoiceCheck();
            // waveformFreq();
            string waveFormOptions[4] = {"sine", "saw", "square", "triangle"};
            int numWaveFormOptions = 4;
            string waveTypeSelection = retrieveUserSelection(waveFormOptions,
            numWaveFormOptions);
            cout << "You selected: " << waveTypeSelection << std::endl;
            cout<< "Type command: ";
        }
        else if(inputExecute == "edit"){
            // waveformFreq();
            cout<< "Type command: ";
        }
        else if(inputExecute == "terminate"){
            terminateBool = true;
        }
        else if(inputExecute == "help" || inputExecute == "?"){
            cout<< "Your options are:\nmake\nedit\nterminate\nhelp or ?" <<endl;
            cout<< "Type command: ";
        }else{
            cout<< inputExecute << " not a valid command" <<endl;
            cout<< "Type command: ";
            execute();
        }
    }while(!terminateBool);
}
