#include <iostream>
using namespace std;
#include "instrument.h"

Instrument::Instrument(){
    cin>> name >> soundDes >> note;
    this-> freq = Instrument::noteToFreq(note);
}

Instrument::~Instrument(){
    
}

float Instrument::noteToFreq(int note){
    freq = 440 * pow(2.0, (note - 69.0) / 12.0);
    return freq;
}

void Instrument::play(string message, string soundDes){
        cout<< name << message << " (" << freq << " Hz) " << soundDes <<endl;

}