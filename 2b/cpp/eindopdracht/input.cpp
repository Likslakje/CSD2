#include <iostream>
using namespace std;
#include "input.h"

UserInput::UserInput(){
    waveformChoice();
    while (true) {
        for(int i = 0; i < 4; i++){
            try{
                if(inputWaveform != waveforms[i]){
                    if(i == 3){
                        cout<< inputWaveform << " does not exist" <<endl;
                        waveformChoice();
                        i = 0;
                    }
                }else{
                    throw(inputWaveform);
                }
            }
            catch(string waveformCatch){
                cout<< inputWaveform << " exists" <<endl;
                break;
            }
        }
        break;
    }
}

UserInput::~UserInput(){

}

void UserInput::waveformChoice(){
    cout<< "Choose waveform: ";
    for(int i = 0; i < 4; i++){
        cout<< waveforms[i] << " ";
    }
    cout<< endl;
    cin>> inputWaveform;
}