#include <iostream>
using namespace std;
#include "input.h"

UserInput::UserInput(){
   waveformChoiceCheck();
    // waveformChoice();
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
                    cout << "does not exist" <<endl;
                    throw(choiceCheck);
                }
            }
        }
    }
    catch(bool boolCatch){
        cout<< boolCatch <<endl;
    }
}

void UserInput::waveformChoiceCheck(){
do{
    waveformChoice();
}
while(!choiceCheck);
// while(choiceCheck)
//     waveformChoice();
//     while (true) {
//         for(int i = 0; i < 4; i++){
//             try{
//                 if(inputWaveform != waveforms[i]){
//                     if(i == 3){
//                         // I think something's going wrong here the second time around.
//                         // is it even allowed to have a while loop inside a class?
//                         cout<< inputWaveform << " does not exist" <<endl;
//                         waveformChoice(); // code too slow because of everything that needs to be printed?
//                         i = 0;
//                         // would continue; help ?
//                     }
//                 }else{
//                     throw(inputWaveform);
//                 }
//             }
//             catch(string waveformCatch){
//                 i = 0;
//                 cout<< inputWaveform << " exists" <<endl;
//                 break;
//             }
//         }
//         break;
//     }
}