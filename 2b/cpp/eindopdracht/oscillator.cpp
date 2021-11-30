#include <iostream>
#include "oscillator.h"
using namespace std;

Oscillator::Oscillator(){
    cout<< "Oscillator" <<endl;

}

Oscillator::~Oscillator(){

}

void Oscillator::selectWaveform(){

}

void Oscillator::playWaveform(){
    sinePlay();
}
