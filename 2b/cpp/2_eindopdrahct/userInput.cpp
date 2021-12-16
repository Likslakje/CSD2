//All credits for userInput go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/xx_eindopdrachtExamples/01_ui_generic
#include <iostream>
#include "userInput.h"
using namespace std;

UserInput::UserInput(){
    cout<< "constructor userInput" <<endl;
}

UserInput::~UserInput(){
    cout<< "destructor userInput" <<endl;
}

void UserInput::commands(){
    make();
}

void UserInput::make(){
    string synthTypeSelection = retrieveUserSelection("synth", synthTypesOptions,
    numSynthTypes);
  cout << "You selected: " << synthTypeSelection << endl;

  string carrierWaveSelection = retrieveUserSelection("carrier oscillator", waveFormOptions,
    numWaveFormOptions);
  cout << "You selected: " << carrierWaveSelection << endl;

  float carrierValue = retrieveValueInRange(0, 128);
  cout << "Carrier value is set to: " << carrierValue << endl;

    string modulatorWaveSelection = retrieveUserSelection("modulator oscillator", waveFormOptions,
    numWaveFormOptions);
  cout << "You selected: " << modulatorWaveSelection << endl;

  float modulatorValue = retrieveValueInRange(0, 128);
  cout << "Carrier value is set to: " << modulatorValue << endl;

}

bool UserInput::validateSelection(string selection, string selectionOptions[],
    int numOptions){
    // check if the selection occurs inside the options, if so, return true
    for (int i = 0; i < numOptions; ++i) {
        if(selection == selectionOptions[i]) {
            return true;
        }
    }
    // selection does not occur in options --> return false
    return false;
}


string UserInput::retrieveUserInput(string subject, string selectionOptions[], 
    int numOptions){
    // show user the allowed options
    cout << "Please enter " << subject << " choice, your options are: ";
    for(int i = 0; i < numOptions - 1; i++) {
        cout << selectionOptions[i] << ", ";
    }
    // print last option outside forloop to end with an .
    cout << selectionOptions[numOptions - 1] << "." << endl;
    // retrieve and return choice
    string selection = "";
    cin >> selection;
    return selection;
}

string UserInput::retrieveUserSelection(string subject, string selectionOptions[], 
    int numOptions){
    bool noCorrectSelection = true;
    string userSelection = "";
    while(noCorrectSelection) {
        // let user choice between the allowed options
        userSelection = retrieveUserInput(subject, selectionOptions,
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


float UserInput::retrieveValueInRange(float min, float max){
    string input;
    float value = 0;
    bool notInRange = true;

    while(notInRange) {
        cout << "Please enter a value between " << min << " and " << max
        << endl;
        // first capture input in input string
        cin >> input;
        // validate if input string can be transformed into a float
        try {
        value = stof(input);
        // validate range
        if(value >= min && value <= max) {
            notInRange = false;
        } else {
            // value not in range
            cout << "Incorrect range, please try again." << endl;
        }
        } catch (const exception& e) {
        // no float as input
        cout << "Invalid input, this was not a number, please try again"
            << endl;
        }
    }
    return value;
}
