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
                        // I think something's going wrong here the second time around.
                        cout<< inputWaveform << " does not exist" <<endl;
                        waveformChoice(); // code too slow because of everything that needs to be printed?
                        i = 0;
                        // continue; ?
                    }
                }else{
                    throw(inputWaveform);
                }
            }
            catch(string waveformCatch){
                i = 0;
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