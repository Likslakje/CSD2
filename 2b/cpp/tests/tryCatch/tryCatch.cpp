#include <iostream>
using namespace std;

string inputWaveform;  
string waveforms[4] = {"sine", "triangle", "saw", "square"};

void input(){
    cout<< "Choose waveform: ";
    for(int i = 0; i < 4; i++){
        cout<< waveforms[i] << " ";
    }
    cout<< endl;
    cin>> inputWaveform;
}

int main(){
    input();
    while (true) {
        for(int i = 0; i < 4; i++){
            try{
                if(inputWaveform != waveforms[i]){
                    if(i == 3){
                        cout<< inputWaveform << " does not exist" <<endl;
                        input();
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
    return 0;
}
