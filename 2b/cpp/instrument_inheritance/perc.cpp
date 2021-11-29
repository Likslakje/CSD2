#include <iostream>
using namespace std;
#include "perc.h"

Percussion::Percussion() : Instrument(){
    cout<< "Percussion: " <<endl;
    this-> lowHz = 55;
    this-> highHz = 7500;
}

Percussion::~Percussion(){
    
}

void Percussion::pitchRangeCheck(){
    if(note >= lowHz && note <= highHz){
        Instrument::play(" is playing", soundDes);
    }else{
        Instrument::play(" pitch is out of range", "*insert crickets");
    }
}