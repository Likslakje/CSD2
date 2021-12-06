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
bool choiceCheck = false;
int makeWaveformTimes = 0;
string inputExecute;
string inputWaveform;  
string inputFreq;
float freq;
array<string, 4> waveforms = {"sine", "triangle", "saw", "square"};
// array<class, 4> waveformObjects = {Sine, Triangle, Saw, Square}; //something like Sine* array[2] = {&.., &..}; idk 


void waveformChoice(){
    cout<< "Choose waveform: ";
    //print everything inside the array
    for(int i = 0; i < waveforms.size(); i++){
        cout<< waveforms[i] << " ";
    }
    cout<< endl;
    cin>> inputWaveform;
    int i = 0; //the index for the waveform array inside the while loop
    do{
        if(inputWaveform == waveforms[i]){
            //check if the input exists inside the array
            //else keep going until choiceCheck is true -> see waveformChoiceCheck()
                choiceCheck = true;
                i = 0;
                break;
        }else{
            i++;
            // cout<< inputWaveform << " does not exist" <<endl;
        }
    }
    while(i < waveforms.size());
}

void waveformChoiceCheck(){
    do{
        //keep executing wavefromChoice until choiceCheck is true
        waveformChoice();
        // cout<< inputWaveform << " does not exist" <<endl;
    }
    while(!choiceCheck);
}

void makeObjectWaveform(){
    makeWaveformTimes++;
    string uniqueNumber = to_string(makeWaveformTimes);
    if(choiceCheck){
        //make an unique object name everytime a wavefrom is called
        string objectName = inputWaveform + uniqueNumber;
        cout<< inputWaveform << objectName <<endl;
       
          
        //return objectName;
        // Sine sine(freq);
        // std::cout << "Sine frequency: " << sine.getFrequency() << "\n";
        // sine.setFrequency(10);
        // std::cout << "Sine frequency: " << sine.getFrequency() << "\n";

        // write 1 second of samples to file
        // second parameter - overwrite is set to true
        // WriteToFile fileWriter("output.csv", true);
        // for(int i = 0; i < SAMPLERATE; i++) {
        //     fileWriter.write(std::to_string(sine.getSample()) + "\n");
        //     sine.tick();
        // }
    }
}

void waveformFreq(){
    cout<< "Set frequency: ";
    cin>> inputFreq;
    freq = stof(inputFreq); //convert str to float
    if (freq >= 20 && freq <= 20000){
        makeObjectWaveform();
    }else{
        cout<< "Frequency out of range (20 - 20k Hz)" <<endl;
        waveformFreq();
    }
}

void execute(){
    do{ 
        cin>> inputExecute;
        if(inputExecute == "make"){
            waveformChoiceCheck();
            waveformFreq();
            cout<< "Type command: ";
        }
        else if(inputExecute == "edit"){
            waveformFreq();
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
