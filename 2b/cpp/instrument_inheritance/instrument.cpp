#include <iostream>
using namespace std;
#include "instrument.h"

Instrument::Instrument(string name, string soundDes){
    this-> name = name;
    this-> soundDes = soundDes;
}

Instrument::~Instrument(){
    
}

void Instrument::play(){
    cout<< name << " is playing \n" << soundDes <<endl;
}