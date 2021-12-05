#include <iostream>
using namespace std;
#include "input.h"

UserInput::UserInput(){
    // do{
        waveformChoiceCheck();
        waveformFreq();
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

void UserInput::waveformFreq(){
    cout<< "Set frequency: ";
    cin>> inputFreq;
    this-> freq = stof(inputFreq); //convert str to float
    if (freq >= 20 && freq <= 20000){
        makeObjectWaveform();
    }else{
        cout<< "Frequency out of range (20 - 20k Hz)" <<endl;
        waveformFreq();
    }
}

void UserInput::makeObjectWaveform(){
    makeWaveformTimes++;
    string uniqueNumber = to_string(makeWaveformTimes);
    if(choiceCheck){
        //make an unique object name everytime a wavefrom is called
        string objectName = inputWaveform + uniqueNumber;
        cout<< inputWaveform << objectName <<endl;
        //return objectName;
        Sine sine(freq);
        std::cout << "Sine frequency: " << sine.getFrequency() << "\n";
        sine.setFrequency(10);
        std::cout << "Sine frequency: " << sine.getFrequency() << "\n";

        // write 1 second of samples to file
        // second parameter - overwrite is set to true
        // WriteToFile fileWriter("output.csv", true);
        // for(int i = 0; i < SAMPLERATE; i++) {
        //     fileWriter.write(std::to_string(sine.getSample()) + "\n");
        //     sine.tick();
        // }
    }
}