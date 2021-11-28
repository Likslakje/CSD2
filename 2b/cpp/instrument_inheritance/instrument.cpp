# include <iostream>
using namespace std;
#include "instrument.h"

Instrument::Instrument(string name){
    this-> name = name;
}

Instrument::~Instrument(){
    
}

void Instrument::play(){
    cout<< name << " is playing" <<endl;
}