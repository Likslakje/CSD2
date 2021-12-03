#include <iostream>
using namespace std;
#include "input.h"

UserInput::UserInput(){
   waveformChoiceCheck();
}

UserInput::~UserInput(){

}

void UserInput::waveformChoice(){
    cout<< "Choose waveform: ";
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
                cout<< "bool voor if " << choiceCheck << "i voor if "<< i <<endl;
                choiceCheck = true;
                cout<< "bool " << choiceCheck << "i " << i <<endl;
                i = 0;
                break;
        }else{
            i++;
        }
    }
    while(i < waveforms.size());
}

void UserInput::waveformChoiceCheck(){
do{
    waveformChoice();
}
while(!choiceCheck);
}