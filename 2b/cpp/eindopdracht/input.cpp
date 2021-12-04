#include <iostream>
using namespace std;
#include "input.h"

UserInput::UserInput(){
    // do{
        waveformChoiceCheck();
        makeObjectName();
    // }
    // while(!terminate);
}

UserInput::~UserInput(){

}

void UserInput::waveformChoice(){
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

void UserInput::waveformChoiceCheck(){
    do{
        //keep executing wavefromChoice until choiceCheck is true
        waveformChoice();
        // cout<< inputWaveform << " does not exist" <<endl;
    }
    while(!choiceCheck);
}

void UserInput::makeObjectName(){
    makeWaveformTimes++;
    stream << makeWaveformTimes;
    stream >> str;
    if(choiceCheck){
        //make an unique object name everytime a wavefrom is called
        string objectName = inputWaveform + str;
        cout<< objectName <<endl;
        //return objectName;
    }
}