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
    try{
        for(int i = 0; i < waveforms.size(); i++){
            if(inputWaveform == waveforms[i]){
                cout<< "bool voor if " << choiceCheck << "i voor if "<< i <<endl;
                choiceCheck = true;
                cout<< "bool " << choiceCheck << "i " << i <<endl;
                i = 0;
                break;
            }else{
                if(i + 1 == waveforms.size()){
                    throw(choiceCheck);
                }
            }
        }
    }
    catch(bool boolCatch){
        cout << "does not exist" <<endl;
        cout<< boolCatch <<endl;
    }
}

void UserInput::waveformChoiceCheck(){
do{
    waveformChoice();
}
while(!choiceCheck);
}